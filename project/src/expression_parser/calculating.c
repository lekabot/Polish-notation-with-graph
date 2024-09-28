#include "calculating.h"

#include "math.h"
#include "stdlib.h"
#include "string.h"

double calculateExpression(const TokenList* rpn, double x) {
    Token* stack = (Token*)malloc(rpn->count * sizeof(Token)); // Выделение памяти для стека токенов
    int stackTop = -1; // Инициализация вершины стека

    for (int i = 0; i < rpn->count; i++) { // Итерация по токенам в обратной польской записи
        Token currentToken = rpn->tokens[i]; // Получение текущего токена

        switch (currentToken.type) { // Обработка различных типов токенов
            case '+':
                performAddition(stack, &stackTop); // Выполнение операции сложения
                break;
            case '-':
                performSubtraction(stack, &stackTop); // Выполнение операции вычитания
                break;
            case '*':
                performMultiplication(stack, &stackTop); // Выполнение операции умножения
                break;
            case '/':
                performDivision(stack, &stackTop); // Выполнение операции деления
                break;
            case '^':
                performExponentiation(stack, &stackTop); // Выполнение операции возведения в степень
                break;
            case 's':
                performSin(stack, &stackTop); // Выполнение операции синуса
                break;
            case 'c':
                performCos(stack, &stackTop); // Выполнение операции косинуса
                break;
            case 't':
                performTan(stack, &stackTop); // Выполнение операции тангенса
                break;
            case 'g':
                performCtg(stack, &stackTop); // Выполнение операции котангенса
                break;
            case 'q':
                performSqrt(stack, &stackTop); // Выполнение операции квадратного корня
                break;
            case 'l':
                performLog(stack, &stackTop); // Выполнение операции логарифма
                break;
            case 'x':
                pushToStack(stack, &stackTop, x); // Добавление значения переменной 'x' на стек
                break;
            default:
                pushToStack(stack, &stackTop, currentToken.value); // Добавление числового значения на стек
                break;
        }
    }

    double result = stack[stackTop].value; // Получение результата из вершины стека
    free(stack); // Освобождение памяти, выделенной для стека
    return result; // Возвращение результата
}

void pushToStack(Token* stack, int* stackTop, double value) {
    (*stackTop)++; // Увеличение вершины стека
    stack[*stackTop].value = value; // Добавление значения на стек
}

void performAddition(Token* stack, int* stackTop) {
    double b = stack[*stackTop].value; // Получение второго операнда
    (*stackTop)--; // Уменьшение вершины стека
    double a = stack[*stackTop].value; // Получение первого операнда
    (*stackTop)++; // Увеличение вершины стека
    stack[*stackTop].value = a + b; // Выполнение операции сложения и добавление результата на стек
}

// Аналогично для остальных функций performSubtraction, performMultiplication, performDivision, performExponentiation, performSin, performCos, performTan, performCtg, performSqrt, performLog

void performSubtraction(Token* stack, int* stackTop) {
    if (*stackTop > 0 && stack[*stackTop - 1].type != 'x') {
        double b = stack[*stackTop].value;
        (*stackTop)--;
        double a = stack[*stackTop].value;
        (*stackTop)++;
        stack[*stackTop].value = a - b;
    } else {
        double a = stack[*stackTop].value;
        (*stackTop)++;
        stack[*stackTop].value = -a;
    }
}

void performMultiplication(Token* stack, int* stackTop) {
    double b = stack[*stackTop].value;
    (*stackTop)--;
    double a = stack[*stackTop].value;
    (*stackTop)++;
    stack[*stackTop].value = a * b;
}

void performDivision(Token* stack, int* stackTop) {
    double b = stack[*stackTop].value;
    (*stackTop)--;
    double a = stack[*stackTop].value;
    (*stackTop)++;
    stack[*stackTop].value = a / b;
}

void performExponentiation(Token* stack, int* stackTop) {
    double b = stack[*stackTop].value;
    (*stackTop)--;
    double a = stack[*stackTop].value;
    (*stackTop)++;
    stack[*stackTop].value = pow(a, b);
}

void performSin(Token* stack, int* stackTop) {
    double a = stack[*stackTop].value;
    (*stackTop)++;
    stack[*stackTop].value = sin(a);
}

void performCos(Token* stack, int* stackTop) {
    double a = stack[*stackTop].value;
    (*stackTop)++;
    stack[*stackTop].value = cos(a);
}

void performTan(Token* stack, int* stackTop) {
    double a = stack[*stackTop].value;
    (*stackTop)++;
    stack[*stackTop].value = tan(a);
}

void performCtg(Token* stack, int* stackTop) {
    double a = stack[*stackTop].value;
    (*stackTop)++;
    double sinValue = sin(a);
    if (sinValue != 0) {
        double cosValue = cos(a);
        stack[*stackTop].value = cosValue / sinValue;
    } else {
        stack[*stackTop].value = INFINITY;
    }
}

void performSqrt(Token* stack, int* stackTop) {
    double a = stack[*stackTop].value;
    (*stackTop)++;
    stack[*stackTop].value = sqrt(a);
}

void performLog(Token* stack, int* stackTop) {
    double a = stack[*stackTop].value;
    (*stackTop)++;
    stack[*stackTop].value = log(a);
}