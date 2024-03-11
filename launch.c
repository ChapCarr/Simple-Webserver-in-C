#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include "webserver.h"

void launch(struct Server *server)
{
    char *hello = "HTTP/1.1 200 OK\nDate: Sunday, 10 March, 2024\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
    char buffer[30000];
   

    while (1)
    {
        
        printf(" **** Waiting For Connection **** \n");

        int addrlen = sizeof(server->address);
        int new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&addrlen);
        read(new_socket, buffer, 30000);
        printf("%s\n", buffer);
        write(new_socket, hello, strlen(hello));
        close(new_socket);
    }
}

int main(void)
{
    Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 8080, 10, launch);
    server.launch(&server);
    return 0;
}
