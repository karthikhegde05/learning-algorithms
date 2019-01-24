#include<stdio.h>
#include<stdlib.h>
#include"linked-list.h"


int main(){
        struct Node* LL = NULL;
        insert_at_beg(&LL, 5); 
        insert_at_beg(&LL, 10);
        insert_at_beg(&LL, 15);
        printList(LL);
        insert_at_pos(LL, 25, 2); 
        printList(LL);
        insert_at_end(LL, 30);
        printList(LL);
        delete_at_beg(&LL);
        printList(LL);
        printf("%d %d\n", search_node(LL, 5)->data, search_pos(LL, 1)->data);
        delete_at_pos(LL, 4); 
        printList(LL);
        delete_at_end(LL);
        printList(LL);
        print_reverse_list(LL);
        printf("\n");
        return 0;
}



