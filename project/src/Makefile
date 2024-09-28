CC = gcc
CFLAGS = -Wall -Werror -Wextra
BUILD_DIR = ../build/
CFILES = expression_parser/calculating.c expression_parser/parser.c graph_drawer/graph_drawer.c rpn_converter/rpn_converter.c graph.c

all:
	$(CC) $(CFLAGS) $(CFILES) -o $(BUILD_DIR)graph
	$(BUILD_DIR)graph