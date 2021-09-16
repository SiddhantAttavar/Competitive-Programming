#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

int main() {
	setup();
	input(int, n);
	tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> t;
	range(i, 0, n) {
		input(int, x);
		print(t.order_of_key(x) + 1);
		t.insert(x);
	}
}