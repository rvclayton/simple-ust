#include <stdlib.h>
#include "jb.h"

typedef struct node {
  jb_snapshot snapshot;
  node * next;
  } node;

static node * ready = NULL;
static node * current = NULL;

jb_snapshot * 
jb_empty() {

  node * n = (node *) malloc(sizeof(node));

  n->next = ready;
  ready = n;

  return &(n->snapshot);
  }


jb_snapshot *
jb_ready() {

  node * n = ready;

  if (n == NULL)
    return NULL;

  current = n;
  ready = n->next;

  return &(n->snapshot);
  }


void 
jb_free() {
  free(current);
  current = NULL;
  }

