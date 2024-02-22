#include <iostream>
#include <gmpxx.h>
#include <vector>

bool isPrimitiveRoot(const mpz_class& base, const mpz_class& modulo) {
    mpz_class result = 1;
    mpz_class eulerPHI = modulo - 1;
    std::vector<bool> visited(eulerPHI.get_ui() + 1, false);

    for (mpz_class i = 0; i < eulerPHI; ++i) {
        result = (result * base) % modulo;
        if (visited[result.get_ui()]) {
            return false;
        }
        visited[result.get_ui()] = true;
    }

    return true;
}

void findAndPrintPrimitiveRoots(const mpz_class& modulo) {
    std::vector<mpz_class> primitiveRoots;
    mpz_class eulerPHI = modulo - 1;

    for (mpz_class candidate = 2; candidate < modulo; ++candidate) {
        if (isPrimitiveRoot(candidate, modulo)) {
            primitiveRoots.push_back(candidate);
        }
    }

    std::cout << primitiveRoots.size() << " ";

    for (int i = 0; i < primitiveRoots.size(); ++i) {
        if (i == primitiveRoots.size() - 1) {
            std::cout << primitiveRoots[i];
        } else {
            std::cout << primitiveRoots[i] << " ";
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <modulo>" << std::endl;
        return 1;
    }

    mpz_class modulo(argv[1]);
    findAndPrintPrimitiveRoots(modulo);

    return 0;
}
