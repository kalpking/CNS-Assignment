#include <bits/stdc++.h>
#include <gmpxx.h>

using namespace std;

mpz_class gcd(const mpz_class& a, const mpz_class& b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}

mpz_class computeEulerTotient(const mpz_class& n) {

  mpz_class phi = 0;
  for (mpz_class i = 1; i < n; i++) {

    if (gcd(i, n) == 1) {
      phi++;
    }
  }

  return phi;
}

int main(int argc, char* argv[]) {
  mpz_class n(argv[1]);
  mpz_class phi = computeEulerTotient(n);

  cout << phi << endl;

  return 0;
}
