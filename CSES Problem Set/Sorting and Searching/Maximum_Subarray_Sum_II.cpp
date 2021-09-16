#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll LINF = 1e18;

int N, A, B;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> A >> B; // reading in variables

	vector<long long> pfx(N+1); 
	for(int i = 1; i <= N; i++) {
		int a; cin >> a;
		pfx[i] = a + pfx[i-1]; // construction of our prefix sum
	}

	ll ret = -LINF;
	multiset<ll> ms;

	// we can keep a sliding window of size B, then find the lowest pfx[j] using multiset
	for(int i = A; i <= N; ++i) {
		if(i > B) ms.erase(ms.find(pfx[i-B-1])); //erase the element if size > B
		ms.insert(pfx[i-A]);
		ret = max(ret, pfx[i]-*ms.begin()); //we want to minimize ms.begin() aka pfx[j]
	}

	cout << ret << "\n";
}