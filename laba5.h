#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>

class Lab5 {
public:
    int selectFunc() {
        int i;
        std:cout << "\nВыберите функцию для вычисления: \n   1 - функция g \n   2 - функция f \n   3 - функция y\nНомер: " << std::endl;
        cin >> i;
        return i;
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

        vector <float> keys = {};
        vector <double> values = {};


        int num = selectFunc();
        double (*selectedFunc)(float, float) = nullptr;

        switch (num) {
            case 1:
                selectedFunc = Utils::calc_g;
                break;
            case 2:
                selectedFunc = Utils::calc_f;
                break;
            case 3:
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
            keys.push_back(x);
            values.push_back(selectedFunc(a, x));
        }
        printf("\nМассив значений функции: ");
        for (double &value : values) {
            printf("%f ", value);
        }

        float find = Utils::read_input_float("значение которое необходимо найти");
        int count = std::count(values.begin(), values.end(), find);
        printf("Совпадений найдено: %d", count);
    }
};
