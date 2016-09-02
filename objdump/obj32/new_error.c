/*
** new_error.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/objdump/obj32
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb 28 01:44:57 2016 Thomas Martins
** Last update Sun Feb 28 13:53:00 2016 Thomas Martins
*/

#include "../struct.h"

int		access_files(t_obj *obj)
{
  Elf32_Shdr	*shdr;

  shdr = (Elf32_Shdr *)(obj->data + obj->elfs->e_shoff);
  if ((intptr_t)(&shdr[obj->elfs->e_shstrndx]) >=
      (intptr_t)(obj->data + get_size(obj->fd)))
    return (FALSE);
  if ((intptr_t)(obj->data + shdr[obj->elfs->e_shstrndx].sh_offset)
      >= (intptr_t)(obj->data + get_sizes(obj->fd)))
    return (FALSE);
  return (TRUE);
}

static int	check_magics(const unsigned char *magic)
{
  if (magic[EI_MAG0] != ELFMAG0)
    return (FALSE);
  if (magic[EI_MAG1] != ELFMAG1)
    return (FALSE);
  if (magic[EI_MAG2] != ELFMAG2)
    return (FALSE);
  if (magic[EI_MAG3] != ELFMAG3)
    return (FALSE);
  return (TRUE);
}

static int	check_fulls(const Elf32_Ehdr *elf)
{
  if (elf->e_machine >= EM_NUM)
    return (FALSE);
  if (elf->e_shstrndx == 0)
    return (FALSE);
  return (TRUE);
}

int		elf_files(t_obj *obj)
{
  if ((unsigned int)get_sizes(obj->fd) < sizeof(*obj->elfs))
    return (return_error(1));
  if (check_magics(obj->elfs->e_ident) == FALSE)
    return (return_error(2));
  if (check_format(obj->data) == FALSE)
    return (return_error(3));
  if (check_endian(obj->data) == FALSE)
    return (return_error(4));
  if (check_currents(obj->data) == FALSE)
    return (return_error(7));
  if (check_fulls(obj->elfs) == FALSE)
    return (return_error(8));
  return (TRUE);
}
