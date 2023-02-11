#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *head = NULL, *tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        struct ListNode *node;
        if (list1->val < list2->val) {
            node = list1;
            list1 = list1->next;
        } else {
            node = list2;
            list2 = list2->next;
        }

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = tail->next;
        }
    }

    if (tail != NULL) {
        tail->next = (list1 != NULL) ? list1 : list2;
    } else {
        head = (list1 != NULL) ? list1 : list2;
    }

    return head;
}

int main() {
    // Example Input: list1 = [1,2,4], list2 = [1,3,4]

    struct ListNode *list1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    list1->val = 1;
    list1->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    list1->next->val = 2;
    list1->next->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    list1->next->next->val = 4;
    list1->next->next->next = NULL;

    struct ListNode *list2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    list2->val = 1;
    list2->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    list2->next->val = 3;
    list2->next->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    struct ListNode *mergedList = mergeTwoLists(list1, list2);

    // Example Output: [1,1,2,3,4,4]
    while (mergedList != NULL) {
        printf("%d ", mergedList->val);
        mergedList = mergedList->next;
    }
    printf("\n");

    return 0;
}
