#ifndef _LIST_H_
#define _LIST_H_

typedef struct List *List;

List newlist(void);
void insert(List l, char *s);
void append(List l, char *s);
char *get(List l, int i);
char *search(List l, char *s);
void printlist(List l);
int listlen(List l);
void apply(List l, void (*func)(char *s));
List map(List l, char *(*func)(char *s));

#endif
