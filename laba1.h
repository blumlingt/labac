#include <iostream>
#include <windows.h>

class Lab1 {
    public:
        void calc(char name, double calcFunc(float, float)) {
            printf("\nРассчет функции %c", name);
            float a = Utils::read_input_float("a");
            float x = Utils::read_input_float("x");
            printf("%c = %f", name, calcFunc(a, x));
        }

        void main() {
            setlocale(LC_CTYPE, "rus");
            Lab1::calc('g', Utils::calc_g);
            Lab1::calc('f', Utils::calc_f);
            Lab1::calc('y', Utils::calc_y);
        }
