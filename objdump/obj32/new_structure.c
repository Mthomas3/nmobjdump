/*
** new_structure.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/objdump
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Thu Feb 25 23:20:17 2016 Thomas Martins
** Last update Sun Feb 28 13:56:40 2016 Thomas Martins
*/

#include "../struct.h"

int	basic_elf(const char *data, t_obj *obj)
{
  if ((unsigned int)get_size(obj->fd) < sizeof(*obj->elf))
    return (FALSE);
  if (data[4] == 2)
    return (TRUE);
  return (FALSE);
}

int	others_structure(t_obj *obj)
{
  obj->elfs = (Elf32_Ehdr *)obj->data;
  if ((elf_files(obj)) == FALSE)
    return (FALSE);
  if (access_files(obj) == FALSE)
    return (return_error(10));
  obj->shdrs = (Elf32_Shdr *)(obj->data + obj->elfs->e_shoff);
  obj->tab = (char *)(obj->data +
		      obj->shdrs[obj->elfs->e_shstrndx].sh_offset);
  print_header_elfs(obj);
  if ((print_section_files(obj)) == FALSE)
    return (return_error(9));
  remove_struct(obj);
  return (TRUE);
}
