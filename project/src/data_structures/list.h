#ifndef LIST_H
#define LIST_H

#include "token.h"

typedef struct {
    Token* tokens;
    int count;
} TokenList;

#endif /* LIST_H */
