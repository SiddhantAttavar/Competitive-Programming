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
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<int> pref(n + 1, 0);
		range(i, 0, n) {
			pref[i + 1] = pref[i] ^ a[i];
		}

		string s;
		input(s);

		vector<bool> v(n);
		range(i, 0, n) {
			v[i] = s[i] == '1';
		}

		int q;
		input(q);

		int x = 0, y = 0;
		range(i, 0, n) {
			if (v[i]) {
				y ^= a[i];
			}
			else {
				x ^= a[i];
			}
		}

		while (q--) {
			int t;
			input(t);

			if (t == 1) {
				int l, r;
				input(l, r);

				x ^= pref[r] ^ pref[l - 1];
				y ^= pref[r] ^ pref[l - 1];
			}
			else {
				int g;
				input(g);

				if (g) {
					print(y);
				}
				else {
					print(x);
				}
			}
		}
	}
}
