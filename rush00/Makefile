
RM ?= rm -f

CXX = clang++

SRC = main.cpp Window.cpp Player.cpp Loger.cpp Projectile.cpp \
	 BackGroundPellet.cpp BackGroundPelletManager.cpp \
	 Invader.cpp EntityManager.cpp
SRCS = $(addprefix src/, $(SRC))

OBJS = $(addprefix obj/, $(SRC:.cpp=.o))
DEPS = $(addprefix dep/, $(SRC:.cpp=.d))

CPPFLAGS = -Wall -Wextra -Werror -I include
LDFLAGS= -lncurses
LDLIBS=


NAME = ft_retro
.PHONY: all clean fclean run debug re run


default:all


all: $(NAME)

$(NAME): $(DEPS) $(OBJS)
	$(CXX) $(LDFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)

obj/%.o: src/%.cpp
	$(CXX) -o $@ -c $< $(CPPFLAGS)
dep/%.d: src/%.cpp
	@echo "generate $@"
	@set -e; $(RM) $@; \
	$(CXX) -MM $(CPPFLAGS) $< > $@.$$$$; \
		sed 's,\($*\)\.o[ :]*,obj/\1.o $@ : ,g' < $@.$$$$ >> $@; \
		$(RM) $@.$$$$

depend: $(DEPS)

clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)
fclean:clean
	$(RM) $(NAME)
	$(RM) .depend
re:fclean all
run:
	./$(NAME) $(ARGS)
debug:all run

-include $(DEPS)
