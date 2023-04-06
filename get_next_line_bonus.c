/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:45:07 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/04/06 15:45:13 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char *annex_ptr)
{
	char	*line;
	int		i;

	i = 0;
	if (!annex_ptr || annex_ptr[0] == '\0')
		return (NULL);
	while (annex_ptr[i] && annex_ptr[i] != '\n')
		i++;
	if (annex_ptr[i] == '\n')
		i++;
	line = (char *)malloc (sizeof(char) * (i + 1));
	line = ft_memmove(line, annex_ptr, (size_t)i);
	line[i] = '\0';
	return (line);
}

static char	*ft_clean_annex(char *annex_ptr)
{
	char	*sub;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (annex_ptr == NULL)
		return (NULL);
	while (annex_ptr[i] && annex_ptr[i] != '\n')
		i++;
	if (annex_ptr[i] == '\0')
	{
		free(annex_ptr);
		return (NULL);
	}
	sub = (char *)malloc (sizeof(char) * (ft_strlen(annex_ptr) + 1 - i));
	if (sub == NULL)
		return (NULL);
	i++;
	while (annex_ptr[i])
		sub[j++] = annex_ptr[i++];
	sub[j] = '\0';
	free(annex_ptr);
	return (sub);
}

char	*ft_gen_line(char **annex_ptr)
{
	char	*line;

	line = ft_get_line(*annex_ptr);
	*annex_ptr = ft_clean_annex(*annex_ptr);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*annex[OPEN_MAX];
	char		*buffer;
	int			n_read;

	n_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (!ft_found_new_line(annex[fd]) && n_read != 0)
	{
		n_read = (int)read(fd, buffer, BUFFER_SIZE);
		if (n_read == -1)
		{	
			free(annex[fd]);
			annex[fd] = NULL;
			free(buffer);
			return (NULL);
		}
		buffer[n_read] = '\0';
		annex[fd] = ft_strjoin(annex[fd], buffer);
	}
	free (buffer);
	return (ft_gen_line(&annex[fd]));
}
