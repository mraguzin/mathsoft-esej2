#include <iostream>
#include <chrono>
#include <bit>

uint32_t sqrt32(uint32_t N)
{
    unsigned e = std::countl_zero(N) >> 1;
    unsigned m = N << (e << 1);
    unsigned a = 1 + (m >> 30);
    a = (a << 1) + (m >> 27) / a;
    a = (a << 3) + (m >> 21) / a;
    a = (a << 7) + (m >> 9) / a;
    a >>= e;

    return a*a <= N ? a : a - 1; // odredimo cjelobrojni korijen iz skoro-korijena
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
        rez += sqrt32(N++);
    }

    auto t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time = t2 - t1;
    double fintime = time.count() / runs * 1e6;
    std::cout << fintime << " " << rez << std::endl;

    return 0;
}