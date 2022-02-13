#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

uint64_t get_fibonacci_last_digit_fast(int n) {
    uint64_t *p=(uint64_t *)malloc((n+1)*sizeof(uint64_t));
    if(n==0) return 0;
    else if(n==1) return 1;
    else{ 
        p[0]=0;
        p[1]=1;
        for(int i=2; i<=n ; ++i)
            p[i]=(p[i-1]+p[i-2])%10;
        return p[n];
    }
    free(p);
}
int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }


