#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

bool isPrime(int x) {
	range(i, 2, sqrt(x) + 2) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	int n = 9;
	int l = 1e4;
	int MAX = l;

	vector<bool> prime(MAX, true);
	prime[0] = prime[1] = false;
	range(i, 2, MAX) {
		if (prime[i]) {
			for (int j = i + i; j < MAX; j += i) {
				prime[j] = false;
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		string s;
		input(s);

		bool flag = false;
		range(i, 0, (1 << n) - 1) {
			int x = 0;
			range(j, 0, n) {
				if (i & (1 << j)) {
					x = 10 * x + (s[j] - '0');
				}
			}

			if (x < 10) {
				continue;
			}

			if ((x < l and prime[x]) or (x >= l and isPrime(x))) {
				print(x);
				flag = true;
				break;
			}
		}

		if (!flag) {
			print(-1);
		}
	}
}
