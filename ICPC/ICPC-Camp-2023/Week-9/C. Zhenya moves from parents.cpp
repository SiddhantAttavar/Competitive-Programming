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

	int n;
	input(n);

	multiset<pair<int, int>> v;
	int res = 0;
	range(i, 0, n) {
		int c;
		string k, l;
		input(c, k, l);
		int d = 10 * (k[0] - '0') + (k[1] - '0');
		int M = 10 * (k[3] - '0') + (k[4] - '0');
		int h = 10 * (l[0] - '0') + (l[1] - '0');
		int m = 10 * (l[3] - '0') + (l[4] - '0');

		int t = 100 * (100 * (100 * M + d) + h) + m;

		while (c >= 0) {
			multiset<pair<int, int>>::iterator j = v.lower_bound({t, c});
			if (j == v.end()) {
				break;
			}

			int x = (*j).second;
			if (x > 0) {
				break;
			}

			v.erase(j);
			res -= x;
			c += x;
			if (c < 0) {
				t = (*j).first;
				break;
			}
		}

		while (c < 0) {
			multiset<pair<int, int>>::iterator j = v.lower_bound({t, c});
			if (j == v.begin()) {
				break;
			}
			j--;

			int x = (*j).second;
			if (x < 0) {
				break;
			}

			v.erase(j);
			c += x;
			if (c > 0) {
				t = (*j).first;
				break;
			}
		}

		if (c < 0) {
			res += c;
		}
		if (c != 0) {
			v.insert({t, c});
		}

		print(res);
		// for (pair<int, int> j : v) {
		// 	print(j.first, j.second);
		// }
	}
}
