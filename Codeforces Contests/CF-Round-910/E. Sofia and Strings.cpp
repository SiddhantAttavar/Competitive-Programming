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
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		string s, t;
		input(s, t);

		vector<vector<int>> v;
		v.push_back({t[0] - 'a'});
		range(i, 1, m) {
			if (t[i] < t[i - 1]) {
				v.push_back({});
			}
			v.back().push_back(t[i] - 'a');
		}

		vector<map<int, int>> l;
		for (vector<int> a : v) {
			l.push_back(map<int, int>());
			for (int i : a) {
				l.back()[i]++;
			}
		}

		int j = 0, x = l[0].size(), c = 0;
		range(i, 0ll, n) {
			if (!l[j].count(s[i] - 'a')) {
				continue;
			}

			l[j][s[i] - 'a']--;
			if (l[j][s[i] - 'a'] == 0) {
				l[j].erase(s[i] - 'a');
			}
			x--;

			if (x > 0) {
				continue;
			}

			vector<int> a;
			range(k, c, i + 1) {
				a.push_back(s[k] - 'a');
			}
			sort(a.begin(), a.end());
			int nc = 0;
			for (int k : v[j]) {
				nc = max(nc, upper_bound(a.begin(), a.end(), k) - a.begin() + c);
			}

			i = nc - 1;
			c = nc;
			j++;
			if (j == (int) l.size()) {
				break;
			}
			x = l[j].size();
		}

		if (j == (int) l.size()) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
