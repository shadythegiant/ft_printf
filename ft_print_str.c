#include <stdlib.h>
#include <unistd.h>


int ft_strlen(const char *s) { 
    int len = 0; 
    while(s[len]) 
        len++; 
    return (len);     
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int ft_putchar(char c) { 
   return  write(1, &c, 1); 
}


int ft_putstr(const char *s) {
    int i; 
    
    if(!s)
        s = "(null)"; 
    i = ft_strlen(s); 
    write(1, s, i);      
    return (i); 
}