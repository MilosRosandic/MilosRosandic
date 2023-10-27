// Problem Statement: Find the sum of all prime numbers in a given range [L, R].

// Input:

// Two integers, L and R(1 ≤ L ≤ R ≤ 10 ^ 6)
// Output :
// A single integer representing the sum of all prime numbers in the range[L, R].

#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieve(int n) {
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;

	for (int p = 2; p * p <= n; ++p) {
		if (is_prime[p]) {
			for (int i = p * p; i <= n; i += p) {
				is_prime[i] = false;
			}
		}
	}

	return is_prime;
}

int main()
{
	int L, R;
	cin >> L >> R;

	vector<bool> is_prime = sieve(R);

	int sum = 0;
	for (int i = L; i <= R; ++i) {
		if (is_prime[i]) {
			sum += i;
		}
	}

	cout << sum << endl;

	return 0;
}