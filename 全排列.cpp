#include<bits/stdc++.h>
using namespace std;
#define MAX 20
int n,arr[MAX],visited[MAX]={0};
void print(){
	for(int i=1;i<=n;i++)cout<<arr[i];
	cout<<endl;
}
void dfs(int k){
  if(k==n+1){
  	print();
  	return ;
  }	
  	
  for(int i=1;i<=n;i++)
    if(visited[i]==0){
    	arr[k]=i;
    	visited[i]=1;
    	dfs(k+1);
    	visited[i]=0;
    	arr[k]=0;
	}	
	return;	
}
int main(){
	cin>>n;
	dfs(1);
	
	return 0;
}
