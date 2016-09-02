/*
** error.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/nm
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Feb 22 23:00:13 2016 Thomas Martins
** Last update Sun Feb 28 16:31:43 2016 Thomas Martins
*/

#include "struct.h"

int		print_different_usage(const char *file)
{
  fprintf(ERROR, "my_objdump: '%s': No such file\n", file);
  return (FALSE);
}

static int	check_magic(const unsigned char *magic)
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

static int	check_full(const Elf64_Ehdr *elf)
{
  if (elf->e_machine >= EM_NUM)
    return (FALSE);
  if (elf->e_shstrndx == 0)
    return (FALSE);
  return (TRUE);
}

int		elf_file(t_nm *obj)
{
  if ((unsigned int)get_size(obj->fd) < sizeof(*obj->elf))
    return (return_error(1));
  if (check_magic(obj->elf->e_ident) == FALSE)
    return (return_error(2));
  if (check_format(obj->data) == FALSE)
    return (return_error(3));
  if (check_endian(obj->data) == FALSE)
    return (return_error(4));
  if (check_currents(obj->data) == FALSE)
    return (return_error(7));
  if (check_full(obj->elf) == FALSE)
    return (return_error(8));
  return (TRUE);
}

int		return_error(int values)
{
  if (values == 1)
    fprintf(ERROR, SIZEFILE);
  else if (values == 2)
    fprintf(ERROR, MAGICNUMBER);
  else if (values == 3)
    fprintf(ERROR, FORMAT);
  else if (values == 4)
    fprintf(ERROR, ENDIAN);
  else if (values == 5)
    fprintf(ERROR, FILEERROR);
  else if (values == 6)
    fprintf(ERROR, MALLOC);
  else if (values == 7)
    fprintf(ERROR, FIRSTCURRENT);
  else if (values == 8)
    fprintf(ERROR, FULL);
  else if (values == 9)
    fprintf(ERROR, PRINT);
  else if (values == 10)
    fprintf(ERROR, PRINT);
  else if (values == 20)
    fprintf(ERROR, "that's not a file\n");
  return (FALSE);
}
