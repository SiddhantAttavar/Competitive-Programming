#include <sys/time.h>
#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <sys/time.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

#define vi vector<int>
#define sz(x) (int) x.size()
typedef uint64_t ull;
static int C; // initialized below

// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() { return x ^ (ull) b << 21; }
	bool operator==(A o) const { return (ull)*this == (ull)o; }
	bool operator<(A o) const { return (ull)*this < (ull)o; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

vector<H> getHashes(string& str, int length) {
	if (sz(str) < length) return {};
	H h = 0, pw = 1;
	rep(i,0,length)
		h = h * C + str[i], pw = pw * C;
	vector<H> ret = {h};
	rep(i,length,sz(str)) {
		ret.push_back(h = h * C + str[i] - pw * str[i-length]);
	}
	return ret;
}

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

void dfs(int u, vector<vector<int>> &graph, string &s) {
	// print(u);
	// cout.flush();
	s += '(';
	for (int v : graph[u]) {
		dfs(v, graph, s);
	}
	s += ')';
}

vector<int> solve(vector<int> a) {
	// arrprint(a);
	int m = *max_element(a.begin(), a.end());
	vector<vector<int>> v(m + 1);
	int n = a.size();
	rep(i, 0, n) {
		a[i]--;
		v[a[i]].push_back(i);
	}
	v[m].push_back(n);

	vector<vector<int>> graph(n + 1);
	rep(i, 1, m + 1) {
		int k = 0;
		rep(j, 0, v[i].size() - 1) {
			while (k < v[i - 1].size() and v[i - 1][k] < v[i][j]) {
				k++;
			}
			while (k < v[i - 1].size() and v[i - 1][k] < v[i][j + 1]) {
				// print(v[i][j], v[i - 1][k]);
				graph[v[i][j]].push_back(v[i - 1][k]);
				k++;
			}
		}
		while (k < v[i - 1].size() and v[i - 1][k] < v[i].back()) {
			k++;
		}
		while (k < v[i - 1].size()) {
			// print(v[i].back(), v[i - 1][k]);
			graph[v[i].back()].push_back(v[i - 1][k]);
			k++;
		}
		k = 0;
		while (k < v[i - 1].size() and v[i - 1][k] < v[i][0]) {
			// print(v[i].back(), v[i - 1][k]);
			graph[v[i].back()].push_back(v[i - 1][k]);
			k++;
		}
	}

	vector<int> res;
	for (int i : graph[n]) {
		string s;
		dfs(i, graph, s);
		// print(s, (ull) hashString(s));
		res.push_back((ull) hashString(s));
	}
	return res;
}

vi Z(vector<int>& S) {
	vi z(sz(S));
	int l = -1, r = -1;
	rep(i,1,sz(S)) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

bool check(vector<int> a, vector<int> b) {
	vector<int> s(b.begin(), b.end());
	s.push_back(-1);
	s.insert(s.end(), a.begin(), a.end());
	s.insert(s.end(), a.begin(), a.end());
	// arrprint(s);
	vector<int> z = Z(s);
	return *max_element(z.begin(), z.end()) == b.size();
}

int32_t main() {
	timeval tp;
	gettimeofday(&tp, 0);
	C = (int)tp.tv_usec; // (less than modulo)
	assert((ull)(H(1)*2+1-3) == 0);
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> a(n), b(n);
		arrput(a);
		arrput(b);

		if (m == 1) {
			print("YES");
			continue;
		}

		if (check(solve(a), solve(b))) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
