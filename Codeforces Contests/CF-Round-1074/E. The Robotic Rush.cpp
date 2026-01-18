#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		vi a(n), b(m);
		arrput(a);
		arrput(b);

		sort(all(a));
		sort(all(b));

		vi l(n, -1e18), r(n, 1e18);
		int res = n;
		vector<bool> v(n, true);
		rep(i, 0, n) {
			int j = lower_bound(all(b), a[i]) - b.begin();
			if (j < m) {
				if (b[j] == a[i]) {
					res--;
					v[i] = false;
					continue;
				}
				r[i] = b[j] - a[i];
			}
			if (j > 0) {
				l[i] = b[j - 1] - a[i];
			}
		}

		map<int, vi> f;
		rep(i, 0, n) {
			f[l[i]].push_back(i);
			f[r[i]].push_back(i);
		}

		string s;
		input(s);

		int x = 0;
		set<int> t;
		for (char c : s) {
			x = c == 'L' ? x - 1 : x + 1;
			if (t.count(x)) {
				cout << res << ' ';
				continue;
			}
			for (int i : f[x]) {
				res -= v[i];
				v[i] = false;
			}
			t.insert(x);
			cout << res << ' ';
		}
		cout << endl;
	}
}
