import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.BindException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * Simple multithreaded Socket server:
 * 1) Print client messages to standard output
 * 2) Support 5+ clients simultaneously (thread pool control)
 * 3) Prompt error on binding error port
 * 4) Support optional duplex: echo received messages back to client
 */
public class Server {
    private final int port;
    private final boolean duplex;
    private final ExecutorService pool;
    private final List<ClientHandler> clients = new CopyOnWriteArrayList<>();

    public Server(int port, boolean duplex, int maxClients) {
        this.port = port;
        this.duplex = duplex;
        this.pool = Executors.newFixedThreadPool(maxClients);
    }

    public void start() {
        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server listening on port " + port + " ...");
            startConsoleBroadcaster();
            while (true) {
                Socket client = serverSocket.accept();
                try {
                    ClientHandler handler = new ClientHandler(client, duplex, clients::remove);
                    clients.add(handler);
                    pool.execute(handler);
                } catch (IOException e) {
                    System.err.println("Failed to initialize client handler: " + e.getMessage());
                    try {
                        client.close();
                    } catch (IOException ignored) {
                    }
                }
            }
        } catch (BindException be) {
            System.err.println("Port binding failed, possibly due to port being in use or insufficient permissions: " + be.getMessage());
        } catch (IOException e) {
            System.err.println("Server exception: " + e.getMessage());
        }
    }

    private void startConsoleBroadcaster() {
        Thread t = new Thread(() -> {
            try (BufferedReader console = new BufferedReader(new InputStreamReader(System.in))) {
                System.out.println("Server console ready. Type messages to broadcast or '/quit' to stop console input.");
                String line;
                while ((line = console.readLine()) != null) {
                    if ("/quit".equalsIgnoreCase(line.trim())) {
                        System.out.println("Console input stopped; server continues running.");
                        break;
                    }
                    broadcast("[Server] " + line);
                }
            } catch (IOException e) {
                System.err.println("Console broadcast error: " + e.getMessage());
            }
        });
        t.setDaemon(true);
        t.start();
    }

    private void broadcast(String msg) {
        for (ClientHandler handler : clients) {
            handler.send(msg);
        }
    }

    private static class ClientHandler implements Runnable {
        private final Socket socket;
        private final boolean duplex;
        private final PrintWriter writer;
        private final java.util.function.Consumer<ClientHandler> onClose;

        ClientHandler(Socket socket, boolean duplex, java.util.function.Consumer<ClientHandler> onClose) throws IOException {
            this.socket = socket;
            this.duplex = duplex;
            this.onClose = onClose;
            this.writer = new PrintWriter(socket.getOutputStream(), true);
        }

        @Override
        public void run() {
            String remote = socket.getRemoteSocketAddress().toString();
            System.out.println("Client connected: " + remote);
            try (BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {

                String line;
                while ((line = reader.readLine()) != null) {
                    // Print received message
                    System.out.println("[" + remote + "]: " + line);
                    // Duplex showback
                    if (duplex) {
                        writer.println("Echo: " + line);
                    }
                }
            } catch (SocketException se) {
                System.err.println("Connection exception (" + remote + "): " + se.getMessage());
            } catch (IOException e) {
                System.err.println("IO exception (" + remote + "): " + e.getMessage());
            } finally {
                try {
                    socket.close();
                } catch (IOException ignored) {
                }
                onClose.accept(this);
                System.out.println("Client disconnected: " + remote);
            }
        }

        void send(String msg) {
            synchronized (writer) {
                writer.println(msg);
            }
        }
    }

    public static void main(String[] args) {
        int port = 9000;
        boolean duplex = true;   // Enable duplex showback by default
        int maxClients = 5;     // Support more than 5 clients

        if (args.length >= 1)
            port = Integer.parseInt(args[0]);
        if (args.length >= 2)
            duplex = Boolean.parseBoolean(args[1]);
        if (args.length >= 3)
            maxClients = Integer.parseInt(args[2]);

        new Server(port, duplex, maxClients).start();
    }
}