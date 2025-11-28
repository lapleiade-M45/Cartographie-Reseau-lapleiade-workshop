
#include "../include/libnet.hpp"


int main(void)
{
    
    Socket_client client(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;

    client.print_socket_client();
    client.create();

    if(client.bind_server_data("192.168.1.147", 2022) < 0)
        return(1);
    if(client.connect_socket() < 0)
    {
        client.destoy();
        printf("client cleaned\n");
    }


    while (1)
    {
        ::sleep(1);
    }
    
    return(0);
}