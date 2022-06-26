#include <iostream>
#include <cmath>

int backjoon1790()
{
    int N, k;
    long long refArray[9];

    scanf("%d %d", &N, &k);

    refArray[0] = 9;
    long long temp = 10;

    for (long long i = 1; i < 9; i++) {
        refArray[i] = (i + 1) * temp * 9 + refArray[i - 1];
        temp *= 10;
    }

    int result = -1;

    for (int i = 0; i < 9; i++) {
        if (k > refArray[i]) {
            continue;
        }

        if (i == 0) {
            result = (k <= N) ? k : -1;
            break;
        }

        long temp = k - refArray[i - 1];
        long quotient = temp / (i + 1);
        long remainder = temp % (i + 1);
        long startNum = long(pow(10, i)) + quotient - 1;

        if (remainder == 0) {
            result = (startNum <= N) ? startNum % 10 : -1;
            break;
        }
        else {
            long nextNum = startNum + 1;
            result = (nextNum <= N) ? (nextNum / long(pow(10, i + 1 - remainder))) % 10 : -1;
            break;
        }
    }

    printf("%d\n", result);

    return 0;
}