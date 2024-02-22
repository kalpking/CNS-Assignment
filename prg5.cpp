#include <iostream>
#include <gmpxx.h>

void calculatePowerMod(const mpz_class& base, const mpz_class& exponent, const mpz_class& modulo, mpz_class& result) {
    result = mpz_class(1);

    mpz_class exp;
    exp = exponent % modulo;

    mpz_powm_ui(result.get_mpz_t(), base.get_mpz_t(), exp.get_ui(), modulo.get_mpz_t());
    std::cout << result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <base> <exponent> <modulo>" << std::endl;
        return 1;
    }

    mpz_class base(argv[1]), exponent(argv[2]), modulo(argv[3]);
    mpz_class result;

    calculatePowerMod(base, exponent, modulo, result);

    return 0;
}
