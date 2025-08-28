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

const int N = 1e5;

int query(vector<int> &a) {
	cout << "? " << a.size();
	for (int i : a) {
		cout << ' ' << i;
	}
	cout << endl;
	cout.flush();
	int x;
	input(x);
	return x;
}

int get(vector<int> &a, int w) {
	if (a.size() > N or *max_element(a.begin(), a.end()) > N) {
		return 0;
	}
	int res = 1, c = 0;
	for (int i : a) {
		if (c + i <= w) {
			c += i;
		}
		else {
			res++;
			c = i;
		}
	}
	return res;
}

// int w;
// int query(vector<int> &a) {
// 	return get(a, w);
// }

int32_t main() {
	int tc; input(tc); while (tc--) {
		// input(w);

		vector<int> a(N, 1);
		int x = query(a);

		if (x == 1) {
			print('!', N);
			cout.flush();
			continue;
		}

		int l = (N + x - 1) / x, r = (N - 1) / (x - 1), res = -1;
		vector<int> b;
		for (int i = r; i > l; i--) {
			b.push_back(l);
			b.push_back(i - l);
		}
		b.push_back(l);

		int y = query(b);
		while (l <= r) {
			int m = (l + r) / 2;
			if (get(b, m) == y) {
				res = m;
				break;
			}
			else if (get(b, m) < y) {
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		print('!', res);
		cout.flush();
	}
}
