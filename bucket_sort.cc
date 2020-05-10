#include"bits/stdc++.h"
using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

void insertion_sort (vector<int>& arr){
  for(int i = 1; i < arr.size(); i++){
    int key = arr[i];
    int j = i - 1;
    while(j >= 0 && j >= key){
      arr[j+1]= arr[j];
      j--;
    }
    arr[j] = key;
  }
}

void bucket_sort(vector<int>& a, int n){
  vector<vector<int>> bucket(n, vector<int> (0));
  int ma = -1;
  for(int i = 0; i < n; i++){
    bucket[i].clear();
  }
  for(int i = 0; i < a.size(); i++){
    if(a[i]>ma) ma = a[i];
  }
  int bucket_size = ma/n + 1;
  for(int i = 0; i < a.size(); i++){
    int p = a[i]/bucket_size;
    bucket[p].push_back(a[i]);
  }
  a.clear();
  for(int i = 0; i < n; i++){
    insertion_sort(bucket[i]);
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < bucket[i].size(); j++){
      a.push_back(bucket[i][j]);
    }
  }
}

int main() {
  vector<int> arr{300, 437, 498, 504, 809, 760, 263, 983, 183, 245};
  bucket_sort(arr,3);
  for(int a:arr) cout << a << ", ";
  return 0;
}
