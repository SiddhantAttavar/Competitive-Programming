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
	arrput(int, a, n);
	
	unordered_map<int, bool> map;
	for (int i : a) {
		map[i] = false;
	}

	range(i, 0, n) {
		range(j, 0, n) {
			if (i != j && a[i] % 2 == a[j] % 2 && map.find((a[i] + a[j]) / 2) != map.end() && !map[(a[i] + a[j]) / 2]) {
				map[(a[i] + a[j]) / 2] = true;
			}
		}
	}

	int res = 0;
	for (int i : a) {
		res += map[i];
	}
	print(res);
}