#ifndef FIBONACCI_PSEUDORANDOM_GENERATOR_FIBONACCIGENERATOR_H
#define FIBONACCI_PSEUDORANDOM_GENERATOR_FIBONACCIGENERATOR_H

#include <vector>

class FibonacciGenerator {
private:
    std::vector<unsigned int> x;
    std::vector<double> z;
    unsigned int m;
    unsigned int mPow;
public:
    explicit FibonacciGenerator(unsigned int m);
    unsigned int generate(unsigned int k);
    int getXsize() {return x.size();};
    unsigned int get(unsigned int index);
    double getZ(unsigned int index);
    int getZsize() {return z.size();};
    ~FibonacciGenerator() = default;
};


#endif //FIBONACCI_PSEUDORANDOM_GENERATOR_FIBONACCIGENERATOR_H
