import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

	private ServerSocket serverSocket;

	public Server(int port) {
		try {
			serverSocket = new ServerSocket(port);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void start() {
		System.out.println("Server listening on port: " + serverSocket.getLocalPort() + "...");

		try {
			// accept connection from client
			Socket clientSocket = serverSocket.accept();

			System.out.println("Accepted connection on: " + serverSocket.getLocalPort() + " ; "+ clientSocket.getPort());

			// create input and output streams for communication
			// object streams can also be used for transporting serialized objects across network
			InputStreamReader clientCharacterStream = new InputStreamReader(clientSocket.getInputStream());
			BufferedReader clientInput = new BufferedReader(clientCharacterStream);

			PrintWriter clientOutput = new PrintWriter(clientSocket.getOutputStream(), true);

			while (true) {
				// echo input from client back to client
				String clientInputString = clientInput.readLine();
				clientOutput.println(clientInputString);
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
		Server server = new Server(8000);
		server.start();
	}
}