#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

int main() {
	setup();

	input(int, n);
	arrput(int, a, n);
	
	int b[n];
	tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t;
	range(i, 0, n) {
		t.insert(i);
	}

	for (int i = n - 1; i >= 0; i--) {
		int k = *(t.find_by_order(t.size() - (a[i] + 1)));
		t.erase(k);
		b[k] = i + 1;
	}

	for (int i : b) {
		cout << i << " ";
	}
}