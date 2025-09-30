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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool debug = false;
vector<int> z;
int k = 0, x;

bool query(vector<int> &v, int x) {
	if (debug) {
		if (v.empty()) {
			return false;
		}
		k--;
		assert(k >= 0);
		for (int i : v) {
			if (z[i] == x) {
				return true;
			}
		}
		return false;
	}
	if (v.empty()) {
		return false;
	}
	cout << "? " << x << ' ' << v.size() << ' ';
	for (int i : v) {
		cout << i + 1 << ' ';
	}
	cout << endl;
	cout.flush();
	int res;
	input(res);
	return res;
}

int get(vector<int> &a, vector<int> &v, int l, int r, vector<int> &b) {
	if (a.empty()) {
		return -1;
	}
	if (l == r or a.size() == 1) {
		assert(a.size() == 1);
		return a[0];
	}

	int m = (l + r) / 2;
	vector<int> p(v.begin() + l, v.begin() + m + 1);
	vector<int> q(v.begin() + m + 1, v.begin() + r + 1);

	vector<int> c, d, e, f;
	for (int i : a) {
		if (rng() % 2) {
			if (query(p, i + 1)) {
				if (query(q, i + 1)) {
					e.push_back(i);
					f.push_back(i);
				}
				else {
					c.push_back(i);
				}
			}
			else {
				d.push_back(i);
			}
		}
		else {
			if (query(q, i + 1)) {
				if (query(p, i + 1)) {
					e.push_back(i);
					f.push_back(i);
				}
				else {
					d.push_back(i);
				}
			}
			else {
				c.push_back(i);
			}
		}
	}

	for (int i : b) {
		if (query(p, i + 1)) {
			e.push_back(i);
		}
		else {
			f.push_back(i);
		}
	}

	if (e.size() + 2 * c.size() > (m - l + 1)) {
		return get(c, v, l, m, e);
	}
	return get(d, v, m + 1, r, f);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		assert(n != -1);

		if (debug) {
			z.resize(2 * n - 1);
			arrput(z);

			input(x);
			k = 1;
			while ((1 << k) < n) {
				k++;
			}
			k = 2 * k + 4 * n;
		}

		vector<int> a(n), b;
		rep(i, 0, n) {
			a[i] = i;
		}
		vector<int> v(2 * n - 1);
		rep(i, 0, 2 * n - 1) {
			v[i] = i;
		}
		shuffle(v.begin(), v.end(), rng);
		int res = get(a, v, 0, 2 * n - 2, b);

		if (debug) {
			print(x, res + 1);
			cout.flush();
			assert(x == res + 1);
		}
		else {
			print('!', res + 1);
			cout.flush();
		}
	}
}
