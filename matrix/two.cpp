#include <iostream>
#include <vector>


class Matrix {
    private:
        std::vector<std::vector<int>> matrix ;
        int rows , cols ;
    
    public :
        // Constructor
        Matrix(int r , int c ) : rows(r) , cols(c){
            matrix.resize( rows , std::vector<int>(cols) );
        }

        // Function to set an element 
        void setElement(int r , int c , int value)
        {
            matrix[r][c] = value ;
        }

        int getElement(int r, int c) const {
        return matrix[r][c];
        }

        void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
            }
        }

            


};

