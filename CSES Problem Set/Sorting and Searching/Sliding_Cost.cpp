#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;
const ll mn = (ll) 2e5+5;

ll N, K;
ll arr[mn];
multiset<ll> up;
multiset<ll> low;
ll sLow, sUp;

void ins(ll val){
	ll a = *low.rbegin();
	if(a < val){
		up.insert(val); sUp += val;
		if(up.size() > K/2){
			ll moving = *up.begin();
			low.insert(moving); sLow += moving;
			up.erase(up.find(moving)); sUp -= moving;
		}
	}
	else{
		low.insert(val); sLow += val;
		if(low.size() > (K + 1)/2){
			ll moving = *low.rbegin();
			up.insert(*low.rbegin()); sUp += moving;
			low.erase(low.find(*low.rbegin())); sLow -= moving;
		}
	}
}

void er(ll val){
	if(up.find(val) != up.end()) up.erase(up.find(val)), sUp -= val;
	else low.erase(low.find(val)), sLow -= val;
	if(low.empty()){
		ll moving = *up.begin();
		low.insert(*up.begin()); sLow += moving;
		up.erase(up.find(*up.begin())); sUp -= moving;
	}
}

ll med(){ return (K%2 == 0) ? 0 : (*low.rbegin()); }

int main() {
	cin >> N >> K;
	for(ll i = 0; i < N; i++) cin >> arr[i];
	low.insert(arr[0]); sLow += arr[0];
	for(ll i = 1; i < K; i++) ins(arr[i]);
	cout << sUp - sLow + med(); if(N!=1) cout << " ";
	for(ll i = K; i < N; i++){
		if(K == 1){
			ins(arr[i]);
			er(arr[i - K]);
		}
		else{
			er(arr[i - K]);
			ins(arr[i]);
		}
		cout << sUp - sLow + med(); if(i != N -1) cout << " ";
	}
	cout << endl;
}