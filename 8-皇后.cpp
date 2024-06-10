#include<bits/stdc++.h>
using namespace std;
int sum=0;
bool column[10],main_diag[20],sub_diag[20];
void dfs(int k){
	if(k==9){
		sum++;
		return;
	}
	for(int i=1;i<=8;i++){
		if(!column[i]&&!main_diag[k+i-1]&&!sub_diag[k+8-i]){
			column[i]=main_diag[k+i-1]=sub_diag[k+8-i]=true;
			dfs(k+1);
			column[i]=main_diag[k+i-1]=sub_diag[k+8-i]=false;
		}
	}
return;
}
int main(){
	dfs(1);
	cout<<sum<<endl;
	
	return 0;
}
