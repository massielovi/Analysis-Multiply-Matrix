#include <iostream>
#include <cstdlib>
#include <chrono> 

#define MAX 4  

void simple_multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
    for (int i = 0; i < MAX; i ++) {
      for (int j = 0; j < MAX; j ++) {
        for (int k = 0; k < MAX; k ++) {
          C[i][j] += A[i][k] * B[k][j];
        }
      }
    }
}

void print(int A[MAX][MAX]){
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
        std::cout<<A[i][j]<<" ";
    }
    std::cout<<"\n";
  }
}

int main() {
  
  //init
  int A[MAX][MAX];
  int B[MAX][MAX];
  int C[MAX][MAX];

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      A[i][j] = rand()%10;
      B[i][j] = rand()%10;
      C[i][j] = 0;
    }
  }
  std::cout<<"A-matrix: \n";
  print(A);
  std::cout<<"B-matrix: \n";
  print(B);
  
  //SIMPLE MULTIPLICATION
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  
  simple_multiply(A, B, C);
  
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "Block Multiplication Time : " << elapsed_seconds.count() << "s\n";


  std::cout<<"Result of Simple Multiplication: \n";
  print(C);
  return 0;
}