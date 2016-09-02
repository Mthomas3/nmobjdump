/*
** new_print_section.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/nm/nm32
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb 28 10:45:54 2016 Thomas Martins
** Last update Sun Feb 28 19:05:41 2016 Thomas Martins
*/

#include <ctype.h>
#include "../struct.h"

static char	last_functions_bits(const char *name,
				    Elf32_Sym *symbols, char c)
{
  if ((strcmp(name, ".debug")) == 0)
    c = 'n';
  else if ((strcmp(name, ".text")) == 0 || (strcmp(name, ".fini_array") == 0)
	   || (strcmp(name, ".init_array") == 0) ||
	   ELF32_ST_TYPE(symbols->st_info) == STT_FUNC)
    c = 't';
  else if ((strcmp(name, ".bss")) == 0)
    c = 'b';
  else if (strcmp(name, ".rodata") == 0 || strcmp(name, ".eh_frame") == 0)
    c = 'r';
  else if (ELF32_ST_TYPE(symbols->st_info) == STT_OBJECT ||
	   ELF32_ST_TYPE(symbols->st_info) == STT_NOTYPE ||
	   (strcmp(name, ".data")) == 0 || (strcmp(name, ".data1")) == 0)
    c = 'd';
  else
    c = '?';
  return (c);
}

static char	new_function_bits(const char *name,
				  Elf32_Sym *symbols, char c)
{
  (void)name;
  if (symbols->st_shndx == SHN_ABS)
    c = 'a';
  else if (symbols->st_shndx == SHN_COMMON)
    c = 'c';
  else if (symbols->st_shndx == SHN_UNDEF)
    c = 'u';
  return (c);
}

char		first_values(const char *name, Elf32_Sym *symbols)
{
  char		c;

  c = '?';
  if (ELF32_ST_BIND(symbols->st_info) == STB_WEAK)
    {
      if (!symbols->st_value)
	if (ELF32_ST_TYPE(symbols->st_info) == STT_OBJECT)
	  return ('v');
	else
	  return ('w');
      else
	if (ELF32_ST_TYPE(symbols->st_info) == STT_OBJECT)
	  return ('V');
	else
	  return ('W');
    }
  c = new_function_bits(name, symbols, c);
  if (c == '?')
    c = last_functions_bits(name, symbols, c);
  if (c == '?')
    return (c);
  if (ELF32_ST_BIND(symbols->st_info) == STB_LOCAL)
    return (c);
  return (c - 32);
}

static int	parse_informations(t_nm *nm, int *currents, t_list *this)
{
  char		*tab;
  int		loop;
  Elf32_Sym	*sym;

  loop = 0;
  tab = (char *)(nm->data + nm->shdrs[nm->shdrs[*currents].sh_link].sh_offset);
  nm->run_tab = (char *)(nm->data + nm->shdrs[nm->elfs->e_shstrndx].sh_offset);
  if (nm->shdrs[*currents].sh_type == SHT_SYMTAB)
    {
      nm->off = 0;
      sym = (Elf32_Sym *)(nm->data + nm->shdrs[*currents].sh_offset);
      loop = nm->shdrs[*currents].sh_size / nm->shdrs[*currents].sh_entsize;
      while (nm->off < loop)
	{
	  if (FALSE == (add_informations(sym, tab, this, nm)))
	    return (FALSE);
	  ++nm->off;
	}
    }
  return (TRUE);
}

int		print_sections(t_nm *nm)
{
  int		i;
  t_list	*this;

  i = 0;
  if (NULL == (this = create_list()))
    return (FALSE);
  while ((size_t)i < get_shnums(nm->elfs))
    {
      if (FALSE == (parse_informations(nm, &i, this)))
	return (FALSE);
      ++i;
    }
  if (NULL == (this = move_list(this)))
    return (FALSE);
  printf_list(this, nm);
  return (TRUE);
}
