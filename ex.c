#include <stdio.h>
#include <stdlib.h>
#include "ust.h"


/* The code a thread executes when a thread executes code. */

   static void
   f(void * param) {

     printf("%s.\n", (const char * const) param);

     ust_exit();
     }


int 
main() {

  ust_init();

  ust_create(f, (void *) "red");
  ust_create(f, (void *) "blue");
  ust_create(f, (void *) "white");

  printf("Go!\n");

  ust_exit();

  /* The next statement never executes because ust_exit() never returns, but it
     keeps the compiler's authoritarian mode happy. */

  return EXIT_SUCCESS;
  }
