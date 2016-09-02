/*
** remove.c for  in /home/mart_4/NEWPSU
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Feb 22 02:28:48 2016 Thomas Martins
** Last update Sun Feb 28 16:23:35 2016 Thomas Martins
*/

#include "struct.h"

int	remove_struct(t_obj *obj)
{
  obj->fd = 0;
  obj->size = 0;
  obj->data = NULL;
  obj->shdr = NULL;
  obj->elf = NULL;
  obj->tab = NULL;
  if (NULL != obj->name)
    {
      free(obj->name);
      obj->name = NULL;
    }
  if (NULL != obj)
    {
      free(obj);
      obj = NULL;
    }
  return (TRUE);
}
