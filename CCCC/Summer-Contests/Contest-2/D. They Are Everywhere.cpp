#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n;
	input(n);

	string s;
	input(s);

	vector<int> v(n);
	rep(i, 0, n) {
		if (islower(s[i])) {
			v[i] = s[i] - 'a';
		}
		else {
			v[i] = s[i] - 'A' + 26;
		}
	}

	set<int> m(s.begin(), s.end());
	int k = m.size();

	if (k == 1) {
		print(1);
		return 0;
	}

	vector<int> a(52, 0);
	int x = 1;
	a[v[0]] = 1;
	int l = 0;
	int res = n;
	rep(i, 1, n) {
		a[v[i]]++;
		if (a[v[i]] == 1) {
			x++;
		}

		while (a[v[l]] > 1) {
			a[v[l]]--;
			l++;
		}

		if (x == k) {
			res = min(res, i - l + 1);
		}
	}
	print(res);
}
