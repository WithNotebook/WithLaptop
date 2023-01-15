#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> router;

int find_max_dist(int n, int c) {

    int start = 1;
    int end = router[n - 1] - router[0];


    int result_dist = 0;

    while (start <= end) {

        int install_router = 1;
        int prev_house = router[0];

        int mid = (start + end) / 2;

        for (int i = 1; i < n; ++i) {

            if (router[i] - prev_house >= mid) {
                install_router++;
                prev_house = router[i];
            }
        }

        if (install_router >= c) {
            result_dist = max(mid, result_dist);
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return result_dist;

}

int 2110() {

    int house_n, router_n;
    cin >> house_n >> router_n;

    int h_loccation;
    for (int i = 0; i < house_n; ++i) {
        cin >> h_loccation;
        router.push_back(h_loccation);
    }
    sort(router.begin(), router.end());

    cout << find_max_dist(house_n, router_n);

}