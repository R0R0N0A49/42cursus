/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:58:42 by trebours          #+#    #+#             */
/*   Updated: 2023/12/01 14:01:36 by trebours         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*ft_strjoin(char *buf, char *result, int t)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = malloc(BUFFER_SIZE + ft_strlen(result) + 1);
	if (!tmp)
		return (0);
	while (result && result[i])
	{
		tmp[i] = result[i];
		i++;
	}
	while (j < BUFFER_SIZE)
	{
		tmp[i + j] = buf[j];
		buf[j] = 0;
		j++;
	}
	tmp[i + j] = 0;
	if (t > 0)
		free(result);
	return (tmp);
}

int	ft_verif(char *result)
{
	int	i;

	if (!result)
		return (0);
	i = 0;
	while (result[i])
	{
		if (result[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_save(char *buf, char *result, int j)
{
	int	i;
	int	len;

	len = ft_strlen(&result[j]);
	i = 0;
	while (len > i)
	{
		buf[i] = result[i + j];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buf[i] = 0;
		i++;
	}
}

char	*ft_cutting(char *result, char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (result[i] != '\n' && result[i])
		i++;
	if (result[i] == '\n' || result[i] == 0)
		i++;
	tmp = malloc(i + 1 * sizeof(char));
	if (!tmp)
		return (0);
	while (j < i)
	{
		tmp[j] = result[j];
		j++;
	}
	tmp[j] = 0;
	ft_save(buf, result, j);
	free(result);
	return (tmp);
}
