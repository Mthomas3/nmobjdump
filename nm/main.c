/*
** main.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/nm
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Feb 22 20:48:34 2016 Thomas Martins
** Last update Sun Feb 28 18:55:01 2016 Thomas Martins
*/

#include "struct.h"

static int	init_struct(t_nm *nm)
{
  void		**voidres;

  (void)voidres;
  if (!(nm->data = mmap(NULL, get_size(nm->fd), PROT_READ,
			MAP_SHARED, nm->fd, 0)))
    return (FALSE);
  if ((basic_nm((char *)nm->data, nm)) == TRUE)
    {
      nm->elf = (Elf64_Ehdr *)nm->data;
      if ((access_file(nm)) == FALSE)
	return (return_error(10));
      if ((elf_file(nm)) == FALSE)
	return (FALSE);
      nm->shdr = (Elf64_Shdr *)(nm->data + nm->elf->e_shoff);
      nm->tab = (char *)(nm->data + nm->shdr[nm->elf->e_shstrndx].sh_offset);
      if (FALSE == (print_section(nm)))
	return (FALSE);
    }
  else
    if (FALSE == (others_structure(nm)))
      return (FALSE);
  return (TRUE);
}

static t_nm	*create_nm(const char *file)
{
  t_nm		*nm;

  nm = NULL;
  if (NULL == (nm = malloc(sizeof(t_nm))))
    return (NULL);
  if (NULL == (nm->name = malloc(sizeof(char) * strlen(file) + 1)))
    return (NULL);
  nm->name[0] = 0;
  nm->name = strcat(nm->name, file);
  return (nm);
}

static int	parser_one_file(void)
{
  t_nm		*nm;
  int		fd;

  nm = NULL;
  if ((fd = open("a.out", O_RDONLY)) <= 0)
    return (FALSE);
  if (NULL == (nm = create_nm("a.out")))
    return (FALSE);
  nm->fd = fd;
  if ((init_struct(nm)) == FALSE)
    return (FALSE);
  return (TRUE);
}

static int	parser_file(const char *file)
{
  t_nm		*nm;
  int		fd;

  nm = NULL;
  if ((fd = open(file, O_RDONLY)) <= 0)
    return (print_different_usage(file));
  if ((correct_folder(file)) == 0)
    return (return_error(20));
  if (NULL == (nm = create_nm(file)))
    return (return_error(2));
  nm->fd = fd;
  if ((init_struct(nm)) == FALSE)
    return (FALSE);
  return (TRUE);
}

int		main(int ac, const char **av)
{
  int		a;

  a = 1;
  if (ac == 1)
    {
      if ((parser_one_file()) == FALSE)
	return (print_usage(av));
    }
  while (a < ac)
    {
      parser_file(av[a]);
      ++a;
    }
  return (0);
}
