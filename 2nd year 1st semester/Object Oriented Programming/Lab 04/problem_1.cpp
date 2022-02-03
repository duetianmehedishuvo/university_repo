#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> matrixC;

class Matrix
{
private:
    vector<vector<int>> matrixA;
    vector<vector<int>> matrixB;

    int m,n,sum=0;
public:
    Matrix(vector<vector<int>> mA,vector<vector<int>> mB)
    {
        matrixA=mA;
        matrixB=mB;
    }

    void MatrixSize(int row,int column)
    {
        m=row;
        n=column;
    }

    void addMatrix()
    {
        matrixC.clear();
        for (int i = 0; i < m; i++)
        {
            vector<int> row;
            for (int j = 0; j < n; j++)
            {
                sum=0;
                sum=matrixA[i][j]+matrixB[i][j];
                row.push_back(sum);
            }
            matrixC.push_back(row);
        }
    }

    friend void addMatrixAB(Matrix a,int m,int n);

};

void displayMatrixC()
{
    for (int i = 0; i < matrixC.size(); i++)
    {
        for (int j = 0; j < matrixC[i].size(); j++)
        {
            cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }
}


void addMatrixAB(Matrix a,int m,int n)
{
    matrixC.clear();
    int sum=0;
    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            sum=0;
            sum=a.matrixA[i][j]+a.matrixB[i][j];
            row.push_back(sum);
        }
        matrixC.push_back(row);
    }
}

int main()
{

    vector<vector<int>> matrixA,matrixB;
    int value,m,n;
    cout<<"Enter The Value Of Row Column: ";
    cin>>m>>n;
    cout<<"\nEnter The Value Of Matrix A"<<endl;

    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            cout <<"A["<<i+1<<"]["<<j+1<<"]: ";
            cin>>value;
            row.push_back(value);
        }
        matrixA.push_back(row);
    }

    cout<<"\n\nEnter The Value Of Matrix B"<<endl;

    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            cout <<"A["<<i+1<<"]["<<j+1<<"]: ";
            cin>>value;
            row.push_back(value);
        }
        matrixB.push_back(row);
    }


    Matrix matrix(matrixA,matrixB);
    cout<<"\n\nValue Of Matrix C Using Member Function"<<endl;
    matrix.MatrixSize(m,n);
    matrix.addMatrix();
    displayMatrixC();

    cout<<"\n\nValue Of Matrix C Using Non Member Function"<<endl;
    addMatrixAB(matrix,m,n);
    displayMatrixC();

    return 0;
}
