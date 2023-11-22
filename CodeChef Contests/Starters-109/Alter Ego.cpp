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

		vector<int> o, e;
		for (int i : a) {
			if (i % 2 == 1) {
				o.push_back(i);
			}
			else {
				e.push_back(i);
			}
		}

		if (o.size() % 2 == 1 or e.size() % 2 == 1) {
			print(-1);
			continue;
		}

		sort(o.begin(), o.end());
		sort(e.begin(), e.end());

		vector<int> v;
		for (int i = 0; i < (int) e.size() / 2; i++) {
			v.push_back(e[i]);
			v.push_back(e[e.size() - i - 1]);
		}
		for (int i = 0; i < (int) o.size() / 2; i++) {
			v.push_back(o[i]);
			v.push_back(o[o.size() - i - 1]);
		}

		vector<int> b, c;
		for (int i = 0; i < (int) v.size(); i += 2) {
			b.push_back((v[i] + v[i + 1]) / 2);
			c.push_back(abs(v[i] - v[i + 1]) / 2);
		}
		for (int i : c) {
			b.push_back(i);
		}
		arrPrint(b);
	}
}
