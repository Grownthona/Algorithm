#include<bits/stdc++.h>
using namespace std;

bool rat_maze(int row,int col,vector<vector<int>>&a,int n)
{
    if(row==n-1 && col==n-1)
    {
        a[row][col] = 2;
        return true;
    }

    if(a[row+1][col]==1)
    {
        a[row][col] = 2;
        if(rat_maze(row+1,col,a,n))
        {
            return true;
        }
        a[row][col] = 0;
    }
    if(a[row][col+1]==1)    //Jodi ekhane else if ditam tahole uporer if theke backtrack kore r nicher condition e ashtona.
    {
        a[row][col] = 2;
        if(rat_maze(row,col+1,a,n))
        {
            return true;
        }
        a[row][col] = 0;
    }
    return false;
}
int main()
{
    int n = 5;
    vector<vector<int>>a={{1,0,1,0,1},
                          {1,1,1,1,1},
                          {0,1,0,1,0},
                          {1,0,0,1,1},
                          {1,1,1,0,1}};

        if(rat_maze(0,0,a,n))
        {
        cout << "Result :" << endl;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
       }

    return 0;
}

