import socket

HOST = "127.0.0.1" # localhost
PORT = 8080
BUFFER_SIZE = 1024

if __name__ == "__main__":
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        # connect to server
        server_socket.connect((HOST, PORT))
        print("Connected to server on port:", PORT)

        while True:
            try:
                message = str(input())

                # send clients message to the server encoded as bytes using default encoding
                server_socket.sendall(message.encode())

                # output the servers response to the client
                server_response = server_socket.recv(BUFFER_SIZE)
                print(server_response.decode())
            except KeyboardInterrupt:
                exit()

