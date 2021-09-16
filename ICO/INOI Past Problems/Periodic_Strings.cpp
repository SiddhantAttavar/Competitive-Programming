#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

vector<int> memo;

int modpow(int a, int b, int m){
    long long x = 1, y = a; 
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y) % m;
        }
        y = (y * y) % m;
        b /= 2;
    }
    return x % m;
}

int solve(int n, int m) {
	if (memo[n - 1] != -1) {
		return memo[n - 1];
	}

	int res = modpow(2, n, m);
	range(i, 1, n / 2 + 1) {
		if (n % i == 0) {
			res = (res + m - solve(i, m)) % m;
		}
	}

	memo[n - 1] = res;
	return res;
}

int main() {
    setup();
    input(int, n);
    input(int, m);

    memo = vector<int>(n);
	fill(memo.begin(), memo.end(), -1);
	memo[0] = 2;

	print(solve(n, m));
}