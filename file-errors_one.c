#include "Shell.H"

/*
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 */

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_errputs - The output of this function is an input string.
 * @str: the text to be printed.
 *
 * Return: Nothing at all.
 */
void ft_errputs(char *str)
{
int a = 0;

if (!str)
return;
while (str[a] != '\0')
{
ft_errputchar(str[a]);
a++;
}
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_errputchar - The character c is written to stderr by this function.
 * @c: To print this character.
 *
 * Return: Regarding accomplishment 1.
 * Errno is set correctly and -1 is given in the event of an error.
 */
int ft_errputchar(char c)
{
static int a;
static char buff[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
{
write(2, buff, a);
a = 0;
}
if (c != BUF_FLUSH)
buff[a++] = c;
return (1);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_putfd - The char c is written to the supplied fd by this function.
 * @c: This char to print.
 * @fd: To write to, use this file descriptor.
 *
 * Return: On success one.
 * Errno is set correctly and -1 is given in the event of an error.
 */
int ft_putfd(char c, int fd)
{
static int a;
static char buff[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
{
write(fd, buff, a);
a = 0;
}
if (c != BUF_FLUSH)
buff[a++] = c;
return (1);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_putsfd - The output of this function is an input string.
 * @str: this string has to be printed.
 * @fd: write to this file descriptor.
 *
 * Return: how many characters are entered.
 */
int ft_putsfd(char *str, int fd)
{
int a = 0;

if (!str)
return (0);
while (*str)
{
a += ft_putfd(*str++, fd);
}
return (a);
}
