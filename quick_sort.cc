#include "bits/stdc++.h"
using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
} ();

int re_arrange(vector<int>& a, int l, int r){
  int key = a[l];
  int i = l;
  int j = r;
  while(i < j){
    while(i < j && a[j] >= key) j--;
    if(i < j){
      a[i] = a[j];
      i++;
    }
    while(i < j && a[i] < key) i++;
    if(i < j){
      a[j] = a[i];
      j--;
    }
  }
  a[i] = key;
  return i;
}

void quick_sort(vector<int>& a, int l, int r){
  if(l < r){
    int i = re_arrange(a,l,r);
    quick_sort(a,l,i - 1);
    quick_sort(a,i + 1,r);
  }
}

int main () {
  vector<int> arr{300, 437, 498, 504, 809, 760, 263, 983, 183, 245};
  quick_sort(arr,0,9);
  for(int a:arr) cout << a << ", ";
  return 0;
}
