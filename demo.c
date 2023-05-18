#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>

// To test apply function
void replacethird(char *s) {
	char *str;
	str = s;
	str += 5;
	*str = '@';
}

// To test map function
char *add_abc(char *s) {
	char *new;
	int len;

	len = strlen(s);

	new = malloc(len+1+4);
	strcpy(new, s);
	new[len+0] = '_';
	new[len+1] = 'a';
	new[len+2] = 'b';
	new[len+3] = 'c';
	new[len+4] = '\0';
	return new;
}


int
main() {
	List list, map_list;
	char *lookfor;
	int index;

	list = newlist();

	insert(list, " test_str1 ");
	insert(list, "test_str0");
	insert(list, "A sentence with spaces and all!\t");
	append(list, "test_str2");
	insert(list, "Thhhhhhhiiii\niiissss is the same item! ");
	append(list, "j(1-95'10 ==zhihisasdf a%@ansd^ifa*sd");
	append(list, "the last entry");

	index = 4;
	lookfor = "his\0";

	printf("List:\n");
	printlist(list);
	printf("\nList length: %d\n", listlen(list));
	printf("Item at index %d: %s\n", index, get(list, index));
	printf("Item containing substring \"%s\": %s\n", lookfor, search(list, lookfor));

	printf("\nList after applying replacethird():\n");
	apply(list, replacethird);
	printlist(list);

	printf("\nNew list from mapping add_abc():\n");
	map_list = map(list, add_abc);
	printlist(map_list);
	return 0;
}

