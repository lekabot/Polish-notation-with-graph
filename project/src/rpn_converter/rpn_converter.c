#include "rpn_converter.h"

#include <stdlib.h>

TokenList convertToRPN(const TokenList* tokens) {
    TokenList rpn;
    rpn.tokens = malloc(tokens->count * sizeof(Token)); // Выделение памяти для массива токенов RPN
    rpn.count = 0; // Инициализация счетчика токенов RPN
    Token* stack = malloc(tokens->count * sizeof(Token)); // Выделение памяти для стека токенов
    int stackTop = -1; // Инициализация вершины стека

    for (int i = 0; i < tokens->count; i++) { // Итерация по токенам в исходном списке токенов
        if (tokens->tokens[i].type == '+' || tokens->tokens[i].type == '-' || tokens->tokens[i].type == '*' ||
            tokens->tokens[i].type == '/' || tokens->tokens[i].type == '^') {
            while (stackTop >= 0 && (stack[stackTop].type == '+' || stack[stackTop].type == '-' ||
                                     stack[stackTop].type == '*' || stack[stackTop].type == '/' ||
                                     stack[stackTop].type == '^')) {
                rpn.tokens[rpn.count] = stack[stackTop]; // Помещение операторов с более высоким приоритетом в RPN
                rpn.count++;
                stackTop--;
            }
            stackTop++;
            stack[stackTop] = tokens->tokens[i]; // Помещение текущего оператора в стек
        } else if (tokens->tokens[i].type == 's' || tokens->tokens[i].type == 'c' ||
                   tokens->tokens[i].type == 't' || tokens->tokens[i].type == 'g' ||
                   tokens->tokens[i].type == 'q' || tokens->tokens[i].type == 'l') {
            stackTop++;
            stack[stackTop] = tokens->tokens[i]; // Помещение функций в стек
        } else if (tokens->tokens[i].type == '(') {
            stackTop++;
            stack[stackTop] = tokens->tokens[i]; // Помещение открывающей скобки в стек
        } else if (tokens->tokens[i].type == ')') {
            while (stackTop >= 0 && stack[stackTop].type != '(') {
                rpn.tokens[rpn.count] = stack[stackTop]; // Перемещение операторов из стека в RPN до открывающей скобки
                rpn.count++;
                stackTop--;
            }
            if (stackTop >= 0 && stack[stackTop].type == '(') {
                stackTop--; // Удаление открывающей скобки из стека
            }
        } else {
            rpn.tokens[rpn.count] = tokens->tokens[i]; // Помещение операндов в RPN
            rpn.count++;
        }
    }
    while (stackTop >= 0) {
        rpn.tokens[rpn.count] = stack[stackTop]; // Перемещение оставшихся операторов из стека в RPN
        rpn.count++;
        stackTop--;
    }
    free(stack); // Освобождение памяти, выделенной для стека
    return rpn; // Возвращение списка токенов RPN
}