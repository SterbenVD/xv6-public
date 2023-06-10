#include "types.h"
#include "user.h"
#include "date.h"

int main(int argc, char *argv[])
{
  struct rtcdate r;

  if (date(&r)) {
    printf(2, "date failed\n");
    exit();
  }
  // Prints in GMT+0.0
  printf(1,"Year: %d\n",r.year);
  printf(1,"Month: %d\n",r.month);
  printf(1,"Date: %d\n",r.day);
  printf(1,"Hour: %d\n",r.hour);
  printf(1,"Minute: %d\n",r.minute);
  printf(1,"Second: %d\n",r.second);

  // your code to print the time in any format you like...
  /* example output format should be like this:
     	Year: 2016
	 Month: 1 or January
	 Date: 26
	 Hour: 15
	 Minute: 12
	 Second: 11
  */
  exit();
}
