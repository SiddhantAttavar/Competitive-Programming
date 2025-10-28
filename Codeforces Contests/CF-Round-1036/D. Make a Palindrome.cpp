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
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrput(a);

		vector<int> x(n, 0);
		rep(i, 0, n) {
			a[i]--;
			x[a[i]]++;
		}

		int c = x[0], l = 0;
		while (c < k) {
			l++;
			c += x[l];
		}

		deque<int> d;
		for (int i : a) {
			if (i <= l) {
				d.push_back(i);
			}
		}

		int y = 0;
		while (d.size() >= 2) {
			if (d.front() == d.back()) {
				y += 2;
				d.pop_back();
				d.pop_front();
			}
			else if (d.front() == l) {
				d.pop_front();
			}
			else if (d.back() == l) {
				d.pop_back();
			}
			else {
				y = -1e18;
				break;
			}
		}
		y += d.size();

		if (y >= k - 1) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
