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
