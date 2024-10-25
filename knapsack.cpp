#include <iostream>
using namespace std;

void knapsack(int[],int[],int,int);

int main()
{
    int v[] = {40,35,18,4,10,2};
    int w[] = {100,50,45,20,10,5};
    const int n = sizeof(v)/sizeof(v[0]);
    const int W = 100;
    knapsack(v,w,n,W);

    return 0;
}

void knapsack(int v[], int w[], int n, int W){
    cout << "Known weights:" << endl;
    for(int i=0;i<n;i++){
        cout << w[i] << " ";
    }
    cout << endl << "Known values:" << endl;
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    // build matrix
    int c[n][W+1]; //need to allocate space for W=0->100 including initial 0
    for(int j = 0 ; j <= W ; j++){
        c[0][j] = 0;
    }
    for(int i=1; i<n; i++){
        c[i][0] = 0;
        for(int k=1; k<=W; k++){
            if(w[i] <= k){
                if(v[i] + c[i-1][k-w[i]] >= c[i-1][k]){
                    c[i][k] = v[i] + c[i-1][k-w[i]];
                }
                else{
                    c[i][k] = c[i-1][k];
                }
            }
            else{
                c[i][k] = c[i-1][k];
            }
        }
    }
    
    // print matrix
    cout << endl << "c matrix:" << endl;
    for(int j=0;j<n;j++){
        for(int k=0; k<=W;k++){
            cout << c[j][k] << " ";
        }
        cout << endl;
    }

    // Computational matricies start at index 0, so c[n,W] is shifted to c[n-1][W]
    cout << endl << "Highest attainable value via DP = " << c[n-1][W] << endl;
}
