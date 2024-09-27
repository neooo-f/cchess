# compiler
CC = gcc

# name of executable
TARGET = chess

# include directories
INCLUDES = -Iinclude/

# library directories
LIB_DIRS = -Llib/

# necessary frameworks for macOS (CoreVideo, IOKit, Cocoa, GLUT, OpenGL)
FRAMEWORKS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL

# external libraries
LIBS = lib/libraylib.a

# source files
SRC = src/main.c

# output directory
BIN_DIR = bin/

# custom compiler flags
# CFLAGS = -Wall -g

# compile rule
$(TARGET): $(SRC)
	$(CC) $(SRC) $(INCLUDES) $(LIB_DIRS) $(FRAMEWORKS) $(LIBS) $(CFLAGS) -o $(BIN_DIR)$(TARGET)

# clean rule
clean:
	rm -f $(BIN_DIR)$(TARGET)