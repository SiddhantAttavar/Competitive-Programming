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
bool debug = true;
vector<int> z;
int k = 0, x;

bool query(vector<int> &v, int x) {
	if (debug) {
		if (v.empty()) {
			return false;
		}
		k++;
		assert(k <= 925);
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

bool check(int n, int x) {
	vector<int> a;
	rep(i, 0, 2 * n - 1) {
		a.push_back(i);
	}
	shuffle(a.begin(), a.end(), rng);
	vector<int> b;
	while (a.size() > b.size()) {
		b.push_back(a.back());
		a.pop_back();
	}
	return query(a, x) and query(b, x);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		if (debug) {
			z.resize(2 * n - 1);
			arrput(z);

			int x = 4 * n;
			k = 0;
		}

		int res = 1;
		rep(i, 0, n) {
			bool flag = false;
			rep(j, 0, 10) {
				if (check(n, i + 1)) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				res = i;
				break;
			}
		}

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
