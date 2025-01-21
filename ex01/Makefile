CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98 #-Wpedantic
NAME = Form
FILES = src/main.cpp src/Bureaucrat.cpp src/Form.cpp
OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(FILES) -o $(NAME)

src/%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $<

clean:
		rm -f $(OBJS)

re: clean all

fclean : clean 
		rm -f $(NAME)

.PHONY: all clean%   