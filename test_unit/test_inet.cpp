
#include "../include/libnet.hpp"

int inet_test()
{
    /*
        gpt assertion test
    */
    assert(ft_inet_addr("0.0.0.0") == inet_addr("0.0.0.0"));
    assert(ft_inet_addr("127.0.0.1") == inet_addr("127.0.0.1"));
    assert(ft_inet_addr("255.255.255.255") == inet_addr("255.255.255.255"));

    assert(ft_inet_addr("192.168.1.5") == inet_addr("192.168.1.5"));
    assert(ft_inet_addr("1.2.3.4") == inet_addr("1.2.3.4"));
    assert(ft_inet_addr("10.20.30.40") == inet_addr("10.20.30.40"));
    assert(ft_inet_addr("8.16.32.64") == inet_addr("8.16.32.64"));

    assert(ft_inet_addr("1.1.1.255") == inet_addr("1.1.1.255"));
    assert(ft_inet_addr("128.0.0.1") == inet_addr("128.0.0.1"));
    assert(ft_inet_addr("1.128.64.32") == inet_addr("1.128.64.32"));
    assert(ft_inet_addr("250.10.200.3") == inet_addr("250.10.200.3"));
    assert(ft_inet_addr("1.0.0.1") == inet_addr("1.0.0.1"));
    assert(ft_inet_addr("1.2.0.3") == inet_addr("1.2.0.3"));
    assert(ft_inet_addr("1.2.3.0") == inet_addr("1.2.3.0"));
    assert(ft_inet_addr("0.1.2.3") == inet_addr("0.1.2.3"));

    assert(ft_inet_addr("255.255.255.0") == inet_addr("255.255.255.0"));
    assert(ft_inet_addr("255.255.0.0") == inet_addr("255.255.0.0"));
    assert(ft_inet_addr("255.0.0.0") == inet_addr("255.0.0.0"));
    assert(ft_inet_addr("255.128.0.0") == inet_addr("255.128.0.0"));
    assert(ft_inet_addr("256.1.1.1") != inet_addr("256.1.1.1"));
    // assert(ft_inet_addr("10.10.10") == -1);
    // assert(ft_inet_addr("10.10") == -1);
    // assert(ft_inet_addr("10") == -1);
    // assert(ft_inet_addr("") == -2 || ft_inet_addr("") == -1);
    // assert(ft_inet_addr("10..10.10") == -1);
    assert(ft_inet_addr("0.255.0.255") == inet_addr("0.255.0.255"));
    
    assert(ft_inet_addr("255.0.255.0") == inet_addr("255.0.255.0"));
    assert(ft_inet_addr("100.200.150.50") == inet_addr("100.200.150.50"));
    assert(ft_inet_addr("5.200.100.250") == inet_addr("5.200.100.250"));
    // assert(ft_inet_addr("abc.def.ghi.jkl") == -1);
    return(0);
}


int main(void)
{
    if(inet_test() != 0);
        return(0);

    return(0);
}