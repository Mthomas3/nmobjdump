/*
** last_print.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/nm
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb 28 13:02:35 2016 Thomas Martins
** Last update Sun Feb 28 18:53:57 2016 Thomas Martins
*/

#include "struct.h"

int	add_simple_information(Elf64_Sym *sym, char *tab, t_list
			       *this, t_nm *nm)
{
  char	res;

  if (remove_section(&tab[sym[nm->off].st_name],
		     sym[nm->off].st_info) == TRUE)
    {
      res = first_value(&nm->run_tab[nm->shdr[sym[nm->off].st_shndx].sh_name],
			&sym[nm->off]);
      if (FALSE == (add_list(this, &tab[sym[nm->off].st_name],
			     res, sym[nm->off].st_value)))
	return (FALSE);
    }
  return (TRUE);
}
