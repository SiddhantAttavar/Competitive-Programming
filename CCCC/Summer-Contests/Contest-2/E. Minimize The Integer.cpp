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
	setup(); int tc; input(tc); while (tc--) {
		string s;
		input(s);

		deque<int> a, b;
		rep(i, 0, s.size()) {
			if (s[i] % 2 == '0' % 2) {
				a.push_back(i);
			}
			else {
				b.push_back(i);
			}
		}

		vector<bool> v(s.size(), false);
		string res;
		while (!a.empty() or !b.empty()) {
			if (a.empty() or (!b.empty() and s[b.front()] < s[a.front()])) {
				res += s[b.front()];
				b.pop_front();
			}
			else {
				res += s[a.front()];
				a.pop_front();
			}
		}
		print(res);
	}
}
