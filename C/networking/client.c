#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int client_file_descriptor;

    // create socket file descriptor using IPv4, TCP and IP protocol
    client_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (client_file_descriptor == -1)
    {
        printf("Failed to create client file descriptor\n");
        return 1;
    }

    struct sockaddr_in server_address;
    int server_address_size = sizeof(server_address);

    server_address.sin_family = AF_INET; // IPv4
    server_address.sin_port = htons(PORT); // convert unsigned short to network byte order

    // convert IPv4 address from text to binary (127.0.0.1 is localhost)
    int conversion_status = inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    if (conversion_status == 0 || conversion_status == -1)
    {
        printf("Failed to convert address\n");
        return 2;
    }

    // connect to server at server_address
    int connection_status = connect(client_file_descriptor, (struct sockaddr *)&server_address, server_address_size);
    if (connection_status == -1)
    {
        printf("Failed to connect\n");
        return 3;
    }

    printf("Connected to server on port: %d\n", PORT);

    int send_status, read_status;
    char message[BUFFER_SIZE], buffer[BUFFER_SIZE];

    while (1)
    {
        fgets(message, sizeof(message), stdin);

        message[strcspn(message, "\n")] = 0;

        // send message to server
        send_status = send(client_file_descriptor, message, strlen(message) + 1, 0);
        if (send_status == -1)
        {
            printf("Failed to send message\n");
            return 4;
        }

        // read from server
        read_status = read(client_file_descriptor, buffer, sizeof(buffer));
        if (read_status == -1)
        {
            printf("Failed reading from server\n");
            return 5;
        }

        printf("Server response: %s\n", buffer);
    }

    return 0;
}
