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
        write(2, "ERROR IPV4 FORMAT\n", ft_strlen("ERROR IPV4 FORMAT\n"));
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
                write(2, "ERROR IPV4 FORMAT\n", ft_strlen("ERROR IPV4 FORMAT\n"));
                ft_split_clean(&split);
                return(NULL);
            }
            j++;
        }
        i++;
    }
    return(split);
}

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
        addr_value |= atoi(split[split_len - 1]);
        addr_value = addr_value << arr[i];
        i++;
        split_len--;
    }
    ft_split_clean(&split);
    return(addr_value);
}