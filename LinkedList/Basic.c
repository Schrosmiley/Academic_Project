#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
};

void input(struct node **head, struct node **tail, int val) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = val;
    newnode->next = NULL;
    if(*head == NULL) {
        *head = newnode;
        *tail = newnode;
        return;
    }
    (*tail)->next = newnode;
    *tail = newnode;
}

void print(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void insert_at_head(struct node **head, int x) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = x;
    newnode->next = NULL;
    if(*head == NULL) {
        *head = newnode;
        return;
    }
    newnode->next = *head;
    *head = newnode;
}

void insert_at_any_position(struct node *head, int pos, int x) {
    if(pos == 0) {
        insert_at_head(&head, x);
        return;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = x;
    newnode->next = NULL;
    struct node *temp = head;
    for(int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_head(struct node **head) {
    if(*head == NULL) {
        puts("Invalid Command\n");
        return;
    }
    if((*head)->next == NULL) {
        free(*head);
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_any_position(struct node *head, int pos) {
    if(head == NULL) {
        printf("Invalid Command\n");
        return;
    }
    struct node *temp = head;
    for(int i = 1; i < pos; i++) {
        temp = temp->next ;
    }
    struct node *deletenode = temp->next;
    temp->next = temp->next->next;
    free(deletenode);
}

void sort(struct node *head) {
    for(struct node *i = head; i != NULL; i = i->next) {
        for(struct node *j = i->next; j != NULL; j = j->next) {
            if(i->val > j->val) {
                int temp = i->val;
                i->val = j->val;
                j->val = temp;
            }
        }
    }
}

void addlist(struct node *head, struct node *head1) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head1;
    print(head);
}

int main() {
    struct node *head = NULL, *tail = NULL, *head1 = NULL, *tail1 = NULL;
    int n, x;
    scanf("%d", &n);
    x = n;
    while(n--) {
        int x;
        scanf("%d", &x);
        input(&head, &tail, x);
    }
    while(x--) {
        int x;
        scanf("%d", &x);
        input(&head1, &tail1, x);
    }
    addlist(head, head1);
    return 0;
}
