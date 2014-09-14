#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ust.h"


/* A pointer to the descriptor of the executing thread. */

   static thread_descriptor * running_thread;


void
ust_create(thread_fun f, void * params) {

  thread_descriptor * new_td = td_new();

  if (!setjmp(new_td->env)) {
    new_td->f = f;
    new_td->params = params;
    return;
    }

  (running_thread->f)(running_thread->params);

  ust_exit();
  }


void
ust_exit() {

  td_free(running_thread);

  if ((running_thread = td_ready()) == NULL)
    exit(EXIT_SUCCESS);
  else
    longjmp(running_thread->env, 1);
  }


void
ust_init() {

  td_init();
  running_thread = td_new();
  }
