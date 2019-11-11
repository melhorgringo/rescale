#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int rank;
  int ierr;
  int numprocs;
  int num = atoi(argv[1]);
  int n1, n2, fact, prod;

  ierr = MPI_Init(&argc,&argv);
  ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  ierr = MPI_Comm_size ( MPI_COMM_WORLD, &num_procs );

  n1 = num/num_procs*rank+1;
  n2 = num/num_procs*(rank+1);

  fact = 1;

  for (int i=n1;i<=n2;i++) {
    fact = fact*i;
  }

  ierr = MPI_Reduce(&fact, &prod, 1, MPI_INT, MPI_PROD, 0,
           MPI_COMM_WORLD);
  if (rank==0) {
    printf("%d\n",prod);
  }

  ierr = MPI_Finalize();

  return 0;
}
