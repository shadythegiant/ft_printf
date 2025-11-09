#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


static int ft_print_format() { 

}



int ft_printf(const char *format , ...) {
    va_list ap;
    int count; 
    char *specifier; 
    char *s; 
    
    if(!format)
        return(-1); 
    count = 0; 
    s = (char *)format; 
    va_start(ap, format); 
    while(*s) { 
        if(*s != '%' && ++count) { 
            write(1, s++, 1); 
            continue;
        }
        specifier = ft_strchr("cspdiuxX%" , *(s + 1 )); 
    }
    
}