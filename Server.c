#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

void readfile(int sd)
{
    FILE *file;
    char buffer[MAX_LINE_LENGTH];
    size_t bytes_read;

    file = fopen("/home/abhi/omen.jpg", "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        if (write(sd, buffer, bytes_read) != bytes_read)
        {
            perror("Error sending file");
            break;
        }
    }

    if (feof(file))
    {
        printf("File transfer completed\n");
    }
    else if (ferror(file))
    {
        perror("Error reading file");
    }

    fclose(file);
}

int main(int argc, char **argv)
{
    int sd, new_sd, port;
    struct sockaddr_in server_address, client_address;

    if (argc != 2)
    {
        fprintf(stderr, "usage %s <port>", argv[0]);
        exit(0);
    }
    port = atoi(argv[1]);

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        fprintf(stderr, "Couldn't create socket\n");
        exit(1);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);
    if ((bind(sd, (struct sockaddr *)&server_address, sizeof(server_address))) == -1)
    {
        fprintf(stderr, "Couldn't bind to socket\n");
        exit(2);
    }
    listen(sd, 5);
    while (1)
    {
        socklen_t client_length = sizeof(client_address);
        if ((new_sd = accept(sd, (struct sockaddr *)&client_address, &client_length)) == -1)
        {
            fprintf(stderr, "Couldn't connect to client\n");
            continue; // Continue to the next iteration
        }
        readfile(new_sd); // Pass new_sd instead of sd
        close(new_sd);
    }
    close(sd);
}
