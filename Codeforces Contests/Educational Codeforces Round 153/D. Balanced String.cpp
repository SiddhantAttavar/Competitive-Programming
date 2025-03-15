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

	int n = s.size();

	int a = 0, b = 0;
	int x = 0, y = 0;
	range(i, 0, n) {
		if (s[i] == '0') {
			x += b;
			a++;
		}
		else {
			y += a;
			b++;
		}
	}

	vector<int> p, q;
	range(i, 0, n) {
		if (s[i] == '0') {
			p.push_back(i);
		}
		else {
			q.push_back(i);
		}
	}

	vector<int> dp(n * n);
}
