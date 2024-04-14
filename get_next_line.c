/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:41:35 by jotavare          #+#    #+#             */
/*   Updated: 2022/12/18 00:41:44 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_from_content(int fd, char **stash, char *buffer)
{
	char	*tmp;
	int		bytes;

    bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0 || buffer == NULL)
	{
		free(*stash);
		*stash = NULL;
		return (-1);
	}
	if (bytes == 0)
		return (bytes);
	buffer[bytes] = '\0';
	tmp = ft_strjoin(*stash, buffer);
	free(*stash);
	*stash = tmp;
	return (bytes);
}



static void	remove_result(char **stash)
{
	char	*nl;
	char	*tmp;
	
	nl = ft_strchr(*stash, '\n');
	if (!nl)
	{
		free(*stash);
		*stash = NULL;
		return ;
	}
	tmp = malloc((ft_strlen(nl)) * sizeof(char));
	if(!tmp)
	{
		free(*stash);
		*stash = NULL;
	}
	ft_strcpy(tmp,nl+1);
	free(*stash);
	*stash = tmp;
	if (**stash == 0)
	{
		free(*stash);
		*stash = NULL;
	}
}

static void get_result(char **stash, char **result)
{
	size_t i;
	 
	i = 0;
	while (!((*stash)[i] == '\n' || (*stash)[i] == '\0'))
		i++;
	if ((*stash)[i] == '\n')
		(*result) = malloc(sizeof(char) * (i + 2));
	if ((*stash)[i] == '\0')
		(*result) = malloc(sizeof(char) * (i + 1));
	i = 0;
    while ((*stash)[i] != '\n' && (*stash)[i] != '\0')
    {
        (*result)[i] = (*stash)[i];
        i++;
    }
	if ((*stash)[i] == '\n')
	{
		(*result)[i] = '\n';
		i++;
	}
	(*result)[i] = '\0';
}


char	*get_next_line(int fd)
{
	static char	*stash;
	char		*result;
	char		*buffer;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buffer)
		return (NULL);
	bytes = 1;
	while (ft_strchr(stash, '\n') == NULL && bytes > 0)
	{
		bytes = read_from_content(fd, &stash, buffer);
	}
	free(buffer);
	if (bytes == -1)
		return (NULL);
	if(ft_strlen(stash) != 0)
	{
		get_result(&stash, &result);
		remove_result(&stash);
		return (result);
	}
	else
		return NULL;
}

// int main()
// {
//   char *line;

//   int fd = open("big_line_no_nl", O_RDONLY);
//   if (fd == -1)
//   {
//     perror("Error opening file");
//     return 1;
//   }
//   line = get_next_line(fd);
//   while (line != NULL)
//   {
//     printf("%s", line);
//     free(line);
//     line = get_next_line(fd);
//   }

//   close(fd);
//   return 0;
// }