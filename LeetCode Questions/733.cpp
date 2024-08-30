/*
Flood Fill

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:
From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]

Explanation:
The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.
*/
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& image, int sr, int sc, int color, int dr[], int dc[], int ini, vector<vector<bool>>& vis) {
    image[sr][sc] = color;
    vis[sr][sc] = true;
    int n = image.size();
    int m = image[0].size();
    
    for (int i = 0; i < 4; ++i) {
        int nr = sr + dr[i];
        int nc = sc + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == ini && !vis[nr][nc]) {
            dfs(image, nr, nc, color, dr, dc, ini, vis);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int ini = image[sr][sc];
    if (ini == color) {
        return image;
    }
    int n = image.size();
    int m = image[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int dr[] = {-1, 0, +1, 0};
    int dc[] = {0, +1, 0, -1};
    dfs(image, sr, sc, color, dr, dc, ini, vis);
    return image;
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, color = 2;
    
    vector<vector<int>> result = floodFill(image, sr, sc, color);
    
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    
    return 0;
}
