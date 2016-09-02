/*
** utils_list.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/nm
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb 28 00:03:04 2016 Thomas Martins
** Last update Sun Feb 28 19:00:07 2016 Thomas Martins
*/

#include "struct.h"

t_list*		clean_list(t_list *list, char *string,
			   char c, long unsigned int addr)
{
  t_list	*new;
  t_list	*tmp;

  if (NULL == (new = malloc(sizeof(*new))))
    return (NULL);
  new->str = string;
  new->addr = addr;
  new->sym = c;
  new->prev = new;
  new->next = new;
  if (!list)
    return (list);
  tmp = list;
  while (tmp->next != list &&
	 my_strcasecmp(string, tmp->next->str) > 0)
    tmp = tmp->next;
  new->next = tmp->next;
  tmp->next->prev = new;
  tmp->next = new;
  new->prev = tmp;
  return (list);
}

t_list		*move_list(t_list *list)
{
  t_list	*new;
  t_list	*tmp;

  tmp = list;
  if (NULL == (new = create_list()))
    return (NULL);
  while (tmp->next != list)
    {
      if (NULL == (new = clean_list(new, tmp->next->str, tmp->next->sym,
				    tmp->next->addr)))
	return (NULL);
      tmp = tmp->next;
    }
  return (new);
}

int		remove_section(const char *name, unsigned char types)
{
  if (name[0] == '\0')
    return (FALSE);
  if (types == STT_FILE)
    return (FALSE);
  return (TRUE);
}

int		my_strcasecmp(const char *s1, const char *s2)
{
  int		ret;
  char		*cp1;
  char		*cp2;

  if (NULL == (cp1 = malloc(strlen(s1) + 1)) ||
      NULL == (cp2 = malloc(strlen(s2) + 1)))
    return (FALSE);
  cp1[0] = 0;
  cp2[0] = 0;
  strcat(cp1, s1);
  strcat(cp2, s2);
  cp1 = del_char(cp1, '_');
  cp2 = del_char(cp2, '_');
  ret = strcasecmp(cp1, cp2);
  free(cp1);
  free(cp2);
  return (ret);
}
