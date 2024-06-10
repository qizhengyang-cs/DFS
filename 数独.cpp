#include<bits/stdc++.h>
using namespace std;
int foundSolution=0;
int table[9][9]={{0,0,5,3,0,0,0,0,0},
                 {8,0,0,0,0,0,0,2,0},
                 {0,7,0,0,1,0,5,0,0},
				 {4,0,0,0,0,5,3,0,0},
				 {0,1,0,0,7,0,0,0,6},
				 {0,0,3,2,0,0,0,8,0},
				 {0,6,0,5,0,0,0,0,9},
				 {0,0,4,0,0,0,0,3,0},
				 {0,0,0,0,0,9,7,0,0}};
void print(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)cout<<table[i][j]<<' ';
		cout<<endl;
	}
}			
bool check(int x,int y,int k){
	for(int l=0;l<9;l++){
		if(table[x][l]==k)return false;
		if(table[l][y]==k)return false;
	}
	for(int l=(x/3)*3;l<(x/3+1)*3;l++)
		for(int m=(y/3)*3;m<(y/3+1)*3;m++)
			if(table[l][m]==k)return false;
	
	return true;
}	 
void dfs(int x,int y){
	if(x==9){
		if(foundSolution==0)foundSolution=1;
		else foundSolution=-1;
		print();
		return;
	}
	int tx=x;
	int ty=y+1;
	if(ty==9){tx++;ty=0;}
	if(table[x][y]==0){
	for(int k=1;k<=9;k++){
		if(check(x,y,k)){
			table[x][y]=k;
			dfs(tx,ty);
			table[x][y]=0;
		}
	}
    }else dfs(tx,ty);
    
    return;
}				 
int main(){
	dfs(0,0);
    if(foundSolution!=1)cout<<"NO Solution!\n";

	return 0;
}
