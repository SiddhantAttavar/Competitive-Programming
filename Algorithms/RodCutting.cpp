<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int main() {
    input(int, n);
    arrput(int, a, n);
    range(i, 2, n + 1) {
        range(j, 1, i / 2 + i % 2 + 1) {
            a[i - 1] = max(a[i - 1], a[j - 1] + a[i - j - 1]);
        }
    }
    print(a[n - 1]);
=======
#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int main() {
    input(int, n);
    arrput(int, a, n);
    range(i, 2, n + 1) {
        range(j, 1, i / 2 + i % 2 + 1) {
            a[i - 1] = max(a[i - 1], a[j - 1] + a[i - j - 1]);
        }
    }
    print(a[n - 1]);
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}