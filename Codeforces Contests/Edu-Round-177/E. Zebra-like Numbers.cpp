#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

map<vector<int>, int> m;
int solve(vector<int> &v, int i, int k) {
	if (k < 0) {
		return 0;
	}
	if (i == 0) {
		return k <= v[i];
	}

	vector<int> z(v.begin(), v.end());
	z.push_back(i);
	z.push_back(k);
	if (m.count(z)) {
		return m[z];
	}

	int res = solve(v, i - 1, k - v[i]);
	vector<int> w(30, 3);
	rep(j, 0, v[i]) {
		res += solve(w, i - 1, k - j);
		res += (k - j) >= 4 and (k - j - 4) % 3 == 0 and (k - j - 4) / 3 <= i - 1;
	}
	return m[z] = res;
}

int32_t main() {
	vector<int> a(30, 1);
	rep(i, 1, 30) {
		a[i] = 4 * a[i - 1] + 1;
	}

	setup(); int tc; input(tc); while (tc--) {
		int l, r, k;
		input(l, r, k);

		if (k > 240) {
			print(0);
			continue;
		}

		m.clear();

		vector<int> v(30, 0);
		for (int i = 29; i >= 0; i--) {
			v[i] = r / a[i];
			r %= a[i];
		}

		vector<int> w(30, 0);
		l--;
		for (int i = 29; i >= 0; i--) {
			w[i] = l / a[i];
			l %= a[i];
		}

		print(solve(v, 29, k) - solve(w, 29, k));
	}
}
