#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
	setup();
	input(int, m);
	int a[m];
	range(i, 0, m) {
		input(int, x);
		input(int, y);
		a[i] = min(x, y);
	}
	
	sort(a, a + m);
	int curr = a[0] - 1;
	range(i, 1, m) {
		if (a[i] == a[i - 1]) {
			if (curr > 0) {
				curr--;
			}
		}
		else {
			curr += a[i] - a[i - 1] - 1;
		}
	}
	print(a[m - 1] - curr);
}