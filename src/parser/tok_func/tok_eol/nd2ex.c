/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd2ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:38:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 01:19:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "minishell.h"

#include <stdlib.h>
#include <sys/types.h>

// todo : split in its own file file (called twice)
static char	*resolve_p(const char **paths, const char *cmd)
{
	char	*path;
	char	*fullpath;
	size_t	i;

	i = 0;
	while (paths[i] != NULL)
	{
		if (paths[i][ft_strlen(paths[i])] == '/')
			path = ft_strdup(paths[i]);
		else
			path = ft_strjoin(paths[i], "/");
		if (path == NULL)
			return (NULL);
		fullpath = ft_strjoin(path, cmd);
		if (fullpath == NULL)
			return (free(path), NULL);
		if (free(path), access(fullpath, X_OK) == 0)
			return (fullpath);
		free(fullpath);
		i++;
	}
	return (NULL);
}

static char	*resolve_cmd(char *cmd, t_minishell_control *sh)
{
	const char	*p;
	char		**paths;
	char		*ret;

	if (!cmd)
		return (NULL);
	p = get_env(sh->env, "PATH");
	if (!p || ft_strchr(cmd, '/') != NULL)
		return (ft_strdup(cmd));
	paths = ft_split(p, ':');
	if (paths == NULL)
		return (NULL);
	ret = resolve_p((const char **)paths, cmd);
	return (ft_free_2d((void **)paths), ret);
}

bool	nd2ex_eol(t_preparsed_node *nd, t_cmd_to_exec *cmd,
		t_minishell_control *sh)
{
	if (cmd->construction_vector == NULL)
		return (false);
	cmd->ac = cmd->construction_vector->count;
	cmd->argv = (char **)ft_vec_to_array(&cmd->construction_vector);
	cmd->construction_vector = NULL;
	if (cmd->argv == NULL)
		return (false);
	cmd->cmd_path = resolve_cmd(cmd->argv[0], sh);
	cmd->env = get_bourne_env(sh->env);
	if (!cmd->env || !cmd->argv)
		return (false);
	ft_vec_shift(sh->preparsed, 0, cmd->nb_tok_consumed);
	if (sh->preparsed->count == 0)
		(ft_vec_destroy(&sh->preparsed), sh->preparsed = NULL);
	free(nd);
	return (true);
}
