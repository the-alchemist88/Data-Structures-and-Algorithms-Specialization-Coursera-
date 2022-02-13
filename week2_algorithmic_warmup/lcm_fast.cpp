#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

uint64_t gcd_fast(uint64_t a, uint64_t b){  //euclidian algorithm
    if(b == 0)
        return a;
    else
        return gcd_fast(b,(a%b));
}

long long lcm_fast (uint64_t a, uint64_t b ) {
    return (uint64_t)(a*b)/gcd_fast(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
