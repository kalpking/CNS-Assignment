#include <iostream>
#include <gmpxx.h>
#include <vector>

mpz_class find_greatest_common_divisor(mpz_class a, mpz_class b) {
  if (a == 0) {
    return b;
  }
  return find_greatest_common_divisor(b % a, a);
}

mpz_class modular_inverse(mpz_class a, mpz_class m) {
  mpz_class initial_mod = m, temp, quotient;
  mpz_class x0 = 0, x1 = 1;

  if (m == 1) {
    return 0;
  }

  while (a > 1) {
    quotient = a / m;
    temp = m;
    m = a % m;
    a = temp;
    temp = x0;
    x0 = x1 - quotient * x0;
    x1 = temp;
  }

  if (x1 < 0) {
    x1 += initial_mod;
  }

  return x1;
}

int main(int argc, char *argv[]) {
  int equation_count = std::stoi(argv[1]);
  std::vector<mpz_class> coefficients(equation_count);
  std::vector<mpz_class> remainders(equation_count);
  std::vector<mpz_class> moduli(equation_count);

  mpz_class product = 1;
  mpz_class solution = 0;

  for (int i = 0; i < equation_count; ++i) {
    coefficients[i] = argv[3 * i + 2];
    remainders[i] = argv[3 * i + 3];
    moduli[i] = argv[3 * i + 4];
  }

  for (int i = 0; i < equation_count; ++i) {
    mpz_class gcd = find_greatest_common_divisor(coefficients[i], moduli[i]);
    coefficients[i] = coefficients[i] / gcd;
    remainders[i] = remainders[i] / gcd;
    moduli[i] = moduli[i] / gcd;

    mpz_class inv = modular_inverse(coefficients[i], moduli[i]);
    remainders[i] = remainders[i] * inv;
  }

  for (int i = 0; i < equation_count; i++) {
    product = product * moduli[i];
  }

  for (int i = 0; i < equation_count; i++) {
    mpz_class val = product / moduli[i];
    solution += remainders[i] * modular_inverse(val, moduli[i]) * val;
  }

  if (solution != 0) {
    std::cout << "Y " << solution % product;
  } else {
    std::cout << "N";
  }

  return 0;
}