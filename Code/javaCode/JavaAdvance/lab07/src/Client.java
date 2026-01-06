import java.io.BufferedInputStream;
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
 * Simple Socket client:
 * 1) Send from standard input (end with two consecutive blank lines) or file
 * 2) Prompt error on connection failure due to incorrect IP/port
 * 3) Support sending long text (20KB+), using buffered streams
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

    public void sendFromStdin() {
        try (Socket socket = createSocket(); PrintWriter writer = new PrintWriter(new BufferedOutputStream(socket.getOutputStream()), true); BufferedReader console = new BufferedReader(new InputStreamReader(System.in))) {

            startReceiverIfNeeded(socket);

            System.out.println("Please enter content, end with two consecutive blank lines:");
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
            // Can keep the connection open to wait for server echo if needed; here simply close.
        } catch (ConnectException ce) {
            System.err.println("Connection failed, check if IP/port is correct: " + ce.getMessage());
        } catch (IOException e) {
            System.err.println("Client IO exception: " + e.getMessage());
        }
    }

    public void sendFromFile(String filePath) {
        try (Socket socket = createSocket(); BufferedInputStream fileIn = new BufferedInputStream(new FileInputStream(filePath)); BufferedOutputStream out = new BufferedOutputStream(socket.getOutputStream())) {

            startReceiverIfNeeded(socket);

            byte[] buf = new byte[8192];
            int n;
            while ((n = fileIn.read(buf)) != -1) {
                out.write(buf, 0, n);
            }
            out.flush();
        } catch (ConnectException ce) {
            System.err.println("Connection failed, check if IP/port is correct: " + ce.getMessage());
        } catch (IOException e) {
            System.err.println("Client IO exception: " + e.getMessage());
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
        String filePath = null;

        if (args.length >= 1)
            host = args[0];
        if (args.length >= 2)
            port = Integer.parseInt(args[1]);
        if (args.length >= 3)
            duplexReceive = Boolean.parseBoolean(args[2]);
        if (args.length >= 4)
            filePath = args[3];

        Client client = new Client(host, port, duplexReceive);
        if (filePath != null) {
            client.sendFromFile(filePath);
        } else {
            client.sendFromStdin();
        }
    }
}