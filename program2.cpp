#include<bits/stdc++.h>
using namespace std;
struct p
{
    int x,y;
};
int main()
{
        int r,c,i,j,time1=0;
        struct p temp={-1,-1};
        struct p w;
        cin>>r>>c;
        int arr[r][c];
        for(i=0;i<r;i++)
        {   
            for(j=0;j<c;j++)
                cin>>arr[i][j];
        }
        queue<p> q;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                if(arr[i][j]==2)
                {
                    w.x=i;
                    w.y=j;
                    q.push(w);
                }
            }
            q.push(temp);
        while(!q.empty())
        {
            struct p t=q.front();
            q.pop();
            if(t.x==temp.x && t.y==temp.y)
                {
                if(q.empty())
                { break;}
                     time1++;
                    q.push(temp);
                    continue;
                }
                if(arr[t.x+1][t.y]==1 && t.x+1<r)
                    {
                        w.x=t.x+1;
                        w.y=t.y;
                        arr[t.x+1][t.y]=2;
                        q.push(w);
                    }
                if(arr[t.x][t.y+1]==1 && t.y+1<c)
                    {
                        w.x=t.x;
                        w.y=t.y+1;
                        arr[t.x][t.y+1]=2;
                        q.push(w);
                    }
                if(arr[t.x-1][t.y]==1 && t.x-1>=0)
                    {
                        w.x=t.x-1;
                        w.y=t.y;
                        arr[t.x-1][t.y]=2;
                        q.push(w);
                    }
                if(arr[t.x][t.y-1]==1 && t.y-1>=0)
                    {
                        w.x=t.x;
                        w.y=t.y-1;
                        arr[t.x][t.y-1]=2;
                        q.push(w);
                    }
        }
        int f=0;
        int r1=0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                {
                    if(arr[i][j]==1)
                       {
                           f++;
                       }
                       else if(arr[i][j]==2)
                       r1++;
                }
       cout<<"time frames: "<<time1<<endl;
       cout<<"fresh oranges: "<<f<<endl;
       cout<<"Rotten oranges: "<<r1<<endl;
    return 0;
}
