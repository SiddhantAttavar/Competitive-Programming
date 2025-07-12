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

bool check(int x, int a) {
	vector<int> v;
	// print(x);
	while (x) {
		v.push_back(x % a);
		x /= a;
	}
	// arrprint(v);
	vector<int> w(v.begin(), v.end());
	reverse(v.begin(), v.end());
	return v == w;
}

int32_t main() {
	setup();

	int a, n;
	input(a, n);

	int res = 0;
	rep(i, 1, 10) {
		if (i <= n and check(i, a)) {
			res += i;
		}
	}
	rep(i, 1, 1e6) {
		string s = to_string(i);
		string t = s;
		reverse(t.begin(), t.end());
		rep(j, 0, 10) {
			string x = s;
			x += j + '0';
			x += t;
			int z = stoll(x);
			if (z <= n and check(z, a)) {
				res += z;
			}
		}
		string x = s + t;
		int z = stoll(x);
		if (z <= n and check(z, a)) {
			res += z;
		}
	}

	print(res);
}
