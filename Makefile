NAME	=	libasm.a
SRCDIR	=	srcs
OBJDIR	=	objs
ASM		=	nasm
AFLAGS	=
CC		=	/usr/bin/clang
CFLAGS	=	-Wall -Wextra -Werror
AR		=	/usr/bin/ar
ARFLAGS	=	rcus
RM		=	/bin/rm
FORMAT	=	elf64
FLAGS	=	-g
UNITS	=	strlen strcpy strcmp write read strdup atoi_base list_push_front list_size list_remove_if
SRCS	=	$(addprefix $(SRCDIR)/ft_, $(addsuffix .s, $(UNITS)))
OBJS	=	$(patsubst $(SRCDIR)/%.s, $(OBJDIR)/%.o, $(SRCS))
TSTDIR	=	tests
TSTSRCS	=	$(addprefix $(TSTDIR)/$(SRCDIR)/,	\
			$(addprefix diff/diff_,				\
				bool.c							\
				sizes.c							\
				types.c)	 					\
			$(addprefix units/test_ft_, $(addsuffix .c, $(UNITS))) \
			main.c utils.c rand.c)
TSTINC	=	$(TSTDIR)/includes
TSTCMD	=	./test

all:			$(NAME)

$(NAME):		$(OBJS)
	@printf "%-3s $@ $(OBJS)\n" AR
	@$(AR) $(ARFLAGS) $@ $(OBJS)

$(OBJDIR):
	@printf "%-3s $@\n" MK
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.s $(OBJDIR) Makefile
	@printf "%-3s $<\n" ASM
	@$(ASM) $(FLAGS) $(AFLAGS) -f$(FORMAT) $< -o $@

clean:
	@printf "%-3s $(OBJDIR)\n" RM
	@$(RM) -rf $(OBJDIR)

fclean:			clean
	@printf "%-3s $(NAME) test\n" RM
	@$(RM) -rf $(NAME) test

re:				fclean all

test:			all $(TSTSRCS)
	@printf "%-3s $(TSTSRCS)\n" CC
	@$(CC) $(CFLAGS) $(TSTSRCS) -I$(TSTINC) -L. -lasm -o test
	$(TSTCMD)
