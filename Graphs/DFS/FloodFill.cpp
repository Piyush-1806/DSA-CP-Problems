// Problem Link: https://leetcode.com/problems/flood-fill/
// The DFS function marks pixels as visited and recursively visits all adjacent pixels with the same initial color.
// The main function initializes the image and calls the floodFill function to execute the DFS.
//Approach - If the initial color is different from the new color, we start a DFS from the starting pixel (sr, sc). And then we change the color of the pixel to the new color. We then recursively call DFS for all 4 adjacent pixels (up, down, left, right) that have the same initial color. This process continues until all connected pixels with the same initial color are changed to the new color.

class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool feasible(int x, int y, vector<vector<int>>& image){
        if(x>=0 && x<image[0].size() && y>=0 && y<image.size()) return 1;
        else return 0;
    }
    void dfs(int sr, int sc, int color, vector<vector<int>>& image, int initial){
        image[sr][sc]=color;
        for(int i=0; i<4; i++){

            if(feasible(sc+dx[i],sr+dy[i],image)){
                if(image[sr+dy[i]][sc+dx[i]]==initial) dfs(sr+dy[i],sc+dx[i],color,image,initial);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];
        if(initial!=color){
            dfs(sr,sc,color,image,initial);
        }
        return image;
    }
};