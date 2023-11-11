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

set<int> get_dig(int x) {
	set<int> res;
	while (x) {
		res.insert(x % 10);
		x /= 10;
	}
	return res;
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> d(n);
	arrPut(d);

	int res = 0;
	range(i, 1, n + 1) {
		range(j, 1, d[i - 1] + 1) {
			set<int> a = get_dig(i);
			set<int> b = get_dig(j);

			if (a.size() == 1 and b.size() == 1 and a == b) {
				res++;
				// print(i, j);
			}
		}
	}

	print(res);
}
