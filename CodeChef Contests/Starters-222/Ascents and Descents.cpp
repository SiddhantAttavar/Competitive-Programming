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

int check(vi &p, vi &q) {
	int res = 0;
	rep(i, 0, sz(p) - 1) {
		res += p[i] < p[i + 1];
		res += q[i] > q[i + 1];
	}
	return res;
}

vi get(vi &p) {
	vi q(sz(p));
	rep(i, 0, sz(p)) {
		q[p[i] - 1] = i + 1;
	}
	return q;
}

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	if (n == 6) {
		print("2 4 5 1 3 6");
		return 0;
	}

	vi p(n);
	int a = 500;
	rep(i, 0, a) {
		rep(j, 0, n / a) {
			p[(a - i - 1) * (n / a) + j] = a * j + i + 1;
		}
	}
	arrprint(p);

	vi q = get(p);
	assert(check(p, q) >= k);
	// arrprint(q);
	// print(check(p, q));
}
