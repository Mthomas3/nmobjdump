/*
** new_structure.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/nm/nm32
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb 28 01:53:34 2016 Thomas Martins
** Last update Sun Feb 28 13:42:33 2016 Thomas Martins
*/

#include "../struct.h"

int	basic_nm(const char *data, t_nm *obj)
{
  if ((unsigned int)get_size(obj->fd) < sizeof(*obj->elf))
    return (FALSE);
  if (data[4] == 2)
    return (TRUE);
  return (FALSE);
}

int	others_structure(t_nm *nm)
{
  nm->elfs = (Elf32_Ehdr *)nm->data;
  if ((elf_files(nm)) == FALSE)
    return (FALSE);
  if ((access_files(nm)) == FALSE)
    return (FALSE);
  nm->shdrs = (Elf32_Shdr *)(nm->data + nm->elfs->e_shoff);
  nm->tab = (char *)(nm->data + nm->shdrs[nm->elfs->e_shstrndx].sh_offset);
  if (FALSE == (print_sections(nm)))
    return (FALSE);
  return (TRUE);
}
