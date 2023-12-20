#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
constexpr int N=35;
 
int t,n,m,x,y,ex,ey,fx,fy,k,ai,bi;
int za[N][N],huo[N][N],temp1[N][N],sum[N][N],temp3[N][N];
int dx[8]={1,0,0,-1,1,1,-1,-1},dy[8]={0,1,-1,0,1,-1,1,-1};
 
int bfs1(int x,int y)
{
    queue<pair<int,int >>q;
    q.push(make_pair(x,y));
    temp1[x][y]=1;
    while(!q.empty())
    {
        auto z=q.front();
        q.pop();
        for(int i=0;i<8;i++ )
        {
            int xx=z.first+dx[i],yy=z.second+dy[i];
            if(xx>=1&&y>=1&&xx<=n&&yy<=m&&temp1[xx][yy]==0)
            {
                temp1[xx][yy]=1;
                huo[xx][yy]=huo[z.first][z.second]+1;
                q.push(make_pair(xx,yy));
            }
        }
    }
    return 0;
}
void bfs2(int a1,int b1){
    queue<pair<int,int >>que;
    que.push(make_pair(a1,b1));
    temp3[a1][b1]=1;
    while(!que.empty()){
        auto w=que.front();
        que.pop();
        int ans=sum[w.first][w.second]+1;
        if(w.first==ex&&w.second==ey){
            printf("%d\n",ans-1);
            return;
        }
        for(int i=0;i<4;i++ )
        {
            int aa=w.first+dx[i],bb=w.second+dy[i];
            if(aa==ex&&bb==ey&&za[aa][bb]==0&&temp3[aa][bb]==0&&ans<=huo[aa][bb])
            {
                printf("%d\n",ans);
                return;
            }
            if(aa>=1&&bb>=1&&aa<=n&&bb<=m&&za[aa][bb]==0&&temp3[aa][bb]==0&&ans<huo[aa][bb])
            {
                temp3[aa][bb]=1;
                que.push(make_pair(aa,bb));
                sum[aa][bb]=ans;
            }
        }
    }
    printf("T_T\n");
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        scanf("%d%d%d%d%d%d",&x,&y,&ex,&ey,&fx,&fy);
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%d%d",&ai,&bi);
            za[ai][bi]=1;
        }
        bfs1(fx,fy);
        bfs2(x,y);
        int num1=sizeof(za);
        int num2=sizeof(temp1);
        int num3=sizeof(temp3);
        int num4=sizeof(sum);
        int num5=sizeof(huo);
        memset(za,0,num1);
        memset(temp1,0,num2);
        memset(temp3,0,num3);
        memset(sum,0,num4);
        memset(huo,0,num5);
    }
}