/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:46:58 by trebours          #+#    #+#             */
/*   Updated: 2023/11/23 11:43:52 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *src)
{
	int	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

static char	*read_finish(char *result)
{
	if (result[0] == '\0')
	{
		free (result);
		result = NULL;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	static char	*result = NULL;
	static int	t;
	int			len_read;

	if (t > 0)
	{
		result = NULL;
		result = ft_strjoin(buf, result, 0);
	}
	while (1)
	{
		if (ft_verif(result) == 0)
		{
			len_read = read(fd, buf, BUFFER_SIZE);
			if (len_read < 0)
				return (NULL);
			result = ft_strjoin(buf, result, t++);
		}
		if (ft_verif(result) > 0)
			return (ft_cutting(result, buf));
		if (len_read == 0)
			return (read_finish(result));
	}
	return (0);
}
