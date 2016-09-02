/*
** create.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/nm
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Fri Feb 26 16:59:15 2016 Thomas Martins
** Last update Sun Feb 28 16:30:46 2016 Thomas Martins
*/

#include "struct.h"

static char	*get_string(int size)
{
  int		a;
  char		*str;

  a = 0;
  str = NULL;
  if (NULL == (str = malloc(sizeof(char) * size)))
    return (NULL);
  while ((unsigned int)a < 16)
    {
      str[a] = ' ';
      ++a;
    }
  str[a] = '\0';
  return (str);
}

int		printf_list(t_list *root, t_nm *nm)
{
  t_list	*tmp;
  char		*str;

  tmp = root;
  if (NULL == (str = get_string(18)))
    return (FALSE);
  while (tmp->next != root)
    {
      if ((basic_nm((char *)nm->data, nm)) == TRUE)
	if (tmp->next->addr != 0)
	  printf("%016lx %c %s\n", tmp->next->addr, tmp->next->sym,
		 tmp->next->str);
	else
	  printf("%s %c %s\n", str, tmp->next->sym, tmp->next->str);
      else
	if (tmp->next->addr != 0)
	  printf("%08x %c %s\n", (unsigned int)tmp->next->addr, tmp->next->sym,
		 tmp->next->str);
	else
	  printf("%s %c %s\n", str, tmp->next->sym, tmp->next->str);
      tmp = tmp->next;
    }
  free(str);
  return (TRUE);
}

int		add_list(t_list *elem, char *str, char symbol,
			 long unsigned int addr)
{
  t_list	*new_elem;

  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    return (FALSE);
  new_elem->str = str;
  new_elem->addr = addr;
  new_elem->sym = symbol;
  new_elem->prev = elem->prev;
  new_elem->next = elem;
  elem->prev->next = new_elem;
  elem->prev = new_elem;
  return (TRUE);
}

t_list		*create_list(void)
{
  t_list	*root;

  if ((root = malloc(sizeof(*root))) == NULL)
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}
