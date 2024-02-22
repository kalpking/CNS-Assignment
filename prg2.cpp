#include <bits/stdc++.h>
#include <gmpxx.h>

using namespace std;

tuple<mpz_class, mpz_class, mpz_class> extended_euclidean_algorithm(const mpz_class& a, const mpz_class& b) {
  if (b == 0) {
    return make_tuple(a, 1, 0);
  }

  mpz_class greatest_common_divisor, x1, y1;
  tie(greatest_common_divisor, x1, y1) = extended_euclidean_algorithm(b, a % b);

  mpz_class y2 = x1 - (a / b) * y1;
  mpz_class x2 = y1;

  return make_tuple(greatest_common_divisor, x2, y2);
}

int main(int argc, char* argv[]) {
  mpz_class a(argv[1]);
  mpz_class b(argv[2]);

  mpz_class greatest_common_divisor, x1, y1;
  tie(greatest_common_divisor, x1, y1) = extended_euclidean_algorithm(a, b);

  cout << x1 << " " << y1 << endl;
  return 0;
}
