#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <map>

class Lab6 {
public:
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

        std::map<char, vector<double>> storage = {{'g', {}},{'f', {}},{'y', {}}};

        float x;
        for (int i = 0; i < steps; i++) {
            x = xMin + ((float) i / 10);
            if (x > xMax) {
                break;
            }
            storage.at('g').push_back(Utils::calc_g(a, x));
            storage.at('f').push_back(Utils::calc_f(a, x));
            storage.at('y').push_back(Utils::calc_y(a, x));
        }

        for (auto itr = storage.begin(); itr != storage.end(); ++itr) {
            printf("\n%c = ", (*itr).first);
            for (double &value : (*itr).second) {
                printf("%f ", value);
            }
        }
    }
};
