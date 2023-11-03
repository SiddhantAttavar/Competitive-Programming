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

int get_sum(string s) {
	int res = 0;
	for (char c : s) {
		res += c - '0';
	}
	return res;
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<string> a(n);
	arrPut(a);

	vector<map<int, int>> v(5);
	for (string s : a) {
		v[s.size() - 1][get_sum(s)]++;
	}

	int res = 0;
	for (string s : a) {
		range(i, 1, (int) s.size() + 1) {
			string x = s.substr(0, i);
			string y = s.substr(i, s.size() - i);
			int k = get_sum(x) - get_sum(y);
			if (x.size() > y.size() and v[x.size() - y.size() - 1].count(k)) {
				res += v[x.size() - y.size() - 1][k];
			}
			// print(x, y);
			// cout.flush();
			if (x.size() < y.size() and v[y.size() - x.size() - 1].count(-k)) {
				res += v[y.size() - x.size() - 1][-k];
			}
		}
	}
	print(res);
}
