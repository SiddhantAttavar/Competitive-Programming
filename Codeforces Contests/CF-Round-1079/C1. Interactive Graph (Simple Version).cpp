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
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

bool debug = false;
vector<vi> G, P;
int K = 1e9;

vi query(int k) {
	assert(K--);

	if (debug) {
		if (k >= sz(P)) {
			return {};
		}
		return P[k];
	}

	print('?', k + 1);
	cout.flush();
	int q;
	input(q);
	if (q == -1) {
		exit(0);
	}
	vi res(q);
	arrput(res);
	rep(i, 0, q) {
		res[i]--;
	}
	return res;
}

void dfs(int u, vi &path) {
	path.push_back(u);
	P.push_back(path);
	for (int v : G[u]) {
		dfs(v, path);
	}
	path.pop_back();
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		if (debug) {
			int m;
			input(m);
			K = 32 * (n + m);

			G.assign(n, {});
			rep(i, 0, m) {
				int u, v;
				input(u, v);
				G[u - 1].push_back(v - 1);
			}

			rep(i, 0, n) {
				vi path;
				dfs(i, path);
			}
			sort(all(P));
		}

		vector<pii> res;
		vi v(n, false), x(n, 0);
		int k = 0;
		while (true) {
			vi l = query(k);
			if (l.empty()) {
				break;
			}

			rep(i, 1, sz(l)) {
				res.push_back({l[i - 1], l[i]});
			}

			int c = 1;
			if (v[l.back()]) {
				c = x[l.back()];
				x[l.back()] = 0;
			}
			vi b(n, false);
			for (int i : l) {
				x[i] += c;
				v[i] = true;
			}
			k += c;
		}

		sort(all(res));
		res.erase(unique(all(res)), res.end());
		print('!', sz(res));
		for (auto [u, v] : res) {
			print(u + 1, v + 1);
		}
		cout.flush();
	}
}
