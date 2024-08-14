#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

template<class T> struct SegTree {
	vector<T> a;
	T id;
	int N;
	T (*combine) (T, T);
	SegTree(int n, T i, T func(T, T)) {
		N = n;
		id = i; combine = func;
		a.resize(4 * n, id);
	}
	T query(int l, int r, int s, int e, int curr) {
		if (l > e || r < s)  return id;
		if (l <= s && r >= e) return a[curr];
		int mid = (s + e) / 2;
		return combine(query(l, r, s, mid, 2 * curr + 1),
			query(l, r, mid + 1, e, 2 * curr + 2));
	}
	void upd(int p, T val) {
		a[p += N - 2] = val;
		for (p = (p - 1) / 2; p; p = (p - 1) / 2) {
			a[p] = combine(a[p * 2 + 1], a[2 * p + 2]);
		}
		a[0] = combine(a[1], a[2]);
	}
	int get(int k) {
		int l = 1, r = N, curr = 0;
		while (l < r) {
			int m = (l + r) / 2;
			curr *= 2;
			curr++;
			if (a[curr][0] >= k) {
				r = m;
			}
			else if (a[curr][2] + a[curr + 1][1] >= k) {
				return a[curr][3];
			}
			else {
				l = m + 1;
				curr++;
			}
		}
		return l - 1;
	}
};

int32_t main() {
	int N = 1 << 21;
	SegTree<array<int, 5>> s(N, {0, 0, 0, -1, 0}, [](array<int, 5> a, array<int, 5> b) {
		return array<int, 5>{
			max({a[0], b[0], a[2] + b[1]}),
			a[0] == a[4] ? a[0] + b[1] : a[1],
			b[0] == b[4] ? b[0] + a[2] : b[2],
			max(a[3], b[3]),
			a[4] + b[4]
		};
	});
	range(i, 0, N) {
		s.a[i + N - 1] = {1, 1, 1, 0, 1};
	}
	for (int i = N - 2; i >= 0; i--) {
		s.a[i] = s.combine(s.a[2 * i + 1], s.a[2 * i + 2]);
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		for (int i : a) {
			s.upd(i, {0, 0, 0, i, 1});
		}

		set<int> b(a.begin(), a.end());
		int m;
		input(m);
		while (m--) {
			char c;
			input(c);

			int x;
			input(x);

			if (c == '+') {
				s.upd(x, {0, 0, 0, x, 1});
				b.insert(x);
			}
			else if (c == '-') {
				s.upd(x, {1, 1, 1, 0, 1});
				b.erase(x);
			}
			else {
				if (s.a[0][0] < x) {
					cout << (*b.rbegin() + 1) << ' ';
				}
				else {
					cout << (s.get(x) + 1) << ' ';
				}
			}
		}
		cout << endl;

		if (tc) {
			for (int i : b) {
				s.upd(i, {1, 1, 1, 0, 1});
			}
		}
	}
}
