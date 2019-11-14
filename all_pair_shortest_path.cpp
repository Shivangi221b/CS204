#include<bits/stdc++.h>
using namespace std;
#define INF 99999
//Using Floyd Warshall Algorithm
int main()
{
    int n=4;
    
    long long int arr[n][n]={ {0, 5, INF, 10},  
                            {INF, 0, 3, INF},  
                            {INF, INF, 0, 1},  
                            {INF, INF, INF, 0} };  
    
    
    long long int d[n][n];
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<n;j++)
        {
            d[i][j]=arr[i][j];
        }
    }
    
    for(long long int k=0;k<n;k++)
    {
        for(long long int i=0;i<n;i++)
        {
            for(long long int j=0;j<n;j++)
            {
                if(d[i][j]>d[i][k]+d[k][j])
                    d[i][j]=d[i][k]+d[k][j];
            }
        }
    }


    for(long long int j=0;j<n;j++){
        for(long long int i=0;i<n;i++)
        {
            cout<<d[j][i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
