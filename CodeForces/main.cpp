///
//first calculate how many 1s are after each cell
//then for every column sort the values of all the rows
//so for every row in this column you are sure that every row under it will contain the same or more ones
///
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt[5005][5005];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    //cin>>n>>m;
    char arr[n][m];
    for(int i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
            //cin>>arr[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(arr[i][j]=='1')
                cnt[i][j]=cnt[i][j+1]+1;
        }
    }
    int mx=0;
    for(int i=0;i<m;i++)
    {
        int tmp[n];
        for(int j=0;j<n;j++)
            tmp[j]=cnt[j][i];
        sort(tmp,tmp+n);
        for(int j=0;j<n;j++)
        {
            mx=max(mx,tmp[j]*(n-j));
        }
    }
    printf("%d\n",mx);
    //cout<<mx<<endl;
    return 0;
}
