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

	vector<vector<bool>> res(1, vector<bool>(n, false));
	range(i, 1, n + 1) {
		vector<vector<bool>> nres(res.begin(), res.end());
		nres.insert(nres.end(), res.rbegin(), res.rend());
		res = nres;
		range(j, res.size() / 2, res.size()) {
			res[j][i - 1] = true;
		}
	}

	for (vector<bool> v : res) {
		for (int i = n - 1; i >= 0; i--) {
			cout << v[i];
		}
		print("");
	}
}
