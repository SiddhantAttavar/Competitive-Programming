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
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

bool debug = false;
int K = -1;
vi A;

int query(vi p, vi &q) {
	assert(K);
	K--;

	if (debug) {
		set<int> s;
		for (int i : p) {
			s.insert(A[i]);
		}
		for (int i : q) {
			s.insert(i);
		}

		int x = 0;
		while (s.count(x)) {
			x++;
		}
		return x;
	}

	print('?', sz(p), sz(q));
	for (int i : p) {
		cout << i + 1 << ' ';
	}
	cout << endl;
	arrprint(q);
	cout.flush();

	int res;
	input(res);
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		
		K = 15 * n;
		if (debug) {
			A.resize(n);
			arrput(A);
		}

		vi p(n), q;
		iota(all(p), 0);
		while (true) {
			int x = query(p, q);
			if (x > n) {
				break;
			}
			q.push_back(x);
		}

		vi res(n, -1);
		while (!p.empty()) {
			int x = query(p, q);
			int l = 0, r = sz(p) - 1, u = 0;
			while (l <= r) {
				int m = (l + r) / 2;
				vi s(p.begin(), p.begin() + m);
				if (query(s, q) < x) {
					u = m;
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			vi s(p.begin(), p.begin() + u);
			int i = p[u];
			res[i] = query(s, q);
			p.erase(p.begin() + u);
			if (query(p, q) < x) {
				q.push_back(res[i]);
			}
		}

		cout << "! ";
		arrprint(res);
		cout.flush();

		if (debug) {
			assert(res == A);
		}
	}
}
