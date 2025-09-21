//https://leetcode.com/problems/number-of-islands/description/

class DSU{
    int joined{};
    vector<int> parent;
    public:
    DSU(int n){

        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int getUniqueComponent(){
        return joined;
    }
    int getParent(int a){
        if(parent[a]!=a){
            parent[a]=getParent(parent[a]);
        }
        return parent[a];
    }
    void join(int a, int b){
        int pa = getParent(a);
        int pb = getParent(b);
        if(pa !=pb){
            joined++;
            parent[pa] = pb;
        }
    }

};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        DSU dsu(n*m);
        int water=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0'){
                    water++;
                    continue;
                }
                int i1 = i*m+j;
                if(i+1<n && grid[i+1][j]=='1'){
                    int i2 = (i+1)*m+j;
                    dsu.join(i1,i2);
                }

                if(j+1<m && grid[i][j+1]=='1'){
                    int i2 = i*m + j+1;
                    dsu.join(i1,i2);
                }
                    
            }
        }
        int ans = n*m- dsu.getUniqueComponent()-water;
        return ans;
        
    }
};
