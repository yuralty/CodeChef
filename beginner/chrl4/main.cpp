#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

const int modulo = 1000000007;

struct Street {
    int id;
    int num;
    double log;
    long long dp;
    double dplog;
    bool operator > (const Street &st) const
    {
        return dplog > st.dplog;
    }
};

int main()
{
    priority_queue<Street, vector<Street>, greater<Street> > queue;
    int n, k;
    cin >> n >> k;
    Street *streets = new Street[n];
    for (int i = 0; i < n; ++i) {
        streets[i].id = i;
        cin >> streets[i].num;
        streets[i].log = log10(streets[i].num);
    }

    streets[0].dp = streets[0].num;
    streets[0].dplog = streets[0].log;

    queue.push(streets[0]);
    for (int i = 1; i < n; ++i) {
        Street lower = queue.top();
        while(lower.id < i-k) {
            queue.pop();
            lower = queue.top();
        }
        streets[i].dp = lower.dp * streets[i].num % modulo;
        streets[i].dplog = lower.dplog + streets[i].log;
        queue.push(streets[i]);
    }

    cout << streets[n-1].dp << endl;


    return 0;
}
