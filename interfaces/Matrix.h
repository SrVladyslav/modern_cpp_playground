#ifndef MATRIX_H // If MATRIX_H is not defined yet, process the next contents
#define MATRIX_H // If MATRIX_H is defined, skip the next contents

#include <vector>
using namespace std;

template <typename Object>

class Matrix
{
public:
    // Init the matrix with the number of rows and columns
    matrix(int rows, int cols) : array(rows)
    {
        for (auto &row : array)
            row.resize(cols);
    }

    // Init the matrix with a vector of vectors
    matrix(vector<vector<Object>> v) : array{v} {}

    // If we have a rhs value, then we transfer it here
    matrix(vector<vector<Object>> &&v) : array{std::move(v)} {}

    /**
     * The idea of operator[] is that if we have a matriz m, then m[i] should return a vector
     * corresponding to row i of matrix m. If this is done, then m[i][j] will give the entry in
     * position j for vector m[i], using the normal vector indexing operator. Thus, the matrix
     * operator[] returns a vector<Object> rather than an Object.
     */
    const vector<Object> &operator[](int row) const
    {
        return array[row];
    }

    vector<Object> &operator[](int row)
    {
        return array[row];
    }

    int numrows() const
    {
        return array.size();
    }
    int numcols() const
    {
        return numrows() ? array[0].size() : 0;
    }

private:
    vector<vector<Object>> array;
};

#endif