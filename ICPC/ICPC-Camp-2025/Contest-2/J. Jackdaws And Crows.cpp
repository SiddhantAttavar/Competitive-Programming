#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int solve(vector<int> &s, int c, int r, bool flag) {
	int n = s.size();
	vector<int> v(n);
	rep(i, 0, n) {
		v[i] = abs(s[i]);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	map<int, vector<int>> l;
	rep(i, 0, n) {
		l[abs(s[i])].push_back(i);
	}
	for (auto [k, v] : l) {
		reverse(l[k].begin(), l[k].end());
	}

	int res = 0;
	bool q = flag;
	rep(j, 0, n) {
		if (s[j] == 0 or q == (s[j] < 0)) {
			res += r;
		}
		else {
			q = !q;
		}
	}
	set<int> p;
	Tree<int> o;
	vector<bool> b(n, false);
	int y = 0;
	for (int i : v) {
		res = min(res, (i + 1) * c + y * r);
		// cout << i << ' ' << y << ' ' << (i + 1) * c + y * r << endl;

		for (int j : l[i]) {
			p.insert(j);
			if (s[j] != 0 and (j + flag + o.order_of_key(j)) % 2 == (s[j] < 0)) {
				b[j] = false;
				continue;
			}
			// cout << j << endl;
			b[j] = true;
			o.insert(j);
			y++;
			set<int>::iterator q = p.upper_bound(j);
			if (q == p.end()) {
				continue;
			}
			if (b[*q]) {
				o.erase(*q);
				b[*q] = false;
				y--;
			}
			else {
				o.insert(*q);
				b[*q] = true;
				y++;
			}
		}
	}
	// cout << res << endl;
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c ,r;
	cin >> n >> c >> r;

	vector<int> s(n);
	rep(i, 0, n) {
		cin >> s[i];
	}

	cout << min(solve(s, c, r, true), solve(s, c, r, false)) << endl;
}
