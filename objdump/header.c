/*
** header.c for  in /home/mart_4/NEWPSU
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Feb 22 00:01:00 2016 Thomas Martins
** Last update Sun Feb 28 13:45:06 2016 Thomas Martins
*/

#include "struct.h"

int		correct_folder(const char *folder)
{
  struct stat	path;

  stat(folder, &path);
  return (S_ISREG(path.st_mode));
}

int		*get_flags_number(t_obj *obj)
{
  obj->e_numbers[0] = NUMBERSZERO;
  obj->e_numbers[1] = NUMBERSONE;
  obj->e_numbers[2] = NUMBERSTWO;
  obj->e_numbers[3] = NUMBERSTHREE;
  return (obj->e_numbers);
}

char		**get_flags(t_obj *obj)
{
  obj->e_types[0] = TYPESZERO;
  obj->e_types[1] = TYPESONE;
  obj->e_types[2] = TYPESTWO;
  obj->e_types[3] = TYPESTHREE;
  obj->e_types[4] = TYPESFOUR;
  return (obj->e_types);
}

void		print_header_elf(t_obj *obj)
{
  obj->format = (((char *)obj->data)[4] == 1 ? FORMAT32 : FORMAT64);
  printf("\n%s:    format de fichier %s\n", obj->name,
	 obj->format == FORMAT64 ? "elf64-x86-64" :
	 "elf32-i386");
  get_flags_number(obj);
  get_flags(obj);
  if (obj->elf->e_type < ET_NUM)
    {
      printf("architecture: i386:x86-64, flags 0x%08x:\n",
	     obj->e_numbers[obj->elf->e_type]);
      printf("%s\n", obj->e_types[obj->elf->e_type]);
      printf("start address 0x%016lx\n", obj->elf->e_entry);
      printf("\n");
    }
}
