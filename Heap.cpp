// Heap.cpp
// Implements a Max Heap
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

// returns index of left child
int getLeft(int parent, int size){
  int left = 2*parent;
  if(left < size){
    return left;
  }
  // left child does not exist
  else{
    return -1;
  }
}

// returns index of right child
int getRight(int parent, int size){
  int right = 2*parent+1;
  if(right < size){
    return right;
  }
  // right child does not exist
  else{
    return -1;
  }
}

// returns index of parent to the child
int getParent(int child){
  // already at top of heap
  if(child == 0){
    return -1;
  }
  else{
    return floor(child/2);
  }
}

// swaps child with parent if child has higher value recursively
void heapifyUp(int* heap, int curr){
  int parent = getParent(curr);
  if(parent >= 0){
    if(heap[curr] > heap[parent]){
      int temp = heap[curr];
      heap[curr] = heap[parent];
      heap[parent] = temp;
      heapifyUp(heap, parent);
    }
  }
}

// swaps parent with largest value child if parent has smaller value recursively
void heapifyDown(int* heap, int curr, int size){
  int large = getLeft(curr, size);
  if(large >= 0){
    int right = getRight(curr, size);
    if(right>=0 && heap[right]>heap[large]){
      large = right;
    }
    if(heap[curr] < heap[large]){
      int temp = heap[curr];
      heap[curr] = heap[large];
      heap[large] = temp;
      heapifyDown(heap, large, size);
    }
  }
}

int main(){
  bool run = true;
  char input[5000];
  int heap[200];
  int size = 0;
  while(run == true){
    cout<<"Add Number(A) Add File(F) Show Heap(H) Print&Quit(P)"<<endl;
    cin>>input;
    // add one number at a time
    if(input[0] == 'A'){
      cout<<"Enter your number"<<endl;
      cin>>heap[size];
      heapifyUp(heap, size);
      size++;
    }
    // read in a series of numbers from a file
    else if(input[0] == 'F'){
      cout<<"Enter the name of the file"<<endl;
      cin>>input;
      fstream myFile(input);
      while(myFile >> heap[size]){
        heapifyUp(heap, size);
        size++;
      }
    }
    // prints visual heap
    else if(input[0] == 'H'){
      int levelSize = 1;
      int totalSize = 1;
      for(int i = 0; i<size; i++){
        cout<<heap[i]<<"\t";
        if(i == totalSize - 1){
          cout<<endl;
          levelSize *= 2;
          totalSize += levelSize;
        }
      }
      cout<<endl;
    }
    // prints sorted numbers and quits program
    else if(input[0] == 'P'){
      while(size>0){
        cout<<heap[0]<<" ";
        size--;
        if(size>0){
          heap[0] = heap[size];
          heapifyDown(heap, 0, size);
        }
      }
      run = false;
    }
    else{
      cout<<"Not a valid command."<<endl;
    }
  }
  return 0;
}
