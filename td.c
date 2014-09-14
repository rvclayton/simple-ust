#include <strings.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include "td.h"


/* Yer basic doubly-linked ring buffer. */

   static thread_descriptor ring_head;


void
td_init() {

  ring_head.prev = &ring_head;
  ring_head.next = &ring_head;
  
  /* The random routines are here and in td_ready() to provide some interest by
     simulating non-deterministic concurrent behavior (wow!). */

  srandom(getpid()); 
  }


void 
td_free(thread_descriptor * td) {
  
  assert(td != NULL && td != &ring_head);

  td->next->prev = td->prev;
  td->prev->next = td->next;

  bzero(td, sizeof(thread_descriptor));

  free(td);
  }


thread_descriptor *
td_new() {

  thread_descriptor * td = 
    (thread_descriptor *) malloc(sizeof (thread_descriptor));

  td->next = ring_head.next;
  td->prev = &ring_head;
  td->prev->next = td;
  td->next->prev = td;

  return td;
  }


thread_descriptor *
td_ready() {

  /* Return either the first (head) or last (tail) thread descriptor based on a
     coin flip. */

  thread_descriptor * td = (random() % 2) ? ring_head.next : ring_head.prev;

  return (td == &ring_head) ? NULL : td;
  }
