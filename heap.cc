#include "bits/stdc++.h"
using namespace std;

struct PriorityQueue{
  vector<int> arr;

  int PARENT(int i){
    return (i - 1) / 2;
  }

  int LEFT(int i){
    return (2 * i + 1);
  }

  int RIGHT(int i){
    return (2 * i + 2);
  }

  void heapify_down(int i){
    int l = LEFT(i);
    int r = RIGHT(i);

    int largest = i;
    if(l < arr.size() && arr[l] > arr[i]) {
      largest = l;
    }
    if(r < arr.size() && arr[r] > arr[largest]){
      largest = r;
    }
    if(largest != i) {
      swap(arr[i], arr[largest]);
      heapify_down(largest);
    }
  }

  void heapify_up(int i){
    if(i && arr[PARENT(i)] < arr[i]) {
      swap(arr[i], arr[PARENT(i)]);
      heapify_up(PARENT(i));
    }
  }

  int size(){
    return arr.size();
  }

  bool empty(){
    return arr.size() == 0;
  }

  void push(int key){
    arr.push_back(key);
    heapify_up(arr.size() - 1);
  }

  void pop(){
    if(arr.size() != 0){
      arr[0] = arr.back();
      arr.pop_back();

      heapify_down(0);
    }
  }

  int top(){
    if(arr.size() != 0) return arr[0];
  }
};



int main() {
  PriorityQueue pq;
  pq.arr = {1,4,3,2,9,8,7,16,14,10};
  for(int i = pq.arr.size(); i >= 0; i--) pq.heapify_down(i);
  for(int a: pq.arr) cout << a <<" ";
  cout << endl;
  pq.push(15);
  for(int a: pq.arr) cout << a <<" ";
  cout << endl;
  pq.pop();
  for(int a: pq.arr) cout << a <<" ";
  cout << endl;
  cout << pq.top();
  return 0;
}
