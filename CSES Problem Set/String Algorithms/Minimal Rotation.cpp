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
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

#define FOR rep
#define R0F(i, a) for (int i = a - 1; i >= 0; i--)
#define F0R(i, a) rep(i, 0, a)
#define vb vector<bool>
#define pb push_back
#define each(a, b) for (auto a : b)

vi sa_is(const vi& s, int upper) {
	int n = sz(s); if (!n) return {};
	vi sa(n); vb ls(n); /// is suffix starting at i < suffix starting at i+1
	R0F(i,n-1) ls[i] = s[i] == s[i+1] ? ls[i+1] : s[i] < s[i+1]; 
	/// s-type: less than next suffix -> ls[i] = 1 
	/// l-type: greater than next suffix -> ls[i] = 0
	vi sum_l(upper), sum_s(upper);
	F0R(i,n) (ls[i] ? sum_l[s[i]+1] : sum_s[s[i]])++; /// note that s[i] = upper-1 -> !ls[i]
	F0R(i,upper) { 
		if (i) sum_l[i] += sum_s[i-1]; /// sum_l[i] = sum_{j=0}^{i-1}(s_j+l_j)
		sum_s[i] += sum_l[i]; /// sum_s[i] = sum_{j=0}^{i-1}s_j+sum_{j=0}^{i}l_j
	}
	auto induce = [&](const vi& lms) {
		fill(all(sa),-1);
		vi buf = sum_s;
		for (int d: lms) if (d != n) sa[buf[s[d]]++] = d; /// lms is s-type, first few ...
		buf = sum_l; sa[buf[s[n-1]]++] = n-1;
		F0R(i,n) { /// do l-type in increasing order, suf[v] > suf[v+1]
			int v = sa[i]-1;
			if (v >= 0 && !ls[v]) sa[buf[s[v]]++] = v;
		}
		buf = sum_l;
		R0F(i,n) { /// do s-type in decreasing order, suf[v] < suf[v+1]
			int v = sa[i]-1;
			if (v >= 0 && ls[v]) sa[--buf[s[v]+1]] = v; /// lms is s-type, last few ...
		}
	};
	vi lms_map(n+1,-1), lms; int m = 0;
	FOR(i,1,n) if (!ls[i-1] && ls[i]) lms_map[i]=m++, lms.pb(i);
	induce(lms); // sorts LMS prefixes
	vi sorted_lms;each(v,sa)if (lms_map[v]!=-1)sorted_lms.pb(v);
	vi rec_s(m); int rec_upper = 0; // smaller subproblem
	FOR(i,1,m) { // compare two lms substrings in sorted order
		int l = sorted_lms[i-1], r = sorted_lms[i];
		int end_l = lms_map[l]+1 < m ? lms[lms_map[l]+1] : n;
		int end_r = lms_map[r]+1 < m ? lms[lms_map[r]+1] : n;
		bool same = 0; // whether lms substrings are same
		if (end_l-l == end_r-r) {
			for (;l < end_l && s[l] == s[r]; ++l,++r);
			if (l != n && s[l] == s[r]) same = 1;
		}
		rec_s[lms_map[sorted_lms[i]]] = (rec_upper += !same);
	}
	vi rec_sa = sa_is(rec_s,rec_upper+1);
	F0R(i,m) sorted_lms[i] = lms[rec_sa[i]];
	induce(sorted_lms); // sorts LMS suffixes
	return sa;
}

int32_t main() {
	setup();

	string s;
	input(s);

	int n = sz(s);
	s += s;
	vi v(2 * n);
	rep(i, 0, 2 * n) {
		v[i] = s[i] - 'a';
	}


	vi a = sa_is(v, 26);
	int i = 0;
	while (a[i] >= n) {
		i++;
	}
	print(s.substr(a[i], n));
}
