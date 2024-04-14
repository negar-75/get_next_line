#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>  // For read() and close()
# include <fcntl.h>   // For open() and O_RDONLY constant
# include <stdio.h>   // For perror()
# include <string.h> 


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif


size_t	ft_strlen(char *afll);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char* ft_strcpy(char *dest, char *src);
char	*get_next_line(int fd);

#endif