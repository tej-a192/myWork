import java.io.*;
import java.net.*;

public class FileServer {

    public static void main(String[] args) throws IOException {
        int port = 3456;
        ServerSocket serverSocket = new ServerSocket(port);  // Create server socket on port 3456
        System.out.println("Server is listening on port " + port);

        // Server will keep running to accept multiple client connections
        while (true) {
            Socket clientSocket = serverSocket.accept();  // Wait for a client connection
            System.out.println("Client connected.");

            // Read data from the client and save it as a file
            DataInputStream input = new DataInputStream(clientSocket.getInputStream());
            FileOutputStream fileOut = new FileOutputStream("received_file.jpg");

            byte[] buffer = new byte[4096];
            int bytesRead;
            // Read file content from the client and write it to the server's file system
            while ((bytesRead = input.read(buffer)) != -1) {
                fileOut.write(buffer, 0, bytesRead);
            }

            System.out.println("File received, connection closed.");
        }
    }
}
