#include "types.h"
#include "user.h"
#include "date.h"

int global[10000];

int main(int argc, char *argv[])
{
  pgtPrint();
  global[8000] = 4;
  if (pgtPrint())
  {
    printf(2, "Error: Cannot print");
  }
  int pid;
  if ((pid = fork()) == 0)
  {
    printf(1, "Child\n");
    global[8000] = 5;
    if (pgtPrint())
    {
      printf(2, "Error: Cannot print");
    }
  }
  else
  {
    printf(1, "Parent\n");
    global[3000]=2;
    if (pgtPrint())
    {
      printf(2, "Error: Cannot print");
    }
    wait();
  }

  exit();
}
