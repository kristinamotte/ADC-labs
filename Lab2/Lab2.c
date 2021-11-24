#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    char* name;
    char* surname;
    struct List *next;
} list;

list* last = NULL;
void addToHead(char*, char*);
void printList();
void removeFromHead();
void removeAll();
void shift(int, int);
int size();

int main() {
    addToHead("Anna", "Vasylenko");
    addToHead("Kristina", "Motte");
    addToHead("Vasylysa", "Summers");
    addToHead("Maksym", "Kondratiev");
    addToHead("Haku", "Kondratiev");

    printf("Original List: "); 
    printList();

    int steps;

    printf("\nPlease provide on how many elements list should be shifted\n");
    scanf("%d", &steps);

    shift(steps, size());

    printf("\n\nAfter shift: ");
    printList();

    removeFromHead();
    
    printf("\n\nAfter remove: ");
    printList();

    removeAll();

    printf("\n\nAfter remove all: ");
    printList();

    return 0;
}

void addToHead(char* name, char* surname) {
    list *temp = (list*)malloc(sizeof(list));
    temp->name = name;
    temp->surname = surname;
	
    if (last == NULL) {
        temp->name = name;
        temp->surname = surname;
        temp->next = temp;
        last = temp;
    } else {
        temp->name = name;
        temp->surname = surname;
        temp->next = last->next;
        last->next = temp;
    } 
}

void printList() {
    if (last == NULL) {
        printf("\nList is empty\n");
    } else {
        list* temp;
        temp = last->next;
 
        do {
            printf("\n%c-%s", temp->name[0], temp->surname);
            temp = temp->next;
        } while (temp != last->next);
    }
}

void removeFromHead() {
    list* temp;
 
    if (last == NULL) {
        printf("\nList is empty.\n");
    } else {
        temp = last->next;
        last->next = temp->next;
        free(temp);
    }
}

void removeAll() {
    while (last != NULL) {
        if (last->next == last) {
            free(last);
            last = NULL;
        } else {
            removeFromHead();
        }
    }
}

void shift(int steps, int size) {    
    if (steps < 1) {
        printf("Steps smaller than 1, can't handle\n");
        return;
    }
    if (steps > size) {
        printf("Steps are bigger than linked list size, can't handle\n");
        return;
    }

    list* temp;
    list* tempLast;

    for(int i = 0; i < size - steps; i++) {
        last = last->next;
    }
}

int size() {
    int size = 0;
    if (last == NULL) {
        return 0;
    } else {
        list* temp;
        temp = last->next;
 
        do {
            size += 1;
            temp = temp->next;
        } while (temp != last->next);
    }

    return size;
}