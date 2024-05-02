#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const db PI = acos((db)-1);
mt19937 rng(0); // or mt19937_64

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

// int main() { cin.tie(0)->sync_with_stdio(0); }
/**
 * Description: \texttt{f[i]} is the max \texttt{len} such that 
 	* \texttt{s.substr(0,len) == s.substr(i,len)}
 * Time: O(N)
 * Source: http://codeforces.com/blog/entry/3107
 * Verification: POI 12 Template, https://codeforces.com/contest/1137/problem/B
 */

vi z(str s) {
	int N = size(s), L = 1, R = 0; s += '#';
	vi ans(N); ans[0] = N; 
	FOR(i,1,N) {
		if (i <= R) ans[i] = min(R-i+1,ans[i-L]);
		while (s[i+ans[i]] == s[ans[i]]) ++ans[i];
		if (i+ans[i]-1 > R) L = i, R = i+ans[i]-1;
	}
	return ans;
}

bool check(int x, vector<int> &v, int k) {
	if (x == 0) {
		return true;
	}

	int n = v.size();
	vector<int> dp(n, 0);
	range(i, x, n) {
		dp[i] = dp[i - 1];
		if (v[i] >= x) {
			dp[i] = max(dp[i], dp[i - x] + 1);
		}
	}
	return dp[n - 1] >= k - 1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, l, r;
		input(n, l, r);

		string s;
		input(s);

		vector<int> v = z(s);
		// arrPrint(v);

		int x = 0, y = n, res = 0;
		while (x <= y) {
			int m = (x + y) / 2;
			if (check(m, v, l)) {
				res = m;
				x = m + 1;
			}
			else {
				y = m - 1;
			}
		}
		print(res);
	}
}
