#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
using namespace std;

#define NMAX 101

vector<int> connect[NMAX];
int parent[NMAX];
bool mark[NMAX];

bool insert(int id)
{
    for (auto child : connect[id])
    {
        if (mark[child]) continue;
        mark[child] = true;
        if (!parent[child] || insert(parent[child]))
        {
            parent[child] = id;
            return true;
        }
    }
    return false;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            connect[i].clear();
        }
        memset(parent, 0, sizeof parent);

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            connect[a].push_back(b);
        }

        int cnt = n;
        for (int i = 1; i <= n; ++i) {
            memset(mark, 0, sizeof mark);
            if (insert(i)) --cnt;
        }
        std::cout << cnt << std::endl;
    }
    return 0;
}
