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
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int check(vi &a) {
	int n = sz(a) / 2;
	vi x(n + 1, false);
	int l = 0, res = 0, s = 0, y = false;
	while (s < n) {
		res++;
		if (y) {
			y = false;
			s++;
			continue;
		}
		assert(l < sz(a));
		int i = a[l];
		l++;
		if (x[i]) {
			x[i] = false;
			s++;
			continue;
		}
		assert(l < sz(a));
		int j = a[l];
		l++;
		// print(i, j);
		// cout.flush();
		if (i == j) {
			s++;
			continue;
		}
		x[i] = true;
		if (x[j]) {
			x[j] = false;
			y = true;
		}
		else {
			x[j] = true;
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);
		int o = k;

		if (n == 1) {
			if (k == 1) {
				print("YES");
				print(1, 1);
			}
			else {
				print("NO");
			}
			continue;
		}

		if (k < n or k > 2 * n - 1) {
			print("NO");
			continue;
		}
		k -= n;

		print("YES");
		if (k == 0) {
			rep(i, 0, n) {
				cout << i + 1 << ' ';
				cout << i + 1 << ' ';
			}
			cout << endl;
			continue;
		}

		int l = 1;
		vi res = {1, 2};
		k--;
		while (k) {
			res.push_back(l + 2);
			res.push_back(l);
			k--;
			l++;
		}
		res.push_back(l);
		res.push_back(l + 1);
		rep(i, l + 2, n + 1) {
			res.push_back(i);
			res.push_back(i);
		}
		arrprint(res);
		// print(check(res), o);
		// cout.flush();
		assert(check(res) == o);
	}
}
