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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k) {
			jmp.emplace_back(V.size() - pw * 2 + 1);
			rep(j,0,jmp[k].size())
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vector<int> a(n);
		arrput(a);

		vector<int> p(n, -1), r(n, n);
		stack<int> s;
		rep(i, 0, n) {
			while (!s.empty() and a[s.top()] < a[i]) {
				s.pop();
			}
			if (!s.empty()) {
				p[i] = s.top();
			}
			s.push(i);
		}
		while (!s.empty()) {
			s.pop();
		}
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() and a[i] < a[s.top()]) {
				s.pop();
			}
			if (!s.empty()) {
				r[i] = s.top();
			}
			s.push(i);
		}
		// arrprint(p);
		// arrprint(r);

		vector<int> v(n, n);
		rep(i, 0, n) {
			if (p[i] != -1) {
				v[p[i]] = min(v[p[i]], r[i]);
			}
		}
		// arrprint(v);

		RMQ t(v);
		while (q--) {
			int l, r;
			input(l, r);

			if (l == r) {
				print("YES");
				continue;
			}

			l--;
			r--;
			if (t.query(l, r) <= r) {
				print("NO");
			}
			else {
				print("YES");
			}
		}
	}
}
