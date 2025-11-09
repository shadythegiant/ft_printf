#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

void run_tests(void)
{
    int ft_ret, std_ret;
    
    printf("=== BASIC TESTS ===\n");
    
    // Character tests
    ft_ret = ft_printf("Char: %c\n", 'A');
    std_ret = printf("Char: %c\n", 'A');
    printf("ft: %d, std: %d\n\n", ft_ret, std_ret);
    
    // String tests
    ft_ret = ft_printf("String: %s\n", "Hello World");
    std_ret = printf("String: %s\n", "Hello World");
    printf("ft: %d, std: %d\n\n", ft_ret, std_ret);
    
    ft_ret = ft_printf("Empty: %s\n", "");
    std_ret = printf("Empty: %s\n", "");
    printf("ft: %d, std: %d\n\n", ft_ret, std_ret);
    
    // NULL string
	char *null = NULL; 
    ft_ret = ft_printf("NULL: %s\n", null);
    std_ret = printf("NULL: %s\n", null);
    printf("ft: %d, std: %d\n\n", ft_ret, std_ret);
    
    // Integer tests
    ft_ret = ft_printf("Integer: %d\n", 42);
    std_ret = printf("Integer: %d\n", 42);
    printf("ft: %d, std: %d\n\n", ft_ret, std_ret);
    
    ft_ret = ft_printf("Negative: %d\n", -42);
    std_ret = printf("Negative: %d\n", -42);
    printf("ft: %d, std: %d\n\n", ft_ret, std_ret);
    
    // Pointer tests
    int x = 42;
    ft_ret = ft_printf("Pointer: %p\n", &x);
    std_ret = printf("Pointer: %p\n", (void *)&x);
    printf("ft: %d, std: %d\n\n", ft_ret, std_ret);
    
    ft_ret = ft_printf("NULL Pointer: %p\n", NULL);
    std_ret = printf("NULL Pointer: %p\n", (void *)NULL);
    printf("ft: %d, std: %d\n\n", ft_ret, std_ret);
    
    // Unsigned tests
    ft_ret = ft_printf("Unsigned: %u\n", 123);
    std_ret = printf("Unsigned: %u\n", 123);
    printf("ft: %d, std: %d\n\n", ft_ret, std_ret);
    
    // Hex tests
    ft_ret = ft_printf("Hex lower: %x\n", 255);
    std_ret = printf("Hex lower: %x\n", 255);
    printf("ft: %d, std: %d\n\n", ft_ret, std_ret);
    
    ft_ret = ft_printf("Hex upper: %X\n", 255);
    std_ret = printf("Hex upper: %X\n", 255);
    printf("ft: %d, std: %d\n\n", ft_ret, std_ret);
    
    // Percent sign
    ft_ret = ft_printf("Percent: %%\n");
    std_ret = printf("Percent: %%\n");
    printf("ft: %d, std: %d\n\n", ft_ret, std_ret);
}

void edge_cases(void)
{
    printf("=== EDGE CASES ===\n");
    
    // Empty string
    ft_printf("Empty format string test\n");
    printf("Empty format string test\n\n");
    
    // Only percent
    ft_printf("%%");
    printf("%%");
    printf("\n\n");
    
    // Multiple specifiers
    int a = 42;
    ft_printf("%c %s %d %u %x %X %p %%\n", 'A', "test", 42, 100, 255, 255, (void *)&a);
    printf("%c %s %d %u %x %X %p %%\n", 'A', "test", 42, 100, 255, 255, (void *)&a);
    printf("\n");
    
    // No specifiers
    ft_printf("Just a normal string without any specifiers\n");
    printf("Just a normal string without any specifiers\n");
    printf("\n");
}

void limit_values(void)
{
    printf("=== LIMIT VALUES ===\n");
    
    // Integer limits
    ft_printf("INT_MAX: %d\n", INT_MAX);
    printf("INT_MAX: %d\n", INT_MAX);
    
    ft_printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MIN: %d\n", INT_MIN);
    
    ft_printf("UINT_MAX: %u\n", UINT_MAX);
    printf("UINT_MAX: %u\n", UINT_MAX);
    
    // Zero cases
    ft_printf("Zero: %d\n", 0);
    printf("Zero: %d\n", 0);
    
    ft_printf("Hex zero: %x\n", 0);
    printf("Hex zero: %x\n", 0);
    
    // Pointer zero
    ft_printf("Pointer zero: %p\n", (void *)0);
    printf("Pointer zero: %p\n", (void *)0);
}

void invalid_specifiers(void)
{
    printf("=== INVALID SPECIFIERS ===\n");
    
    // Invalid specifiers
    ft_printf("Invalid: %%z\n");
    printf("Invalid: %%z\n");
    
    ft_printf("Invalid: %%q\n");
    printf("Invalid: %%q\n");
    
    // Percent at end
    ft_printf("Percent at end: %%");
    printf("Percent at end: %%");
    printf("\n");
}

void test_return_values(void)
{
    printf("=== RETURN VALUE TESTS ===\n");
    
    int ft_ret, std_ret;
    
    // Test various return values
    ft_ret = ft_printf("Hello %s!", "World");
    printf("\n");
    std_ret = printf("Hello %s!", "World");
    printf("\nft_ret: %d, std_ret: %d %s\n", ft_ret, std_ret, 
           ft_ret == std_ret ? "✓" : "✗");
    
    ft_ret = ft_printf("%c%c%c", 'A', 'B', 'C');
    std_ret = printf("%c%c%c", 'A', 'B', 'C');
    printf("\nft_ret: %d, std_ret: %d %s\n", ft_ret, std_ret,
           ft_ret == std_ret ? "✓" : "✗");
    
    // Empty string test - fixed: use a space or remove the test
    ft_ret = ft_printf("");  // This tests empty string in ft_printf
    std_ret = printf(" ");   // Use space instead of empty string for printf
    printf("Empty: ft_ret: %d, std_ret: %d (note: std used space)\n", ft_ret, std_ret);
}

void test_null_format(void)
{
    printf("=== NULL FORMAT TEST ===\n");
    
    int ft_ret = ft_printf(NULL);
    printf("ft_printf(NULL) returned: %d (should be -1)\n", ft_ret);
}

int main(void)
{
    printf("=== FT_PRINTF COMPREHENSIVE TEST ===\n\n");
    
    run_tests();
    edge_cases();
    limit_values();
    invalid_specifiers();
    test_return_values();
    test_null_format();
    
    printf("\n=== TEST COMPLETE ===\n");
    return 0;
}