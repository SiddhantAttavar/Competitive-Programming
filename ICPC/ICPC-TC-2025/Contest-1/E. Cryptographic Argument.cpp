#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define endl '\n'
 
int k, m, l, r, h, a, b, c, n;
// Use unsigned long long for bitwise operations
typedef unsigned long long ull;

inline ull bitreverse64(ull n) {
    n = (n & 0xAAAAAAAAAAAAAAAA) >> 1 | (n & 0x5555555555555555) << 1;
    n = (n & 0xCCCCCCCCCCCCCCCC) >> 2 | (n & 0x3333333333333333) << 2;
    n = (n & 0xF0F0F0F0F0F0F0F0) >> 4 | (n & 0x0F0F0F0F0F0F0F0F) << 4;
    n = (n & 0xFF00FF00FF00FF00) >> 8 | (n & 0x00FF00FF00FF00FF) << 8;
    n = (n & 0xFFFF0000FFFF0000) >> 16 | (n & 0x0000FFFF0000FFFF) << 16;
    n = (n >> 32) | (n << 32);
    return n;
    
}
inline int value(int row) {
    // k=0, n=1. The only index is 0, its value is 0.
    if (k == 0) return 0; 

    // Get the least significant bit (b0)
    int b0 = row & 1;

    // k=1, n=2. a[0]=0, a[1]=1. The value is just the index itself.
    if (k == 1) return b0;

    // --- k >= 2 ---
    
    // Get the bits b_{k-1} ... b_1
    // We cast row to ull for the 64-bit reversal
    ull i_prime = (ull)row >> 1;
    
    // k-1 is the number of bits in i_prime
    int k_minus_1 = k - 1;

    // 1. __builtin_bitreverse64(i_prime) reverses all 64 bits.
    //    This turns (0...0 b_{k-1} ... b_1) into (b_1 ... b_{k-1} 0...0)
    // 2. We shift right by (64 - (k-1)) to get (0...0 b_1 ... b_{k-1})
    //    This is the bit-reversal of i_prime.
    ull reversed_i_prime = bitreverse64(i_prime) >> (64 - k_minus_1);

    ull col_prime;
    if (b0 == 0) {
        // If b0 is 0, c_j = b_{k-j}
        col_prime = reversed_i_prime;
    } else {
        // If b0 is 1, c_j = b_{k-j} ^ 1
        // This is (reversed_i_prime) ^ (11...1)
        ull mask = (1ULL << k_minus_1) - 1;
        col_prime = reversed_i_prime ^ mask;
    }

    // Combine (c_{k-1} ... c_1) with c_0
    // (col_prime << 1) | b0
    return (int)((col_prime << 1) | b0);
}
// inline int value(int row){
//     int sc = n;
//     int col = 0;
//     int sr = 1;
//     while(sc != 1){
//         sr <<= 1;
//         if(row >= ((sc>>1))){
//             row = sc - 1 - row;
//             col = sr - 1 - col;
//         }
//         sc >>= 1;
//     }
//     return col;
// }
 
inline int F(){
    if(l == r){
        return value(l);
    }
    int len = r - l + 1;
    if(l%2 == 0){
        int rem = len%4;
        if(rem == 0){
            return 0;
        } else if(rem == 1){
            return value(r);
        } else if(rem == 2){
            return n-1;
        } else{
            return ((n-1) ^ (value(r)));
        }
    } else {
        int pairs = len/2;
        if(len%2 == 0){
            return ((pairs-1) * ((n)-1)) + value(l) + value(r);
        } else{
            return value(l) + ((pairs) * ((n)-1));
        }
    }
}
const int mod = 1e9 + 7;
void solve() {
    cin >> k;
    n = (1ll<<k);
    cin >> m >> l >> r;
    cin >> a >> b >> c;
    h = 0;
    for(int times = 0; times < m; times++){
        h = ((l ^ r ^ h ^ F())+c)%mod;
        l = ((l ^ a ^ h)%(n+1));
        if(l == n){ l = 0; }
        r = ((r^b^h)%(n-l)) + l;
    }
    cout << h << endl;
}
 
signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1; while (t--) {
		solve();
	}
}
