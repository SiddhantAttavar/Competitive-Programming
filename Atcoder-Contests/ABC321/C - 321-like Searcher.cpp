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

	int k;
	input(k);

	vector<int> v;
	range(i, 0, (1 << 10)) {
		int x = 0;
		for (int j = 9; j >= 0; j--) {
			if (i & (1 << j)) {
				x *= 10;
				x += j;
			}
		}
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	// arrPrint(v);

	print(v[k + 1]);
}
