#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

uint64_t get_pisano_period(uint64_t m) {
    uint64_t a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1)
            return i + 1;
    }
    return 0;
}

uint64_t get_fibonacci_huge_fast(uint64_t n, uint64_t m) {
    n = n % get_pisano_period(m);
    uint64_t *p=(uint64_t *)malloc((n+1)*sizeof(uint64_t));
    if(n==0) return 0;
    else if(n==1) return 1;
    else{ 
        p[0]=0;
        p[1]=1;
        for(int i=2; i<=n ; ++i)
            p[i]=(p[i-1]+p[i-2])%m;
        return p[n]%m;
    }
    free(p);
}

int main() {
    uint64_t n=0;
    uint64_t m=0;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m);
}
