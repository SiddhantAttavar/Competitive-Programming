#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup();

	int x;
	input(x);
	if (x == 1) {
		print("yoink a\nyoink b\n*slaps a on top of b*\nyeet b\ngo touch some grass\n");
	}
	else if (x == 2) {
		print("yoink a\nbruh b is lowkey just 0\nrip this b fell off by a\nvibe check a ratios b\nsimp for 7\nbruh a is lowkey just b\nyeet a\ngo touch some grass");
	}
	else if (x == 3) {
		print("yoink n\nyoink a\nbruh m is lowkey just a[0]\nbruh i is lowkey just 1\nvibe check n ratios i\nsimp for 9\nyeet m\ngo touch some grass\nvibe check a[i] ratios m\nbruh m is lowkey just a[i]\n*slaps 1 on top of i*\nsimp for 5\n");
	}
	else {
		print("yoink n\nyoink a\nbruh i is lowkey just n\nvibe check i ratios 1\nsimp for 7\nsimp for 22\nbruh j is lowkey just 1\nvibe check i ratios j\nsimp for 11\nsimp for 20\nbruh k is lowkey just j\n*slaps -1 on top of k*\nvibe check a[k] ratios a[j]\nsimp for 18\nbruh tmp is lowkey just a[j]\nbruh a[j] is lowkey just a[k]\nbruh a[k] is lowkey just tmp\n*slaps 1 on top of j*\nsimp for 8\nrip this i fell off by 1\nsimp for 4\nyoink k\nrip this k fell off by 1\nyeet a[k]\ngo touch some grass");
	}
}
