#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    double price;       
    int pages;          
    char language[30];  
    double weight;      
    int year;          
    struct Book *next;  
} Book;

Book* createBook(const char *title, double price, int pages, const char *language, double weight, int year) {
    Book *newBook = (Book*)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    strncpy(newBook->title, title, sizeof(newBook->title) - 1);
    newBook->title[sizeof(newBook->title) - 1] = '\0';
    
    strncpy(newBook->language, language, sizeof(newBook->language) - 1);
    newBook->language[sizeof(newBook->language) - 1] = '\0';

    newBook->price = price;
    newBook->pages = pages;
    newBook->weight = weight;
    newBook->year = year;

    newBook->next = NULL;
    
    return newBook;
}

void appendBook(Book **head, Book *newBook) {
    if (*head == NULL) {
        *head = newBook;
        return;
    }
    
    Book *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newBook;
}

void printList(Book *head) {
    Book *current = head;
    int index = 1;

    printf("-----------------------------------------------------------------------------------------\n");
    printf("%-3s | %-38s | %-7s | %-6s | %-8s | %-8s | %-4s\n", 
           "#", "Title", "Price", "Pages", "Lang", "Weight(g)", "Year");
    printf("-----------------------------------------------------------------------------------------\n");

    while (current != NULL) {
        printf("%-3d | %-38s | $%-6.2f | %-6d | %-8s | %-9.1f | %-4d\n",
               index++,
               current->title,
               current->price,
               current->pages,
               current->language,
               current->weight,
               current->year);
        current = current->next;
    }
    printf("-----------------------------------------------------------------------------------------\n");
}

void freeList(Book *head) {
    Book *current = head;
    while (current != NULL) {
        Book *temp = current;
        current = current->next;
        free(temp);
    }
}

int main(void) {
    Book *harryPotterSeries = NULL;

    appendBook(&harryPotterSeries, createBook("Harry Potter and the Philosopher's Stone", 12.99, 223, "English", 310.0, 1997));
    appendBook(&harryPotterSeries, createBook("Harry Potter and the Chamber of Secrets", 13.50, 251, "English", 330.0, 1998));
    appendBook(&harryPotterSeries, createBook("Harry Potter and the Prisoner of Azkaban", 14.99, 317, "English", 410.0, 1999));
    appendBook(&harryPotterSeries, createBook("Harry Potter and the Goblet of Fire", 18.00, 636, "English", 720.0, 2000));
    appendBook(&harryPotterSeries, createBook("Harry Potter and the Order of the Phoenix", 19.99, 766, "English", 890.0, 2003));
    appendBook(&harryPotterSeries, createBook("Harry Potter and the Half-Blood Prince", 17.50, 607, "English", 680.0, 2005));
    appendBook(&harryPotterSeries, createBook("Harry Potter and the Deathly Hallows", 21.00, 607, "English", 750.0, 2007));

    printList(harryPotterSeries);

    freeList(harryPotterSeries);

    return 0;
}