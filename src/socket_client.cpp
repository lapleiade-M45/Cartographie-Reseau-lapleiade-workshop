#include "../include/libnet.hpp"

Socket_client::Socket_client(int d, int t, int p) :domain_(d),type_(t),protocol_(p), fd_(-1) { this->addr = {0};};

Socket_client::~Socket_client()
{
    if(fd_ >= 0)    
        ::close(fd_);
};

void Socket_client::print_socket_client()
{
    cout << "[ State ]:" << (fd_ < 0 ? "Inactif" : " Actif") << endl;
    cout << "[ Domain ]:" << domain_<< endl;
    cout << "[ Type ]:" << type_<< endl;
    cout << "[ Protocol ]:" << protocol_<< endl;
    cout << endl;
};

int Socket_client::create()
{
    if((fd_ = socket(domain_,type_,protocol_)) < 0) {perror("Socket_client"); return (1);}
    else
        cout << "Socket_client " <<  fd_ << " created" << endl; return(0);
};

int Socket_client::destoy()
{
    if(this->fd_ >= 0){close(fd_);fd_ = -1;}
    this->domain_ = 0;
    this->type_ = 0;
    ft_memset(&this->addr, 0, sizeof(this->addr));
    ft_memset(this->buffer, 0, sizeof(char) * BUFFER_SIZE);
    cout << "Socket cleaned" << endl;
    return(1);
}   

int Socket_client::bind_server_data(const char *addr, uint16_t  port)
{
    this->addr.sin_family = domain_;
    this->addr.sin_port = htons(port);
    this->addr.sin_addr.s_addr = ft_inet_addr(addr);
    return(1);
}

// int Socket_client::connect_socket()
// {
//     int r;
//     pid_t f;

//     if((f = fork()) < 0 )
//     {
//         perror("fork"); 
//         return(1);
//     };

//     if(f == 0)
//     {
//         printf("we are in children\n");
//         if(fcntl(this->fd_, F_SETFL, O_NONBLOCK) < 0)
//         {
//             perror("fcntl");
//             exit(1);
//         }
//         cout << "Socket en mdoe non blokant" << endl;
//         r = 0;
//         if((r = connect(this->fd_, (struct sockaddr *)&(Socket_client::addr), sizeof(addr))) < 0) 
//         {
//             perror(" Error Socket_client"); 
//             if(errno != EINPROGRESS)
//                 exit (1);
//         }
//         cout << "Socket_client " <<  this->fd_ << " Connected" << endl; return(this->fd_);
//         exit(0);
//     }
//     else
//     {

//         waitpid(f,&r, 0);
//         if( r != 0)
//             return(1);
//     }
//     return(0);
// }

int Socket_client::connect_socket()
{
    pid_t f;
    int r = 0;
    int j = 0;

    if((f = fork()) < 0 )
    {
        perror("fork"); 
        return(1);
    };

    if(f == 0)
    {
        // if(fcntl(this->fd_, F_SETFL, O_NONBLOCK) < 0)
        // {
        //     perror("fcntl");
        //     exit(1);
        // }
        //cout << "Socket en mdoe non blokant" << endl;
        if(((j = connect(this->fd_, (struct sockaddr *)&(this->addr), sizeof(this->addr)))) < 0) 
        {
            perror(" Error Socket_client"); 
            exit (1);
        }
        else
        {

            cout << "Socket_client " <<  j<< " Connected" << endl;
            exit(0);
        }
    }
    else
    {

        waitpid(f,&r, 0);
        if( r != 0)
            return(1);
    }
   
    return(0);
}
