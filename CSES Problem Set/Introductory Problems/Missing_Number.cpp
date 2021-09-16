#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
	setup();
	
	input(int, n);
	bool present[n];
	fill(present, present + n, false);
	range(i, 0, n - 1) {
		input(int, x);
		present[x - 1] = true;
	}
	range(i, 0, n) {
		if (!present[i]) {
			print(i + 1);
			break;
		}
	}
}