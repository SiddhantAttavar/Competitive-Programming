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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = gcd(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) { b++; // (for right inclusive)
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return gcd(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n);
		arrput(a);

		RMQ<int> s(a);
		int res = 0;
		rep(i, 0, n - 1) {
			int x = s.query(0, i), y = s.query(i + 1, n - 1);
			if (x % y == 0 or y % x == 0) {
				res++;
				continue;
			}

			int l = 0, r = i, u = -1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (s.query(0, m) % y == 0) {
					u = m;
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}

			if (u == i - 1 or s.query(u + 2, i) % y == 0) {
				res++;
				continue;
			}

			l = i + 1, r = n - 1, u = n;
			while (l <= r) {
				int m = (l + r) / 2;
				if (s.query(m, n - 1) % x == 0) {
					u = m;
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}

			if (u - 1 == i + 1 or s.query(i + 1, u - 2) % x == 0) {
				res++;
			}
		}
		print(res);
	}
}
