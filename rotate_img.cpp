/*
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise) in place
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
        int temp;
        for (int i=0; i< length/2; i++){
            for (int j = i; j < length-1-i; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[length-1-j][i];
                matrix[length-1-j][i] = matrix[length-1-i][length-1-j];
                matrix[length-1-i][length-1-j] = matrix[j][length-1-i];
                matrix[j][length-1-i]=temp;
            }
        }
        return;
    }
};