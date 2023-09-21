#include "main.h"

int main (void)
{
    char num = 'a';
    char *str = "Hello, World!";
    int num1 = -1;
    int num2 = 3;
    int decimalNum3 = 075;
    unsigned int numhex = 255; 
    
    
    // Test cases
    _printf("Integer: %c\n", num);
    _printf("String: %s\n", str);
    _printf("int: %i\n", num1);
    _printf("int: %d\n", num2);
    _printf("Binary: %b\n", 98);
    _printf("Decimal 99 in Octal: %o\n", decimalNum3);
    _printf("%x\n", numhex);
    _printf("%X\n", numhex);
    _printf("Let's try to printf a simple sentence.\n");
    
    return 0;
}
