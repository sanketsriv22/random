#include <iostream>
#include <cmath>
using namespace std;

// using modular exponentiation
long long mod_pow(long long base, long long exp, long long mod)
{
    // using proof that f(n+1) = f(n) (mod 10^n), where f(n) = base^exp
    // identity below for memory efficiency
    // (a*b) mod(m) = [a mod(m) * b mod(m)] mod(m)
    
    long long result = 1;

    for (int i=1; i<=exp; i++)
    {
        result = (base * result) % mod;
    }

    return result;
}

// calulate power tower mod nE10
long long graham_last_digits(int digits)
{
    long long mod = pow(10, digits);
    
    // 3 up up (nth digits) mod nE10

    long long result = 3;
    for (int i = 1; i <= digits; i++)
    {
        cout << "3^" << result << " mod(" << mod << ") = ";
        result = mod_pow(3, result, mod);
        cout << result << endl;
    }
    // call mod_pow in here
    return result;
}

int main()
{
    int digits;
    
    cout << "how many digits: ";
    cin >> digits;

    // cout << "mod_pow of 3, 13 = " << mod_pow(4, 13, mod) << endl;

    cout << "last " << digits << " of grahams number: " << endl; 
    cout << graham_last_digits(digits) << endl;
    return 0;
    
}