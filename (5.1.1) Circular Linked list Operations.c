#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

NODE createCLL(int n) {
 if (n <= 0) return NULL;
    NODE head = NULL, temp = NULL, newNode;
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = createNodeInCLL(x);
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    temp->next = head; 
    return head;

}
void traverseListInCLL(NODE head) {

 if (head == NULL) {
        printf("CLL is empty\n");
        return;
    }
    NODE temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");

}
NODE insertAtPositionInCLL(NODE head, int pos, int x) {
NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = x;

    if (pos == 1) { 
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }
        NODE temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        return newNode;
}
    NODE temp = head;
    int count = 1;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }
    if (count != pos - 1) {
        printf("Position not found\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;

}
NODE deleteAtPositionInCLL(NODE head, int pos) {
if (head == NULL) {
        printf("CLL is empty\n");
        return NULL;
    }
    NODE temp = head, prev = NULL;
    int count = 1;

    if (pos == 1) {
        
        while (temp->next != head) {
            temp = temp->next;
        }
        NODE del = head;
        if (head->next == head) { 
            head = NULL;
        } else {
            temp->next = head->next;
            head = head->next;
        }
        printf("Deleted element: %d\n", del->data);
        free(del);
        return head;
}

    temp = head;
    while (count < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (count != pos) {
        printf("Position not found\n");
        return head;
    }
    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
    return head;
	
}
NODE reverseCLL(NODE head) {
 if (head == NULL || head->next == head) return head;

    NODE prev = NULL, curr = head, next = NULL;
    NODE tail = head;

    while (tail->next != head) {
        tail = tail->next;
    }

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    head->next = prev; 
    head = prev;       
    return head;

}
NODE concatCLL(NODE first, NODE second) {
 if (first == NULL) return second;
    if (second == NULL) return first;

    NODE temp1 = first, temp2 = second;
    while (temp1->next != first) temp1 = temp1->next;
    while (temp2->next != second) temp2 = temp2->next;

    temp1->next = second;
    temp2->next = first;
    return first;

}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);  
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
