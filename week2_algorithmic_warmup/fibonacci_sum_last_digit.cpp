#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

uint64_t fibonacci_sum_fast(uint64_t n) {
    n = n % 60;
    uint64_t *p=(uint64_t *)malloc((3)*sizeof(uint64_t));
    if(n==0) return 0;
    else if(n==1) return 1;
    else{
        p[0]=0;
        p[1]=1;
        uint64_t i=2;
        uint64_t sum=1;
        while(i<=n){
            p[2]=p[0]+p[1];
            sum += p[2];
            i++;
            if(i%2==1)
                p[0]=p[2];
            else p[1]=p[2];
        }
        return sum%10;
    }
    free(p);
    return 0;
}

int main() {
    uint64_t n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n)<<"\n";
//    std::cout << fibonacci_sum_naive(n)<<"\n";
}
