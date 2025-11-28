#include "../include/libnet.hpp"

Socket_client::Socket_client(int d, int t, int p) :domain_(d),type_(t),protocol_(p), fd_(-1) { this->addr = {0}; this->status = CLOSE;};

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
    {
        cout << "Socket_client " <<  fd_ << " created" << endl; return(0);
        this->status = OPEN;
    }
};

int Socket_client::destoy()
{
    if(this->fd_ >= 0){close(fd_);fd_ = -1;}
    this->domain_ = 0;
    this->type_ = 0;
    ft_memset(&this->addr, 0, sizeof(this->addr));
    ft_memset(this->read_buffer, 0, sizeof(char) * BUFFER_SIZE);
    ft_memset(this->write_buffer, 0, sizeof(char) * BUFFER_SIZE);
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

int Socket_client::send_message( std::string line)
{
    int b_read;

    b_read = 0;
    if(this->status != CONNECTED || send(this->fd_, line.c_str(), line.length(),0) < 0)
    {
        cout << " Error envoi impossible" << endl;
        return(1);
    }
    else
    {
        cout << "STrart too read" << endl;
        if((b_read = recv(this->fd_, this->read_buffer, BUFFER_SIZE - 1, 0)) < 0)
        {
            perror("recv");
            return(1);
        }
        else
        {
            this->read_buffer[BUFFER_SIZE] = '\0';
            cout << this->read_buffer << endl;
        }
    }
    return(0);
}

int Socket_client::connect_socket()
{
    int j = 0;

    // if(fcntl(this->fd_, F_SETFL, O_NONBLOCK) < 0)
    // {
    //     perror("fcntl");
    //     exit(1);
    // }
    if(((j = connect(this->fd_, (struct sockaddr *)&(this->addr), sizeof(this->addr)))) < 0) 
    {
        this->status = ERROR;
        perror(" Error Socket_client");

        return (1);
    }
    else
    {
        this->status = CONNECTED;
        cout << "Socket_client " <<  j << " Connected" << endl;
        return(0);
    }
   
}
