// Main.cpp
#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;

void addToHeap(int newval){

}

char* readFile(char* input){
  char output[5000];
  int pos = 0;
  ifstream fin(input);
  if(fin.is_open()){
    while(!fin.eof() && pos<5000){
      fin.get(output[pos]);
      pos++;
    }
    output[pos-1] = '\0';
  }
  else{
    cout<<"File could not be found." << endl;
  }
  for(int i = 0; output[i] != '\0'; i++){
    cout<<output[i];
  }
  cout<"hi"<<endl;
  return output;
}

int main(){
  char input[5000];
  int intput;
  hi:
  while(1){
    cout<<"Add Number(A) Add File(F) Show Heap(H) Sort(S) Quit(Q)"<<endl;
    cin>>input;
    if(input[0] == 'A'){
      cout<<"Enter your number"<<endl;
      cin>>intput;
    }
    else if(input[0] == 'F'){
      cout<<"Enter the name of the file"<<endl;
      cin>>input;
      readFile(input);
      cout<<"1231232"<<endl;
      for(int i = 0; input[i] != '\0'; i++){
      intput = 0;
        while(input[i+1] != ' '){
          intput = 10*intput + (int)input[i];
          i++;
        }
          intput = 10*intput + (int)input[i];
          i+=2;
          cout<<intput<<endl;
        }
      }
    }
    else if(input[0] == 'H'){

    }
    else if(input[0] == 'S'){

    }
    else if(input[0] == 'Q'){
      break hi;
    }
    else{
      cout<<"Not a valid command."<<endl;
    }
    return 0;
  }
}
