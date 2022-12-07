#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define LOWER 1
#define UPPER 5

#include "mylib/mylib.h"

void test_multiply_vector_matrix(int *Matrix, int *Vector, int N, int *vector_expected)
{
  int *vector_result = (int*)malloc(N * sizeof(int));

  if (vector_result == NULL)
  {
    printf("Malloc is failed!\n");
    return;
  }
  
  matVecMult(Matrix, Vector, vector_result, N);

  /*
    the code to compare the result of the multiply 
    vector matrix function and the expected result
  */

  int i;
  for (i = 0; i < N; i++)
  {
    printf("Actual V[%d] = %-2d; Expected V[%d] = %-2d\n", i, vector_result[i], i, vector_expected[i]);
    assert(vector_result[i] == vector_expected[i]);
  }
}

int generateRandomInt(int lower, int upper){
    return (rand() % (upper-lower+1)) + lower;
}

void initMat(int* Matrix, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            Matrix[N*i+j] = generateRandomInt(LOWER,UPPER);
        }
    }
}

void initVec(int* Vector, int N){
    for(int i=0; i<N; i++){
        Vector[i] = generateRandomInt(LOWER,UPPER);
    }
}

int main()
{
  int Total_test_cases = 3;
  int N = 2;

  int matrix_input_test_case[3][4] = {
    {2, 3, 4, 1},
    {3, 4, 1, 3},
    {4, 1, 6, 5},
  };

  int vector_input_test_case[3][2] = {
    {0, 0},
    {1, 2},
    {4, 1},
  };

  int vector_expected_test_case[3][2] = {
    {0, 0},
    {11, 7},
    {17, 29},
  };


  int i;
  for (i = 0; i < Total_test_cases; i++)
  {
    printf("Test #%d:\n", i + 1);
    test_multiply_vector_matrix(
      matrix_input_test_case[i],
      vector_input_test_case[i],
      N,
      vector_expected_test_case[i]
    );
    printf("\n");
  }

  return 0;
}