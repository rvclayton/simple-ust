#ifndef _ust_h_defined_
#define _ust_h_defined_

#include "td.h"


/* Create a thread to execute the given function on the given argument. */

   extern void ust_create(thread_fun, void *);


/* Terminate the calling thread. */

   extern void ust_exit();


/* Initialize the thread system.  Should be called exactly once before calling
   any other ust_ function. */

   extern void ust_init();

#endif

/* $Log:$ */
