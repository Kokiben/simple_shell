#include "Shell.H"

/*
 * Code by: Badar Benami & Kaoutar Bennassar.
*/


/**
 * Code by: Badar Benami & Kaoutar Bennassar.
 * ft_interactive - This function returns true
 * when the shell is in interactive mode.
 * @info: this address of the struct.
 *
 * Return: one if interactive mode, zero otherwise.
 */
int ft_interactive(inf_y *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 * Code by --- Badar Benami & Kaoutar Bennassar.
 * ft_is_delim --- This program determines whether a character is a delimeter.
 * @c: this character to verify.
 * @delim: this string of delimeters.
 * Return: one if true, zero if false.
 */
int ft_is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
* Code by: Badar Benami & Kaoutar Bennassar.
* ft_isalpha --- This function verifies that the characters are alphabetic.
* @c: The character to enter.
* Return:one if c is alphabetic, zero otherwise.
*/

int ft_isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * Code by: Badar Benami & Kaoutar Bennassar.
 * ft_atoi --- An integer is created from a string using this method.
 * @str: the string that has to be changed.
 * Return:nmbr is changed to zero if there are no nmbrs in the string.
 */

int ft_atoi(char *str)
{
int a, sign = 1, flag = 0, out;
unsigned int r = 0;

for (a = 0; str[a] != '\0' && flag != 2; a++)
{
if (str[a] == '-')
sign *= -1;

if (str[a] >= '0' && str[a] <= '9')
{
flag = 1;
r *= 10;
r += (str[a] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
out = -r;
else
out = r;

return (out);
}
