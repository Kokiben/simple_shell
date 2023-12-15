#include "Shell.H"

/*
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 */

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_myenv - The current environment is printed using this function.
 * @info: this structure that might support arguments.
 *        used to keep the function prototype consistent.
 * Return: Always zero.
 */
int ft_myenv(inf_y *info)
{
ft_print_list_str(info->env);
return (0);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_getenv - This function retrieves an environment variable's value.
 * @info: this structure that might support arguments. used for upkeep.
 * @name: this env variable name.
 *
 * Return: the value
 */
char *ft_getenv(inf_y *info, const char *name)
{
list_x *node = info->env;
char *ptr;

while (node)
{
ptr = ft_starts_with(node->str, name);
if (ptr && *ptr)
return (ptr);
node = node->next;
}
return (NULL);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_mysetenv - this function sets a new environment variable's initial value,
 *             or modifies an already-existing one.
 * @info: this structure that might support arguments. used to keep
 *        the function prototype consistent.
 *  Return: Always zero.
 */
int ft_mysetenv(inf_y *info)
{
if (info->argc != 3)
{
ft_errputs("Incorrect number of arguements\n");
return (1);
}
if (ft_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_myunsetenv - An environment variable is removed by this function.
 * @info: tthis structure that might support arguments.
 *        used to keep the function prototype consistent.
 * Return: Always zero.
 */
int ft_myunsetenv(inf_y *info)
{
int a;

if (info->argc == 1)
{
ft_errputs("Too few arguements.\n");
return (1);
}
for (a = 1; a <= info->argc; a++)
ft_unsetenv(info, info->argv[a]);

return (0);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_populate_env_list - This function fills the environment linked list.
 * @info: this structure that might support arguments.
 *          used to keep the function prototype consistent.
 * Return: Always zero.
 */
int ft_populate_env_list(inf_y *info)
{
list_x *node = NULL;
size_t a;

for (a = 0; environ[a]; a++)
ft_add_node_end(&node, environ[a], 0);
info->env = node;
return (0);
}
