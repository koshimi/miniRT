#	Toggle line comment at line 89 ~ 90, 96 ~ 97 for fast-make (WILL NOT make lib_subdirs clean or fclean)
#	If make error, miniRT.tmp should be deleted

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = miniRT
NAME_HEADER_DIR = headers
NAME_H =	$(NAME_HEADER_DIR)/rtstructs.h \
			$(NAME_HEADER_DIR)/mlxstructs.h \
			$(NAME_HEADER_DIR)/minirt.h

LIBFT = libft.a
LIBFT_DIR = Libft
LIBFT_H = $(LIBFT_DIR)/libft.h

LIBMLX = libmlx.dylib
# mlx_mms or mlx_linux
LIBMLX_DIR = mlx/mlx_mms
LIBMLX_H = mlx/mlx.h

SRCS =	srcs/main.c \
		srcs/my_list/new_node.c \
		srcs/my_list/del_node.c \
		srcs/my_list/new_list.c \
		srcs/my_list/del_list.c \
		srcs/my_list/add_list.c \
		srcs/mlx/mlx_rt_utils.c \
		srcs/mlx/mlx_draw_utils.c \
		srcs/rt/rt_dat/new_rt_dat.c \
		srcs/rt/rt_dat/del_rt_dat.c \
		srcs/rt/rt_color.c \
		srcs/rt/types/types_utils.c \
		srcs/rt/types/types_vector3_double.c \
		srcs/rt/types/types_vector3_double_base_op.c \
		srcs/rt/types/types_vector3_double_product.c \
		srcs/rt/types/types_mat_3x3_double.c \
		srcs/rt/o_ambient/new_ambient.c \
		srcs/rt/o_ambient/del_ambient.c \
		srcs/rt/o_camera/new_camera.c \
		srcs/rt/o_camera/del_camera.c \
		srcs/rt/o_light/new_light.c \
		srcs/rt/o_light/del_light.c \
		srcs/rt/o_sphere/new_sphere.c \
		srcs/rt/o_sphere/del_sphere.c \
		srcs/rt/o_sphere/is_hit_sphere.c \
		srcs/rt/o_plane/new_plane.c \
		srcs/rt/o_plane/del_plane.c \
		srcs/rt/o_plane/is_hit_plane.c \
		srcs/rt/o_cylinder/new_cylinder.c \
		srcs/rt/o_cylinder/del_cylinder.c \
		srcs/rt/o_cylinder/is_hit_cylinder.c \
		srcs/rt/linear_func/rotation.c \
		srcs/rt/linear_func/linear_map.c \
		srcs/rt/linear_func/linear_get_inverse_3x3.c \
		srcs/rt/raytrace/ray.c \
		srcs/rt/raytrace/ray_hit.c \
		srcs/mlx/mlx_event/mlx_event_destroy.c \
		srcs/mlx/mlx_event/mlx_event_keyup.c

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

# Everytime makes all LIB_SUBDIR
$(NAME) :
	make -C $(LIBFT_DIR)
	make -C $(LIBMLX_DIR)
	make $(LIBMLX_H)
	make $(LIBMLX)
# If $(NAME) is exist: rename $(NAME) -> $(NAME).tmp
ifneq ($(shell find . -name $(NAME) | wc -l | tr -d ' '), 0)
	mv $(NAME) $(NAME).tmp
endif
	make $(NAME).tmp
	mv $(NAME).tmp $(NAME)

# LIBMLX dependancies
$(LIBMLX_H) : $(LIBMLX_DIR)/mlx.h
	cp $(LIBMLX_DIR)/mlx.h $(LIBMLX_H)
$(LIBMLX) : $(LIBMLX_DIR)/$(LIBMLX)
	cp $(LIBMLX_DIR)/$(LIBMLX) $(LIBMLX)

# Includes LIB_SUBDIR.TARGET makes LIB_SUBDIR-update
$(NAME).tmp : $(NAME_H) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(LIBFT_H) $(LIBMLX_H)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(LIBMLX) -o $(NAME).tmp

clean :
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(LIBMLX_DIR) clean
	rm -f mlx/mlx_mms/*.swiftsourceinfo

fclean :
	make clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMLX_DIR) clean
	rm -f $(LIBMLX_H)
	rm -f $(LIBMLX)

re : 
	make fclean
	make all

.PHONY : all clean fclean re $(NAME)