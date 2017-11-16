#include <fcnt.l>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#define BUFFER 500

int get_next_line(const int fd, char **line)
{
  int buf;
  static char *temp;

  if (fd == -1)
      return (-1);
  if (fd == 0)
    return (0);
  if (!(*temp = ft_strnew(BUF_SIZE)))
    return (0);
  if (read(1, &buf, 1))
    {
      
    }
}

char	*filetoarr(char *av)
{
  char	*s;
  int	i;
  int	fd;
  char	buf;

  i = 0;
  fd = open(av, O_RDONLY);
  if (fd == -1)
    return ("error");
  if (fd == 0)
    return ("error");
  s = (char *)malloc(sizeof(char) * 547);
  while (read(fd, &buf, 1))
    {
      s[i] = buf;
      i++;
      if (i >= 547)
	return ("error");
    }
  s[i] = '\0';
  if (!tetchecker(s))
    return ("error");
  close(fd);
  return (s);
}

int main(int argc, char **argv)
{
  int fd;
  char *str;

  if (argc == 2)
    {
      fd = open(fd, O_RDONLY);
      get_next_line(fd, &str);
    }
}
