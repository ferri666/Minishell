/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:55:08 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/12/05 11:24:12 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "colors.h"

char	*eliminate_quotes(char *st)
{
	char			*ret;
	int				n_quo;

	n_quo = n_quotes(st);
	ret = st;
	if (n_quo == 0)
		return (st);
	while (n_quo--)
	{
		ret = quolim(st, ft_strlen(ret));
		st = ret;
	}
	return (st);
}

char	*find_env(char **env, char *find, size_t len)
{
	int	i;

	i = 0;
	if (ft_strncmp(find, "?", 1) == 0)
		return (ft_itoa(0));
	while (env[i])
	{
		if (ft_strncmp(env[i], find, len) == 0)
			return (extract_env(env[i]));
		i++;
	}
	return (NULL);
}

char	*replace(char *cmd, char **env, size_t i)
{
	char	*subs[5];
	char	*ret;
	size_t	j;
	size_t	k;

	k = 0;
	subs[0] = ft_substr(cmd, 0, i);
	i++;
	j = 0;
	while (*(cmd + i + j) && *(cmd + i + j) != '$' && !is_blank(*(cmd + i + j))
		&& !is_quote(*(cmd + i + j)))
		j++;
	subs[1] = ft_substr(cmd, i, j);
	if (ft_strlen(subs[1]) == 0)
		subs[2] = ft_strdup("$");
	else
		subs[2] = find_env(env, subs[1], ft_strlen(subs[1]));
	while (*(cmd + i + j + k) != '\0')
		k++;
	subs[3] = ft_substr(cmd, i + j, k);
	subs[4] = ft_strjoin(subs[0], subs[2]);
	ret = ft_strjoin(subs[4], subs[3]);
	free_this(subs);
	return (ret);
}

char	*expand_this(char *str, char **env)
{
	size_t	i;
	int		n;
	int		flag;
	char	*ret;

	i = 0;
	n = n_expands(str);
	flag = 0;
	if (n == 0)
		return (eliminate_quotes(str));
	while (n--)
	{
		while (*(str + i) && *(str + i) != '$'
			&& (!flag || *(str + 1) == ' ' || *(str + 1) == ' '))
		{
			if (*(str + i) == '\'')
				changeflag(*(str + i), &flag);
			i++;
		}
		ret = replace (str, env, i);
		free (str);
		str = ret;
		i = 0;
	}
	return (eliminate_quotes(str));
}

t_cmd	**expand_all(t_cmd **cmd, int n_cmds, char **env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n_cmds)
	{
		j = -1;
		while (cmd[i]->input[++j])
			cmd[i]->input[j] = expand_this(cmd[i]->input[j], env);
		j = -1;
		while (cmd[i]->output[++j])
			cmd[i]->output[j] = expand_this(cmd[i]->output[j], env);
		j = -1;
		while (cmd[i]->args[++j])
			cmd[i]->args[j] = expand_this(cmd[i]->args[j], env);
		cmd[i]->command = expand_this(cmd[i]->command, env);
	}
	return (cmd);
}
