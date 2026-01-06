import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ConnectException;
import java.net.InetSocketAddress;
import java.net.Socket;

/**
 * Simple Socket client with interactive send:
 * 1) Connect once, then send multiple messages without disconnecting
 * 2) Each message can be chosen as text or file after startup
 * 3) Prompt error on connection failure due to incorrect IP/port
 * 4) Optionally start a receiving thread to support duplex communication
 */
public class Client {
    private final String host;
    private final int port;
    private final boolean duplexReceive;

    public Client(String host, int port, boolean duplexReceive) {
        this.host = host;
        this.port = port;
        this.duplexReceive = duplexReceive;
    }

    public void runInteractive() {
        try (Socket socket = createSocket(); BufferedOutputStream out = new BufferedOutputStream(socket.getOutputStream()); PrintWriter writer = new PrintWriter(out, true); BufferedReader console = new BufferedReader(new InputStreamReader(System.in))) {

            startReceiverIfNeeded(socket);

            System.out.println("Connected. Commands: 'text' to type, 'file <path>' to send file, 'exit' to quit.");
            while (true) {
                System.out.print("[text|file <path>|exit]>\n");
                String command = console.readLine();
                if (command == null)
                    break;
                command = command.trim();
                if (command.isEmpty())
                    continue;
                if ("exit".equalsIgnoreCase(command))
                    break;
                if (command.equalsIgnoreCase("text")) {
                    sendTextMessage(writer, console);
                    continue;
                }
                if (command.toLowerCase().startsWith("file ")) {
                    String filePath = command.substring(5).trim();
                    if (filePath.isEmpty()) {
                        System.out.println("Please provide a file path after 'file'.");
                        continue;
                    }
                    sendFileMessage(writer, filePath);
                    continue;
                }
                System.out.println("Unknown command, please use 'text', 'file <path>' or 'exit'.");
            }
        } catch (ConnectException ce) {
            System.err.println("Connection failed, check if IP/port is correct: " + ce.getMessage());
        } catch (IOException e) {
            System.err.println("Client IO exception: " + e.getMessage());
        }
    }

    private void sendTextMessage(PrintWriter writer, BufferedReader console) throws IOException {
        System.out.println("Enter text, end with two consecutive blank lines:");
        StringBuilder sb = new StringBuilder();
        String line;
        int blankCount = 0;
        while ((line = console.readLine()) != null) {
            if (line.isEmpty())
                blankCount++;
            else
                blankCount = 0;
            sb.append(line).append("\n");
            if (blankCount >= 2)
                break;
        }
        writer.print(sb.toString());
        writer.flush();
    }

    private void sendFileMessage(PrintWriter writer, String filePath) {
        try (BufferedReader fileReader = new BufferedReader(new InputStreamReader(new FileInputStream(filePath)))) {
            String line;
            while ((line = fileReader.readLine()) != null) {
                writer.println(line);
            }
            writer.flush();
            System.out.println("File sent: " + filePath);
        } catch (IOException e) {
            System.err.println("Failed to send file: " + e.getMessage());
        }
    }

    private Socket createSocket() throws IOException {
        Socket socket = new Socket();
        // 3 seconds connection timeout to avoid hanging
        socket.connect(new InetSocketAddress(host, port), 3000);
        return socket;
    }

    private void startReceiverIfNeeded(Socket socket) {
        if (!duplexReceive)
            return;
        Thread t = new Thread(() -> {
            try (BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    System.out.println("[Server] " + line);
                }
            } catch (IOException e) {
                // Read failure often due to peer closing, do not throw
            }
        });
        t.setDaemon(true);
        t.start();
    }

    public static void main(String[] args) {
        String host = "127.0.0.1";
        int port = 9000;
        boolean duplexReceive = true;

        if (args.length >= 1)
            host = args[0];
        if (args.length >= 2)
            port = Integer.parseInt(args[1]);
        if (args.length >= 3)
            duplexReceive = Boolean.parseBoolean(args[2]);

        Client client = new Client(host, port, duplexReceive);
        client.runInteractive();
    }
}