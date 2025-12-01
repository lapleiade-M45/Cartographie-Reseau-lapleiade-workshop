
#include "../include/libnet.hpp"

int start_client()
{
     Socket_client client(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;

    client.print_socket_client();
    client.create();

    if(client.bind_server_data("192.168.1.147", 2022) < 0)
        return(1);
    if(client.connect_socket() > 0)
    {
        client.destoy();
        printf("client cleaned\n");
    }
    else
    {
        std::string line;
        char *l;

        cout << "send message: ";
        std::getline(std::cin, line);
        client.send_message(line);
    }
    return(0);
}


int main(void)
{
    Socket_serveur serveur(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;

    serveur.create();
    serveur.bind_server_data("127.0.0.10", 8081);
    serveur.start_serveur();

    return(0);
}