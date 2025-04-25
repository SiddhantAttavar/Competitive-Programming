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

int n;
vector<int> a;
vector<int> s;

void update(int i, int x) {
	s[i += n] += x;
	for (i /= 2; i; i /= 2) {
		s[i] = s[i * 2] + s[i * 2 + 1];
	}
}

int query(int l, int r) {
	int a = 0, b = 0;
	for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
		if (l & 1) {
			a += s[l++];
		}
		if (r & 1) {
			b += s[--r];
		}
	}
	return a + b;
}

int solve(int x, int i) {
	int res = x;
	while (i--) {
		int c = res;
		res = 0;
		while (c) {
			res += c % 10;
			c /= 10;
		}

		if (res < 10) {
			return res;
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int q;
		input(n, q);

		a.clear();
		a.resize(n);
		arrPut(a);

		s.clear();
		s.resize(4 * n);

		while (q--) {
			int o;
			input(o);

			if (o == 1) {
				int l, r;
				input(l, r);
				update(l, 1);
				update(r + 1, -1);
			}
			else {
				int i;
				input(i);
				print(solve(a[i - 1], query(1, i)));
			}
		}
	}
}
