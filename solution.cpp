#include <iostream>
using namespace std;

void solver(int block[9][9], int a, int b);
void insert(int block[9][9], int a, int b);
void printit(int block[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << block[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int block[9][9] = {
        {0, 9, 0, 0, 0, 0, 8, 5, 3},
        {0, 0, 0, 8, 0, 0, 0, 0, 4},
        {0, 0, 8, 2, 0, 3, 0, 6, 9},
        {5, 7, 4, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 9, 0, 0, 6, 3, 7},
        {9, 4, 0, 1, 0, 8, 5, 0, 0},
        {7, 0, 0, 0, 0, 6, 0, 0, 0},
        {6, 8, 2, 0, 0, 0, 0, 9, 0}};
    solver(block, 9, 9);
    return 0;
}

void solver(int block[9][9], int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (block[i][j] == 0)
            {
                insert(block, i, j);
            }
            if (i == a - 1 && j == b - 1)
            {
                printit(block);
            }
        }
    }
}

void insert(int block[9][9], int a, int b)
{
    int flag = 0;
    int flag2 = 0;
    int v = 1;
    for (int x = 1; x < 10; x++)
    {
        if (block[x - 1][b] == x || block[a][x - 1] == x)
        {
            flag2 = 0;
        }
        else
        {
            flag2 = 1;
            v = x;
        }
        if (flag2 == 1)
        {
            int l, k;
            int m = ((a) / 3) * 3;
            int n = ((b) / 3) * 3;
            for (k = m; k < m + 3; k++)
            {
                for (l = n; l < n + 3; l++)
                {
                    if (block[k][l] == v)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    break;
                }
                else
                {
                    block[k][l] = v;
                }
            }
            if(block[k][l] != 0){
                break;
            }
        }
    }
}

// ------------------------------------------------------------
// for(int x=1;x<=9;x++){
//         if(block[x-1][b]==x || block[a][x-1]==x){
//             continue;
//         }
//         else{
//             int m = ((a)/3)*3;
//             int n = ((b)/3)*3;
//             for(int k=m;k<m+3;k++){
//                 for(int l=n;l<n+3;l++){
//                     if(block[k][l]==x){
//                         continue;
//                     }
//                     else{
//                         block[a][b]=x;
//                         flag=1;
//                         break;
//                     }
//                 }
//                 if(flag==1){
//                     break;
//                 }
//             }
//         }
//         if(flag==1){
//             break;
//         }
//     }