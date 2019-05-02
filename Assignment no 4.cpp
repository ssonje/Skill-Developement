#include<iostream>
using namespace std;

int min(int key[],int n,int mst[])
{
    int i,m=32767,h;//IMPORTANT
    for(i=0;i<n;i++)
    {
        if(key[i]<=m && mst[i]==0)
        {
            m=key[i];
            h=i;
        }
    }

    cout<<h;
    return h;
}

int main()
{
    int n,i,j,u,v;
    cout<<"Enter the number of vertices\n";
    cin>>n;
    int arr[n][n];
    cout<<"Enter the Adjacency matrix with weights\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"The entered graph is:\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           cout<<""<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }

    int mst[n],parent[n];
    int key[n];//Very important
    int count=1;

    for(i=0;i<n;i++)
    {
        mst[i]=0;
        parent[i]=0;
        key[i]=32767;
    }
    key[0]=0;
   // parent[0]=-1;

    while(count<=n)
    {
        u=min(key,n,mst);
        mst[u]=1;
        cout<<".........."<<u<<"\n";

        cout<<""<<parent[u]<<"-"<<u<<" "<<key[u]<<"\n";

        for(i=0;i<n;i++)
        {
            if(arr[u][i]!=0 && arr[u][i]<key[i])
            {
                parent[i]=u;
                key[i]=arr[u][i];
            }
        }
        for(i=0;i<n;i++)
        {
            cout<<""<<key[i]<<"\t";
        }

        count++;
    }
    return 0;
}
