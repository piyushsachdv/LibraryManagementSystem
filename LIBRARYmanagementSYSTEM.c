#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100

typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    Book new_book;
    printf("Enter book ID: ");
    scanf("%d", &new_book.id);
    printf("Enter book title: ");
    getchar(); // Clear newline
    fgets(new_book.title, TITLE_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; // Remove newline
    printf("Enter author name: ");
    fgets(new_book.author, AUTHOR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0; // Remove newline
    library[book_count++] = new_book;
    printf("Book added successfully!\n");
}

void search_book() {
    int id;
    printf("Enter book ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            printf("Found book:\nID: %d\nTitle: %s\nAuthor: %s\n", library[i].id, library[i].title, library[i].author);
            return;
        }
    }
    printf("Book not found.\n");
}

void delete_book() {
    int id;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            for (int j = i; j < book_count - 1; j++) {
                library[j] = library[j + 1];
            }
            book_count--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void display_books() {
    printf("Library Books:\n");
    printf("ID\tTitle\t\t\tAuthor\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d\t%s\t%s\n", library[i].id, library[i].title, library[i].author);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Delete Book\n");
        printf("4. Display Books\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_book(); break;
            case 2: search_book(); break;
            case 3: delete_book(); break;
            case 4: display_books(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

