/*
** struct.h for  in /home/mart_4/rendu/PSU_2015_nmobjdump/nm
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Feb 22 22:50:42 2016 Thomas Martins
** Last update Sun Feb 28 13:36:39 2016 Thomas Martins
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/mman.h>

# define		NOFILE "my_objdump: \n"
# define		ERROR	stderr
# define		SIZEFILE "File format not recognized\n"
# define		MAGICNUMBER "File format not recognized\n"
# define		FORMAT	"File format not recognized\n"
# define		ENDIAN	"File format not recognized\n"
# define		FILEERROR "File format not recognized\n"
# define		MALLOC "Can't malloc the structure\n"
# define		FIRSTCURRENT "File format not recognized\n"
# define		FULL "File format not recognized\n"
# define		PRINT "File truncated\n"

typedef enum	e_bool	t_bool;
typedef struct	s_nm	t_nm;
typedef struct s_list	t_list;

struct			s_list
{
  char			c;
  char			*str;
  char			sym;
  long unsigned int	addr;
  struct s_list		*next;
  struct s_list		*prev;
};

enum			e_bool
  {
			FALSE,
			TRUE
  };

struct			s_nm
{
  char			*name;
  int			fd;
  Elf64_Shdr		*shdr;
  Elf64_Ehdr		*elf;
  Elf32_Shdr		*shdrs;
  Elf32_Ehdr		*elfs;
  char			*tab;
  int			size;
  void			*data;
  int			off;
  char			*run_tab;
};

int			return_error(int values);
char			*get_name(t_nm *obj, int i);
size_t			get_shnum(Elf64_Ehdr *elf);
unsigned int		get_offsetsize(t_nm *obj, int i);
unsigned int		get_shdrsize(t_nm *obj, int i);
int			get_size(int fd);
int			print_section(t_nm *nm);
int			printf_list(t_list *, t_nm *);
int			add_list(t_list *, char *, char, long unsigned int);
t_list			*create_list(void);
int			print_symbol(t_nm *);
int			my_strcasecmp(const char *, const char *);
char			get_real_sym(Elf64_Sym *sym, t_nm *nm);
char			*del_char(char *s, char c);
t_list*			clean_list(t_list *list, char *string,
				   char c, long unsigned int addr);
t_list			*move_list(t_list *list);
int			remove_section(const char *name,
				       unsigned char types);
int			my_strcasecmp(const char *s1, const char *s2);
int			elf_file(t_nm *obj);
int			print_usage(const char **error);
int			access_file(t_nm *obj);
int			access_files(t_nm *obj);
int			check_currents(const void *data);
int			check_endian(const void *data);
int			check_format(const void *data);
int			print_different_usage(const char *file);
int			basic_nm(const char *str, t_nm *nm);
int			others_structure(t_nm *nm);
char			*get_names(t_nm *obj, int i);
size_t			get_shnums(Elf32_Ehdr *elf);
unsigned int		get_shdrsizes(t_nm *obj, int i);
int			get_sizes(int fd);
unsigned int		get_offsetsizes(t_nm *obj, int i);
int			print_sections(t_nm *nm);
int			elf_files(t_nm *obj);
int			correct_folder(const char *);
int			add_informations(Elf32_Sym *, char *,
					 t_list *, t_nm *);
char			first_values(const char *name, Elf32_Sym *symbols);
int			add_simple_information(Elf64_Sym *, char *,
					       t_list *, t_nm *);
char			first_value(const char *name, Elf64_Sym *symbols);

#endif
