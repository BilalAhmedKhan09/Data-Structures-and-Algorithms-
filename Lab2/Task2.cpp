#include <iostream>
namespace MySpace {
    using namespace std;

    class Matrix {
    private:
        int** data;
        int rows, cols;

        void allocate(int r, int c) {
            rows = r; cols = c;
            data = new int*[rows];
            for (int i = 0; i < rows; i++) data[i] = new int[cols];
        }

    public:
        Matrix(int r, int c) { allocate(r, c); }

        void fill() {
            cout << "Enter elements:\n";
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    cin >> data[i][j];
        }

        void resize(int nr, int nc, int val) {
            int** temp = new int*[nr];
            for (int i = 0; i < nr; i++) {
                temp[i] = new int[nc];
                for (int j = 0; j < nc; j++)
                    temp[i][j] = (i < rows && j < cols) ? data[i][j] : val;
            }
            for (int i = 0; i < rows; i++) delete[] data[i];
            delete[] data;
            data = temp; rows = nr; cols = nc;
        }

        void transpose() {
            int** t = new int*[cols];
            for (int i = 0; i < cols; i++) {
                t[i] = new int[rows];
                for (int j = 0; j < rows; j++) t[i][j] = data[j][i];
            }
            for (int i = 0; i < rows; i++) delete[] data[i];
            delete[] data;
            data = t;
            int tmp = rows; rows = cols; cols = tmp;
        }

        void display() {
            cout << "Matrix:\n";
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    int v = data[i][j];
                    if ((i + j) % 2) v += 2;
                    cout << v << " ";
                }
                cout << '\n';
            }
        }

        ~Matrix() {
            for (int i = 0; i < rows; i++) delete[] data[i];
            delete[] data;
        }
    };
}

int main() {
    using namespace MySpace;
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    Matrix m(r, c);
    m.fill();
    cout << "Original:\n"; m.display();
    m.transpose();
    cout << "Transposed:\n"; m.display();
    m.resize(r + 1, c + 1, 0);
    cout << "Resized:\n"; m.display();
}