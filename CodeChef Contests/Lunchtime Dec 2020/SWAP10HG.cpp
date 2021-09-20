#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
    setup();
    input(int, tc); while (tc--) {
        input(int, n);
        char a[n], b[n];
        cin >> a >> b;
        int curr = 0;
        bool flag = true;
        range(i, 0, n) {
            if (a[i] != b[i]) {
                if (a[i] == '0') {
                    if (curr == 0) {
                        flag = false;
                        break;
                    }
                    curr--;
                }
                else {
                    curr++;
                }
            }
        }
        print((flag && curr == 0 ? "Yes": "No"));
    }
}