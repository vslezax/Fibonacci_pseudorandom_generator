#include "FibonacciGenerator.h"

#include <random>
#include <iostream>

FibonacciGenerator::FibonacciGenerator(unsigned int m){
    this->m = m;
    mPow = static_cast<int>(pow(2, m));

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(0,static_cast<int>(mPow));

    for (unsigned int i = 0; i < 16; i++){
        x.emplace_back(dist(rng));
    }
}

unsigned int FibonacciGenerator::get(unsigned int index){
    if (index > x.size()) return x.back();
    return x.at(index);
}

double FibonacciGenerator::getZ(unsigned int index){
    if (index > z.size()) return z.back();
    return z.at(index);
}

unsigned int FibonacciGenerator::generate(unsigned int k){
    if (k < 16){
        k = 16;
    }
    x.emplace_back((x.back() + x.at(x.size() - k + 1)) % mPow);
    z.emplace_back((double)(x.back()) / (double)(mPow));
    return x.back();
}
