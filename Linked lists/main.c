// 我們應該總是檢查 malloc 是否返回了 NULL 值

// Linked lists 相對於 Array 有一些優勢：
// 可以從列表的中間添加或刪除項目
// 無需定義初始大小

// 然而，Linked lists 也有一些缺點：
// 沒有“隨機”訪問 - 不可能在不先遍歷所有項目的情況下到達數組中的第 n 個項目。這意味著我們必須從列表的開頭開始，並計算我們在列表中前進的次數，直到到達所需的項目。
// 需要動態記憶體分配和指針，這使程式碼變得複雜，並增加了記憶體泄漏和段錯誤(segmentation faults)的風險。
// Linked lists 比 Array 有更大的開銷，因為 Linked list 項目是動態分配的（這在記憶體使用方面效率較低），並且列表中的每個項目還必須存儲一個額外的指針。

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_break_line(void) {
    printf("\n--------------------\n");
}

int main () {
    node_t *head = NULL;

    head = (node_t *) malloc(sizeof(node_t));
    head->val = 2;
    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 3;
    head->next->next = (node_t *) malloc(sizeof(node_t));
    head->next->next->val = 4;
    head->next->next->next = NULL;

    print_list(head);
    print_break_line();

    push(&head, 5);
    push(&head, 6);
    print_list(head);
    print_break_line();

    unshift(&head, 1);
    print_list(head);
    print_break_line();
    unshift(&head, 0);
    print_list(head);
    print_break_line();
    
    int pop_val = pop(&head);
    printf("pop value is: %d\n", pop_val);
    print_list(head);
    print_break_line();
    pop_val = pop(&head);
    printf("pop value is: %d\n", pop_val);
    print_list(head);
    print_break_line();

    int shift_val = shift(&head);
    printf("shift value is: %d\n", shift_val);
    print_list(head);
    print_break_line();
    shift_val = shift(&head);
    printf("shift value is: %d\n", shift_val);
    print_list(head);
    print_break_line();

    print_list(head);
    printf("\n");
    int find_value = 2;
    printf("value of %d index is: %d\n", find_value, find_index_by_value(head, find_value));
    find_value = 4;
    printf("value of %d index is: %d\n", find_value, find_index_by_value(head, find_value));
    find_value = 10;
    printf("value of %d index is: %d", find_value, find_index_by_value(head, find_value));
    print_break_line();

    print_list(head);
    printf("\n");
    int find_index = 0;
    printf("index of %d value is: %d\n", find_index, find_value_by_index(head, find_index));
    find_index = -1;
    printf("index of %d value is: %d\n", find_index, find_value_by_index(head, find_index));
    find_index = 10;
    printf("index of %d value is: %d", find_index, find_value_by_index(head, find_index));
    print_break_line();

    print_list(head);
    printf("\n");
    int remove_value = 0;
    printf("remove value is %d, index of the remove value is: %d\n", remove_value, remove_by_value(&head, remove_value));
    remove_value = 4;
    print_list(head);
    printf("\n");
    printf("remove value is %d, index of the remove value is: %d\n", remove_value, remove_by_value(&head, remove_value));
    remove_value = 10;
    print_list(head);
    printf("\n");
    printf("remove value is %d, index of the remove value is: %d", remove_value, remove_by_value(&head, remove_value));
    print_break_line();


    int remove_index = 0;
    print_list(head);
    printf("\n");
    printf("remove index is %d, index of the remove index is: %d\n", remove_index, remove_by_index(&head, remove_index));
    remove_index = 1;
    print_list(head);
    printf("\n");
    printf("remove index is %d, index of the remove index is: %d\n", remove_index, remove_by_index(&head, remove_index));
    remove_index = 10;
    print_list(head);
    printf("\n");
    printf("remove index is %d, index of the remove index is: %d", remove_index, remove_by_index(&head, remove_index));
    print_break_line();

    free_list(&head);

    return 0;
}

