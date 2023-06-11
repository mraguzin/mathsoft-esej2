#include <iostream>
#include <cstdint>
#include <chrono>
#include <bit>

float sqrt2(float x)
{
    float pola = 0.5f * x;
    int32_t i = std::bit_cast<int>(x);
    i = 0x5f375a86 - (i >> 1);
    float reciproc = std::bit_cast<float>(i);
    reciproc *= 1.5f - pola*reciproc*reciproc; // Newton-Raphson iteracija; moguće ponoviti više puta

    return x*reciproc;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cout << "Upotreba: " << argv[0] << " x broj_iteracija" << std::endl;
        return 0;
    }

    float x = std::atof(argv[1]);
    float rez = 0;
    float sigh = 0;
    int runs = std::atoi(argv[2]);
    auto t1 = std::chrono::steady_clock::now();
    for (int i = 0; i < runs; ++i) {
        rez += sqrt2(x++); // x++ jer je inače petlja kompletno invarijanta; *poziv* mora biti ponovljen svaku iteraciju
    }

    auto t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time = t2 - t1;
    double fintime = time.count() / runs * 1e6;
    std::cout << fintime << " " << rez << " " << std::endl;

    return 0;
}