#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	
	int n; input(n);

	stack<int> s;
	vector<int> a;
	range(i, 0, n) {
		int x; input(x);
		while (!s.empty() &&  a[s.top()] >= x) {
			s.pop();
		}

		if (s.empty()) {
			cout << "0 ";
		}
		else {
			cout << s.top() + 1 << " ";
		}
		s.push(i);
		a.push_back(x);
	}
}