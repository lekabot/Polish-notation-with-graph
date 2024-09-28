#include "graph_drawer.h"

#include <math.h>
#include <stdio.h>

#include "../expression_parser/calculating.h"

void drawGraph(const TokenList* tokens, int width, int height) {
    clearScreen(); // Очистка экрана

    double xMin = 0.0;
    double xMax = 4.0 * M_PI;
    double xRange = xMax - xMin;
    double xStep = xRange / (width - 1); // Шаг по оси абсцисс

    double yMin = -1.0;
    double yMax = 1.0;
    double yRange = yMax - yMin;
    double yStep = yRange / (height - 1); // Шаг по оси ординат

    double centerX = 0.0 - xMin; // Центрирование графика относительно оси абсцисс

    for (int y = height - 1; y >= 0; y--) { // Итерация по строкам (ось ординат вниз)
        double yValue = yMin + yStep * y; // Вычисление текущего значения на оси ординат

        for (int x = 0; x < width; x++) { // Итерация по столбцам (ось абсцисс вправо)
            double xValue = xMin + xStep * x; // Вычисление текущего значения на оси абсцисс

            xValue -= centerX; // Центрирование значения на оси абсцисс

            TokenList evaluatedTokens = *tokens; // Создание копии списка токенов для вычислений
            for (int i = 0; i < tokens->count; i++) {
                if (tokens->tokens[i].type == 'x') {
                    evaluatedTokens.tokens[i].value = xValue; // Замена переменной 'x' на текущее значение на оси абсцисс
                }
            }
            double realY = calculateExpression(&evaluatedTokens, xValue); // Вычисление значения функции для текущего 'x'

            if (fabs(realY - yValue) <= yStep / 2.0) {
                printf("*"); // Если значение функции близко к текущему значению на оси ординат, выводится символ '*'
            } else {
                printf("."); // В противном случае выводится символ '.'
            }
        }
        printf("\n"); // Переход на новую строку
    }
}


void clearScreen() {
    printf("\33[2J");
    setCursorPosition(0, 0);
}

void setCursorPosition(int x, int y) { printf("\033[%d;%dH", y + 1, x + 1); }