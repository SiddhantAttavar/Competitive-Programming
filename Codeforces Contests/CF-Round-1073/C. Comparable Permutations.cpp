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
vi P;
int K;
map<pair<int, int>, bool> memo;

bool query(int i, int j) {
	if (memo.count({i, j})) {
		return memo[{i, j}];
	}
	if (memo.count({j, i})) {
		return !memo[{j, i}];
	}
	assert(K);
	K--;
	if (debug) {
		memo[{i, j}] = P[i] < P[j];
		return P[i] < P[j];
	}
	print('?', i + 1, j + 1);
	cout.flush();
	int x;
	input(x);
	memo[{i, j}] = x;
	return x;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		K = 3 * n;
		memo.clear();
		if (debug) {
			P.resize(n);
			arrput(P);
		}

		int r = n - 1;
		while (r and query(r - 1, r)) {
			r--;
		}
		int l = r;
		while (l and !query(l - 1, l)) {
			l--;
		}

		if (l == 0) {
			print("! -1");
			cout.flush();
			continue;
		}

		vi v = {l - 1, r};
		int a = r - 1, b = r + 1;
		while (a >= l or b < n) {
			if (a >= l and (b == n or query(a, b))) {
				v.push_back(a);
				a--;
			}
			else {
				v.push_back(b);
				b++;
			}
		}

		rep(i, 1, sz(v)) {
			if (query(l - 1, v[i])) {
				swap(v[0], v[i]);
				break;
			}
		}

		vi res;
		rep(i, 0, l - 1) {
			res.push_back(i + 1);
		}
		for (int i : v) {
			res.push_back(i + 1);
		}

		cout << "! ";
		arrprint(res);
		cout.flush();

		if (debug) {
			vi Q(n);
			rep(i, 0, n) {
				Q[i] = P[res[i] - 1];
			}
			assert(Q > P);
			reverse(all(P));
			reverse(all(Q));
			assert(Q > P);
		}
	}
}
