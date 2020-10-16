class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        
        int cnt = 0,itr = -1;
        
        vector<vector<int>> g2 = g;
        do
        {
            itr++; cnt = 0;
            for(int index1 = 0; index1 < g.size(); index1++)
            {
                for(int index2 = 0; index2 < g[0].size(); index2++)
                {
                    if(g[index1][index2]==2)
                    {
                        if(index1 > 0 && g[index1 - 1][index2] == 1)
                        {
                            g2[index1 - 1][index2] = 2; cnt++;
                        }
                        if(index1 < g.size()-1 && g[index1 + 1][index2]==1)
                        {
                            g2[index1 + 1][index2] = 2; cnt++;
                        }    
                        
                        if(index2 > 0 && g[index1][index2 - 1] == 1)
                        {   
                            g2[index1][index2 - 1] = 2; cnt++;
                        }
                        
                        if(index2 < g[0].size()-1 && g[index1][index2 + 1] == 1)
                        {    
                            g2[index1][index2 + 1] = 2; cnt++;
                        }
                    }
                }
            }
            g = g2;
            
        }while(cnt != 0);
        
            for(int index1 = 0; index1 < g.size(); index1++)
            {
                for(int index2 = 0; index2 < g[0].size(); index2++)
                {
                    if(g[index1][index2] == 1)
                    {
                        itr = -1; break;
                    }
                }
            }
        
        return itr;
    }
};
