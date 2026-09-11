#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 998244353;
const int N = 1e5;
vi fact(N + 1, 1);

int mpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int mdiv(int a, int b) {
	return a * mpow(b, MOD - 2) % MOD;
}

int b(int x) {
	return x * (x - 1) / 2;
}

int a(int x) {
	return b(x / 2) + b((x + 1) / 2);
}

int f(int x, int k) {
	return (x % k) * a(x / k + 1) + (k - x % k) * a(x / k);
}

int g(int x) {
	return b((x + 1) / 2) + b(x / 2);
}

// int get(int x, int n, int k) {
// 	int res = mdiv(fact[k], fact[x % k] * fact[k - x % k] % MOD);
// 	if ((n - x) % 2) {
// 		res = res * 2 % MOD;
// 	}
// 	return res;
// }

// pii brute(int n, int k) {
// 	int res = 2e18, z = 0;
// 	rep(x, k - 1, n - 1) {
// 		int s = f(x, k - 1) + g(n - x);
// 		if (s < res) {
// 			res = s;
// 			z = get(x, n, k - 1);
// 		}
// 		else if (s == res) {
// 			z = (z + get(x, n, k - 1)) % MOD;
// 		}
// 	}
// 	return {res, z};
// }

int get(int x, int a, int b, int c) {
	if (x == 0 and a > 0) {
		return 0;
	}
	// cout << x << ' ' << a << ' ' << b << ' ' << c << endl;

	int res = 0, k = a + b + c;
	if (x > 1 and a > 0) {
		res = (res + mdiv(fact[k - 1], fact[a - 1] * fact[b] % MOD * fact[c] % MOD) * (x % 2 + 1)) % MOD;
	}
	if (x + 1 > 1 and b > 0) {
		res = (res + mdiv(fact[k - 1], fact[a] * fact[b - 1] % MOD * fact[c] % MOD) * ((x + 1) % 2 + 1)) % MOD;
	}
	if (x + 2 > 1 and c > 0) {
		res = (res + mdiv(fact[k - 1], fact[a] * fact[b] % MOD * fact[c - 1] % MOD) * ((x + 2) % 2 + 1)) % MOD;
	}
	return res;
}

int cmb(int n, int k) {
	return mdiv(fact[n], fact[k] * fact[n - k] % MOD);
}

void solve() {
	int n, k;
	cin >> n >> k;

	int res = f(n, k);

	int x = n / k;
	int a = k - n % k, b = n % k;
	
	int z = 0;
	if (x % 2 == 1) {
		int c = 0;
		while (a >= 0) {
			z = (z + get(x - 1, c, a, b)) % MOD;
			a -= 2;
			c++;
			b++;
		}
	}
	else {
		int c = 0;
		while (b >= 0) {
			z = (z + get(x, a, b, c)) % MOD;
			b -= 2;
			a++;
			c++;
		}
	}
	cout << res << ' ' << z << endl;
}

signed main() {
	rep(i, 2, N + 1) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
