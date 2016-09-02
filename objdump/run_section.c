/*
** run_section.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/objdump
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Thu Feb 25 22:05:42 2016 Thomas Martins
** Last update Sun Feb 28 13:48:20 2016 Thomas Martins
*/

#include "struct.h"

int	bool_section(t_obj *obj, const char *section)
{
  (void)obj;
  if (!(!strcmp(section, ".bss")
        || !strcmp(section, ".shstrtab")
        || !strcmp(section, ".symtab")
        || !strcmp(section, ".strtab")
        || !strcmp(section, ".rela.text")
        || !strcmp(section, ".rel.text")
        || !strcmp(section, ".rela.debug_info")
        || !strcmp(section, ".rela.debug_aranges")
        || !strcmp(section, ".note.GNU-stack")
        || !strcmp(section, ".rela.eh_frame")
        || !strcmp(section, ".rela.debug_line")))
    return (TRUE);
  return (FALSE);
}

int	section_get(t_obj *obj)
{
  (void)obj;
  return (TRUE);
}

void	simple_init(t_obj *obj)
{
  obj->b = 0;
  obj->c = 0;
  memset(obj->tab_name, 0, 16 + 1);
}

int	init_all_struct(t_obj *obj)
{
  obj->a = 0;
  obj->b = 0;
  obj->c = 0;
  obj->iterator = 0;
  if (NULL == (obj->tab_name = malloc(sizeof(char) * 16 + 1)))
    return (FALSE);
  if (NULL == (obj->results = malloc(sizeof(char) * 4 * (16 + 1))))
    return (FALSE);
  return (TRUE);
}

int	print_information_section(const char *addr, size_t size,
				  size_t addr_size, t_obj *obj)
{
  int	lines;
  int	div;

  lines = 0;
  div = (size / 16);
  lines = div + (size % 16 > 0 ? 1 : 0);
  obj->iterator = 0;
  while (obj->iterator < lines)
    {
      printf(" %04lx ", addr_size + (obj->iterator * 16));
      print_before(addr, div, size, obj);
      obj->iterator++;
    }
  return (TRUE);
}
