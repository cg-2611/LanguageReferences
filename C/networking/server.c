#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int server_file_descriptor;

    // create socket file descriptor using IPv4, TCP and IP protocol
    server_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (server_file_descriptor == -1)
    {
        printf("Failed to create server file descriptor\n");
        return 1;
    }

    struct sockaddr_in address;
    int address_size = sizeof(address);

    address.sin_family = AF_INET; // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // accept connections from any address
    address.sin_port = htons(PORT); // convert unsigned short to network byte order

    // bind the socket to the address and port provided in the address struct
    int bind_status = bind(server_file_descriptor, (struct sockaddr *)&address, address_size);
    if (bind_status == -1)
    {
        printf("Failed to bind to port %d", PORT);
        return 2;
    }

    // wait for client to connect to the server
    // passing 3 allows a maximum of 3 clients to be in the queue
    // if any more clients attempt to connect, they may receive an error
    int listen_status = listen(server_file_descriptor, 3);
    if (listen_status == -1)
    {
        printf("Failed listening");
        return 3;
    }

    printf("Server listening on port: %d\n", PORT);

    int new_client = accept(server_file_descriptor, (struct sockaddr *)&address, (socklen_t *)&address_size);
    if (new_client == -1)
    {
        printf("Failed to accept client\n");
        return 4;
    }

    printf("Accepted connection on port: %d\n", PORT);

    int read_status, send_status;
    char buffer[BUFFER_SIZE], response[BUFFER_SIZE];

    while (1)
    {
        // read from client
        read_status = read(new_client, buffer, sizeof(buffer));
        if (read_status == -1)
        {
            printf("Failed to read from client\n");
            return 5;
        }

        strcpy(response, buffer);

        // send response to client
        send_status = send(new_client, response, strlen(response) + 1, 0);
        if (send_status == -1)
        {
            printf("Failed to send response\n");
            return 6;
        }
    }

    return 0;
}
