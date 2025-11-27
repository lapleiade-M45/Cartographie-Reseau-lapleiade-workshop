#ifndef LIBNET_H
#define LIBNET_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <assert.h>
#include "libft.h"

using namespace std;

#define  CHECK_PARAM(param,flag) (((param) & (flag)) == (flag))


class Socket_client
{
    public:

        Socket_client(int d, int t, int p);
        ~Socket_client();
        void print_socket_client();
        int create();
        int connect_socket(const struct sockaddr_in *addr);
        
    private:
        int fd_;
        int domain_;
        int type_;
        int protocol_;
        
};

int ft_inet_addr(const char *addr);


#endif