#include <iostream>
#include <gmpxx.h>

void calculate_element_order(const mpz_class& base, const mpz_class& modulus) {
  mpz_class element_order = 1;
  mpz_class current_power = base;

  while (current_power != 1) {
    current_power = (current_power * base) % modulus;
    element_order += 1;
  }

  std::cout << element_order;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <base> <modulus>" << std::endl;
    return 1;
  }

  mpz_class base(argv[1]);
  mpz_class modulus(argv[2]);

  calculate_element_order(base, modulus);

  return 0;
}