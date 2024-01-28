#include<iostream>
#include<vector>
using namespace std;

void MatrixPrint(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

vector<vector<int>> MatrixAdd(vector<vector<int>> a , vector<vector<int>> b) {
    vector<vector<int>> res(a.size() , vector<int>(a[0].size()));

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }

    return res;
}

vector<vector<int>> MatrixMultiply(vector<vector<int>>& a , vector<vector<int>>& b) {
    int na = a.size() , ma = a[0].size();
    int nb = b.size() , mb = b[0].size();

    if (na == 1 || ma == 1 || mb == 1) {
        vector<vector<int>> res(na , vector<int>(mb , 0));
        for (int row = 0; row < na; row++) {
            for (int col = 0; col < mb; col++) {
                for (int i = 0; i < ma; i++) {
                    res[row][col] += a[row][i] * b[i][col];
                }
            }
        }
        return res;
    }

    vector<vector<int>>
        a11(na / 2 , vector<int>(ma / 2)) ,
        a12(na / 2 , vector<int>(ma - ma / 2)) ,
        a21(na - na / 2 , vector<int>(ma / 2)) ,
        a22(na - na / 2 , vector<int>(ma - ma / 2));

    vector<vector<int>>
        b11(nb / 2 , vector<int>(mb / 2)) ,
        b12(nb / 2 , vector<int>(mb - mb / 2)) ,
        b21(nb - nb / 2 , vector<int>(mb / 2)) ,
        b22(nb - nb / 2 , vector<int>(mb - mb / 2));

    for (int i = 0; i < na / 2; i++) {
        for (int j = 0; j < ma / 2; j++) {
            a11[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < na / 2; i++) {
        for (int j = 0; j < ma - ma / 2; j++) {
            a12[i][j] = a[i][j + ma / 2];
        }
    }
    for (int i = 0; i < na - na / 2; i++) {
        for (int j = 0; j < ma / 2; j++) {
            a21[i][j] = a[i + na / 2][j];
        }
    }
    for (int i = 0; i < na - na / 2; i++) {
        for (int j = 0; j < ma - ma / 2; j++) {
            a22[i][j] = a[i + na / 2][j + ma / 2];
        }
    }



    for (int i = 0; i < nb / 2; i++) {
        for (int j = 0; j < mb / 2; j++) {
            b11[i][j] = b[i][j];
        }
    }
    for (int i = 0; i < nb / 2; i++) {
        for (int j = 0; j < mb - mb / 2; j++) {
            b12[i][j] = b[i][j + mb / 2];
        }
    }
    for (int i = 0; i < nb - nb / 2; i++) {
        for (int j = 0; j < mb / 2; j++) {
            b21[i][j] = b[i + nb / 2][j];
        }
    }
    for (int i = 0; i < nb - nb / 2; i++) {
        for (int j = 0; j < mb - mb / 2; j++) {
            b22[i][j] = b[i + nb / 2][j + mb / 2];
        }
    }

    vector<vector<int>> p1 =
        MatrixAdd(
            MatrixMultiply(a11 , b11) ,
            MatrixMultiply(a12 , b21)
        );

    vector<vector<int>> p2 =
        MatrixAdd(
            MatrixMultiply(a11 , b12) ,
            MatrixMultiply(a12 , b22)
        );

    vector<vector<int>> p3 =
        MatrixAdd(
            MatrixMultiply(a21 , b11) ,
            MatrixMultiply(a22 , b21)
        );

    vector<vector<int>> p4 =
        MatrixAdd(
            MatrixMultiply(a21 , b12) ,
            MatrixMultiply(a22 , b22)
        );

    vector<vector<int>> res(na , vector<int>(mb));

    for (int i = 0; i < p1.size(); i++) {
        for (int j = 0; j < p1[0].size(); j++) {
            res[i][j] = p1[i][j];
        }
    }

    for (int i = 0; i < p2.size(); i++) {
        for (int j = 0; j < p2[0].size(); j++) {
            res[i][j + p1.size()] = p2[i][j];
        }
    }

    for (int i = 0; i < p3.size(); i++) {
        for (int j = 0; j < p3[0].size(); j++) {
            res[i + p1.size()][j] = p3[i][j];
        }
    }

    for (int i = 0; i < p4.size(); i++) {
        for (int j = 0; j < p4[0].size(); j++) {
            res[i + p1.size()][j + p1.size()] = p4[i][j];
        }
    }

    return res;

}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int na , ma , nb , mb;
        cin >> na >> ma >> nb >> mb;
    }
    return 0;
}
