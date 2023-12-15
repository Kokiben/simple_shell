#include "Shell.H"


/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_myhistory --- This function shows the history list line by line,
 * command by command, with line numbers beginning at zero.
 * @info: Structure that might support arguments,
 *        used to keep the function prototype consistent.
 *  Return: Always zero.
 */
int ft_myhistory(inf_y *info)
{
ft_print_list(info->history);
return (0);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_unset_alias ---This function sets the string alias.
 * @info: this structure of parameters.
 * @str: this alias for a string.
 *
 * Return: zero always for success and 1 for failure.
 */
int ft_unset_alias(inf_y *info, char *str)
{
	char *ptr, c;
	int r;

	ptr = ft_strchr(str, '=');
	if (!ptr)
		return (1);
	c = *ptr;
	*ptr = 0;
	r = ft_delete_node_at_index(&(info->alias),
			ft_get_node_index(info->alias, ft_node_starts_with(info->alias, str, -1)));
	*ptr = c;
	return (r);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_set_alias --- This function sets the string alias.
 * @info: this structure of parameters.
 * @str: this alias for a string.
 *
 * Return: Always zero on success, one on error.
 */
int ft_set_alias(inf_y *info, char *str)
{
char *ptr;

ptr = ft_strchr(str, '=');
if (!ptr)
return (1);
if (!*++ptr)
return (ft_unset_alias(info, str));
ft_unset_alias(info, str);
return (ft_add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_print_alias --- An alias string is printed by this function.
 * @node: this node alias.
 *
 * Return:Always one on mistake, zero on success.
 */
int ft_print_alias(list_x *node)
{
char *pt = NULL, *a = NULL;

if (node)
{
pt = ft_strchr(node->str, '=');
for (a = node->str; a <= pt; a++)
ft_putchar(*a);
ft_putchar('\'');
ft_puts(pt + 1);
ft_puts("'\n");
return (0);
}
return (1);
}

/**
 * Collaboration_Simple Shell: Badar Benami & Kaoutar Bennassar.
 * ft_myalias - This function emulates the built-in alias (man alias).
 * @info: this structure that might support arguments.
 *        used to keep the function prototype consistent.
 *  Return: Always zero.
 */
int ft_myalias(inf_y *info)
{
int a = 0;
char *pt = NULL;
list_x *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
ft_print_alias(node);
node = node->next;
}
return (0);
}
for (a = 1; info->argv[a]; a++)
{
pt = ft_strchr(info->argv[a], '=');
if (pt)
ft_set_alias(info, info->argv[a]);
else
ft_print_alias(ft_node_starts_with(info->alias, info->argv[a], '='));
}
return (0);
}
