#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n;
vector<int> a;
vector<int> memo;

int main() {
    setup();
    input(int, tc); while (tc--) {
        cin >> n;
        a = vector<int>(n);
        memo = vector<int>(n);
        range(i, 0, n) {
            cin >> a[i];
            memo[i] = -1;
        }
        
        unordered_map<int, int> map;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 2;
        range(i, 2, n + 1) {
            dp[i] = dp[i - 1] + 1;
            if (map.find(a[i - 1]) != map.end()) {
                if (map[a[i - 1]] == 0) {
                    dp[i] = min(dp[i], i - 2);
                }
                else {
                    dp[i] = min(dp[i], (i - map[a[i - 1]] - 1) + dp[map[a[i - 1]] - 1]);
                }
            }
            map[a[i - 1]] = i;
        }
        print(dp[n] - 1);
    }
}