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
int K = 3;
vi A, S;

vi query(const string &s) {
	assert(K--);

	vector<pii> v;
	rep(i, 0, sz(A)) {
		v.push_back({A[i], S[i]});
	}
	if (debug) {
		for (char c : s) {
			vector<pii> nv;
			if (c == 'L') {
				for (auto [x, s] : v) {
					if (nv.empty() or nv.back().first < x - s) {
						nv.push_back({x - s, s});
					}
				}
			}
			else {
				reverse(all(v));
				for (auto [x, s] : v) {
					if (nv.empty() or nv.back().first > x + s) {
						nv.push_back({x + s, s});
					}
				}
				reverse(all(nv));
			}
			v = nv;
		}
		vi res;
		for (auto [x, i] : v) {
			res.push_back(x);
		}
		return res;
	}

	print('?', s);
	cout.flush();

	int x;
	input(x);
	assert(x != -1);
	vi res(x);
	arrput(res);
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n), s(n, -1);
		arrput(a);

		K = 3;
		if (debug) {
			A = a;
			S.resize(n);
			arrput(S);
		}

		vi p = query("L"), q = query("LR"), r = query("R");

		vector<bool> v(n, false);
		int l = 0;
		for (int x : q) {
			while (a[l] < x) {
				l++;
			}
			v[l] = true;
		}

		int j = 0, c = -1e18;
		rep(i, 0, n) {
			if (v[i]) {
				s[i] = a[i] - p[j];
				c = p[j];
				j++;
			}
			else if (c < a[i] - 1) {
				s[i] = 2;
			}
		}

		bool flag = true;
		rep(i, 0, n - 1) {
			if (s[i] == -1 and (s[i + 1] == 0 and a[i] + 1 == a[i + 1])) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			print("! -1");
			cout.flush();
			continue;
		}
		
		set<int> t(all(r));
		rep(i, 0, n) {
			if (s[i] == -1) {
				s[i] = t.count(a[i] + 1) ? 1 : 2;
			}
		}

		cout << "! ";
		arrprint(s);
		cout.flush();

		if (debug) {
			assert(s == S);
		}
	}
}
