#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>

class Lab4 {
public:
    int selectFunc() {
        int i;
        std:cout << "\nВыберите функцию для вычисления: \n   1 - функция g \n   2 - функция f \n   3 - функция y\nНомер: " << std::endl;
        cin >> i;
        return i;
    }

    int even_count(int integer) {
        int even = 0;
        while (integer > 0) {
            if (integer % 2 == 0) {
                even++;
            }
            integer /= 10;
        }
        return even;
    }

    void print_result(char name, const vector<float> &keys, const vector<double> &values) {
        printf("\nРассчет функции %c", name);
        for (unsigned int i = 0; i < keys.size(); i++) {
            printf("\n%f    %f", keys.at(i), values.at(i));
        }

        printf("\n");
        double max = *std::max_element(values.begin(), values.end());
        double min = *std::min_element(values.begin(), values.end());

        printf("\nМаксимальное значение функции %c: %f", name, max);
        printf("\nМинимальное значение функции %c: %f", name, min);
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
            keys.push_back(x);
            values.push_back(selectedFunc(a, x));
        }
        print_result(funcName, keys, values);
        printf("\n");

        int integer = Utils::read_input_int("число, для подсчета четных цифр");
        printf("Четных цифр в числе %d: %d", integer, even_count(integer));
    }
};
