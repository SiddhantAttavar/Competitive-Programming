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

pair<int, bool> query(int l, int r) {
	print('?', l + 1, r + 1);
	cout.flush();
	int x, y;
	input(x, y);
	return {x, y};
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);
		
		vector<bool> a(n);
		a[0] = query(0, 0).first;
		for (int i = 2; i < n; i += 2) {
			pair<int, int> p = query(i - 2, i);
			if (a[i - 2]) {
				if (p.first == 1) {
					a[i - 1] = 0;
					a[i] = 0;
				}
				else if (p.first == 3) {
					a[i - 1] = 1;
					a[i] = 1;
				}
				else if (p.second) {
					a[i - 1] = 1;
					a[i] = 0;
				}
				else {
					a[i - 1] = 0;
					a[i] = 1;
				}
			}
			else {
				if (p.first == 0) {
					a[i - 1] = 0;
					a[i] = 0;
				}
				else if (p.first == 2) {
					a[i - 1] = 1;
					a[i] = 1;
				}
				else if (p.second) {
					a[i - 1] = 0;
					a[i] = 1;
				}
				else {
					a[i - 1] = 1;
					a[i] = 0;
				}
			}
		}
		if (n % 2 == 0) {
			a[n - 1] = query(n - 1, n - 1).first;
		}

		vector<int> res;
		rep(i, 0, n) {
			if (a[i]) {
				res.push_back(i + 1);
			}
		}
		cout << "! " << res.size() << ' ';
		arrprint(res);
	}
}
