#include "types.h"
#include "user.h"
#include "date.h"

int global[10000];

int main(int argc, char *argv[])
{

  global[8000] = 4;
  
  // int local[100000];
  // for(int i=0;i<100000;i++){
  //   local[i]=0;
  // }
  if (pgtPrint())
  {
    printf(2, "Error: Cannot print");
  }
  int *marr = (int *)malloc(30000 * sizeof(int));
  
  if (pgtPrint())
  {
    printf(2, "Error: Cannot print");
  }

  exit();
}
