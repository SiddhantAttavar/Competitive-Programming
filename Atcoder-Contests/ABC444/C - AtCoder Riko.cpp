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

bool check(vi &a, int x) {
	int l = 0, r = sz(a) - 1;
	while (r >= 0 and a[r] == x) {
		r--;
	}
	while (l < r) {
		if (a[l] + a[r] != x) {
			return false;
		}
		l++;
		r--;
	}
	return l > r;
}

int32_t main() {
	setup();

	int n;
	input(n);

	vi a(n);
	arrput(a);
	sort(all(a));

	if (check(a, a[n - 1])) {
		cout << a[n - 1] << ' ';
	}
	if (check(a, a[0] + a[n - 1])) {
		cout << a[0] + a[n - 1] << ' ';
	}
	cout << endl;
}
