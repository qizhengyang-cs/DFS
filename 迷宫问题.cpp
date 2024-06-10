#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N][N], visited[N][N]={0};
int n, m, startx, starty, endx, endy;
bool foundSolution=false;
vector<pair<int, int>> path;
vector<pair<int, int>> moves = {{-1, 0},{1, 0},{0, 1}, {0, -1}}; //down,up,right,left 
void Input(){
	cout << "Input the scale of labyrinth: ";
    cin >> n >> m;
    cout << "Input the labyrinth(1 means obstacle):\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    cout << "Input the initial position: ";
    cin >> startx >> starty;
    visited[startx][starty] = 1;
    cout << "Input the destination: ";
    cin >> endx >> endy;
}
void print(){
	if(foundSolution){
	   cout << "The  steps: " << path.size() << endl;
       cout << "The path route:";cout<<'('<<startx<<','<<starty<<')';
       for (size_t i = 0; i < path.size(); i++)
           cout<<'('<<path[i].first <<','<<path[i].second<<')';
       cout << endl;
	}
}
void dfs(int x, int y, int step) {
    if (x == endx && y == endy) {
    	foundSolution=true;
    	print();
        return;
    }
    
    for (int k = 0; k < 4; k++) {
        int tx = x + moves[k].first;
        int ty = y + moves[k].second;
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] == 0 && visited[tx][ty] == 0) {
        	visited[tx][ty]=1;
            path.push_back(make_pair(tx, ty));
            dfs(tx, ty, step + 1);
            visited[tx][ty] = 0;
            path.pop_back();
        }
    }
    return;
}
int main() {
    Input();
    dfs(startx,starty,0);
    if(!foundSolution)cout << "NO solution!\n";

    return 0;
}
