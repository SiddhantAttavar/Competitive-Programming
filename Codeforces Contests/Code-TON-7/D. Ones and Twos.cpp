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
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vector<int> a(n);
		arrPut(a);

		int s = 0;
		for (int i : a) {
			s += i;
		}


		int l = -1, r = n;
		while (l < n - 2 and a[l + 1] == 2) {
			l++;
		}
		while (r > 0 and a[r - 1] == 2) {
			r--;
		}

		while (q--) {
			int o;
			input(o);

			if (o == 1) {
				int x;
				input(x);

				if (x > s) {
					print("NO");
					continue;
				}

				if (x % 2 == s % 2) {
					print("YES");
					continue;
				}

				if (max(s - 2 * (l + 1), s - 2 * (n - r)) < x) {
					print("NO");
				}
				else {
					print("YES");
				}
			}
			else {
				int i, v;
				input(i, v);
				i--;

				s -= a[i];
				a[i] = v;
				s += a[i];

				if (v == 2) {
					if (l == i - 1) {
						l = i;
					}
					if (r == i + 1) {
						r = i;
					}
				}
				else {
					l = min(l, i - 1);
					r = max(r, i + 1);
				}
			}
		}
	}
}
