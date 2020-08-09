// Time complexity :- O(n*m)
// Space complexity :- O(n*m)
class Solution {
    int d1[4] = {1, -1, 0, 0};
    int d2[4] = {0, 0, 1, -1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int> >q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        int ans = -1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int d=0;d<4;d++)
                {
                    int x_p = x + d1[d];
                    int y_p = y + d2[d];
                    
                    if(x_p <0 || x_p >= grid.size() || y_p <0 || y_p >= grid[0].size()) continue;
                    if(grid[x_p][y_p] == 0 || grid[x_p][y_p] == 2)  continue;
                    grid[x_p][y_p] = 2;
                    q.push({x_p, y_p});
                }
            }
            ans++;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return ans == -1?0:ans;
    }
};