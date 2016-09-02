/*
** section_file.c for  in /home/mart_4/NEWPSU
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Feb 22 00:13:07 2016 Thomas Martins
** Last update Sun Feb 28 16:24:56 2016 Thomas Martins
*/

#include <ctype.h>
#include "struct.h"

static int	print_information_line(const unsigned char *addr,
				       int size, t_obj *obj)
{
  simple_init(obj);
  while (obj->b < (size))
    {
      obj->a = 0;
      while ((obj->a < 4) && (obj->a + obj->b < size))
	{
	  if (isprint(addr[obj->b + obj->a]))
	    obj->tab_name[obj->b + obj->a] = addr[obj->b + obj->a];
	  else
	    obj->tab_name[obj->b + obj->a] = '.';
	  sprintf(&(obj->results[obj->c]), "%02x ", addr[obj->a + obj->b]);
	  ++obj->a;
	  obj->c += 2;
	}
      obj->c++;
      obj->b += 4;
    }
  printf("%-36s %-16s", obj->results, obj->tab_name);
  return (TRUE);
}

int		print_before(const char *addr, const int div,
			     size_t size, t_obj *obj)
{
  if (obj->iterator >= div)
    print_information_line((unsigned char *)addr +
			   (obj->iterator * 16), size % 16, obj);
  else
    print_information_line((unsigned char *)addr +
			   (obj->iterator * 16), 16, obj);
  printf("\n");
  return (TRUE);
}

int		print_section_file(t_obj *obj)
{
  int		i;

  i = 0;
  if (FALSE == (init_all_struct(obj)) || (FALSE == section_get(obj)))
    return (FALSE);
  while ((size_t)++i < get_shnum(obj->elf))
    {
      if (bool_section(obj, get_name(obj, i)) == TRUE)
	{
	  printf("Contents of section %s:\n", get_name(obj, i));
	  print_information_section(((char *)obj->data +
				     obj->shdr[i].sh_offset),
				    obj->shdr[i].sh_size,
				    obj->shdr[i].sh_addr, obj);
	}
    }
  return (TRUE);
}
