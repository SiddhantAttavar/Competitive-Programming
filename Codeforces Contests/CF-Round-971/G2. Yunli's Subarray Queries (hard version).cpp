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

int seg[1<<21], lazy[1<<21]; 
tcT, int SZ> struct LazySeg {
	LazySeg() { F0R(i,2*SZ) {seg[i] = 0; lazy[i] = -1;} }
	void push(int ind, int L, int R) { /// modify values for current node
		if (lazy[ind] == -1) return;
		seg[ind] = (R-L+1)*lazy[ind]; // dependent on operation
		if (L != R) F0R(i,2) lazy[2*ind+i] = lazy[ind]; /// prop to children
		lazy[ind] = -1; 
	} // recalc values for current node
	void pull(int ind){seg[ind]=seg[2*ind]+seg[2*ind+1];}
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return (query(lo,hi,2*ind,L,M)+
			query(lo,hi,2*ind+1,M+1,R));
	}
};

/* struct LazySeg {
	vector<int> a, b;
	
	LazySeg(int n) {
		a.resize(4 * n, 0);
		b.resize(4 * n, -1);
	}

	void push(int i, int l, int r) {
		if (b[i] == -1) {
			return;
		}

		a[i] = (r - l + 1) * b[i];
		if (l != r) {
			b[2 * i + 1] = b[i];
			b[2 * i + 2] = b[i];
		}
		b[i] = -1;
	}

	void pull(int i) {
		a[i] = a[2 * i + 1] + a[2 * i + 2];
	}

	void upd(int i, int x, int l, int r, int s, int e) {
		push(i, l, r);
		if (r < s or l > e) {
			return;
		}

		if (l <= s and e <= r) {
			b[i] = x;
			push(i, l, r);
			return;
		}

		int m = (s + e) / 2;
		upd(2 * i + 1, x, l, r, s, m);
		upd(2 * i + 2, x, l, r, m + 1, e);
		pull(i);
	}

	int query(int i, int l, int r, int s, int e) {
		push(i, l, r);
		if (r < s or l > e) {
			return 0;
		}

		if (l <= s and e <= r) {
			return a[i];
		}

		int m = (s + e) / 2;
		return query(2 * i + 1, l, r, s, m) + query(2 * i + 2, l, r, m + 1, e);
	}
} */;

int32_t main() {
	LazySeg<int, 1 << 18> t;
	setup(); int tc; input(tc); while (tc--) {
		int n, k, q;
		input(n, k, q);

		vector<int> a(n);
		arrPut(a);

		range(i, 0, n) {
			a[i] -= i;
		}

		map<int, int> m;
		range(i, 0, k) {
			m[a[i]]++;
		}
		multiset<int> s;
		for (pair<int, int> p : m) {
			s.insert(p.second);
		}

		vector<int> z(n);
		z[k - 1] = k - *s.rbegin();
		range(i, k, n) {
			s.erase(s.find(m[a[i - k]]));
			m[a[i - k]]--;
			s.insert(m[a[i - k]]);

			if (s.count(m[a[i]])) {
				s.erase(s.find(m[a[i]]));
			}
			m[a[i]]++;
			s.insert(m[a[i]]);

			z[i] = k - *s.rbegin();
		}

		vector<pair<pair<int, int>, int>> v(q);
		range(i, 0, q) {
			input(v[i].first.first, v[i].first.second);
			v[i].second = i;
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		stack<int> st;
		st.push(n);

		int i = n;
		vector<int> res(q);
		for (pair<pair<int, int>, int> p : v) {
			int l, r;
			tie(l, r) = p.first;

			l--;
			r--;
			l += k - 1;

			while (i > l) {
				i--;

				while (st.top() != n and z[i] < z[st.top()]) {
					st.pop();
				}

				t.upd(i, st.top() - 1, z[i]);
				st.push(i);
			}

			res[p.second] = t.query(l, r);
		}

		for (int i : res) {
			print(i);
		}
	}
}
