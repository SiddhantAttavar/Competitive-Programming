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
	input(int, n);
	arrput(int, p, n);

	range(a, 0, n) {
		unordered_set<int> s;
		int curr = a;
		while (s.find(curr) == s.end()) {
			s.insert(curr);
			curr = p[curr] - 1;
		}
		cout << curr + 1 << " ";
	}
}