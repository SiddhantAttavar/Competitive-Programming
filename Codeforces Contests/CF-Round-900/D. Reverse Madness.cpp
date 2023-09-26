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
		int n, k;
		input(n, k);

		string s;
		input(s);

		vector<int> l(k);
		arrPut(l);
		vector<int> r(k);
		arrPut(r);
		range(i, 0, k) {
			l[i]--;
			r[i]--;
		}

		int q;
		input(q);
		vector<int> x(q);
		arrPut(x);
		range(i, 0, q) {
			x[i]--;
		}
		sort(x.begin(), x.end());

		vector<vector<pair<int, int>>> v(k);
		int j = 0;
		for (int i : x) {
			while (i > r[j]) {
				j++;
			}

			v[j].push_back({
				min(i, r[j] + l[j] - i),
				max(i, r[j] + l[j] - i),
			});
		}

		range(i, 0, k) {
			sort(v[i].begin(), v[i].end());
		}
		// for (pair<int, int> p : v) {
		// 	print(p.first, p.second);
		// }

		int p = 0, t = v[0].size() - 1;
		j = 0;
		vector<int> st;
		vector<bool> b(n, false);
		range(i, 0, n) {
			if (i > r[j]) {
				j++;
				p = 0;
				t = v[j].size() - 1;
			}

			while (t >= 0 and i == v[j][t].second + 1) {
				t--;
			}
			while (p < (int) v[j].size() and i == v[j][p].first) {
				p++;
			}
			b[i] = (p - (v[j].size() - t - 1)) % 2 == 1;
		}

		vector<char> res(n);
		j = 0;
		range(i, 0, n) {
			if (i > r[j]) {
				j++;
			}
			if (b[i]) {
				res[r[j] + l[j] - i] = s[i];
			}
			else {
				res[i] = s[i];
			}
		}

		string ans(res.begin(), res.end());
		print(ans);
	}
}
