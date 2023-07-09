#include "parser.h"

#include "math.h"
#include "stdlib.h"
#include "string.h"

TokenList parseExpression(const char* expression) {
    TokenList tokens; // Создается переменная типа TokenList для хранения списка токенов
    tokens.tokens = malloc(strlen(expression) * sizeof(Token)); // Выделяется память для массива токенов в соответствии с длиной выражения
    tokens.count = 0; // Инициализируется счетчик токенов

    int i = 0; // Инициализируется переменная-счетчик для обхода символов в выражении
    while (expression[i] != '\0') { // Пока не достигнут символ завершения строки
        if (expression[i] == ' ') { // Если текущий символ - пробел, пропускаем его и переходим к следующему
            i++;
            continue;
        }

        if (expression[i] >= '0' && expression[i] <= '9') { // Если текущий символ - цифра
            char* endptr; // Указатель, используемый для определения конца числовой строки
            double value = strtod(&expression[i], &endptr); // Конвертация числовой строки в число с помощью функции strtod
            tokens.tokens[tokens.count].type = 0; // Тип токена устанавливается на 0 для числа
            tokens.tokens[tokens.count].value = value; // Значение токена устанавливается на полученное число
            tokens.count++; // Увеличивается счетчик токенов
            i += endptr - &expression[i]; // Обновление счетчика i для пропуска числовой строки
        } else { // Если текущий символ - оператор или переменная
            Token currentToken; // Создается переменная типа Token для текущего токена
            currentToken.type = expression[i]; // Тип токена устанавливается на текущий символ

            // Установка значения токена для переменной 'x' или числа E
            if (expression[i] == 'x' || expression[i] == 'e') {
                currentToken.value = (expression[i] == 'x') ? 0 : M_E;
            }

            tokens.tokens[tokens.count] = currentToken; // Текущий токен добавляется в массив токенов
            tokens.count++; // Увеличивается счетчик токенов
            i++; // Переход к следующему символу
        }
    }
    return tokens; // Возвращается созданный список токенов
}

