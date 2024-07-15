#include<iostream>
#include<math.h>
using namespace std;

bool solver(int block[9][9], int i, int j);
void printit(int block[9][9]);
bool isValid(int board[9][9],int i,int j,int n);
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
    solver(block, 0, 0);
    return 0;
}

bool solver(int block[9][9], int i, int j){
    // base case 
    if(i==9){
        printit(block);
        return true;
    }
    if(j==9){
       return solver(block,i+1,0);
    }
    if(block[i][j]!=0){
       return solver(block,i,j+1);
    }
    for(int n=1;n<=9;n++){
        if(isValid(block,i,j,n)){
            block[i][j]=n;
            bool ans = solver(block,i,j+1);
            if(ans){
                return true;
            }
            block[i][j]=0;
        }
    }
    return false;
}

void printit(int block[9][9]){

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<block[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isValid(int block[9][9],int i,int j,int n){
    for(int x=0;x<9;x++){
        if(block[i][x] == n || block[x][j] == n){
            return false;
        }
    }

    int p = i - i%3;
    int q = j - j%3;
    for(int x=p;x<p+3;x++){
        for(int y=q;y<q+3;y++){
            if(block[x][y] == n){
                return false;
            }
        }
    }
    return true;
}

