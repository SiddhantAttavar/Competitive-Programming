#include <bits/stdc++.h>
#include <ext/rope>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	
	int n; input(n);
	rope<int> r;
	range(i, 0, n) {
		int x; input(x);
		r.push_back(x);
	}
	range(i, 0, n) {
		int p; input(p);
		p--;
		cout << r[p] << " ";
		r.erase(r.mutable_begin() + p);
	}
}