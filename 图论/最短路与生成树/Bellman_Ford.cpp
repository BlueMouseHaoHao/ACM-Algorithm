#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10000
int n,m;

struct Edge{
    int v,w;
    Edge(int v,int w):v(v),w(w){}
};

vector<Edge> e[MAX];

void addEdge(int u,int v,int w)
{
    e[u].push_back(Edge(v,w));
}

int dis[MAX];
const int inf = 1<<30;
void Bellman_ford(int s)
{
    for(int i = 0;i <= n;i++)
        dis[i] = inf;
    dis[s] = 0;
    for(int i = 1;i < n;i++)//n�����㣬����n-1��ȫ���ɳ�
    {
        for(int u = 1;u <= n;u++)//ÿ��ȫ���ɳڣ������еĶ��㶼���ٱ��ɳ�
        {
            for(int j = 0;j < e[u].size();j++)
            {
                int v = e[u][j].v;
                int w = e[u][j].w;
                if(dis[u] + w < dis[v])
                    dis[v] = dis[u] + w;
            }
        }
    }
}

int main()
{
    int a,b,c,i,j;
    while(~scanf("%d%d",&n,&m))
    {
        for(i = 0;i <= n;i++)
            e[i].clear();
        for(i = 0;i < m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        Bellman_ford(1);//�ӵ�һ�������
        for(i = 1;i <= n;i++)
            printf("%d ",dis[i]);
        printf("\n");
    }
    return 0;
}
/*
Bellman_ford:
5 7
2 4 3
1 2 2
1 4 7
1 3 6
3 5 1
2 5 6
4 5 5

0 2 6 5 7
*/
