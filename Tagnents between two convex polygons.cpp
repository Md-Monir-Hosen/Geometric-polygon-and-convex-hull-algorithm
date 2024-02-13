#include<bits/stdc++.h>
using namespace std;
pair<int,int> mid;

int quad(pair<int,int> p)
{
    if (p.first >= 0 && p.second >= 0)
        return 1;
    if (p.first <= 0 && p.second >= 0)
        return 2;
    if (p.first <= 0 && p.second <= 0)
        return 3;
    return 4;
}
int orientation(pair<int,int> a, pair<int,int> b,
                                 pair<int,int> c)
{
    int res = (b.second-a.second)*(c.first-b.first) -
              (c.second-b.second)*(b.first-a.first);

    if (res == 0)
        return 0;
    if (res > 0)
        return 1;
    return -1;
}
bool compare(pair<int,int> p1, pair<int,int> q1)
{
    pair<int,int> p = make_pair(p1.first - mid.first,
                                p1.second - mid.second);
    pair<int,int> q = make_pair(q1.first - mid.first,
                                q1.second - mid.second);

    int one = quad(p);
    int two = quad(q);

    if (one != two)
        return (one < two);
    return (p.second*q.first < q.second*p.first);
}
void findUpperTangent(vector<pair<int,int> > a,
                      vector<pair<int,int> > b)
{
    int n1 = a.size(), n2 = b.size();

    int maxa = INT_MIN;
    for (int i=0; i<n1; i++)
    {
        maxa = max(maxa, a[i].first);
        mid.first  += a[i].first;
        mid.second += a[i].second;
        a[i].first *= n1;
        a[i].second *= n1;
    }
    sort(a.begin(), a.end(), compare);

    for (int i=0; i<n1; i++)
    {
        a[i].first /= n1;
        a[i].second /= n1;
    }

    mid = {0, 0};

    int minb = INT_MAX;
    for (int i=0; i<n2; i++)
    {
        mid.first += b[i].first;
        mid.second += b[i].second;
        minb = min(minb, b[i].first);
        b[i].first *= n2;
        b[i].second *= n2;
    }
    sort(b.begin(), b.end(), compare);

    for (int i=0; i<n2; i++)
    {
        b[i].first/=n2;
        b[i].second/=n2;
    }
    if (minb < maxa)
    {
        a.swap(b);
        n1 = a.size();
        n2 = b.size();
    }
    int ia = 0, ib = 0;
    for (int i=1; i<n1; i++)
        if (a[i].first > a[ia].first)
            ia = i;
    for (int i=1; i<n2; i++)
        if (b[i].first < b[ib].first)
            ib=i;
    int inda = ia, indb = ib;
    bool done = 0;
    while (!done)
    {
        done = 1;
        while (orientation(b[indb], a[inda], a[(inda+1)%n1]) > 0)
            inda = (inda + 1) % n1;

        while (orientation(a[inda], b[indb], b[(n2+indb-1)%n2]) < 0)
        {
            indb = (n2+indb-1)%n2;
            done = 0;
        }
    }

    cout << "upper tangent (" << a[inda].first << ","
        << a[inda].second << ") (" << b[indb].first
        << "," << b[indb].second << ")\n";
}
int main()
{
     vector<pair<int,int> > a;
    a.push_back({2, 2});
    a.push_back({3, 1});
    a.push_back({3, 3});
    a.push_back({5, 2});
    a.push_back({4, 0});

    vector<pair<int,int> > b;
    b.push_back({0, 1});
    b.push_back({1, 0});
    b.push_back({0, -2});
    b.push_back({-1, 0});

    findUpperTangent(a, b);

    return 0;
}
