/*
** new_header.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/objdump/obj32
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb 28 01:20:44 2016 Thomas Martins
** Last update Sun Feb 28 16:28:40 2016 Thomas Martins
*/

#include "../struct.h"

void		print_header_elfs(t_obj *obj)
{
  obj->format = (((char *)obj->data)[4] == 1 ? FORMAT32 : FORMAT64);
  printf("\n%s:    format de fichier %s\n", obj->name,
	 obj->format == FORMAT64 ? "elf64-x86-64" :
	 "elf32-i386");
  get_flags_number(obj);
  get_flags(obj);
  if (obj->elfs->e_type < ET_NUM)
    {
      printf("architecture: i386, flags 0x%08x:\n",
  	     obj->e_numbers[obj->elfs->e_type]);
      printf("%s\n", obj->e_types[obj->elfs->e_type]);
      printf("start address 0x%08x\n", obj->elfs->e_entry);
      printf("\n");
    }
}
