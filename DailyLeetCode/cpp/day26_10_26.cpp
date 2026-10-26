#include <iostream>
#include <vector>

template<typename T>
using matrix = std::vector<std::vector<T>>;

int go_area_v(const matrix<int> &grid, matrix<bool> &visited, int curr_row, int curr_col, int n, int m){
    visited[curr_row][curr_col]=true;
    const std::array<std::pair<int, int>, 4> dirc{{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
    int to_return = grid[curr_row][curr_col];

    for(auto [row_c, col_c] : dirc){
        int next_r = curr_row+row_c;
        int next_c = curr_col+col_c;


        if(next_r>=0 && next_r < n && next_c>=0 && next_c < m && grid[next_r][next_c]>0 && !visited[next_r][next_c]){
            to_return+=go_area_v(grid, visited, next_r, next_c, n, m);
        }        
    }
    return to_return;
}

int main(int argc, char** argn){
    //variablees
    int n,m, k;
    std::cin>>n>>m>>k;
    matrix<int> grid(n, std::vector<int>(m));
    matrix<bool> visited(n, std::vector<bool>(m));
    int to_return=0;


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cin>>grid[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && grid[i][j] > 0 && go_area_v(grid, visited, i, j, n, m)%k==0){
                to_return++;
            }
        }
    }

    std::cout<<to_return<<std::endl;
    return to_return;

}