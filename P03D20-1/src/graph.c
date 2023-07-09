#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_structures/list.h"
#include "expression_parser/parser.h"
#include "graph_drawer/graph_drawer.h"
#include "rpn_converter/rpn_converter.h"

#define MAX_EXPRESSION_LENGTH 100

void runGraphProgram();

int main() {
    runGraphProgram();
    return 0;
}

void runGraphProgram() {
    char expression[MAX_EXPRESSION_LENGTH]; // Объявление массива символов для хранения выражения
    fgets(expression, sizeof(expression), stdin); // Считывание выражения с помощью fgets
    expression[strcspn(expression, "\n")] = '\0'; // Удаление символа новой строки из введенного выражения

    TokenList tokens = parseExpression(expression); // Парсинг выражения в список токенов
    TokenList rpn = convertToRPN(&tokens); // Преобразование выражения в обратную польскую нотацию (ОПН)
    drawGraph(&rpn, 80, 25); // Отрисовка графика на основе ОПН

    free(tokens.tokens); // Освобождение памяти, выделенной под список токенов
    free(rpn.tokens); // Освобождение памяти, выделенной под ОПН
}
