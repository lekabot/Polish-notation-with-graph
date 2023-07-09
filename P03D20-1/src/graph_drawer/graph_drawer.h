#ifndef GRAPH_DRAWER_H
#define GRAPH_DRAWER_H

#include "../data_structures/list.h"
#include "../expression_parser/parser.h"

void drawGraph(const TokenList* tokens, int width, int height);
void clearScreen();
void setCursorPosition(int x, int y);

#endif /* GRAPH_DRAWER_H */
