# This is a minimal set of ANSI/VT100 color codes
END			=	\e[0m
BOLD		=	\e[1m
UNDER		=	\e[4m
REV			=	\e[7m

# Colors

DEF_COLOR 	= 	\033[0;39m
GRAY 		= 	\033[0;90m
GREY_01		=	\033[30m
RED 		= 	\033[0;91m
RED_01		=	\033[31m
GREEN 		= 	\033[0;92m
GREEN_01	=	\033[32m
YELLOW 		= 	\033[0;93m
YELLOW_01	=	\033[33m
BLUE 		= 	\033[0;94m
BLUE_01		=	\033[34m
PURPLE		=	\033[35m
MAGENTA 	= 	\033[0;95m
CYAN 		= 	\033[0;96m
CYAN_01		=	\033[36m
WHITE 		= 	\033[0;97m
WHITE_01	=	\033[37m

# Inverted, i.e. colored backgrounds
IGREY		=	\e[40m
IRED		=	\e[41m
IGREEN		=	\e[42m
IYELLOW		=	\e[43m
IBLUE		=	\e[44m
IPURPLE		=	\e[45m
ICYAN		=	\e[46m
IWHITE		=	\e[47m

# **************************************************************************** #

#Variables‹

NAME			= fdf
INCLUDE			= include/
LIBFT			= libft
SRC_DIR			= src/
OBJ_DIR			= obj/
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g3 -I
MLX42           = MLX42/build/libmlx42.a
HEADER          = $(MLX42) $(LIBFT)/libft.a -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L "/Users/juguerre/.brew/opt/glfw/lib/" 
RM				= rm -f
AR				= ar rcs

# =========================================================================== #


#Sources

SRC_FILES	=	main error read_map

SRCS 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) $(HEADER)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(MAGENTA)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ $(HEADERS)

$(OBJF):
			@mkdir -p $(OBJ_DIR)

# Rules

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -rf utils/
			@make clean -C $(LIBFT)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(NAME2)
			@$(RM) -f $(NAME_TEST)
			@$(RM) -f $(NAME_DEBUG)
			@$(RM) -f $(LIBFT)/libft.a
			@$(RM) -f $(TEST_DIR)/libft.a
			@$(RM) -f libft.a
			@echo "$(CYAN)$(NAME) executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "  ________  ______      ________"
			@echo " |        ||    _ '''. |        |"
			@echo " |   .----'| _ | $(RED))$(DEF_COLOR) _  \|   .----'"
			@echo " |  _|____ |$(CYAN)($(DEF_COLOR) ''_'  $(CYAN))$(DEF_COLOR) ||  _|____"
			@echo " |_$(CYAN)( )$(DEF_COLOR)_   || . $(CYAN)($(DEF_COLOR)_$(CYAN))$(DEF_COLOR) '. ||_$(CYAN)( $(CYAN))$(DEF_COLOR)_   |"
			@echo " $(CYAN)($(DEF_COLOR)_ o._$(CYAN))$(DEF_COLOR)__||$(CYAN)($(DEF_COLOR)_    ._$(CYAN)) '$(CYAN)($(DEF_COLOR)_ o._$(CYAN))$(DEF_COLOR)__|"
			@echo " |$(CYAN)($(DEF_COLOR)_,_$(CYAN))$(DEF_COLOR)    |  $(RED)($(DEF_COLOR)_.\.' / |$(YELLOW)($(DEF_COLOR)_,_$(YELLOW))$(DEF_COLOR)"
			@echo " |   |     |       .'  |   |"
			@echo " '---'     '-----''    '---'"

git: fclean
			@git add .
			@git commit -m "auto commit"
			@git push

.PHONY:		all clean fclean re libmlx
