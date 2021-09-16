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
	
	input(string, s);
	char curr = s[0];
	int currLen = 1;
	int res = 0;
	range(i, 1, s.size()) {
		if (curr != s[i]) {
			res = max(res, currLen);
			curr = s[i];
			currLen = 0;
		}
		currLen++;
	}
	print(max(res, currLen));
}