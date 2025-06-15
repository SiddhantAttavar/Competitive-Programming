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
		int n, q;
		input(n, q);

		string s;
		input(s);

		set<int> ba, ca, bc, cb;
		rep(i, 0, q) {
			char x, y;
			input(x, y);

			if (x == 'b' and y == 'a') {
				ba.insert(i);
			}
			else if (x == 'c' and y == 'a') {
				ca.insert(i);
			}
			else if (x == 'b' and y == 'c') {
				bc.insert(i);
			}
			else if (x == 'c' and y == 'b') {
				cb.insert(i);
			}
		}

		rep(i, 0, n) {
			if (s[i] == 'b') {
				set<int>::iterator j = ba.begin();
				if (j != ba.end()) {
					ba.erase(j);
					s[i] = 'a';
					continue;
				}

				j = bc.begin();
				if (j == bc.end()) {
					continue;
				}

				set<int>::iterator k = ca.lower_bound(*j);
				if (k != ca.end()) {
					bc.erase(j);
					ca.erase(k);
					s[i] = 'a';
				}
			}
			else if (s[i] == 'c') {
				set<int>::iterator j = ca.begin();
				if (j != ca.end()) {
					ca.erase(j);
					s[i] = 'a';
					continue;
				}

				j = cb.begin();
				if (j == cb.end()) {
					continue;
				}
				s[i] = 'b';

				set<int>::iterator k = ba.lower_bound(*j);
				cb.erase(j);
				if (k != ba.end()) {
					ba.erase(k);
					s[i] = 'a';
				}
			}
		}

		print(s);
	}
}
