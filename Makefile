##
## Makefile<2> for  in /home/mart_4/rendu/PSU_2015_malloc
##
## Made by Thomas Martins
## Login   <mart_4@epitech.net>
##
## Started on  Mon Jan 25 23:08:27 2016 Thomas Martins
## Last update Sun Feb 28 13:12:40 2016 Thomas Martins
##

NAMEOBJ	=	my_objdump

NAMENM	=	my_nm

CC      =	gcc

SRCNM	=	nm/main.c				\
		nm/error.c				\
		nm/file_information.c			\
		nm/new_print.c				\
		nm/create.c				\
		nm/print_values.c			\
		nm/utils_list.c				\
		nm/error_again.c			\
		nm/nm32/new_structure.c			\
		nm/nm32/new_print_section.c		\
		nm/nm32/new_file_information.c		\
		nm/nm32/new_error.c			\
		nm/nm32/last_print.c			\
		nm/last_new_print.c			\

SRCOBJ	=	objdump/main.c				\
		objdump/error.c				\
		objdump/file_information.c		\
		objdump/header.c			\
		objdump/section_file.c			\
		objdump/remove.c			\
		objdump/error_again.c			\
		objdump/run_section.c			\
		objdump/obj32/new_structure.c		\
		objdump/obj32/new_header.c		\
		objdump/obj32/new_print_section.c	\
		objdump/obj32/new_file_information.c	\
		objdump/obj32/new_error.c		\

RM      =	rm -f

OBJDUMP	=	$(SRCOBJ:.c=.o)

OBJNM	=	$(SRCNM:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror

all:		$(NAMEOBJ) $(NAMENM)

$(NAMEOBJ):	$(OBJDUMP)
		$(CC) -o $(NAMEOBJ) $(OBJDUMP)

$(NAMENM):	$(OBJNM)
		$(CC) -o $(NAMENM) $(OBJNM)

%.o : %.c
		$(CC) -c $(CFLAGS) -o $@ $^

clean:
		$(RM) $(OBJDUMP) $(OBJNM)

fclean:		clean
		$(RM) $(NAMEOBJ) $(NAMENM)

re:		fclean all

nm:		$(NAMENM)

$(NAMENMS):	$(OBJNM)
		$(CC) -o $(NAMENM) $(OBJNM)

%.o : %.c
		$(CC) -c $(CFLAGS) -o $@ $^

cleannm:
		$(RM) $(OBJNM)

fcleannm:	cleannm
		$(RM) $(NAMENM)

renm:		fcleannm nm

objdump:	$(NAMEOBJ)

$(NAMEOBJS):	$(OBJDUMP)
		$(CC) -o $(NAMEOBJ) $(OBJDUMP)

%.o : %.c
		$(CC) -c $(CFLAGS) -o $@ $^

cleanobjdump:
		$(RM) $(OBJDUMP)

fcleanobjdump:	cleanobjdump
		$(RM) $(NAMEOBJ)

reobjdump:	fcleanobjdump objdump
