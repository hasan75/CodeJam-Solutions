#include <bits/stdc++.h>

using namespace std;


#define N 101
#define sc scanf
#define pc printf

int T;
int n;
char input[101];
char ans[1000];

int main()
{
    sc("%d", &T);
    
    for(int cases = 1; cases <= T; cases++){
        sc("%s", input);

        int ansInd = 0;
        int opening_count = 0;

        for(int i = 0 ; input[i]; i++){
            int val = input[i] - '0';
            if(opening_count == val){
                ans[ansInd++] = input[i];
            }
            else if(opening_count > val){
                while(opening_count > val){
                    ans[ansInd++] = ')';
                    opening_count--;
                }
                ans[ansInd++] = input[i];
            }
            else{
                while(opening_count < val){
                    ans[ansInd++] = '(';
                    opening_count++;
                }
                ans[ansInd++] = input[i];
            }
        }

        while(opening_count > 0){
            ans[ansInd++] = ')';
            opening_count--;
        }
        ans[ansInd++] = '\0';



        

        pc("Case #%d: %s\n", cases, ans);
        

    }
    
    
    return 0;
}