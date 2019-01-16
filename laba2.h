#include <iostream>
#include <windows.h>

class Lab2 {
    public:
        int selectFunc() {
            int i;
            std:cout << "\nВыберите функцию для вычисления: \n   1 - функция g \n   2 - функция f \n   3 - функция y\nНомер: " << std::endl;
            cin >> i;
            return i;
        }

        void calc(char name, double calcFunc(float, float)) {
            printf("\nРассчет функции %c", name);
            float a = Utils::read_input_float("a");
            float x = Utils::read_input_float("x");
            printf("%c = %f", name, calcFunc(a, x));
        }

        void main() {
            setlocale(LC_CTYPE, "rus");
            int num = selectFunc();
            switch (num) {
                case 1:
                    calc('g', Utils::calc_g);
                    break;
                case 2:
                    calc('f', Utils::calc_f);
                    break;
                case 3:
                    calc('y', Utils::calc_y);
                    break;
                default:
                    printf("Функции не найдено");
                    main();
                    break;
            }
    }
};
