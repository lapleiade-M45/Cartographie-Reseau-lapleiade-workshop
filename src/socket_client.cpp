#include "../include/libnet.hpp"

Socket_client::Socket_client(int d, int t, int p) :domain_(d),type_(t),protocol_(p), fd_(-1) {};

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
};

int Socket_client::create()
{
    if((fd_ = socket(domain_,type_,protocol_)) < 0) {perror("Socket_client"); return (1);}
    else
        cout << "Socket_client " <<  fd_ << " created" << endl; return(0);
};

int Socket_client::connect_socket(const struct sockaddr_in *addr)
{
    if(connect(domain_,(struct sockaddr *)addr,sizeof(addr)) < 0) {perror("Socket_client"); return (1);}
    else
        cout << "Socket_client " <<  fd_ << " Connected" << endl; return(0);
}