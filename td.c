#include <strings.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include "td.h"


/* The extended thread descriptor, containing the links needed to maintain the
   ready ring.  Quasi-inheritance!  The thread descriptor field must be
   first. */

   typedef struct ring_node {
     thread_descriptor td;
     struct ring_node * next, * prev;
     } ring_node;


/* Yer basic doubly-linked ring buffer of ready-to-run thread descriptors. */

   static ring_node ready_ring_head;


void
td_init() {

  ready_ring_head.prev = ready_ring_head.next = &ready_ring_head;
  
  /* The random routines are here and in td_ready() to provide some interest by
     simulating non-deterministic concurrent behavior (wow!). */

  srandom(getpid()); 
  }


void 
td_free(thread_descriptor * td) {
  
  ring_node * rn = (ring_node *) td;

  assert(rn != NULL && rn != &ready_ring_head);

  rn->next->prev = rn->prev;
  rn->prev->next = rn->next;

  bzero(rn, sizeof(ring_node));

  free(rn);
  }


thread_descriptor *
td_new() {

  ring_node * rn = 
    (ring_node *) malloc(sizeof (ring_node));

  rn->next = ready_ring_head.next;
  rn->prev = &ready_ring_head;
  rn->prev->next = rn;
  rn->next->prev = rn;

  return (thread_descriptor *) rn;
  }


thread_descriptor *
td_ready() {

  /* Return either the first (head) or last (tail) thread descriptor based on a
     coin flip to simulate the non-determinism of true concurrency. */

  const ring_node * rn = 
    (random() % 2) ? ready_ring_head.next : ready_ring_head.prev;

  return (thread_descriptor *) ((rn == &ready_ring_head) ? NULL : rn);
  }
