class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n=land.size();
        int m=land[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                
                int r=i;
                int c=j;
                for(r=i;r<n && land[r][j]==1;r++){
                    for(c=j;c<m && land[r][c]==1;c++ ){
                        land[r][c]=2;
                    }
                }
              temp.push_back(r-1);
                temp.push_back(c-1);
                ans.push_back(temp);
            }
            }
        }
        return ans;
    }
};