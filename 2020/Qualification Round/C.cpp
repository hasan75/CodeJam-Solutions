#include <bits/stdc++.h>

using namespace std;


#define N 1001
#define sc scanf
#define pc printf

int T;
int n;
vector<pair<pair<int,int>, int>>works;
bool vis[N];
char ans[N];

int main()
{
    sc("%d", &T);
    
    for(int cases = 1; cases <= T; cases++){
        sc("%d", &n);
        works.clear();
        int st, ed;
        for(int i = 0; i < n; i++){
            sc("%d%d", &st, &ed);
            works.push_back({{st,ed}, i});
            vis[i] = false;
        }
        sort(works.begin(), works.end());

        int cur_end_time = 0;
        
        for(int i = 0; i < n; i++){
            int start_time = works[i].first.first;
            int end_time = works[i].first.second;
            int ind = works[i].second;

            if(vis[ind] == false && start_time >= cur_end_time){
                vis[ind] = true;
                ans[ind] = 'C';
                cur_end_time = end_time;
            }
        }

        cur_end_time = 0;
        for(int i = 0; i < n; i++){
            int start_time = works[i].first.first;
            int end_time = works[i].first.second;
            int ind = works[i].second;

            if(vis[ind] == false && start_time >= cur_end_time){
                vis[ind] = true;
                ans[ind] = 'J';
                cur_end_time = end_time;
            }
        }



        bool isValid = true;

        for(int i = 0; i < n; i++){
            if(!vis[i]) {
                isValid = false;
                break;
            }
        }

        if(!isValid){
            pc("Case #%d: IMPOSSIBLE\n", cases);
        }
        else{
            ans[n] = '\0';
            pc("Case #%d: %s\n", cases, ans);
        }

        
        

    }
    
    
    return 0;
}