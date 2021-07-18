import socket

HOST = "127.0.0.1" # localhost
PORT = 8080
BUFFER_SIZE = 1024

if __name__ == "__main__":
    # create a socket using IPv4 and TCP
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.bind((HOST, PORT)) # bind the socket to the address and port

        # listen for client connections, a backlog argument can be passed to limit the number of clients in the queue
        server_socket.listen()
        print("Server listening on port:", PORT)

        # blocks while waiting for a connection
        # setblocking() can be used to tell the socket not to block, which is can be used to accept multiple connections
        client_socket, address = server_socket.accept()

        with client_socket:
            print(f"Accepted connection on port {PORT} ; {address}")
            while True:
                client_message = client_socket.recv(BUFFER_SIZE)

                # if client_message is None then exit
                if not client_message:
                    exit()

                client_socket.sendall(client_message) # send() method also available which is similar to send() in C
