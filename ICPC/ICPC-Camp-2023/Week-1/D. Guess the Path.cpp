#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

vector<int> query(vector<int> v) {
	int x = 0;
	string s;
	for (int i : v) {
		while (x < i) {
			s += 'D';
			x++;
		}
		s += 'R';
	}
	s = s.substr(0, s.size() - 1);
	print('?', s);

	int t;
	input(t);
	vector<int> res;
	while (t--) {
		int r, c;
		input(r, c);
		res.push_back(c - 1);
	}
	return res;
}

int32_t main() {
	int m, n;
	input(m, n);

	vector<int> l(n, 0), r(n, n - 1), res(n, -1);
	while (true) {
		vector<int> mi(n, 0);
		range(i, 1, n) {
			l[i] = max(l[i - 1], l[i]);
		}
		for (int i = n - 2; i >= 0; i--) {
			r[i] = min(r[i], r[i + 1]);
		}
		range(i, 0, n) {
			mi[i] = l[i] + r[i] / 2;
		}
	}
}
