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

bool debug = false;
string S;
int K = 200;

int query(vector<int> v) {
	assert(K);
	K--;
	if (!debug) {
		assert(v.size() <= 1000);
		cout << "? " << v.size();
		for (int i : v) {
			cout << ' ' << i + 1;
		}
		cout << endl;
		cout.flush();
		int x;
		input(x);
		return x;
	}
	string s;
	for (int i : v) {
		s += S[i];
	}
	int res = 0;
	rep(i, 0, s.size()) {
		int c = 0;
		rep(j, i, s.size()) {
			if (s[j] == '(') {
				c++;
			}
			else {
				c--;
				if (c < 0) {
					break;
				}
				res += c == 0;
			}
		}
	}
	return res;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		K = 550;
		if (debug) {
			input(S);
		}

		int u = -1;
		for (int j = 1; j < n; j += 250) {
			int l = j, r = min(n - 1, j + 249);
			while (l <= r) {
				int m = (l + r) / 2;
				vector<int> v;
				rep(i, j, m + 1) {
					v.push_back(0);
					v.push_back(i);
					v.push_back(i);
					v.push_back(0);
				}
				if (query(v)) {
					u = m;
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}
			if (u != -1) {
				break;
			}
		}

		string s(n, ' ');
		int x = 0, y = u;
		if (query({0, u})) {
			rep(i, 0, u) {
				s[i] = '(';
			}
			s[u] = ')';
		}
		else {
			swap(x, y);
			rep(i, 0, u) {
				s[i] = ')';
			}
			s[u] = '(';
		}

		for (int i = u + 1; i < n; i += 8) {
			vector<int> v;
			rep(j, i, min(i + 8, n)) {
				rep(k, 0, 1 << (j - i)) {
					v.push_back(j);
					v.push_back(y);
					v.push_back(y);
				}
			}
			int x = query(v);
			rep(j, i, min(i + 8, n)) {
				if (x >> (j - i) & 1) {
					s[j] = '(';
				}
				else {
					s[j] = ')';
				}
			}
		}

		print('!', s);
		cout.flush();

		if (debug) {
			assert(s == S);
		}
	}
}
