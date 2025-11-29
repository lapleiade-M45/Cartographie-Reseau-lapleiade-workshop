#ifndef LIBNET_H
#define LIBNET_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <iostream>
#include <assert.h>
#include <string.h>
#include "libft.h"

using namespace std;

#define  CHECK_PARAM(param,flag) (((param) & (flag)) == (flag))

#define BUFFER_SIZE 4096

#define CLOSE       0 
#define OPEN        1
#define WAIT        2
#define CONNECTED   3
#define ERROR       4


class Socket_client
{
    public:

        Socket_client(int d, int t, int p);
        ~Socket_client();
        void print_socket_client();
        int create();
        int destoy();
        int connect_socket();
        int bind_server_data(const char *addr, uint16_t  port);
        int send_raw_data();
        int send_message(std::string );
        
    private:

        int fd_;
        int domain_;
        int type_;
        int protocol_;
        struct sockaddr_in addr;
        char read_buffer[BUFFER_SIZE];
        char write_buffer[BUFFER_SIZE];
        int status;
        
};


class Socket_serveur
{
    public:

        Socket_serveur(int d, int t, int p);
        ~Socket_serveur();
        void print_socket_serveur();
        int create();
        int destoy();
        int connect_socket();
        int bind_server_data(const char *addr, uint16_t  port);
        int send_raw_data();
        int start_serveur();
        
    private:

        int fd_;
        int domain_;
        int type_;
        int protocol_;
        struct sockaddr_in addr;
        char read_buffer[BUFFER_SIZE];
        char write_buffer[BUFFER_SIZE];
        int status;
        
};

int ft_inet_addr(const char *addr);
int *get_ip_range(string ip);


#endif