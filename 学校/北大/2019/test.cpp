#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
#define INF 1000000
using namespace std;
int n,f,l;
int w[103][103];
void floyed()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
            }
        }
    }
    if(w[f][l]<INF)
        printf("%d\n",w[f][l]);
    else
        printf("-1\n");
}
int main()
{
	scanf("%d%d%d",&n,&f,&l);
    
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++)
           {
               w[i][j]=(i==j?0:INF);
           }
       }
        int m;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&m);
            for(int j=1; j<=m; j++)
            {
                int x;
                scanf("%d",&x);
                if(j==1)
                    w[i][x]=0;
                else
                    w[i][x]=1;
            }
        }
        floyed();
    
}
