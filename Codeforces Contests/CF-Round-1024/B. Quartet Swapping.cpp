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

bool count(vector<int> &a) {
	ordered_set o;
	int res = 0;
	for (int i : a) {
		res ^= o.size() - o.order_of_key(i);
		o.insert(i);
	}
	return res & 1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		vector<int> x, y;
		for (int i = 0; i < n; i += 2) {
			x.push_back(a[i]);
		}
		for (int i = 1; i < n; i += 2) {
			y.push_back(a[i]);
		}
		bool flag = count(x) ^ count(y);
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());

		for (int i = 0; i < n; i += 2) {
			a[i] = x[i / 2];
		}
		for (int i = 1; i < n; i += 2) {
			a[i] = y[i / 2];
		}
		if (flag) {
			swap(a[n - 1], a[n - 3]);
		}
		arrprint(a);
	}
}
