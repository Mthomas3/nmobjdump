/*
** fonction_information.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/nm
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Tue Feb 23 13:42:17 2016 Thomas Martins
** Last update Sun Feb 28 13:01:00 2016 Thomas Martins
*/

#include "struct.h"

char		*get_name(t_nm *obj, int i)
{
  return (&obj->tab[obj->shdr[i].sh_name]);
}

size_t		get_shnum(Elf64_Ehdr *elf)
{
  return (elf->e_shnum);
}

unsigned int	get_offsetsize(t_nm *obj, int i)
{
  return (obj->shdr[i].sh_offset);
}

unsigned int	get_shdrsize(t_nm *obj, int i)
{
  return (obj->shdr[i].sh_size);
}

int		get_size(int fd)
{
  return (lseek(fd, 0, SEEK_END));
}
