/*
** last_print.c for  in /home/mart_4/rendu/PSU_2015_nmobjdump/nm/nm32
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb 28 12:52:32 2016 Thomas Martins
** Last update Sun Feb 28 19:02:34 2016 Thomas Martins
*/

#include "../struct.h"

int	add_informations(Elf32_Sym *sym, char *tab, t_list *this, t_nm *nm)
{
  char	res;

  if (remove_section(&tab[sym[nm->off].st_name],
		     sym[nm->off].st_info) == TRUE)
    {
      res =
	first_values(&nm->run_tab[nm->shdrs[sym[nm->off].st_shndx].sh_name],
		     &sym[nm->off]);
      if (FALSE == (add_list(this, &tab[sym[nm->off].st_name],
			     res, sym[nm->off].st_value)))
	return (FALSE);
    }
  return (TRUE);
}
