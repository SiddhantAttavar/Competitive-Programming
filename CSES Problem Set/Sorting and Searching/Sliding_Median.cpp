#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

long N, M;
long arr[200010];
multiset<long> up;
multiset<long> low;

void ins(long val){ // insert val into sets
	long a = *low.rbegin(); // current median
	if(a < val){
		up.insert(val);
		if(up.size() > M/2){
			low.insert(*up.begin());
			up.erase(up.find(*up.begin()));
		}
	}
	else{
		low.insert(val);
		if(low.size() > (M + 1)/2){
			up.insert(*low.rbegin());
			low.erase(low.find(*low.rbegin()));
		}
	}
}

void er(long val){ // erase from sets
	if(up.find(val) != up.end()) up.erase(up.find(val));
	else low.erase(low.find(val));
	if(low.empty()){
		low.insert(*up.begin());
		up.erase(up.find(*up.begin()));
	}
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> arr[i];
	low.insert(arr[0]); for(int i = 1; i < M; i++) ins(arr[i]);
	cout << *low.rbegin() << " ";
	for(long i = M; i < N; i++){
		if(M == 1){
			ins(arr[i]);
			er(arr[i - M]);
		}
		else{
			er(arr[i - M]);
			ins(arr[i]);
		}
		cout << *low.rbegin() << " ";
	}
	cout << endl;
}