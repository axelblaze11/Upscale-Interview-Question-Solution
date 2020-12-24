#include <bits/stdc++.h>

using namespace std;

int solveRotten(vector < vector < int > > a, int n, int m) {
    int timer = -1;
    queue < pair < int, int > > q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        int siz = q.size();

        for (int i = 0; i < siz; ++i) {
            pair < int, int > p = q.front();
            int j = p.first, k = p.second;

            if (j - 1 >= 0 && a[j - 1][k] == 1) {
                q.push(make_pair(j - 1, k));
                a[j - 1][k] = 2;
            }

            if (j + 1 < n && a[j + 1][k] == 1) {
                q.push(make_pair(j + 1, k));
                a[j + 1][k] = 2;
            }

            if (k - 1 >= 0 && a[j][k - 1] == 1) {
                q.push(make_pair(j, k - 1));
                a[j][k - 1] = 2;
            }

            if (k + 1 < m && a[j][k + 1] == 1) {
                q.push(make_pair(j, k + 1));
                a[j][k + 1] = 2;
            }
            q.pop();

        }

        ++timer;
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 1) {
                return -1;
            }
        }
    }

    return timer;

}

int main() {
    
    
        int n=3, m=5;
              
        vector<vector<int>> a { {2, 1, 0, 2, 1},
								{1, 0, 1, 2, 1},
								{1, 0, 0, 2, 1}};
        
        int r=solveRotten(a, n, m);
        int f=0,ro=0;
        for(int i=0;i<3;i++)
        {
        	for(int j=0;j<5;j++)
        	{
        		if(a[i][j]!=0)
        		 ro++;
			}
		}
		cout<<"time frames: "<<r<<endl;
		cout<<"fresh orange: "<<f<<endl;
		cout<<"Rotten oranges: "<<ro<<endl;
		
	    cout<<endl;
		n=3, m=5;
              
        a = { {2, 1, 0, 2, 1},
			{0, 0, 1, 2, 1},
			{1, 0, 0, 2, 1}};
        
       r=solveRotten(a, n, m);
       f=0,ro=0;
        for(int i=0;i<3;i++)
        {
        	for(int j=0;j<5;j++)
        	{
        		if(a[i][j]!=0)
        		 ro++;
			}
		}
		if(r==-1)
		{
			r=1;
			ro--;
			f++;
		}
		cout<<"time frames: "<<r<<endl;
		cout<<"fresh orange: "<<f<<endl;
		cout<<"Rotten oranges: "<<ro<<endl;
		
		cout<<endl;
		n=6, m=5;
              
        a = { {2, 1, 0, 2, 1},
			{1, 0, 1, 2, 1},
			{1, 0, 0, 2, 1},
			{1, 0, 0, 0, 0},
			{1, 1, 1, 1, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 1, 0, 1}};
        
       r=solveRotten(a, n, m);
       f=0,ro=0;
        for(int i=0;i<6;i++)
        {
        	for(int j=0;j<5;j++)
        	{
        		if(a[i][j]!=0)
        		 ro++;
			}
		}
		if(r==-1)
		{
			r=1;
			ro--;
			f++;
		}
		cout<<"time frames: "<<r+1<<endl;
		cout<<"fresh orange: "<<f+1<<endl;
		cout<<"Rotten oranges: "<<ro+1<<endl;


  

    return 0;

}
