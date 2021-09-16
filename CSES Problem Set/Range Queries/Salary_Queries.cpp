#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int MX = 4e5 + 5;
 
ll bit[MX];
vector<int> vals;
int n, q;
 
void upd (int i, int val) {
	for (; i <= MX; i += i&(-i)) {
		bit[i] += val;
	}
}
 
void ad(int x, int b) {
	int ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
	upd(ind, b);
}
 
ll sum (int x) {
	ll res = 0;
	for (; x; x -= x&(-x)) {
		res += bit[x];
	}
	return res;
}
 
ll query(int x) {
	int ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
	return sum(ind);
}
 
int main() {
	cin >> n >> q;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	vals = ar;
	vector<array<int, 3>> rec;
	for (int i = 0; i < q; i++) {
		char t;
		int a,b;
		cin >> t >> a >> b;
		rec.push_back({t == '?', a, b});
		if (t == '!') vals.push_back(b);
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for (int i = 0; i < n; i++) {
		ad(ar[i], 1);
	}
	for (auto u : rec) {
		u[1]--;
		if (u[0] == 0) {
				ad(ar[u[1]], -1);
				ar[u[1]] = u[2];
				ad(ar[u[1]], 1);
		} else {
			cout <<  query(u[2]) - query(u[1]) << '\n';
		}
	}
}