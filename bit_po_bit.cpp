#include <cstdint>
#include <iostream>
#include <chrono>

int32_t sqrt(int32_t N)
{
	int32_t op = N;
	int32_t rezultat = 0;

	int32_t jedinica = 1 << 30;
	while (jedinica > op) jedinica >>= 2;

	while (jedinica != 0) {
		if (op >= rezultat + jedinica) {
			op -= rezultat + jedinica;
			rezultat += jedinica << 1;
		}

		rezultat >>= 1;
		jedinica >>= 2;
	}

	return rezultat;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cout << "Upotreba: " << argv[0] << " N broj_iteracija" << std::endl;
        return 0;
    }

    int32_t N = std::atoi(argv[1]);
    int32_t rez;
    int runs = std::atoi(argv[2]);
    auto t1 = std::chrono::steady_clock::now();
    for (int i = 0; i < runs; ++i) {
        rez = sqrt(N);
    }

    auto t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time = t2 - t1;
    std::cout << time.count()/runs*1e6 << " " << rez << std::endl;

    return 0;
}