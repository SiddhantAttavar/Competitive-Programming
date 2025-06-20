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

	string s;
	input(s);

	vector<int> a(26, 0);
	for (char c : s) {
		a[c - 'A']++;
	}

	if (*max_element(a.begin(), a.end()) > (s.size() + 1) / 2) {
		print(-1);
		return 0;
	}

	string res;
	rep(i, 0, s.size()) {
		int x = max_element(a.begin(), a.end()) - a.begin();
		int y = x == 0;
		rep(j, 0, 26) {
			if (j != x and a[j] > a[y]) {
				y = j;
			}
		}
		rep(j, 0, 26) {
			if (a[j] == 0 or (!res.empty() and (j + 'A') == res.back())) {
				continue;
			}
			a[j]--;
			if (max(a[x], a[y]) > (s.size() - i) / 2) {
				a[j]++;
			}
			else {
				res += j + 'A';
				break;
			}
		}
	}
	print(res);
}
