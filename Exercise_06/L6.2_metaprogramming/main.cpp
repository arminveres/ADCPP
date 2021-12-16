#include <iterator>
#include <utility>
#include <iostream>

using namespace std;

// template metaprogramming

// template gcd
template<int a, int b> struct gcd
{
    static constexpr auto value = gcd<b, a % b>::value;
};

template<int a>
struct gcd<a, 0>
{
    static constexpr auto value = a;
};

// constexpr gcd
constexpr int constgcd(int a, int b) {
    if (b == 0) return a;
    return constgcd(b, a%b);
}

// template fibonacci
template<int n>
struct fib {
    static constexpr auto value = fib<n-1>::value + fib<n-2>::value;
};

template<>
struct fib<0> {
    static constexpr auto value = 0;
};

template<>
struct fib<1> {
    static constexpr auto value = 1;
};

// constexpr fibonacci
constexpr int constfib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return constfib(n-1)+constfib(n-2);
}

int main()
{
    auto x = gcd<10,5>::value;
    cout << "template: " << x << endl;

    static_assert(constgcd(10,5)>1, "constgcd(10,5)>1");
    cout << "meta: " << constgcd(10,5) << endl;

    auto y = fib<5>::value;
    cout << "template: " << y << endl;

    static_assert(constfib(5)>1, "constfib(5)>1");
    cout << "meta: " << constfib(5) << endl;
}
