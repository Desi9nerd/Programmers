#include <string>
#include <vector>
using namespace std;

long long solution(int cap, int n, vector<int> dv, vector<int> pickups) {
    long long answer = 0;

    int i = n - 1;
    while (i >= 0) {
        while (i >= 0 && dv[i] == 0 && pickups[i] == 0) {
            i--;
        }
        if (i < 0) break;

        answer += (i + 1) * 2; // 현재 집까지 이동 + 택배창고까지 되돌아감.

        int box = cap;
        for (int j = i; j >= 0; j--) {
            if (dv[j] > 0) {
                int deliverable = min(dv[j], box);
                dv[j] -= deliverable;
                box -= deliverable;
            }
            if (box == 0) break;
        }

        int recycle = cap;
        for (int j = i; j >= 0; j--) {
            if (pickups[j] > 0) {
                int pickupable = min(pickups[j], recycle);
                pickups[j] -= pickupable;
                recycle -= pickupable;
            }
            if (recycle == 0) break;
        }

        while (i >= 0 && dv[i] == 0 && pickups[i] == 0) {
            i--;
        }
    }

    return answer;
}