#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>a[1000];
int visited[7]={0};
int dis[7]={0};
deque<int>q;
void bfs(int s)
{
    if(visited[s]==0)
    {
        visited[s] = 1;
        q.push_back(s);
    }
    if(!q.empty())
    {
        for(int i=0;i<a[s].size();i++)
        {
            if(visited[a[s][i]]==0)
            {
                int d = a[s][i];
                visited[d] = 1;
                dis[d]= dis[s]+1;
                q.push_back(d);
            }
        }
    }
    q.pop_front();
    int k = q.front();
    if(q.empty())
        return;
    bfs(k);
}

int main()
{
    int n,e,s=1;
    cin >> n >> e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    bfs(s);

    for(int i=1;i<=n;i++)
        cout << "node :" << i << ' ' << "level : " << dis[i] << endl;
}


/* Sample Input 
7 17
1 2
1 3
1 7
2 3
2 4
3 1
3 2
3 6
3 7
4 2
4 5
5 4
5 6
6 3
6 5
7 1
7 3
*/
