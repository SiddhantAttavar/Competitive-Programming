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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

bool check(vector<int> &v, vector<int> &a) {
	if (accumulate(v.begin(), v.end(), 0ll) != a.size()) {
		return false;
	}
	int i = 0;
	for (int x : v) {
		if (accumulate(a.begin() + i, a.begin() + i + x, 0ll) <= 0) {
			return false;
		}
		i += x;
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrput(a);

		vector<int> p(n);
		p[0] = a[0];
		rep(i, 1, n) {
			p[i] = p[i - 1] + a[i];
		}

		vector<int> l, v(n, -1);
		map<int, int> m;
		rep(i, 0, n) {
			if (p[i] <= 0) {
				continue;
			}
			int j = lower_bound(l.begin(), l.end(), p[i]) - l.begin();
			if (j == l.size()) {
				l.push_back(p[i]);
			}
			else {
				l[j] = p[i];
			}
			if (j > 0) {
				v[i] = m[l[j - 1]];
			}
			m[p[i]] = i;
		}

		int u = n - 1;
		vector<int> res;
		while (u != -1 and res.size() < k) {
			res.push_back(u);
			u = v[u];
		}

		if (p[n - 1] < k or res.size() < k) {
			print("NO");
		}
		else {
			print("YES");
			reverse(res.begin(), res.end());
			for (int i = k - 1; i > 0; i--) {
				res[i] -= res[i - 1];
			}
			res[0]++;
			arrprint(res);
			assert(res.size() == k);
			assert(check(res, a));
		}
	}
}
