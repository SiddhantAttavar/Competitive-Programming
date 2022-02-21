#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);
 
int n, d, k;
const int MOD = 1000000007;
 
int solve(int n, int k) {
    int prefSum[n + 2];
    prefSum[0] = 0;
    prefSum[1] = 1;
    
    range(i, 2, n + 2) {
        prefSum[i] = (((prefSum[i - 1] + prefSum[i - 1] - prefSum[max(0, i - k - 1)]) % MOD) + MOD) % MOD;
    }
    
    return ((prefSum[n + 1] - prefSum[n]) % MOD + MOD) % MOD;
}
 
int main() {
    setup();
    cin >> n >> k >> d;
    
    print((((solve(n, k) - solve(n, d - 1)) % MOD) + MOD) % MOD);
}
