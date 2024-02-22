#include <bits/stdc++.h>
#include <gmpxx.h>

using namespace std;

mpz_class gcd(mpz_class a, mpz_class b) {
  mpz_class temp;
  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

mpz_class modPow(mpz_class base, mpz_class exponent, const mpz_class& modulus) {
  mpz_class result;
  mpz_powm(result.get_mpz_t(), base.get_mpz_t(), exponent.get_mpz_t(), modulus.get_mpz_t());
  return result;
}

mpz_class findFactor(mpz_class n) {
  if (n % 2 == 0) return 2;
  mpz_class b = rand() % n + 1;
  mpz_class x = rand() % n + 1;
  mpz_class y = x;
  mpz_class a = 1;

  while (a == 1) {
    x = (modPow(x, 2, n) + b + n) % n;
    y = (modPow(y, 2, n) + b + n) % n;
    y = (modPow(y, 2, n) + b + n) % n;
    a = gcd(abs(x - y), n);
    if (a == n) return findFactor(n);
  }
  return a;
}

void factor(mpz_class n, vector<mpz_class>& factors) {
  if (n == 1) return;
  if (mpz_probab_prime_p(n.get_mpz_t(), 25) > 0) {
    factors.push_back(n);
    return;
  }
  mpz_class divisor = findFactor(n);
  factor(divisor, factors);
  factor(n / divisor, factors);
}

int main(int argc, char* argv[]) {
  string inputString(argv[1]);
  mpz_class input(inputString);

  srand(time(0));

  vector<mpz_class> factorList;
  factor(input, factorList);

  int numFactors = factorList.size();

  for (int i = 0; i < numFactors; i++) {
    if (i == numFactors - 1) {
      cout << factorList[i];
    } else {
      cout << factorList[i] << " ";
    }
  }

  return 0;
}
