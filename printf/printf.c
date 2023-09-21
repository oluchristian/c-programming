#include "main.h"
#define BUFFER_SIZE 1024
/**
 * _printf - prints values to stdout
 *
 * @format: number of arguements passed
 *
 * Return: the number of characters printed
 */
int _printf(char *format, ...)
{
        int i = 0, j = 0, octalArrSize = 0, hexArrSize = 0, num = 0, capsHexArrSize = 0;
        //I used 64 as array size to represent 64bits machine
        unsigned int binaryNum[64];
        int octalNum[64];
        int hexNum[64];
        int capitalHexNum[64];
        char buffer[BUFFER_SIZE];
        int buff_ind = 0;
        int divisor, k, octalArrayInit, hexArrayInit, capsHexArrayInit;
        va_list args;

        va_start(args, format);

        for (i = 0; format[i] != '\0'; i++)
        {
                if (format[i] == '%')
                {
                        i++;

                        if (format[i] == 'c')
                        {
                                char letter = va_arg(args, int);

                                _putchar(letter);
                                num += 1;
                        }
                        else if (format[i] == 's')
                        {
                                char *str = va_arg(args, char*);

                                while (*str)
                                {
                                        _putchar(*str);
                                        str++;
                                        num += 1;
                                }
                        }
                        else if (format[i] == 'd' || format[i] == 'i')
                        {
                                int digits = va_arg(args, int);

                
                                if (digits < 0)
                                {
                                    _putchar('-');
                                    num += 1;
                                    digits = -digits;
                                }
                
                                divisor = 1;
                                while (digits / divisor > 9)
                                {
                                    divisor *= 10;
                                }

                                while (divisor != 0)
                                {
                                    int digit = (digits / divisor) % 10;
                                    _putchar('0' + digit);
                                    num += 1;
                                    divisor /= 10;
                                }
                        }
                        else if (format[i] == 'b')
                        {
                            unsigned int positiveNum = va_arg(args, unsigned int);

                            while (positiveNum > 0)
                            {
                            binaryNum[j++] = positiveNum % 2;
                            positiveNum /= 2;
                            }

                            for (k = j-1; k >= 0; k--)
                            {
                                _putchar(binaryNum[k] + 48);
                                num += 1;
                            }
                        }
                        else if (format[i] == 'u')
                        {
                            unsigned int unsignedDecimal = va_arg(args, unsigned int);
                            _putchar(unsignedDecimal);
                            num += 1;
                        }
                        else if (format[i] == 'o')
                        {
                            int convertToBase8 = va_arg(args, unsigned int);
                            //convert digit to octal
                            while (convertToBase8 > 0)
                            {
                                octalNum[octalArrSize++] = convertToBase8 % 8;
                                convertToBase8 /= 8;
                            }

                            for (octalArrayInit = octalArrSize - 1; octalArrayInit >= 0; octalArrayInit--)
                            {
                                _putchar(octalNum[octalArrayInit] + 48);
                                num += 1;
                            }
                        }
                        else if (format[i] == 'x')
                        {
                            int convertToHex= va_arg(args, unsigned int);

                            while(convertToHex > 0)
                            {
                                int remainder = convertToHex % 16;

                                if (remainder < 10)
                                {
                                    hexNum[hexArrSize++] = remainder + '0';
                                }
                                else
                                {
                                    hexNum[hexArrSize++] = remainder - 10 + 'a';
                                }
                                convertToHex /= 16;
                            }

                            for (hexArrayInit = hexArrSize - 1; hexArrayInit >= 0; hexArrayInit--)
                            {
                                _putchar(hexNum[hexArrayInit]);
                                num += 1;
                            }
                        }
                        else if (format[i] == 'X')
                        {
                            int convertToCapsHex= va_arg(args, unsigned int);

                            while(convertToCapsHex > 0)
                            {
                                int remainder = convertToCapsHex % 16;

                                if (remainder < 10)
                                {
                                    capitalHexNum[capsHexArrSize++] = remainder + '0';
                                }
                                else
                                {
                                    capitalHexNum[capsHexArrSize++] = remainder - 10 + 'A';
                                }
                                convertToCapsHex /= 16;
                            }

                            for (capsHexArrayInit = capsHexArrSize - 1; capsHexArrayInit >= 0; capsHexArrayInit--)
                            {
                                _putchar(capitalHexNum[capsHexArrayInit]);
                                num += 1;
                            }
                        }
                }
                        else
                        {
                                _putchar(format[i]);
                                num += 1;
                        }
        }
        va_end(args);
        return (num);
}

void write_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        for (int i = 0; i < *buff_ind; i++)
        {
            _putchar(buffer[i]);
        }
    }
}
