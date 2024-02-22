#include <bits/stdc++.h>
#include <gmpxx.h>

using namespace std;

mpz_class calculate_greatest_common_divisor(mpz_class x, mpz_class y) {
  while (y != 0) {
    mpz_class temporary = y;
    y = x % y;
    x = temporary;
  }
  return x;
}

mpz_class find_common_divisor(const vector<mpz_class>& numbers) {
  if (numbers.empty()) return 0;
  mpz_class result = numbers[0];
  int size = numbers.size();

  for (size_t i = 1; i < size; i++) {
    result = calculate_greatest_common_divisor(result, numbers[i]);
  }

  return result;
}

void print_divisors(mpz_class number) {
  for (mpz_class i = 1; i <= number; ++i) {
    if (number % i == 0) {
      if (i != number) {
        cout << i << " ";
      } else {
        cout << i;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  int numberOfNumbers = atoi(argv[1]);
  vector<mpz_class> numbers;
  vector<mpz_class> values;

  for (int i = 2; i < argc; ++i) {
    mpz_class number(argv[i]);
    values.push_back(number);
    numbers.push_back(number);
  }

  mpz_class common_divisor = find_common_divisor(values);
  print_divisors(common_divisor);

  return 0;
}
