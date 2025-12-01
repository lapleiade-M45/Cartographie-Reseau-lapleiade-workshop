
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
    assert(ft_inet_addr("192.168.0.255") == inet_addr("192.168.0.255"));
    // assert(ft_inet_addr("abc.def.ghi.jkl") == -1);
    return(0);
}



void print_arr_int(int *arr)
{
    int i;

    for(i = 0; i < 4; i++)
        cout << arr[i]  << " " ;
    cout << endl;

}


int generation_test()
{
    string ip_start = "192.168.255.245";
    string ip_end = "192.168.255.255";

    std::array< string, 11> arr = {"192.168.255.245","192.168.255.246","192.168.255.247","192.168.255.248","192.168.255.249","192.168.255.250","192.168.255.251","192.168.255.252","192.168.255.253","192.168.255.254","192.168.255.255"};
    uint32_t size;
    size = 0;
    uint32_t *ar = gnr_range_ip(CUSTOM, ip_start.c_str(), ip_end.c_str(), &size);

    // if(size > 0)
    // {
    //     cout << "start test size " << size  << endl;
    //     int i = 0;
    //     while (i < size)
    //     {
    //         in_addr_t test = inet_addr(arr.at(i).c_str());
    //         cout << " string: " << arr.at(i).c_str() << " uint32 og " << test << " own version " << ar[i] << endl;
    //         assert(ar[i] == (uint32_t)test);
    //         i++;
    //     }
        
    // }
    cout << "end test" << endl;  
    return(0);
}


int main(void)
{

    generation_test();

    return(0);
}