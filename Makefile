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
FLAGS	=	-g
SRCS	=	$(addprefix $(SRCDIR)/ft_, strlen.s strcpy.s strcmp.s write.s read.s strdup.s atoi_base.s)
OBJS	=	$(patsubst $(SRCDIR)/%.s, $(OBJDIR)/%.o, $(SRCS))
TSTDIR	=	tests
TSTSRCS	=	$(addprefix $(TSTDIR)/$(SRCDIR)/,												\
			$(addprefix diff/diff_, bool.c sizes.c types.c)									\
			$(addprefix units/test_ft_, strlen.c strcpy.c strcmp.c write.c read.c strdup.c atoi_base.c)	\
			main.c utils.c rand.c)
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
	@$(ASM) $(FLAGS) -f$(FORMAT) $< -o $@

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
