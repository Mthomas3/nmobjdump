/*
** main.c for  in /home/mart_4/NEWPSU
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb 21 22:50:00 2016 Thomas Martins
** Last update Sun Feb 28 16:23:13 2016 Thomas Martins
*/

#include "struct.h"

static int	init_struct(t_obj *obj)
{
  if (!(obj->data = mmap(NULL, get_size(obj->fd), PROT_READ,
			 MAP_SHARED, obj->fd, 0)))
    return (return_error(1));
  if (obj->data == MAP_FAILED)
    return (FALSE);
  if ((basic_elf((char *)obj->data, obj)) == TRUE)
    {
      obj->elf = (Elf64_Ehdr *)obj->data;
      if ((elf_file(obj)) == FALSE)
	return (FALSE);
      if (access_file(obj) == FALSE)
	return (return_error(10));
      obj->shdr = (Elf64_Shdr *)(obj->data + obj->elf->e_shoff);
      obj->tab = (char *)(obj->data +
			  obj->shdr[obj->elf->e_shstrndx].sh_offset);
      print_header_elf(obj);
      if ((print_section_file(obj)) == FALSE)
	return (return_error(9));
      remove_struct(obj);
    }
  else
    if (FALSE == (others_structure(obj)))
      return (FALSE);
  return (TRUE);
}

static t_obj	*create_obj(const char *file)
{
  t_obj		*obj;

  obj = NULL;
  if (NULL == (obj = malloc(sizeof(t_obj))))
    return (NULL);
  if (NULL == (obj->name = malloc(sizeof(char) * strlen(file) + 1)))
    return (NULL);
  obj->name[0] = 0;
  obj->name = strcat(obj->name, file);
  return (obj);
}

static int	parser_one_file(void)
{
  t_obj		*obj;
  int		fd;

  obj = NULL;
  if ((fd = open("a.out", O_RDONLY)) <= 0)
    return (FALSE);
  if (NULL == (obj = create_obj("a.out")))
    return (FALSE);
  obj->fd = fd;
  if ((init_struct(obj)) == FALSE)
    return (FALSE);
  return (TRUE);
}

static int	parser_file(const char *file)
{
  t_obj		*obj;
  int		fd;

  obj = NULL;
  if ((fd = open(file, O_RDONLY)) <= 0)
    return (print_different_usage(file));
  if ((correct_folder(file)) == 0)
    return (return_error(20));
  if (NULL == (obj = create_obj(file)))
    return (return_error(6));
  obj->fd = fd;
  if ((init_struct(obj)) == FALSE)
    return (FALSE);
  return (TRUE);
}

int		main(int ac, const char **av)
{
  int		a;

  a = 1;
  if (ac == 1)
    if ((parser_one_file()) == FALSE)
      return (print_usage(av));
  while (a < ac)
    {
      parser_file(av[a]);
      ++a;
    }
  return (TRUE);
}
