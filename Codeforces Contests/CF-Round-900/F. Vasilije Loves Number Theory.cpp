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

int32_t main() {
	setup();

	int MAX_N = 1e6;
	vector<int> seive(MAX_N + 1), d(MAX_N + 1, 2), l(MAX_N + 1, 1);
	seive[1] = 1;
	d[1] = 1;
	range(i, 4, MAX_N + 1) {
		seive[i] = 2;
	}

	range(i, 1, MAX_N + 1) {
		seive[i] = i;
	}

	range(i, 3, MAX_N + 1) {
		print(i);
		cout.flush();
		if (seive[i] == i) {
			for (int j = i * i; j <= MAX_N; j += i) {
				if (seive[j] == j) {
					seive[j] = i;
					if (l[j / i] == j / i / i) {
						l[j] = l[j / i];
					}
					else {
						l[j] = j / i;
					}
				}
			}
		}
		else {
			d[i] = d[i / seive[i]] + d[l[i]];
		}
		print(i);
		cout.flush();
	}

	vector<bool> b(MAX_N + 1, false);
	range(i, 1, MAX_N + 1) {
		b[d[i]] = true;
	}

	int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		int m = n;

		while (q--) {
			int k;
			input(k);

			if (k == 1) {
				int x;
				input(x);

				n *= x;

				print(b[n + 1 - d[n]] ? "YES" : "NO");
			}
			else {
				n = m;
			}
		}
	}
}
