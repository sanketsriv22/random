#include <iostream>
#include <cmath>
using namespace std;

// euler's totient function
long long euler_phi(long long n) {
    long long result = n;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// modular exponentiation
long long mod_exp(long long base, long long exp, long long m) {
    if (m == 1) return 0;
    long long result = 1;
    base = base % m;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % m;
        exp = exp >> 1;
        base = (base * base) % m;
    }
    return result;
}

// recursive power tower calc using Euler's theorem
long long power_tower(int height, long long m) {
    if (m == 1) return 0;
    if (height == 1) return 3 % m;
    
    long long phi = euler_phi(m);
    
    // recursive call
    long long exp_mod_phi = power_tower(height - 1, phi);
    
    long long actual_exp = phi + exp_mod_phi;
    
    return mod_exp(3, actual_exp, m);
}

int main() {
    const long long MOD = 10e5;
    
    cout << "Computing the last 5 digits of Graham's number" << endl;
    cout << "This uses the power tower structure: G(64)" << endl;
    
    int tower_height = 64; // Representing G(64) in the Graham sequence
    
    long long last_digits = power_tower(tower_height, MOD);
    
    cout << "The last 15 digits of Graham's number are: ";
    cout.width(5);
    cout.fill('0');
    cout << last_digits << endl;
    
    return 0;
}