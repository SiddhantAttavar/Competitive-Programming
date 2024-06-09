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

#include <bits/stdc++.h>
using namespace std;
 
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

#define sz(x) (int)((x).size())
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

// const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0); // or mt19937_64

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

// int main() { cin.tie(0)->sync_with_stdio(0); }

vi kmp(str s) {
	int N = sz(s); vi f(N+1); f[0] = -1;
	FOR(i,1,N+1) {
		for (f[i]=f[i-1];f[i]!=-1&&s[f[i]]!=s[i-1];)f[i]=f[f[i]];
		++f[i]; }
	return f;
}
vi getOc(str a, str b) { // find occurrences of a in b
	vi f = kmp(a+"@"+b), ret;
	FOR(i,sz(a),sz(b)+1) if (f[i+sz(a)+1] == sz(a)) 
		ret.pb(i-sz(a));
	return ret;
}

/**
 * Description: \texttt{f[i]} is the max \texttt{len} such that 
 	* \texttt{s.substr(0,len) == s.substr(i,len)}
 * Time: O(N)
 * Source: http://codeforces.com/blog/entry/3107
 * Verification: POI 12 Template, https://codeforces.com/contest/1137/problem/B
 */

vi z(str s) {
	int N = sz(s), L = 1, R = 0; s += '#';
	vi ans(N); ans[0] = N; 
	FOR(i,1,N) {
		if (i <= R) ans[i] = min(R-i+1,ans[i-L]);
		while (s[i+ans[i]] == s[ans[i]]) ++ans[i];
		if (i+ans[i]-1 > R) L = i, R = i+ans[i]-1;
	}
	return ans;
}
vi getPrefix(str a, str b) { // find prefixes of a in b
	vi t = z(a+b); t = vi(sz(a)+all(t)); 
	each(u,t) ckmin(u,sz(a));
	return t;
}
/// Usage: pr(z("abcababcabcaba"),getPrefix("abcab","uwetrabcerabcab"));

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		string s;
		input(s);

		int n = s.size();
		vector<int> a;
		range(i, 0, n) {
			if (s[i] != 'a') {
				a.push_back(i);
			}
		}

		if (a.size() == 0) {
			print(n - 1);
			continue;
		}

		vector<int> v = z(s.substr(a[0]));
		int x = a[0], y = n - a.back() - 1;
		int res = 0;
		range(k, 1, n - x + 1) {
			int u = 0;
			int x = a[0] + 1;
			while (u < n) {
				int i = lower_bound(a.begin(), a.end(), u) - a.begin();
				if (i == (int) a.size()) {
					break;
				}
				x = min(x, a[i] - u + 1);
				u = a[i];
				
				if (v[u - a[0]] < k) {
					x = 0;
					break;
				}
				u += k;
			}
			res += x;
		}

		print(res);
	}
}
