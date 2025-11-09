#include <stdlib.h>
#include <unistd.h>



int ft_print_hex(unsigned long n , int uppercase) { 
    char *hex; 
    
    hex = "123456789abcdef"; 
    if(uppercase == 1) 
        hex = "123456789ABCDEF"; 
    if(n > 15) 
       return(ft_print_hex(n / 16, uppercase ) + ft_putchar(hex[n % 16])); 
     else 
        return (ft_putchar(hex[n]));   

}


int ft_putptr(void *n) { 
    
    if (n == NULL)
        return(ft_putstr("nil")); 

     return(ft_putstr("0x") + ft_print_hex((unsigned int)n, 0));  
}


int ft_putunbr(unsigned int n) {

    if(n > 9)
        return (ft_putunbr(n / 10) + ft_putchar((n % 10) + '0')); 
     else 
        return(ft_putchar(n + '0')); 
}

int ft_putnbr(int n) { 
    long nbr; 
    int count; 

    nbr = n; 
    count = 0; 
    if(nbr < 0) { 
        count += ft_putchar('-'); 
        nbr = -nbr; 
    }
    if(nbr > 9) {
        count += ft_putnbr(nbr / 10); 
        return(count + ft_putchar((nbr % 10) + '0')); 
    } 
    else 
     return( count + ft_putchar(nbr + '0')); 
}