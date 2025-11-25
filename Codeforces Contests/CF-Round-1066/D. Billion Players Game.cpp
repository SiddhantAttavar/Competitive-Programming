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
		int n, l, r;
		input(n, l, r);

		vector<int> a(n);
		arrput(a);

		vector<int> b;
		int x = 0, y = 0, p = 0, q = 0;
		for (int i : a) {
			if (i < l) {
				x++;
				p += i;
			}
			else if (i > r) {
				y++;
				q += i;
			}
			else {
				b.push_back(i);
			}
		}

		sort(b.begin(), b.end());
		int s = 0, t = b.size() - 1;
		while (s <= t) {
			if (x > y) {
				y++;
				q += b[t];
				t--;
			}
			else if (x < y) {
				x++;
				p += b[s];
				s++;
			}
			else if (s < t) {
				x++;
				p += b[s];
				s++;

				y++;
				q += b[t];
				t--;
			}
			else {
				break;
			}
		}
		while (x > y) {
			y++;
			q += l;
		}
		while (x < y) {
			x++;
			p += r;
		}
		print(q - p);
	}
}
