#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

vector<int> segTree;
bool flag = true;
int n, q;

void update(int x, int l, int r, int i, int s, int e) {
	if (i < s or e < i) {
		return;
	}
	if (l <= s and e <= r) {
		if (segTree[x] != -1 and segTree[x] != i) {
			flag = false;
			return;
		}
		segTree[x] = i;
	}
	if (x > n) {
		return;
	}

	int mid = (s + e) / 2;
	update(2 * x, l, r, i, s, mid);
	update(2 * x + 1, l, r, i, mid + 1, e);
}

int32_t main() {
	setup();
	input(n, q);
	segTree.resize(4 * n + 1, -1);
	range(i, 0, n) {
		update(1, i, i, i, 0, n - 1);
	}
	arrPrint(segTree);
	range(i, 0, q) {
		int a, b, c; input(a, b, c);
		a--; b--; c--;
		update(1, a, b, c, 0, n - 1);
	}
	if (!flag) {
		print(-1);
		return 0;
	}
	//arrPrint(segTree);
	int c = 1;
	set<int> s;
	vector<int> b(n);
	range(i, 1, 4 * n + 1) {
		if (segTree[i] != -1 and s.find(segTree[i]) == s.end()) {
			b[segTree[i]] = c;
			c++;
			s.insert(segTree[i]);
		}
	}
	arrPrint(b);
}
