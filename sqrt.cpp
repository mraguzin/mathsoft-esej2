#include <iostream>
#include <cstdint>
#include <chrono>
#include <bit>

float sqrt(float x)
{
    int32_t repr = std::bit_cast<int>(x);
    repr -= 1 << 23;
    repr >>= 1;
    repr += 1 << 29;

    return std::bit_cast<float>(repr);
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cout << "Upotreba: " << argv[0] << " x broj_iteracija" << std::endl;
        return 0;
    }

    float x = std::atof(argv[1]);
    float rez;
    float sigh = 0;
    int runs = std::atoi(argv[2]);
    auto t1 = std::chrono::steady_clock::now();
    for (int i = 0; i < runs; ++i) {
        rez += sqrt(x++);
    }

    auto t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time = t2 - t1;
    double fintime = time.count() / runs * 1e6;
    std::cout << fintime << " " << rez << std::endl;

    return 0;
}