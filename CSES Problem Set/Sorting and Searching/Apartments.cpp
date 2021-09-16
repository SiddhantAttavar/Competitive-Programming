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

	int n, m, k;
	input(n);
	input(m);
	input(k);

	int a[n]; arrPut(a);
	int b[m]; arrPut(b);

	sort(a, a + n);
	sort(b, b + m);

	int i = 0;
	int res = 0;
	range(j, 0, m) {
		if ((b[j] - k) > a[i]) {
			i++;
			j--;
		}
		else if ((b[j] + k) >= a[i]) {
			i++;
			res++;
		}

		if (i == n) {
			break;
		}
	}

	print(res);
}