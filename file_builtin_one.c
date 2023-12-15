#include "Shell.H"

/*
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 */

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_myexit --- This feature leaves the shell.
 * @info: this structure that might support arguments. used for upkeep
 * constant prototype function.
 * Return: exits that have a specified status.
 * (0) if info.argv[0] != "exit"
 */
int ft_myexit(inf_y *info)
{
int exit_check;

if (info->argv[1])
{
exit_check = ft_erratoi(info->argv[1]);
if (exit_check == -1)
{
info->status = 2;
ft_print_error(info, "Illegal number: ");
ft_errputs(info->argv[1]);
ft_errputchar('\n');
return (1);
}
info->err_num = ft_erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_mycd - This function modifies the process's current directory.
 * @info: this structure that might support arguments. used for upkeep.
 * constant prototype function.
 * Return: Always zero.
 */
int ft_mycd(inf_y *info)
{
char *str, *dir, buffer[1024];
int chdir_ret;

str = getcwd(buffer, 1024);
if (!str)
ft_puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
dir = ft_getenv(info, "HOME=");
if (!dir)
chdir_ret =
chdir((dir = ft_getenv(info, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (ft_strcmp(info->argv[1], "-") == 0)
{
if (!ft_getenv(info, "OLDPWD="))
{
ft_puts(str);
ft_putchar('\n');
return (1);
}
ft_puts(ft_getenv(info, "OLDPWD=")), ft_putchar('\n');
chdir_ret =
chdir((dir = ft_getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
ft_print_error(info, "can't cd to ");
ft_errputs(info->argv[1]), ft_errputchar('\n');
}
else
{
ft_setenv(info, "OLDPWD", ft_getenv(info, "PWD="));
ft_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_myhelp --- This function modifies the process's current directory.
 * @info: this structure that might support arguments. used for upkeep.
 * constant: prototype function.
 * Return: Always zero.
 */
int ft_myhelp(inf_y *info)
{
char **arg_arr;

arg_arr = info->argv;
ft_puts("help call works. Function not yet implemented \n");
if (0)
ft_puts(*arg_arr);
return (0);
}
