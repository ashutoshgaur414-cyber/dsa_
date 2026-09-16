class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      
      int  row = matrix.size();
      int col = matrix[0].size();
      vector<int>r(row,1);
      vector<int>c(col,1);
      for(int j =0;j<col;j++)
      {
        for(int i =0;i<row;i++)
        {
            if(matrix[i][j]==0)
            {
                r[i]=0;
                c[j]=0;
            }
        }
      }

      for(int j =0;j<col;j++)
      {
        for(int i =0;i<row;i++)
        {
            if(r[i]==0 || c[j]==0)
            {
               matrix[i][j]=0;
            }
        }

      }
    }
};