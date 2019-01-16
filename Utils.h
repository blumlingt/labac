#include <cmath>
#include <iostream>

using namespace std;

class Utils {
    public:
        static float read_input_float(std::string name) {
            float input;
            cout << "\nВведите " + name + ": " << endl;
            cin >> input;
            return input;
        }
        static int read_input_int(std::string name) {
            int input;
            cout << "\nВведите " + name + ": " << endl;
            cin >> input;
            return input;
        }
        static double calc_g(float a, float x) {  return 2 * ((-5 * pow(a, 2)) + (3 * a * x) + (2 * pow(a, 2))) / ((5 * pow(a, 2)) + (9 * a * x) - (2 * pow(a, 2))); }
        static double calc_f(float a, float x) {  return sin(pi*((10 * pow(a, 2)) + (37 * a * x) + (7 * pow(a, 2))))/pi*(10 * pow(a, 2)) + (37 * a * x) + (7 * pow(a, 2)) ; }
        static double calc_y(float a, float x) {  return log((-5 * pow(a, 2)) - (16 * a * x) + (16 * pow(a, 2)) + 1)/log(2) ; }
};
