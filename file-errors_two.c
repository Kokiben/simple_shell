#include "Shell.H"

/*
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 */

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_erratoi - An integer is created from a string using this method.
 * @str: the string that has to be changed.
 * Return: zero If there are no numbers in the string, the converted nmbr
 *       -one on error.
 */
int ft_erratoi(char *str)
{
int a = 0;
unsigned long int result = 0;

if (*str == '+')
str++;
for (a = 0;  str[a] != '\0'; a++)
{
if (str[a] >= '0' && str[a] <= '9')
{
result *= 10;
result += (str[a] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_print_error --- An error message is printed by this function.
 * @info: this argument & info struct return.
 * @estr:this string with the designated error type.
 * Return: 0 If there are no numbers in the string, the converted nmbr
 *        -one on error.
 */
void ft_print_error(inf_y *info, char *estr)
{
ft_errputs(info->fname);
ft_errputs(": ");
ft_print_d(info->line_count, STDERR_FILENO);
ft_errputs(": ");
ft_errputs(info->argv[0]);
ft_errputs(": ");
ft_errputs(estr);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_print_d - this function prints a decimal (integer) number (base 10)
 * @input: this input
 * @fd: write to this file descriptor.
 *
 * Return: nmbr of chars printed.
 */
int ft_print_d(int input, int fd)
{
int (*__putchar)(char) = ft_putchar;
int i, count = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
__putchar = ft_errputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
__putchar('0' + current / i);
count++;
}
current %= i;
}
__putchar('0' + current);
count++;

return (count);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_convert_number-This function is an itoa clone, a converter.
 * @nbr: this nmbr.
 * @base: This base.
 * @flags: This argument raises red flags.
 *
 * Return:String.
 */
char *ft_convert_number(long int nbr, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = nbr;

if (!(flags & CONVERT_UNSIGNED) && nbr < 0)
{
n = -nbr;
sign = '-';

}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do
{
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;
return (ptr);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_remove_comments-This function substitutes the first instance of '#' with '\0'
 * @buff: The address of this string needs to be updated.
 *
 * Return: Always zero.
 */
void ft_remove_comments(char *buff)
{
int a;

for (a = 0; buff[a] != '\0'; a++)
if (buff[a] == '#' && (!a || buff[a - 1] == ' '))
{
buff[a] = '\0';
break;
}
}
