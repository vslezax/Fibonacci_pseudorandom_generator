#include <iostream>
#include <random>
#include <fstream>
#include <cstdint>

#include "FibonacciGenerator.h"

int main() {
    int T = 1000;
    FibonacciGenerator gen(T);
    std::cout << gen.generate(17);

    ///
    /// Checking the uniformity of number distribution
    ///
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(0,100);
    for (int i = 0; i < 5000; i++) gen.generate(10);

    int size = 500;
    double delta = 1.0 / size;
    int k[size] = {0}; // [0; 1] separate for 50 clusters
    for (int i = 0; i < gen.getZsize(); i++){
        double tmp = 0;
        int tmp_index = 0;
        while (tmp <= gen.getZ(i)){
            tmp_index++;
            tmp += delta;
        }
        k[tmp_index - 1]++;
    }

    std::ofstream file("C:\\2\\AAAAAAAA.txt");
    double tmp = 0;
    for (int i = 0; i < size; i++){
        file << tmp << " " << k[i] << std::endl;
        tmp += delta;
    }
    file.close();

    ///
    /// Test of statistical independence
    ///
    int s = 10;
    double sum = 0;
    for (int i = 0; i < T - s; i++){
        sum += gen.getZ(i) * gen.getZ(i + s);
    }
    std::cout << "R = " << 12.0 / (T - s) * sum - 3 << std::endl;

    ///
    /// Mean and D
    ///
    long double mean = 0;
    for (int i = 0; i < gen.getZsize(); i++){
        mean += gen.getZ(i);
    }
    mean /= gen.getZsize();
    std::cout << "M[X] = " << mean << std::endl;

    long double D = 0;
    for (int i = 0; i < gen.getZsize(); i++){
        D += (gen.getZ(i) - mean)*(gen.getZ(i) - mean);
    }
    D /= gen.getZsize();
    std::cout << "D = " << D << std::endl;
}
