#include <iostream>
#include <windows.h>

class Lab3 {
public:
    int selectFunc() {
        int i;
        std:cout << "\nВыберите функцию для вычисления: \n   1 - функция g \n   2 - функция f \n   3 - функция y\nНомер: " << std::endl;
        cin >> i;
        return i;
    }

    void calc(char name, float a, float  x, double calcFunc(float, float)) {
        printf("\nРассчет функции %c", name);
        printf("%c = %f", name, calcFunc(a, x));
    }

    void main() {
        setlocale(LC_CTYPE, "rus");
        float a = Utils::read_input_float("a");
        int steps = Utils::read_input_int("количество шагов для вычисления функции");

        float xMax = Utils::read_input_float("максимальное значение x");
        float xMin = Utils::read_input_float("минимальное значение x");

        while (xMin >= xMax) {
            printf("Минимальное значение значение %f >= максимального %f", xMin, xMax);
            xMax = Utils::read_input_float("максимальное значение x");
            xMin = Utils::read_input_float("минимальное значение x");
        }

        int num = selectFunc();
        double (*selectedFunc)(float, float) = nullptr;
        char funcName = 0;

        switch (num) {
            case 1:
                funcName = 'g';
                selectedFunc = Utils::calc_g;
                break;
            case 2:
                funcName = 'f';
                selectedFunc = Utils::calc_f;
                break;
            case 3:
                funcName = 'y';
                selectedFunc = Utils::calc_y;
                break;
            default:
                printf("Функции не найдено");
                main();
                break;
        }

        float x;
        for (int i = 0; i < steps; i++) {
            x = xMin + ((float) i / 10);
            if (x > xMax) {
                break;
            }
            calc(funcName, a, x, selectedFunc);
        }
    }
};
