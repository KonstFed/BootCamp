#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void find_shortest_path_5(int distances[5][5])
{
    int currentMinimalPathDistance = 1000000;
    int answ[5];
    int firstCity = 0;
    for (int sc = 1; sc<5; sc++)
    {
        for (int tc = 1; tc < 5; tc++)
        {
            for (int fc = 1; fc<5; fc ++)
            {
                for (int fivec = 1; fivec<5; fivec++)
                {
                    int tmp[5] = {0,sc,tc,fc,fivec};
                    bool flag = true;
                    for (int f_ind = 0; f_ind < 5; f_ind++)
                    {
                        for (int s_ind = 0; s_ind < 5; s_ind++)
                        {
                            if (f_ind!=s_ind)
                            {
                                int fccheck = tmp[f_ind];
                                int sccheck = tmp[s_ind];
                                if (fccheck == sccheck)
                                {
                                    flag = false;
                                }
                            }
                        }
                    }
                    if (flag)
                    {

                        int cursum = distances[firstCity][sc] + distances[sc][tc] + distances[tc][fc] + distances[fc][fivec] + distances[fivec][firstCity];

                        if (currentMinimalPathDistance > cursum)
                        {
                            currentMinimalPathDistance = cursum;
                            for (int i = 0; i <= 4; i++)
                            {
                                cout<<tmp[i];
                                answ[i] = tmp[i];
                            }
                            cout<<"\n";
                        }
                        currentMinimalPathDistance = min(currentMinimalPathDistance,cursum);
                    }
                }
            }
        }
    }
    cout<<"Minimum path is "<<currentMinimalPathDistance<<"\n";
    for (int i = 0; i < 5; i++)
    {
        cout<<answ[i]<<" ";
    }
}
int cost_path(vector<int> a, vector<vector<int>> distances)
{
    int s = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        vector<int> kavo = distances[a[i]];
        s += kavo[a[(i+1)%n]];

    }
    return s;
}
void printVector2d(vector<vector<int>> a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        vector<int> b = a[i];
        for (int j = 0; j<n; j++)
        {
            cout<<b[j]<<' ';
        }
        cout<<'\n';
    }
}
void find_shortest_path(vector<vector<int>> distances)
{
    printVector2d(distances);
    int n = distances.size();
    int minCos = 10000000;
    vector<int> a(n);
    vector<int> best(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    do {
        int curs = cost_path(a,distances);
        if (curs < minCos)
        {
            minCos = curs;
            for (int i = 0; i < n; i ++)
            {
                best[i] = a[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout<<a[i]<<' ';
        }
        cout<<curs<<'\n';
    } while (next_permutation(a.begin(),a.end()));
    cout<<"Minimal cost is "<<minCos<<'\n';
    for (int i = 0; i < n; i++)
    {
        cout<<best[i]<<' ';
    }
}

int main() {
    int n;
    cin>>n;

    vector<vector<int>> distances(n);

    for (int i = 0; i < n; i++)
    {
        vector<int> tmp(n);
        for (int j = 0; j < n; j++)
        {
            cin>>tmp[j];
        }
        distances[i] = tmp;
    }

    find_shortest_path(distances);



//    if (n == 5)
//    {
//        int distances[5][5];
//        for (int i = 0; i < 5; i++)
//        {
//            for (int j = 0; j < 5; j++)
//            {
//                cin>>distances[i][j];
//            }
//        }
//        find_shortest_path_5(distances);
//    }
}
