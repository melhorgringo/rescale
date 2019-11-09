#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int rank;
  int num = atoi(argv[1]);
  int num2 = num/2;
  int n1, n2, fact, prod2;

  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank==0) {
    n1 = 1;
    n2 = num2;
  }
  else {
    n1 = num2 + 1;
    n2 = num;
  }

  fact = 1;

  for (int i=n1;i<=n2;i++) {
    fact = fact*i;
  }

  if (rank==1) {
    MPI_Send(&fact, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }
  else {
    MPI_Recv(&prod2, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    fact = fact*prod2;
    printf("%d\n",fact);
  }

  MPI_Finalize();

  return 0;
}
