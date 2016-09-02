/*
** struct.h for  in /home/mart_4/rendu/PSU_2015_nmobjdump
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Wed Feb 17 23:40:35 2016 Thomas Martins
** Last update Sun Feb 28 13:52:19 2016 Thomas Martins
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>

# define			VALUES4 " %04x\t"
# define			VALUES2 "%02x"
# define			SPACE " "
# define			RETURN "\n"
# define			RETURN_T "\t"
# define			SECTION 3

# define			NOFILE "my_objdump: \n"
# define			ERROR	stderr
# define			SIZEFILE "File format not recognized\n"
# define			MAGICNUMBER "File format not recognized\n"
# define			FORMAT	"File format not recognized\n"
# define			ENDIAN	"File format not recognized\n"
# define			FILEERROR "File format not recognized\n"
# define			MALLOC "Can't malloc the structure\n"
# define			FIRSTCURRENT "File format not recognized\n"
# define			FULL "File format not recognized\n"
# define			PRINT "File truncated\n"
# define			FILES "File truncated\n"

# define			TYPESZERO ""
# define			TYPESONE "HAS_RELOC, HAS_SYMS"
# define			TYPESTWO "EXEC_P, HAS_SYMS, D_PAGED"
# define			TYPESTHREE "HAS_SYMS, DYNAMIC, D_PAGED"
# define			TYPESFOUR ""

# define			NUMBERSZERO 0x0
# define			NUMBERSONE 0x11
# define			NUMBERSTWO 0x112
# define			NUMBERSTHREE 0x150

typedef enum	e_bool		e_bool;
typedef struct	s_obj		t_obj;

enum				e_format
  {
				FORMAT64,
				FORMAT32
  };

enum				e_bool
  {
				FALSE,
				TRUE
  };

struct				s_obj
{
  void				*data;
  Elf64_Shdr			*shdr;
  Elf64_Ehdr			*elf;
  Elf32_Shdr			*shdrs;
  Elf32_Ehdr			*elfs;
  int				fd;
  char				*tab;
  char				*name;
  int				size;
  enum e_format			format;
  int				e_numbers[ET_NUM];
  char				*e_types[ET_NUM];
  int				a;
  int				b;
  int				c;
  char				*tab_name;
  char				*results;
  int				iterator;
};

int				get_size(int fd);
void				print_sh_name(Elf64_Shdr *shdr,
					      char *str, int shnum);
int				return_error(int values);
int				file_is_elf(t_obj *);
int				elf_file(t_obj *obj);
void				print_header_elf(t_obj *obj);
void				print_header_elfs(t_obj *obj);
int				print_section_file(t_obj *obj);
unsigned int			get_offsetsize(t_obj *obj, int i);
unsigned int			get_shdrsize(t_obj *obj, int i);
size_t				get_shnum(Elf64_Ehdr *);
char				*get_name(t_obj *obj, int i);
int				remove_struct(t_obj *obj);
int				check_currents(const void *);
int				check_endian(const void *);
int				check_format(const void *);
int				access_file(t_obj *);
int				access_files(t_obj *);
int				bool_section(t_obj *obj, const char *section);
int				section_get(t_obj *);
void				simple_init(t_obj *);
int				init_all_struct(t_obj *);
int				print_information_section(const char *addr,
							  size_t size,
							  size_t addr_size,
							  t_obj *obj);
int				print_before(const char *addr,
					     const int div, size_t,
					     t_obj *obj);
int				print_usage(const char **error);
int				print_different_usage(const char *file);
int				copy(t_obj *);
int				others_structure(t_obj *obj);
int				basic_elf(const char *, t_obj *);
int				*get_flags_number(t_obj *obj);
char				**get_flags(t_obj *obj);
int				print_section_files(t_obj *);
char				*get_names(t_obj *, int);
size_t				get_shnums(Elf32_Ehdr *elf);
unsigned int			get_offsetsizes(t_obj *obj, int i);
unsigned int			get_shdrsizes(t_obj *obj, int i);
int				get_sizes(int fd);
int				elf_files(t_obj *obj);
int				correct_folder(const char *);

#endif
