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

void rev(vector<string> &a) {
	int n = sz(a);
	rep(i, 0, n) {
		rep(j, 0, n) {
			a[i][j] = a[i][j] == '#' ? '.' : '#';
		}
	}
}

void first(vector<string> &a) {
	int n = sz(a);
	int w = 0;
	rep(i, 0, n) {
		w += count(all(a[i]), '#');
	}

	if (2 * w > n * n) {
		rev(a);
		w = n * n - w;
	}

	int r, c;
	input(r, c);

	r--;
	c--;

	int s = 0, t = 0;
	rep(i, 0, n) {
		rep(j, 0, n) {
			if (a[i][j] == '#') {
				s = (s + i) % n;
				t = (t + j) % n;
			}
		}
	}

	int x = (w * r - s + n) % n, y = (w * c - t + n) % n;
	if (x == 0 and y == 0) {
		print(1, 1, 1, 1);
		return;
	}

	rep(i, 0, n) {
		rep(j, 0, n) {
			int k, l;
			if (a[i][j] == '.') {
				k = (i - x + n) % n;
				l = (j - y + n) % n;
			}
			else {
				k = (i + x) % n;
				l = (j + y) % n;
			}
			if (a[i][j] != a[k][l]) {
				print(i + 1, j + 1, k + 1, l + 1);
				return;
			}
		}
	}
}

int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int div(int a, int b, int m) {
	int x, y;
	int g = gcd(b, m, x, y);
	assert(g == 1);
	x = (x + m) % m;
	return a * x % m;
}

void second(vector<string> &a) {
	int n = sz(a);
	int w = 0;
	rep(i, 0, n) {
		w += count(all(a[i]), '#');
	}

	if (2 * w > n * n) {
		rev(a);
		w = n * n - w;
	}

	int s = 0, t = 0;
	rep(i, 0, n) {
		rep(j, 0, n) {
			if (a[i][j] == '#') {
				s = (s + i) % n;
				t = (t + j) % n;
			}
		}
	}

	int r = div(s, w, n), c = div(t, w, n);
	print(r + 1, c + 1);
}

int32_t main() {
	setup();

	string s;
	input(s);

	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<string> a(n);
		arrput(a);

		if (s == "first") {
			first(a);
		}
		else {
			second(a);
		}
	}
}
