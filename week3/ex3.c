#include <stdio.h>

typedef struct {
    int data;
    struct node *next;
} node;


void print_list(node *head) {
    while (head->next != NULL) {
        head = head->next;
        printf("%d ", head->data);
    }
    printf("\n");
}

void insert_node(node *head, int data) {
    while (head->next != NULL) {
        head = head->next;
    }
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    head->next = (struct node *) new_node;
}

void delete_node(struct node **head, int data) {
    node *temp = *head, *prev;

    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
    } else {
        while (temp != NULL && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
    }
}


int main() {

    node *head = (node *) malloc(sizeof(node));

    insert_node(head, 1);
    insert_node(head, 2);
    insert_node(head, 4);
    insert_node(head, 8);
    print_list(head);
    delete_node(&head, 4);
    print_list(head);
    delete_node(&head, 1);
    print_list(head);

    return 0;
}
