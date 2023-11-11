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

	string s;
	input(s);

	vector<char> res;
	for (char c : s) {
		res.push_back(c);
		if (res.size() >= 3 and res[res.size() - 1] == 'C' and res[res.size() - 2] == 'B' and res[res.size() - 3] == 'A') {
			res.pop_back();
			res.pop_back();
			res.pop_back();
		}
		// arrPrint(res);
		// if (res.size() >= 3) {
		// 	print(res[-3], res[-2], res[-1]);
		// }
	}

	string t(res.begin(), res.end());
	print(t);
}
