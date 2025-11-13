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

#define sz(x) (int) x.size()

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		b++;
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

vector<int> solve(int l, int r, vector<int> &a, vector<int> &b, RMQ<int> &c) {
	if (l > r) {
		return vector<int>(61, 1);
	}

	int k = c.query(l, r);
	int s = l, t = r, u = -1;
	while (s <= t) {
		int m = (s + t) / 2;
		if (c.query(l, m) == k) {
			u = m;
			t = m - 1;
		}
		else {
			s = m + 1;
		}
	}

	vector<int> x = solve(l, u - 1, a, b, c), y = solve(u + 1, r, a, b, c);
	vector<int> z(61, 1e18);
	rep(i, 0, 61) {
		rep(j, 0, 61 - i) {
			z[i + j] = min(z[i + j], max(x[i], y[j]));
		}
	}
	rep(i, 0, 61) {
		z[i] = max(z[i], a[u]);
	}
	rep(i, 0, 60) {
		z[i + 1] = min(z[i + 1], (z[i] + b[u] - 1) / b[u]);
	}
	return z;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		
		vector<int> a(n), b(n);
		arrput(a);
		arrput(b);

		RMQ c(b);
		vector<int> res = solve(0, n - 1, a, b, c);
		rep(i, 0, 61) {
			if (res[i] == 1) {
				print(i);
				break;
			}
		}
	}
}
