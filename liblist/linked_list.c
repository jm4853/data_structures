#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct Node Node;

struct List {
	Node *head;
	Node *tail;
};

struct Node {
	char *str;
	Node *next;
};

// This function, returns an empty list.
List
newlist(void) {
	List newlist;

	newlist = malloc(sizeof(struct List));
	newlist->head = NULL;
	newlist->tail = NULL;
	return newlist;
}

// Add string s to the head of the list
void
insert(List l, char *s) {
	Node *nn;

	nn = malloc(sizeof(Node));
	// nn->str = s;
	nn->str = malloc(strlen(s)+1);
	strcpy(nn->str, s);

	if (l->head != NULL) {
		nn->next = l->head;
	} else {
		l->tail = nn;
	}
	l->head = nn;
}

// Add string s to the tail of the list
void append(List l, char *s) {
	Node *nn;

	nn = malloc(sizeof(Node));
	// nn->str = s;
	nn->str = malloc(strlen(s)+1);
	strcpy(nn->str, s);
	nn->next = NULL;

	if (l->tail != NULL) {
		l->tail->next = nn;
	} else {
		l->head = nn;
	}
	l->tail = nn;
}

// Return the string in the ith element
char *get(List l, int i) {
	Node *current;

	for (current=l->head; current!=NULL; current=current->next) if (i-- == 0) return current->str;

	return NULL;
}

// Return the first element of the list whose string contains the string s as a substring
char *search(List l, char *s) {
	char *p, *str;
	Node *current;

	str = s;

	for (current=l->head; current!=NULL; current=current->next) {
		for (p=current->str; *p!=0; p++) {
			if (*p == *str) {
				str++;
			} else if (str != s) {
				str = s;
				p--;
			}
			if (*str == 0) {
				return current->str;
			}
		}
	}
	return NULL;
}

// For each string in the list, print the string stored in the list node
void printlist(List l) {
	Node *current;
	int i;

	i = 0;

	for (current=l->head; current!=NULL; current=current->next) {
		printf("%d: %s\n", i, current->str);
		i++;
	}
}

// Return the number of elements in the list
int listlen(List l) {
	int len;
	Node *current;

	len = 0;
	for (current=l->head; current!=NULL; current=current->next) len++;
	return len;
}

// Applies provided function to each element in list
void apply(List l, void (*func)(char *s)) {
	Node *current;

	for (current=l->head; current!=NULL; current=current->next) func(current->str);
}

// Returns a list where each item is the returned value of func for the corresponding item in the original list
List map(List l, char *(*func)(char *s)) {
	List new;
	Node *current;

	new = newlist();
	for (current=l->head; current!=NULL; current=current->next) {
		append(new, func(current->str));
	}
	return new;
}

