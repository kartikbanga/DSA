class Solution {
public:
    
    void helper(int x, int y, vector<vector<int>>& m, int r, int c)
    {
        for(int i=0;i<r;i++)
            m[i][y]=0;
        for(int i=0;i<c;i++)
            m[x][i]=0;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        vector<pair<int,int>> v;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(matrix[i][j]==0)
                    v.push_back({i,j});
        for(int i=0;i<v.size();i++)
            helper(v[i].first,v[i].second,matrix,r,c);
    }
};
