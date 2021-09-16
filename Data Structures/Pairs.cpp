#include <bits/stdc++.h>
using namespace std;
#define print(x) printf("%d\n", x);
#define printd(x) printf("%f\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define range(i, n) for (int i = 0; i < n; i++)
#define reverseRange(i, n) for (int i = n - 1; i >= 0; i++)
#define stepRange(i, n, s) for (int i = 0; i < n; i += s)
#define len(a) (*(&a + 1) - a)

int main() {
    //Constructors
    pair<int, char> pair1;
    pair1.first = 1;
    pair1.second = 'A';
    pair<int, char> pair2(2, 'B');
    pair<int, char> pair3 = make_pair(3, 'C');

    println("1st pair: %d, %c", pair1.first, pair1.second);
    println("2nd pair: %d, %c", pair2.first, pair2.second);
    println("3rd pair: %d, %c", pair3.first, pair3.second);
    
    if (pair1 > pair2) {
        println("First pair is greater");
    }
    else if (pair1 < pair2) {
        println("Second pair is greater");
    }
    else {
        println("1st and 2nd pair are equal");
    }
}