#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
map<int,int> ans;

int cuttingRodRecursive(int val[],int n){
  if(n <= 0) return 0;
  int max_value = INT_MIN;
  for(int i = 0; i < n; ++i){
    max_value = max(max_value, val[i] + cuttingRodRecursive(val,n-i-1));
  }
  return max_value;
}

int cuttingRodMemoized(int val[],int n){
  if(n <= 0) return 0;

  auto it = ans.find(n);
  if(it != ans.end()) return it->second;

  int max_value = INT_MIN;
  for(int i = 0; i < n; ++i){
    max_value = max(max_value, val[i] + cuttingRodMemoized(val, n-i-1 ));
  }
  return ans[n] = max_value;
}

int cuttingRodDP(int val[],int n){
  int dp[n+1];
  dp[0] = 0;
  int max_value;
  for(int i = 1; i <= n; ++i){
    max_value = INT_MIN;
    for(int j = 0; j < i ; ++j){
      max_value = max(max_value,val[j] + dp[i-j-1]);
    }
    dp[i] = max_value;
  }
  return dp[n];
};

int main() 
{ 
  FASTIO;
  int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
  int size = sizeof(arr)/sizeof(arr[0]); 
  cout<<cuttingRodRecursive(arr, size)<<endl; 
  cout<<cuttingRodMemoized(arr, size)<<endl; 
  cout<<cuttingRodDP(arr, size)<<endl; 
  return 0; 
} 