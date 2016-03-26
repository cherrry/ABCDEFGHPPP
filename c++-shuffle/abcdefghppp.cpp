#include <cstdio>
#include <algorithm>

using namespace std;

#define X(a, b) (x[a]*10+x[b])
int x[] = { 8, 5, 4, 6, 3, 9, 7, 2, 1, 0 }; // I know this will be fast :)

int correct() {
    int ab = X(0, 1), cd = X(2, 3), ef = X(4, 5), gh = X(6, 7), ppp = x[8] * 111;
    return (
        (ab >= 10 && cd >= 10 && ef >= 10 && gh >= 10) &&
        (ab - cd) == ef &&
        (ef + gh) == ppp
    );
}

int main() {
    while (!correct()) {
        random_shuffle(x, x + 10);
    };

    int ab = X(0, 1), cd = X(2, 3), ef = X(4, 5), gh = X(6, 7), ppp = x[8] * 111;
    printf("%d - %d = %d, %d + %d = %d\n", ab, cd, ef, ef, gh, ppp);

    return 0;
}
