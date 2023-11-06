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

	int n, a, b;
	input(n, a, b);

	vector<int> v(n);
	arrPut(v);

	vector<int> p(n + 1);
	p[0] = 0;
	range(i, 0, n) {
		p[i + 1] = p[i] + v[i];
	}

	int res = p[a];
	multiset<int> m;
	m.insert(0);
	range(i, a, b) {
		m.insert(p[i - a + 1]);
		res = max(res, p[i + 1] - *m.begin());
	}

	range(i, b, n) {
		m.erase(m.find(p[i - b]));
		m.insert(p[i - a + 1]);
		res = max(res, p[i + 1] - *m.begin());
	}

	print(res);
}
