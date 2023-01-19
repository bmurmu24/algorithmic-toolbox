#include <iostream>

int get_fibonacci_last_digit(long long n) {
    int previous = 0;
    int current = 1;

    for (long long i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;
}

int main() {
    long long n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
}
