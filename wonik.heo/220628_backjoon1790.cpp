#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int TENS = 10;
int DIGIT = 9;

int Problem_1790()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    long long k;
    cin >> n >> k;

    int count = 1;
    long long ans, digit_total;
    int ans_index;
    string ans_string;

    digit_total = DIGIT * pow(TENS, count - 1) * count;
    while ((k - digit_total) > 0)
    {
        k -= digit_total;
        count++;
        digit_total = DIGIT * pow(TENS, count - 1) * count;
    }

    ans_index = (k - 1) % count;
    ans = pow(TENS, count - 1) + (k - 1) / count;

    if (n < ans)
    {
        cout << "-1" << endl;
    }
    else
    {
        ans_string = to_string(ans);
        cout << char(ans_string[ans_index]) << endl;
    }
}
