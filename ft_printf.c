#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



//

int ft_printformat(char specifier, va_list ap) { 

    // 

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

}