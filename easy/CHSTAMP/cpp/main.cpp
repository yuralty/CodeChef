#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

#define MAXN 200001
#define MAXM 50001
#define MAXT 50001

using namespace std;

struct Offer {
    Offer() {}
    Offer(int day, int from, int to) : day(day), from(from), to(to) {}
    int day, from, to;
    bool operator<(const Offer &o)
    {
        if (day < o.day) return true;
        if (day == o.day) return from < o.from;
        return false;
    }
};

int parent[MAXT];
int find(int x)
{
    if (parent[x] != x) return parent[x] = find(parent[x]);
    return x;
}

void join(int x, int y)
{
    int px = find(x), py = find(y);
    if (px > py) swap(px, py);
    parent[px] = py;
}


int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> stamps;
        set<int> reachable;
        for (int i = 0; i < n; ++i) {
            int s;
            cin >> s;
            stamps.push_back(s);
            reachable.insert(s);
        }
        for (int i = 0; i < MAXT; ++i) {
            parent[i] = i;
        }

        vector<Offer> offers;
        for (int i = 0; i < m; ++i) {
            int day, from, to;
            cin >> day >> from >> to;

            if (from > to) swap(from, to);
            Offer newOffer(day, from, to);
            offers.push_back(newOffer);
        }
        sort(offers.begin(), offers.end());


        int cur = 0;
        vector<pair<int, int> > disconnect;
        for(Offer offer : offers)
        {
            if (offer.day > cur) {
                for (auto pair : disconnect)
                {
                    if (reachable.find(find(pair.first)) == reachable.end())
                    {
                        parent[pair.first] = pair.first;
                        parent[pair.second] = pair.second;
                        std::cout << "this is a bad change";
                    }
                }

                cur = offer.day;
                disconnect.clear();
            }
            join(offer.from, offer.to);
            if (reachable.find(offer.from) != reachable.end()
                || reachable.find(offer.to) != reachable.end())
                reachable.insert(offer.from), reachable.insert(offer.to);
            else
                disconnect.push_back(make_pair(offer.from, offer.to));
        }

        long long sum = 0;
        for (int origin : stamps)
            sum += find(origin);

        for (int i=1; i<=10; ++i)
            std::cout << parent[i] << " ";
        std::cout << std::endl;


        std::cout << sum << std::endl;
        std::cout << "this is a good change" << std::endl;
    }

    return 0;
}
