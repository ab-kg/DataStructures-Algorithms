#include <iostream>
#include <vector>

int main() {
    const int rows = 3;
    const int cols = 3;

    // Initialize a 2D array (matrix)
    int matrix2[rows][cols] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // matrix through vector 
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for(const auto& row :matrix)
    {
        for(auto& elem : row)
        {
            std::cout << elem << " " ;
        }
        std::cout << std::endl ;
    }

    // Print matrix
    // for(int i = 0; i < rows; ++i) {
    //     for (int j = 0; j < cols; ++j) {
    //         std::cout << matrix[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}

