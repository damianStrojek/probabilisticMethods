#include <iostream>
#include <time.h>
#include <vector>

void task1(int n) {
    srand(time(NULL));
    std::cout << "TASK 1:\n";
    std::vector<int> values, res;
    for (int i = 0; i < 40; i++) {
        values.push_back(1);
        if (i < 25) {
            values.push_back(3);
            if (i < 20) {
                values.push_back(0);
                if (i < 15) {
                    values.push_back(2);
                    if (i < 4) res.push_back(0);
                }
            }
        }
    }
    int index;
    for (int i = 0; i < n; i++) {
        index = rand() % 100;
        res[values[index]]++;
    }
    for (int i = 0; i < 4; i++) std::cout << "Liczba " << i << ": " << res[i] << "\n";
};

void task2(int n) {
    srand(time(NULL));
    std::cout << "\n\n\nTASK 2:\n";
    int index;
    double temp;
    std::vector<int> sets;
    std::vector<double> res;

    for (int i = 0; i < 10; i++) sets.push_back(0);
    for (int i = 0; i < n; i++) {
        temp = (double)rand() / RAND_MAX;
        res.push_back(temp * 100 + 50);
        index = ((int)res[i] - 50) / 10;
        if (index == 10) index--;
        sets[index]++;
    }
    for (int i = 0; i < 10; i++) std::cout << "Liczba " << i << ": " << sets[i] << "\n";
};

int main() {
    std::cout << "Input number of samples (100000 in task): ";
    int temp;
    std::cin >> temp;
    task1(temp);
    task2(temp);

    return 0;
};
