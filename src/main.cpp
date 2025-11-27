
#include "../include/libnet.hpp"


#define  CHECK_PARAM(param,flag) (((param) & (flag)) == (flag))






int main(void)
{

    Socket_client client(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;

    client.print_socket_client();
    client.create();

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = ft_inet_addr("10.10.10.10");
    addr.sin_port = htons(1);
 
    return(1);
}