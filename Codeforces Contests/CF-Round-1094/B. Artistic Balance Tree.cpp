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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vi a(n), x(m);
		arrput(a);
		arrput(x);

		std::priority_queue<int> s, t;
		rep(i, 0, n) {
			if (i % 2 == 0) {
				s.push(a[i]);
			}
			else {
				t.push(a[i]);
			}
		}

		int res = accumulate(all(a), 0ll);
		bool p = false, q = false;
		for (int i : x) {
			i--;
			if (i % 2 == 1) {
				swap(s, t);
				swap(p, q);
			}

			if (!s.empty() and (s.top() > 0 or !p)) {
				res -= s.top();
				s.pop();
				p = true;
			}

			if (i % 2 == 1) {
				swap(s, t);
				swap(p, q);
			}
		}
		print(res);
	}
}
