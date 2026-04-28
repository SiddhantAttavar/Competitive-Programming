#include <algorithm>
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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

bool check(vi &a, vi &b) {
	int x = *min_element(all(b)), y = *max_element(all(b));
	int m = 0;
	for (int i : a) {
		m = max(m, i);
		if (x > i and y < m) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n);
		arrput(a);

		vi o, e;
		for (int i : a) {
			if (i % 2 == 1) {
				o.push_back(i);
			}
			else {
				e.push_back(i);
			}
		}

		if (o.empty() or e.empty()) {
			if (is_sorted(all(a))) {
				print("YES");
			}
			else {
				print("NO");
			}
			continue;
		}

		if (check(o, e) and check(e, o)) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
