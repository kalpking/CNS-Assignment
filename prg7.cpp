#include <bits/stdc++.h>
#include <gmpxx.h>

using namespace std;

mpz_class extended_euclidean(const mpz_class& a, const mpz_class& b, mpz_class& x, mpz_class& y) {
  if (b == 0) {
    y = 0;
    x = 1;
    return a;
  } else {
    mpz_class x1, y1;
    mpz_class gcd = extended_euclidean(b, a % b, x1, y1);
    y = x1 - (a / b) * y1;
    x = y1;
    return gcd;
  }
}

void find_congruences(const mpz_class& a, const mpz_class& b, const mpz_class& m) {
  mpz_class x, y;
  mpz_class gcd = extended_euclidean(a, m, x, y);

  if (b % gcd != 0) {
    cout << "N" << endl; 
    return;
  }

  cout << "Y ";
  cout << gcd << " "; 
  mpz_class x0 = (x * (b / gcd)) % m;
  if (x0 < 0) x0 += m;
  for (mpz_class i = 0; i < gcd; i++) {
    mpz_class solution = (x0 + i * (m / gcd)) % m;
    if (i == gcd - 1) {
      cout << solution << endl;
    } else {
      cout << solution << " ";
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    cerr << "Error: Please provide three integers as arguments." << endl;
    return 1;
  }

  mpz_class a(argv[1]);
  mpz_class b(argv[2]);
  mpz_class m(argv[3]);

  find_congruences(a, b, m);

  return 0;
}
