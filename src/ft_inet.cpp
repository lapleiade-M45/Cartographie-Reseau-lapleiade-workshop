#include "../include/libnet.hpp"


/*
    Inversion byte à byte

    from :  11100000 11000010 10111001 00000110
    to:     01100000 10011101 01000011 00000111     


*/

uint32_t ft_reverse_bit(uint32_t n)
{
    
    int j; 
    int bit;
    uint32_t reverse_ip;
    
    if(n <= 0)
        return(0);
    j = 0;
    bit = 31;
    while (bit >= 0)
    {
        reverse_ip = reverse_ip >> bit;
        reverse_ip |=  (n >> j) & 1 ;
        reverse_ip = reverse_ip << bit;
        j++;
        bit--;
    }
    return(reverse_ip);
}




/*
                    valeur       représentation binaire

    entré:          112837344 =  00000110 10111001 11000010 11100000
    sorti:          3770857734 = 11100000 11000010 10111001 00000110
    mask binaire:   255 =        00000000 00000000 00000000 11111111
    
*/

uint32_t ft_reverse_octets(uint32_t n)
{
    
    uint32_t h;                     // commentaire
    
    ft_print_bit_32(n);
    cout << n << endl;
    h =  0;                         // h = 00000000 00000000 00000000 00000000
    h |= (n >> 0) & 0x000000FF;     // h = 00000000 00000000 00000000 11100000
    h = h << 8;                     // h = 00000000 00000000 11100000 00000000
    h |= (n >> 8) & 0x000000FF;     // h = 00000000 00000000 11100000 11000010
    h = h << 8;                     // h = 00000000 11100000 11000010 00000000 
    h |= (n >> 16) & 0x000000FF;    // h = 00000000 11100000 11000010 10111001
    h = h << 8;                     // h = 11100000 11000010 10111001 00000000 
    h |= (n >> 24) & 0x000000FF;    // h = 11100000 11000010 10111001 00000110
    ft_print_bit_32(h);
    return(h);
}


static char **get_split_if_valide(const char *addr, int *split_len)
{
    int i;
    int j;
    char     **split;
    
    split = ft_split(addr, '.');
    if(!split)
        return(NULL);
    *split_len = ft_get_split_len(split);
    if(*split_len  != 4)
    {
        write(2, "ERROR 1 IPV4 FORMAT\n", ft_strlen("ERROR IPV4 FORMAT\n"));
        ft_split_clean(&split);
        return(NULL);
    }
    i = 0;
    while (split[i])
    {
        j = 0;
        while (split[i][j])
        {
            if(!ft_isdigit(split[i][j]))
            {
                write(2, "ERROR 2 IPV4 FORMAT\n", ft_strlen("ERROR IPV4 FORMAT\n"));
                ft_split_clean(&split);
                return(NULL);
            }
            j++;
        }
        i++;
    }
    return(split);
}

/*
    Ce que fait inet_addr:

    converti une ip format char * en entier.
    Comment?

    192.168.1.10

    ici 4 valeur:

        uint16_t    binaire     offset 
        192     =   11000000    24
        168     =   11000000    26
        1       =   10101000    8
        10      =   00001010    0

    chaqu'un de ces morceau de 8 bytes va etre integré a un entier vierge d'apres:

    i = 0 = 00000000 00000000 00000000 00000000

    1) decalé de offser bit vers la droite i >> offset

    2) activé les bytes dans i : i |= int

    3) decalé de offset bit vers la gauche i << 24

*/

uint32_t ft_inet_addr(const char *addr)
{
    
    int     i;
    char    **split;
    int     split_len;
    uint32_t addr_value;
    int arr[] = {24,16,8,0};

    if(!addr)
        return(0);
    addr_value = 0;
    split = get_split_if_valide(addr, &split_len);
    if(!split)
        return(0);
    i = 0;
    while (i <= 3)
    {
        addr_value = addr_value >> arr[i];
        addr_value |= ::atoi(split[split_len - 1]);
        addr_value = addr_value << arr[i];
        i++;
        split_len--;
    }
    ft_split_clean(&split);
    return(addr_value);
}

#define PRIVATE_1 1
#define PRIVATE_2 2
#define PRIVATE_3 2

/*
    les reseaux privées sont defini d'apres la rfc 1918

    PRIVATE_1       10.255.255.255  (10/8 prefix)
    PRIVATE_2       172.31.255.255  (172.16/12 prefix)
    PRIVATE_3       192.168.255.255 (192.168/16 prefix)
*/

int get_ip_range(uint32_t range[2], int net_type)
{



}

uint32_t *gnr_range_ip(string ip_start, string ip_end, uint32_t *size)
{

    int i;
    uint32_t ip;
    uint32_t *ips;
    uint32_t ptr;
    uint32_t start;
    uint32_t end;
    
    
    start = ft_reverse_octets(ft_inet_addr(ip_start.c_str()));
    end = ft_reverse_octets(ft_inet_addr(ip_end.c_str()));
   
    ips = (uint32_t *)::malloc(sizeof(uint32_t) * (end - (start - 1)));
    if(!ips)
    {
        cout << "Malloc error in generation" << endl;
        return(NULL);
    }
    i = 0;
    ptr = start;
    while(i <= (end - start))
    {
        ip  = ft_reverse_octets(ptr);
        ips[i] = ip;
        i++;
        (*size)++;
        ptr++;
    }
    return(ips);
}