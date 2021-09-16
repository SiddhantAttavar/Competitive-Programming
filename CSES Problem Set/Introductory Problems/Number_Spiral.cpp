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
	int tc; input(tc); while (tc--) {
		long long x, y;
		input(x);
		input(y);

		bool flag = true;
		if (x > y) {
			swap(x, y);
			flag = false;
		}
		if (flag == y % 2 == 0) {
			print((y - 1) * (y - 1) + x);
		}
		else {
			print(y * y - x + 1);
		}
	}
}