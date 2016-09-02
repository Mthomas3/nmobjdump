/*
** new_file_information.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/objdump/obj32
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb 28 01:40:13 2016 Thomas Martins
** Last update Sun Feb 28 13:53:42 2016 Thomas Martins
*/

#include "../struct.h"

char		*get_names(t_obj *obj, int i)
{
  return (&obj->tab[obj->shdrs[i].sh_name]);
}

size_t		get_shnums(Elf32_Ehdr *elf)
{
  return (elf->e_shnum);
}

unsigned int	get_offsetsizes(t_obj *obj, int i)
{
  return (obj->shdrs[i].sh_offset);
}

unsigned int	get_shdrsizes(t_obj *obj, int i)
{
  return (obj->shdrs[i].sh_size);
}

int		get_sizes(int fd)
{
  return (lseek(fd, 0, SEEK_END));
}
