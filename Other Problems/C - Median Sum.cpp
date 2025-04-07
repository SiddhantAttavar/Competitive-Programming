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

	vector<int> a(n);
	arrput(a);

	map<int, int> m;
	for (int i : a) {
		m[i]++;
	}

	vector<int> v;
	for (pair<int, int> p : m) {
		int y = 0, x = 0;
		while (y + (x + 1) <= p.second) {
			x++;
			y += x;
			v.push_back(p.first * x);
		}
		rep(i, y, p.second) {
			v.push_back(p.first);
		}
	}
	
	const int N = 4e6 + 1;
	bitset<N> b = 1;
	for (int i : a) {
		b |= b << i;
	}

	int x = accumulate(a.begin(), a.end(), 0);
	rep(i, (x + 1) / 2, x + 1) {
		if (b[i]) {
			print(i);
			break;
		}
	}
}
