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

int check(int n, string s, string b) {
	int res = 0;
	int c = 0;
	range(i, 0, n) {
		if (s[i] != b[i]) {
			res += c * (c + 1) / 2;
			c = 0;
		}
		else {
			c++;
		}
	}
	res += c * (c + 1) / 2;
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);
		string a, b;
		input(a, b);

		set<char> d;
		for (char c : a) {
			d.insert(c);
		}
		vector<char> l;
		for (char c : d) {
			l.push_back(c);
		}

		int res = 0;

		range(i, 0, (1 << l.size())) {
			int c = 0;
			set<char> f;
			range(j, 0, l.size()) {
				if ((1 << j) & i) {
					c++;
					f.insert(l[j]);
				}
			}
			if (c <= k) {
				string s(a);
				range(j, 0, n) {
					if (f.count(a[j])) {
						s[j] = b[j];
					}
				}
				res = max(res, check(n, s, b));
			}
		}

		print(res);
	}
}
