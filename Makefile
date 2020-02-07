NAME	=	libft.a
SRCDIR	=	srcs
OBJDIR	=	objs
ASM		=	/Users/chamada/brew/bin/nasm
CC		=	/usr/bin/clang
CFLAGS	=	-Wall -Wextra -Werror
AR		=	/usr/bin/ar
AFLAGS	=	rcus
RM		=	/bin/rm
FORMAT	=	macho64
FLAGS	=	-f$(FORMAT)
SRCS	=	$(addprefix $(SRCDIR)/ft_, strlen.s strcpy.s)
OBJS	=	$(patsubst $(SRCDIR)/%.s, $(OBJDIR)/%.o, $(SRCS))
TSTDIR	=	tests
TSTSRCS	=	$(addprefix $(TSTDIR)/$(SRCDIR)/, tests.c test_utils.c)
TSTINC	=	$(TSTDIR)/includes
TSTCMD	=	./test

all:			$(NAME)

$(NAME):		$(OBJS)
	@printf "%-3s $@ $(OBJS)\n" AR
	@$(AR) $(AFLAGS) $@ $(OBJS)

$(OBJDIR):
	@printf "%-3s $@\n" MK
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.s $(OBJDIR) Makefile
	@printf "%-3s $<\n" ASM
	@$(ASM) $(FLAGS) $< -o $@

clean:
	@printf "%-3s $(OBJDIR)\n" RM
	@$(RM) -rf $(OBJDIR)

fclean:			clean
	@printf "%-3s $(NAME) test\n" RM
	@$(RM) -rf $(NAME) test

re:				fclean all

test:			all $(TSTSRCS)
	@printf "%-3s $(TSTSRCS)\n" CC
	@$(CC) $(CFLAGS) $(TSTSRCS) -I$(TSTINC) -L. -lft -o test
	$(TSTCMD)