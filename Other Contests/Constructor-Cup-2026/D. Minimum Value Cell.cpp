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

int get(int x, vi &a) {
	int i = lower_bound(all(a), x) - a.begin();
	if (i == 0) {
		return a[i] - x;
	}
	if (i == sz(a)) {
		return x - a[i - 1];
	}
	return min(a[i] - x, x - a[i - 1]);
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vi a(n), b(n);
	arrput(a);
	arrput(b);

	vi s = a, t = b;
	sort(all(s));
	sort(all(t));

	vi x(q), y(q);
	arrput(x);
	arrput(y);

	rep(i, 0, q) {
		print(min(get(a[x[i] - 1], t), get(b[y[i] - 1], s)));
	}
}
