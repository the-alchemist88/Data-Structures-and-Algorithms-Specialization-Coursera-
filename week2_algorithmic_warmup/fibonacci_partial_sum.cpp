#include <iostream>
//#include <vector>
//using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }
        long long new_current = next;
        next = next + current;
        current = new_current;
    }
    return sum % 10;
}

uint64_t get_fibonacci_partial_sum_fast(uint64_t from, uint64_t to) {
    from=(from % 60);
    to=((to-from) % 60 ) + from;
    uint64_t *p=(uint64_t *)malloc((3)*sizeof(uint64_t));
    p[0]=0;
    p[1]=1;
    uint64_t i=2;
    uint64_t sum=0;
    for(uint64_t i=from; i<=to;i++)
        if(i==1)
            sum=1;
    while(i<=to){
        p[2]=(p[0]+p[1])%10;
        if(from<=i)
            sum += p[2];
        i++;
        if(i%2==1)
            p[0]=p[2];
        else 
            p[1]=p[2];
    }
    return sum%10;
    free(p);
}



int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
//    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
