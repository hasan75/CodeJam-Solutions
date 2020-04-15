#include <bits/stdc++.h>

using namespace std;


#define N 101
#define sc scanf
#define pc printf

int T;
int n, matrix[N][N];
set<int>repeated;

int main()
{
    sc("%d", &T);
    
    for(int cases = 1; cases <= T; cases++){
        sc("%d", &n);

        int trace = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                sc("%d", &matrix[i][j]);
                if(i == j) trace += matrix[i][j];
            }
                
        }
        
        int row_count = 0, col_count = 0;
        
        for(int i = 0; i < n; i++){
            repeated.clear();
            for(int j = 0; j < n; j++){
                if(repeated.find(matrix[i][j]) != repeated.end() ){
                    row_count++;
                    break;
                }
                else repeated.insert(matrix[i][j]);
            }
        }

        for(int i = 0; i < n; i++){
            repeated.clear();
            for(int j = 0; j < n; j++){
                if(repeated.find(matrix[j][i]) != repeated.end() ){
                    col_count++;
                    break;
                }
                else repeated.insert(matrix[j][i]);
            }
        }

        pc("Case #%d: %d %d %d\n", cases, trace, row_count, col_count);
        

    }
    
    
    return 0;
}