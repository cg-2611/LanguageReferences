import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {

    private Socket serverSocket;

    public Client(String host, int port) {
        try {
            serverSocket = new Socket(host, port);
        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public void start() {
        
        try {
            BufferedReader userInputReader = new BufferedReader(new InputStreamReader(System.in));

            // create input and output streams for communication
            // object streams can also be used for transporting serialized objects across network
            PrintWriter serverOutput = new PrintWriter(serverSocket.getOutputStream(), true);

            InputStreamReader serverCharacterStream = new InputStreamReader(serverSocket.getInputStream());
            BufferedReader serverInput = new BufferedReader(serverCharacterStream);

            while (true) {
                // get input from user and send to server
                String userInput = userInputReader.readLine();
                serverOutput.println(userInput);

                // get response from server and print to console
                String serverResponse = serverInput.readLine();
                System.out.println("Server Response: " + serverResponse);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                serverSocket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        Client client = new Client("localhost", 8000);
        client.start();
    }

}