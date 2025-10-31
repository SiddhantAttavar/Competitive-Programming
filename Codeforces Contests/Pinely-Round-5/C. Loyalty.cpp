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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, x;
		input(n, x);

		vector<int> a(n);
		arrput(a);

		multiset<int> m(a.begin(), a.end());
		int c = 0, res = 0;
		vector<int> l;
		while (!m.empty()) {
			multiset<int>::iterator i = m.lower_bound(x - c);
			if (i == m.end()) {
				l.push_back(*m.begin());
				c += *m.begin();
				m.erase(m.begin());
			}
			else {
				i = --m.end();
				l.push_back(*i);
				res += *i;
				c = (c + *i) % x;
				m.erase(i);
			}
		}
		print(res);
		arrprint(l);
	}
}
