#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

struct SegTree {
	int n;
	vector<int> a;
	vector<int> segmentTree;

	//Build Array
	int build(int l, int r, int x) {
		if ((r - l) <= 1) {
			//We have reached a leaf
			segmentTree[x] = a[l];
			return segmentTree[x];
		}

		//Divide into 2 halves and recursively build the segment tree
		int m = (l + r) / 2;
		segmentTree[x] = max(build(l, m, 2 * x), build(m, r, 2 * x + 1));
		return segmentTree[x];
	}

	//Range query from segment tree
	int query(int s, int e, int l, int r, int x) {
		if (r <= s || l >= e) {
			//Range is outside target range
			return 0;
		}
		if (l >= s && r <= e) {
			//Range is completely inside target range
			return segmentTree[x];
		}

		//Range has an intersection with target range
		int m = (l + r) / 2;
		return max(query(s, e, l, m, 2 * x), query(s, e, m, r, 2 * x + 1));
	}

	//Point update of segment tree
	int update(int i, int v, int l, int r, int x) {
		if (i < l || i >= r) {
			//Target position not in range
			return segmentTree[x];
		}
		if ((r - l) == 1) {
			//Position is found
			segmentTree[x] = v;
			a[i] = v;
			return segmentTree[x];
		}

		//Split subtree into 2 halves and recursively search for value
		int m = (l + r) / 2;
		segmentTree[x] = max(update(i, v, l, m, 2 * x), update(i, v, m, r, 2 * x + 1));
		return segmentTree[x];
	}
};

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	vector<vector<int>> a(n, vector<int>(m));
	vector<SegTree> s(n);
	range(i, 0, n) {
		s[i].segmentTree = vector<int>(4 * n);
		arrPut(s[i].a);
		s[i].build(0, m, 1);
	}

	int res = 0;
	range(p, 0, m - k + 1) {
		res ++ 
	}

	print(res);
}
