import java.io.*;
import java.net.*;

public class FileClient {
    public static void main(String[] args) throws IOException {
        String host = "localhost";
        int port = 3456;

        // Connect to server and send file
        Socket socket = new Socket(host, port);
        System.out.println("Connected to server!");

        DataOutputStream output = new DataOutputStream(socket.getOutputStream());
        FileInputStream fileIn = new FileInputStream("/workspaces/myWork/CNLAB/photo.png"); // Use correct file name

        byte[] buffer = new byte[4096];
        int bytesRead;

        // Loop to send the file
        while ((bytesRead = fileIn.read(buffer)) != -1) {
            output.write(buffer, 0, bytesRead);
        }

        System.out.println("File sent!");
    }
}
