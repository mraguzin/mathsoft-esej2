#include <bit>
#include <iostream>
#include <chrono>

int nsqrt(unsigned int N)
{
    if (N < 4)
        return 1;

    int bitova = sizeof(int)*8 - std::countl_zero(N);
    int e = (bitova - 3) >> 2;
    int b = nsqrt(N >> ((e << 1)+2));

    return (b << e) + (N >> e+2) / b;
}

int isqrt(unsigned int N)
{
    int skoro = nsqrt(N);
    return skoro*skoro <= N ? skoro : skoro - 1;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cout << "Upotreba: " << argv[0] << " N broj_iteracija" << std::endl;
        return 0;
    }

    int32_t N = std::atoi(argv[1]);
    int32_t rez;
    int sigh = 0;
    int runs = std::atoi(argv[2]);
    auto t1 = std::chrono::steady_clock::now();
    for (int i = 0; i < runs; ++i) {
        rez += isqrt(N++);
    }

    auto t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time = t2 - t1;
    double fintime = time.count() / runs * 1e6;
    std::cout << fintime << " " << rez << std::endl;

    return 0;
}