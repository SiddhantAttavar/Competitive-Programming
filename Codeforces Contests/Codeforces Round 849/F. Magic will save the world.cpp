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
		int w, f;
		input(w, f);

		int n;
		input(n);

		vector<int> s(n);
		arrPut(s);

		int c = 0;
		for (int i : s) {
			c += i;
		}

		set<int> v;
		v.insert(0);
		range(i, 0, n) {
			set<int> nv;
			for (int j : v) {
				nv.insert(j + s[i]);
			}
			for (int j : nv) {
				v.insert(j);
			}
		}

		int res = 1e9;
		for (int i : v) {
			res = min(res, (int) max(ceil(i * 1.0 / w), ceil((c - i) * 1.0 / f)));
		}

		print(res);
	}
}