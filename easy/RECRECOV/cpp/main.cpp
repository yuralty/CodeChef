#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
using namespace std;

#define NMAX 101

vector<int> connect[NMAX];
int parent[NMAX];
bool used[NMAX];

bool dfs(int id)
{
    for (auto child : connect[id])
    {
        if (!parent[child])
        {
            
        }
    }
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            connect[i].clear();
        }

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            connect[a].push_back(b);
        }
    }
    return 0;
}
