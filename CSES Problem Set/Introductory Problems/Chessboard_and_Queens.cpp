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

	int n = 8;

	vector<string> v(n);
	arrPut(v);

	vector<int> a(n);
	range(i, 0, n) {
		a[i] = i;
	}

	int res = 0;
	do {
		bool flag = true;

		set<int> x, y;
		range(i, 0, n) {
			if (v[i][a[i]] == '*') {
				flag = false;
				break;
			}

			if (x.count(i + a[i]) or y.count(i - a[i])) {
				flag = false;
				break;
			}
			x.insert(i + a[i]);
			y.insert(i - a[i]);
		}

		res += flag;

	} while (next_permutation(a.begin(), a.end()));

	print(res);
}
