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
#define int unsigned long long

vector<int> get_digits(int n) {
	if (n == 0) {
		return {0};
	}

	vector<int> res;
	while (n) {
		res.push_back(n % 10);
		n /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int p, q;
		input(p, q);

		int g = __gcd(p, q);
		int a = p / g, b = q / g;

		vector<int> x = get_digits(p);
		vector<int> y = get_digits(q);

		if (p == 0) {
			int k = 10;
			for (int i : y) {
				if (i != 0) {
					k = min(k, i);
				}
			}
			print(0, k);
			continue;
		}

		int res = -1;
		int m;

		range(i, 1, (1 << x.size())) {
			vector<int> d;
			int t = 0;
			range(j, 0, (int) x.size()) {
				if (i & (1 << j)) {
					t = (10 * t + x[j]);
				}
				else {
					d.push_back(x[j]);
				}
			}
			sort(d.begin(), d.end());

			if (t == 0) {
				continue;
			}

			if (t % a != 0) {
				continue;
			}

			int k = t / a;

			vector<int> z = get_digits(k * b);
			int w = d.size();
			int e = y.size() - z.size();
			// if (w < e) {
			// 	continue;
			// }

			reverse(z.begin(), z.end());
			range(j, 0, (int) w - e) {
				z.push_back(0);
			}
			reverse(z.begin(), z.end());

			int j = 0;
			vector<int> f;
			range(l, 0, (int) y.size()) {
				if (j < (int) z.size() and z[j] == y[l]) {
					j++;
				}
				else {
					f.push_back(y[l]);
				}
			}
			sort(f.begin(), f.end());

			if (j != (int) z.size()) {
				continue;
			}

			bool flag = true;
			range(l, 0, (int) d.size()) {
				if (d[l] != f[l]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				if (res == -1 or (k * a) < m) {
					res = k;
					m = k * a;
				}
			}
		}

		print(res * a, res * b);
	}
}
