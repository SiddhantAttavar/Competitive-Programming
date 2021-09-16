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

int x,n,p; set<int> lights; multiset<int> dist;

int main() {
	setup();
	
	cin >> x >> n;
	lights.insert(0); lights.insert(x);
	dist.insert(x);
	for (int i=0;i<n;++i){
		cin >> p;
		auto it1 = lights.upper_bound(p),it2 = it1; --it2;
		dist.erase(dist.find(*it1-*it2));
		dist.insert(p-*it2); dist.insert(*it1-p);
		lights.insert(p);
		auto ans = dist.end(); --ans;
		cout << *ans << " ";
	}
}