/*
** file_information.c for  in /home/mart_4/NEWPSU
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb 21 23:34:53 2016 Thomas Martins
** Last update Sun Feb 28 13:44:44 2016 Thomas Martins
*/

#include "struct.h"

char		*get_name(t_obj *obj, int i)
{
  return (&obj->tab[obj->shdr[i].sh_name]);
}

size_t		get_shnum(Elf64_Ehdr *elf)
{
  return (elf->e_shnum);
}

unsigned int	get_offsetsize(t_obj *obj, int i)
{
  return (obj->shdr[i].sh_offset);
}

unsigned int	get_shdrsize(t_obj *obj, int i)
{
  return (obj->shdr[i].sh_size);
}

int		get_size(int fd)
{
  return (lseek(fd, 0, SEEK_END));
}
