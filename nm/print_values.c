/*
** print_values.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/nm
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sat Feb 27 23:59:51 2016 Thomas Martins
** Last update Sun Feb 28 13:35:21 2016 Thomas Martins
*/

#include "struct.h"

int		correct_folder(const char *folder)
{
  struct stat	path;

  stat(folder, &path);
  return (S_ISREG(path.st_mode));
}

char		*del_char(char *s, char c)
{
  int		i;
  int		j;
  int		size;

  size = strlen(s);
  i = 0;
  j = 0;
  while (i < size)
    {
      if (s[i] != c)
	{
	  s[j] = s[i];
	  ++j;
	}
      ++i;
    }
  s[j] = '\0';
  return (s);
}
