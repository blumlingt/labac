#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>

class Serializable {
    typedef map<char, vector<double>> RESULT_MAP;

    public:
        static std::string serialize(RESULT_MAP obj) {
            std::string filename = "result.bin";
            std::ofstream file(filename);

            for (auto &itr : obj) {
                file << itr.first << ": [";
                for (double &value : itr.second) {
                    file << value << ", ";
                }
                file << "]" << "\n";
            }
            file.close();

            return filename;
        }
        static RESULT_MAP deserialize(std::string filename) {
            RESULT_MAP result = {};
            ifstream file(filename);
            std::string str;

            while (std::getline(file, str)) {
                const char *func = str.substr(0, str.find(':')).c_str();
                std::vector<double> values = {};
                std::string val = str.substr(str.find(':') + 3, str.length() - 7);

                size_t pos = 0;
                while ((pos = val.find(", ")) != std::string::npos) {
                    values.push_back(atof(val.substr(0, pos).c_str()));
                    val.erase(0, pos + 2);
                }

               result[*func] = values;
            }

            file.close();
            return result;
        }
};

class Lab7 {
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

        std::string filename = Serializable::serialize(storage);
        storage = {};
        storage = Serializable::deserialize(filename);

        for (auto &itr : storage) {
            printf("\n%c = ", itr.first);
            for (double &value : itr.second) {
                printf("%f ", value);
            }
        }
    }
};
