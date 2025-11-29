#include "../include/libnet.hpp"

Socket_serveur::Socket_serveur(int d, int t, int p) :domain_(d),type_(t),protocol_(p), fd_(-1) { this->addr = {0}; this->status = CLOSE;};

Socket_serveur::~Socket_serveur()
{
    if(fd_ >= 0)    
        ::close(fd_);
};

void Socket_serveur::print_socket_serveur()
{
    cout << "[ State ]:" << (fd_ < 0 ? "Inactif" : " Actif") << endl;
    cout << "[ Domain ]:" << domain_<< endl;
    cout << "[ Type ]:" << type_<< endl;
    cout << "[ Protocol ]:" << protocol_<< endl;
    cout << endl;
};

int Socket_serveur::create()
{
    if((fd_ = socket(domain_,type_,protocol_)) < 0) {perror("Socket_serveur"); return (1);}
    else
    {
        cout << "Socket_serveur " <<  fd_ << " created" << endl; return(0);
        this->status = OPEN;
    }
};

int Socket_serveur::destoy()
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

int Socket_serveur::bind_server_data(const char *addr, uint16_t  port)
{
    this->addr.sin_family = this->domain_;
    this->addr.sin_port = htons(port);
    this->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(this->fd_, (struct sockaddr *)&(this->addr), sizeof(this->addr)) < 0)
    {
        perror("Serveur binding");
        return(1);
    }
    return(0);
}



int Socket_serveur::start_serveur()
{
    int csocket;
    int b_read;
    struct sockaddr_in addr;

    if(listen(this->fd_, 1) < 0)
    {
        perror("Listen error");
        return(1);
    }
    cout << "serveur is listen" << endl;

    socklen_t size =  sizeof(struct sockaddr_in);

    while (1)
    {
        if((csocket  = accept(this->fd_, (struct sockaddr *)&addr, &size)) < 0)
        {
            perror("accepte error");
            return(1);
        }
        cout << "receive message from " << csocket << endl;
        
        in_addr a =  (in_addr)addr.sin_addr;

        char *ip = inet_ntoa(a);

        cout << "ip: " << ip  << endl;
        if((b_read = recv(csocket, this->read_buffer, BUFFER_SIZE - 1, 0)) < 0)
        {
            perror("read error");
            return(1);

        }
        const char *response = "HTTP/1.0 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 11\r\n\r\nHello world";

        write(csocket, response, strlen(response));
        cout << "message: " << this->read_buffer << endl;
        close(csocket);
    }
    
    
    return(0);
}