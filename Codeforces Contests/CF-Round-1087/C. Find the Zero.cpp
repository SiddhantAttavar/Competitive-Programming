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

bool debug = false;
vi A;
int K = -1;

bool query(int i, int j) {
	assert(K--);
	if (debug) {
		return A[i - 1] == A[j - 1];
	}

	print('?', i, j);
	cout.flush();
	int x;
	input(x);
	return x;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		K = n + 1;
		if (debug) {
			A.resize(2 * n);
			arrput(A);
		}

		int res = -1;
		while (n > 2) {
			if (query(2 * n - 1, 2 * n)) {
				res = 2 * n;
				break;
			}
			n--;
		}

		if (res == -1) {
			if (query(1, 2) or query(1, 3)) {
				res = 1;
			}
			else if (query(2, 3)) {
				res = 2;
			}
			else {
				res = 4;
			}
		}

		print('!', res);
		cout.flush();
		if (debug) {
			assert(A[res - 1] == 0);
		}
	}
}
