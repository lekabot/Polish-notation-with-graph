#ifndef CALCULATING_H
#define CALCULATING_H

#include "../data_structures/list.h"

double calculateExpression(const TokenList* rpn, double x);
void pushToStack(Token* stack, int* stackTop, double value);
void performAddition(Token* stack, int* stackTop);
void performSubtraction(Token* stack, int* stackTop);
void performMultiplication(Token* stack, int* stackTop);
void performDivision(Token* stack, int* stackTop);
void performExponentiation(Token* stack, int* stackTop);
void performSin(Token* stack, int* stackTop);
void performCos(Token* stack, int* stackTop);
void performTan(Token* stack, int* stackTop);
void performCtg(Token* stack, int* stackTop);
void performSqrt(Token* stack, int* stackTop);
void performLog(Token* stack, int* stackTop);

#endif /* EXPRESSION_PARSER_H */
