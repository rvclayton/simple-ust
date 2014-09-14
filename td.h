#ifndef _td_h_defined_
#define _td_h_defined_

#include <setjmp.h>


/* The type of the function a thread executes. */

   typedef void (* thread_fun)(void *);


/* What a thread descriptor is. */

   typedef struct thread_descriptor {

     /* The thread state. */

        jmp_buf env;

     /* The function providing the code the thread runs. */

        thread_fun f;

     /* Parameters passed into f() when the thread calls f(). */

     void * params;

     } thread_descriptor;


/* Initilze the thread descriptor library.  Should be called exactly once
   before calling any other td_ function. */

   extern void td_init();


/* Free the given thread descriptor. */

   extern void td_free(thread_descriptor *);


/* Create and return a new thread descriptor.  The new descriptor is added to
   the ready list, so the jump buffer should be filled in before calling
   td_ready(). 

   This is a stupid design becaue td_new() does two things when it should only
   be doing one.  A better design would split out the ready-queue add to a
   separate function. */

   extern thread_descriptor * td_new();


/* Return the next ready thread descriptor, or null if there are no ready
   descriptors. */

   extern thread_descriptor * td_ready();

#endif

