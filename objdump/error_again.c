/*
** error_again.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/objdump
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Thu Feb 25 21:59:11 2016 Thomas Martins
** Last update Sun Feb 28 16:19:59 2016 Thomas Martins
*/

#include "struct.h"

int	print_usage(const char **error)
{
  if (error[1] == NULL)
    fprintf(ERROR, "my_objdump: '%s': No such file\n", "a.out");
  else
    fprintf(ERROR, "my_objdump: '%s': No such file\n", error[1]);
  return (FALSE);
}

int		access_file(t_obj *obj)
{
  Elf64_Shdr	*shdr;

  shdr = (Elf64_Shdr *)(obj->data + obj->elf->e_shoff);
  if ((intptr_t)(&shdr[obj->elf->e_shstrndx]) >=
      (intptr_t)(obj->data + get_size(obj->fd)))
    return (FALSE);
  if ((intptr_t)(obj->data + shdr[obj->elf->e_shstrndx].sh_offset)
      >= (intptr_t)(obj->data + get_size(obj->fd)))
    return (FALSE);
  return (TRUE);
}

int	check_currents(const void *data)
{
  if (((char *)data)[6] == EV_CURRENT)
    return (TRUE);
  return (FALSE);
}

int	check_endian(const void *data)
{
  if (((char *)data)[5] <= 0 || ((char *)data)[5] > 2)
    return (FALSE);
  return (TRUE);
}

int	check_format(const void *data)
{
  if (((char *)data)[4] == 2 || ((char *)data)[4] == 1)
    return (TRUE);
  return (FALSE);
}
