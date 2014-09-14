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

  if (1) {
    ust_create(f, (void *) "red");
    ust_create(f, (void *) "blue");
    ust_create(f, (void *) "white");

    printf("Go!\n");
    }
  else {
    thread_descriptor
      * td1 = td_new(),
      * td2 = td_new(),
      * td3 = td_new();

    td_free(td1);
    td_free(td2);
    td_free(td3);
    }

  ust_exit();

  /* The next statement never executes because ust_exit() never returns, but it
     keeps the compiler's authoritarian mode happy. */

  return EXIT_SUCCESS;
  }
