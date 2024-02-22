#include <bits/stdc++.h>
#include <gmpxx.h>

using namespace std;

void calculate_modular_inverse(const mpz_class& dividend, const mpz_class& modulus) {
  mpz_class gcd;
  mpz_gcd(gcd.get_mpz_t(), dividend.get_mpz_t(), modulus.get_mpz_t());
  if (gcd != 1) {
    cout << "N" << endl;
  } else {

    mpz_class inverse;
    mpz_invert(inverse.get_mpz_t(), dividend.get_mpz_t(), modulus.get_mpz_t());
    cout << "Y " << inverse << endl; 
  }
}
int main(int argc, char* argv[]) {

  if (argc != 3) {
    cerr << "Error: Please provide two integers as arguments." << endl;
    return 1;
  }

  mpz_class dividend(argv[1]);
  mpz_class modulus(argv[2]);
  calculate_modular_inverse(dividend, modulus);

  return 0;
}
