#include <iostream>
#include <cstdlib>
#include <chrono> 

#define MAX 4  
#define BLOCK_SIZE 2  

void block_multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
  //READ INTO FAST MEMORY
    for (int i = 0; i < MAX; i += BLOCK_SIZE) {
      for (int j = 0; j < MAX; j += BLOCK_SIZE) {
        for (int k = 0; k < MAX; k += BLOCK_SIZE) {
          // BLOCK MULTIPLICATION
          for (int ii = i; ii < i + BLOCK_SIZE; ii++) {
            for (int jj = j; jj < j + BLOCK_SIZE; jj++) {
              for (int kk = k; kk < k + BLOCK_SIZE; kk++) {
                  C[ii][jj] += A[ii][kk] * B[kk][jj];
              }
            }
          }
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
  
  //BLOCKED MULTIPLICATION
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  
  block_multiply(A, B, C);
  
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "Block Multiplication Time : " << elapsed_seconds.count() << "s\n";


  std::cout<<"Result of Block Multiplication: \n";
  print(C);
  return 0;
}