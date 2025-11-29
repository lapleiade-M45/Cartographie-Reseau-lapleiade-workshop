#include "../include/libnet.hpp"

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

int ft_inet_addr(const char *addr)
{
    
    int     i;
    char    **split;
    int     split_len;
    uint32_t addr_value;
    int arr[] = {24,16,8,0};

    if(!addr)
        return(-1);
    addr_value = 0;
    split = get_split_if_valide(addr, &split_len);
    if(!split)
        return(-1);
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


/*
    adresse type 192 . 168 . 1 . 0 / 24

    ip::=         address taille
    taille::=     sep value
    sep ::=         "/"
    value ::=       ("24" | "16" | "8")
    address::=      val sep2 val sep2 val sep2 val
    sep2::=         "."
    val::=          entier
    entier::=       chiffre | chiffre chiffre | chiffre chiffre chiffre

*/

int get_subnetwork(string ip, char buffer[15], int mask)
{
    int dot;
    int i;

    if(mask == 24)
        dot = 3;
    else if(mask == 16)
        dot = 2;
    else
        dot = 1;
    i = 0;
    while (ip.at(i) && dot > 0)
    {
        ip.copy(&buffer[i],1, i);
        if(buffer[i] == '.')
            dot--;
        i++;
    }
    buffer[i] = '\0';
    return(i);
}

int *gen_ip(string ip, int mask)
{

    int idx;
    char *value;
    // 192.168.1.10
    char buffer[16];

    get_subnetwork(ip, buffer, mask);
    cout << "buffer: " << buffer << endl;
    

    int i = 0;

    idx = ((string)buffer).find_last_of('.') + 1;
    while (i <= 255)
    {
        value = ft_itoa(i);
        memcpy(&buffer[idx], value, ft_strlen(value));
        buffer[idx + ft_strlen(value)] = '\0';
        cout << buffer << endl;
        i++;
    }

    return(NULL);


}


int *get_ip_range(string ip)
{

    int net_size_idx;
    int net_size;
    int split_len;

    net_size_idx = ip.find_last_of('/');
    if(net_size_idx < 0)
    {
        cout << "network size is missing" << endl;
        return(NULL);
    }
    cout << "size idx: " << net_size_idx << endl;
    net_size = ::atoi(&ip[net_size_idx + 1]);
    if(net_size != 24 && net_size != 16 && net_size != 8)
    {
        cout << "This network size is not ipv4 compatible" << endl;
        return(NULL);
    }
    string str = ip.substr(0, net_size_idx);
    
    int *arr_ip = gen_ip(str, net_size);
        
    return(NULL);
}