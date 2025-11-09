#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



//

static int ft_printchar(int c) {
    return(write(1, &c, 1)); 
}

static int print_str(char const *s) {
    int count = 0; 
    while(*s) { 
        ft_printchar((int)*s); 
        count++; 
        s++; 
    }
    return (count); 
}

//

static int ft_printformat(char specifier, va_list ap) { 
    // 
    int count = 0; 
    if (specifier == 'c')
       count +=  print_char(va_arg(ap, int)); 
    else if(specifier == 's')
        count += print_str(va_arg(ap, char *)); 
    else if (specifier == 'd') 
        count += print_digit(va_arg(ap, int), 10) ;  
    else if(specifier == 'x')
        count += print_digit(va_arg(ap, unsigned int ), 16); 
     else 
        count += write(1, &specifier, 1); 
     return (count);       
}


// 

int ft_printf(const char *format , ...) { 

    va_list ap; 
    int count; 

    count = 0; 
    va_start(ap, format); 

    while(*format) {
        if(format == '%')
           count +=  ft_printformat(*(++format), ap); 
            // why do  we pass the arg pointer ??
         else 
            count += write(1, format, 1); 
            format++;    
    }
    va_end(ap); 
    return (count); 
}


int main() { 
    int count; 
    count = ft_printf("Hello %s \n", "jhon"); 
    ft_printf("the number os bytes written "); 

}