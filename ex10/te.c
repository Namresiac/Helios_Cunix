#include <stdio.h>
#include <stdlib.h>
 
struct Matrix {
  size_t row;
  size_t col;
  double **mat;
};
typedef struct Matrix TMatrix;
 
void initMatrix(TMatrix *m, int row, int col) {
    m->row = row;
    m->col = col;
    int i;
    m->mat = malloc(m->row * sizeof(double*));  // allocate array of double pointers
    for (i=0; i<m->row; ++i)
    {
        m->mat[i] = malloc(m->col * sizeof(double));  // allocate array of doubles
    }
}
 
void freeMatrix(TMatrix m) {
    int i;
    for (i=0; i<m.row; ++i)
    {
        free(m.mat[i]);
    }
    free(m.mat);
}
 
int readMatrix(TMatrix m) {
    for(int i=0; i<m.row; i++)
    {
      for(int j=0; j<m.col; j++)
      {
        if(scanf(" %lg", &m.mat[i][j]) != 1) return 0;
      }
    }
    return 1;
}
 
 
void printMatrix(TMatrix m) {
    for(int i=0; i<m.row; i++)
    {
      for(int j=0; j<m.col; j++)
      {
        printf("%f ", m.mat[i][j]);
      }
      printf("\n");
    }
}
 
 
 
int main(void) {
    TMatrix a;
    initMatrix(&a, 2, 3);
    if (!readMatrix(a))
    {
        printf("input error\n");
        return -1;
    }
    printMatrix(a);
    freeMatrix(a);
 
    return 0;
}