#include <bits/stdc++.h>
using namespace std;

#define N 100001
#define M 100002
#define sc scanf
#define pc printf
#define ll long long
#define eps 1e-9
#define INF 100000000000000
#define mp make_pair

int T;
int n, L;
char inp_str[2000][11];
int cnt[10][26];
int unique_cnt[10];
char output_str[11];
bool is_valid;

typedef struct TRIE{
	int mark;
	int unique;
	struct TRIE *next[26];
}TRIE;

TRIE nodePool[2000 * 10 * 26];
int nodePoolInd;

TRIE *getNewNode()
{
	TRIE *newNode = &nodePool[nodePoolInd++];
	newNode->mark = 0;
	newNode->unique = 0;
	for(int j = 0; j < 26; j++){
		newNode->next[j] = NULL;
	}
	return newNode;
}

void Insert(TRIE *root, char *str)
{
	TRIE *cur = root;
	for(int j = 0; str[j]; j++){
		int ind = str[j] - 'A';
		if(cur->next[ind] == NULL){
			cur->next[ind] = getNewNode();
			cur->unique++;
		}
		cur = cur->next[ind];
	}

	cur->mark = 1;

}

void dfs(TRIE *root, int pos, int is)
{
	if(root == NULL || pos == L) {
		//pc("yes\n");
		if(is && !is_valid){
			output_str[pos] = '\0';
			is_valid = true;
		}
		
		return;
	}

	if(is_valid) return;
	if(is){
		int ind = 0;
		for(int j = 0; j < 26; j++){
			if(root->next[j]){
				ind = j;
				break;
			}
		}
		//pc("first pos %d -> %c\n", pos, 'A' + ind);
		output_str[pos] = 'A' + ind;
		dfs(root->next[ind], pos+1, 1);
	}
	else{
		if(pos == L - 1){
			if(root->unique < unique_cnt[pos]){
				int ind = 0;
				for(int j = 0; j < 26; j++){
					if(root->next[j]){
						ind = j;
						break;
					}
				}
				for(int j = 0; j < 26; j++){
					if(cnt[pos][j] > 0 && root->next[j] == NULL){
						output_str[pos] = 'A' + j;
						//pc("second pos %d -> %c\n", pos, 'A' + j);
						dfs(root->next[ind], pos + 1, 1);
						break;
					}
				}
			}
			else{
				//pc("ekhane\n");
				output_str[pos] = '\0';
			}
		}
		else{

			if(root->unique < unique_cnt[pos]){
				int ind = 0;
				for(int j = 0; j < 26; j++){
					if(root->next[j]){
						ind = j;
						break;
					}
				}
				for(int j = 0; j < 26; j++){
					if(cnt[pos][j] > 0 && root->next[j] == NULL){
						output_str[pos] = 'A' + j;
						//pc("third pos %d -> %c\n", pos, 'A' + j);
						dfs(root->next[ind], pos + 1, 1);
						break;
					}
				}
			}
			else{
				for(int j = 0; j < 26; j++){
					if(root->next[j] && !is_valid){
						output_str[pos] = 'A' + j;
						//pc("fourth pos %d -> %c\n", pos, 'A' + j);
						dfs(root->next[j], pos + 1, 0);
						//break;
					}
				}
			}
			
		}
	}

	
}


void reset()
{
	nodePoolInd = 0;
	is_valid = false;

	for(int i = 0; i < 10; i++){
		unique_cnt[i] = 0;
		for(int j = 0; j < 26; j++){
			cnt[i][j] = 0;
		}
	}
}



void solve()
{
	reset();
	sc("%d%d", &n, &L);

	TRIE *root = getNewNode();

	for(int i = 0; i < n; i++){
		sc("%s", inp_str[i]);
		Insert(root, inp_str[i]);
		for(int j = 0; inp_str[i][j]; j++){
			char ch = inp_str[i][j];
			cnt[j][ch - 'A']++;
			if(cnt[j][ch - 'A'] == 1) unique_cnt[j]++;
		}
	}

	// for(int i = 0;  i< L; i++){
	// 	pc("unique %d\n", unique_cnt[i]);
	// }

	dfs(root, 0, 0);

	if(is_valid){
		pc("%s\n", output_str);
	}
	else{
		output_str[0] = '-';
		output_str[1] = '\0';
		pc("%s\n", output_str);
	}

	
	
}


int main()
{
	freopen("sample_input.txt", "r", stdin);
	freopen("sample_output.txt", "w", stdout);
	// freopen("A-large-practice.in", "r", stdin);
	// freopen("A-large-practice.out", "w", stdout);
	
    

    sc("%d", &T);


    for(int Cas = 1; Cas <= T; Cas++){
        //sc("%d", &n);
        

		pc("Case #%d: ", Cas);
		solve();
    }




    return 0;
}
