#include <iostream>
#include <set>
using namespace std;

typedef struct list {
    struct list *next;
    int key;
}list;

list *create_list();

int main() {
    list *head;
    head = create_list();

    set<list *> list_set;

    list *tmp = head;
    while(tmp != NULL) {
        if(list_set.find(tmp) != list_set.end()) {
            cout << "true" << endl;
            return 0;
        }
        list_set.insert(tmp);
        tmp = tmp->next;
    }
    cout << "false" << endl;
    return 0;
}

list *create_list() {
    list *head = new list;
    head->next = NULL;
    head->key = 0;
    list *tail = head;
    for(int i = 1; i != 10; ++i) {
        list* tmp = new list;
        tmp->next = NULL;
        tmp->key = i;
        tail -> next = tmp;
        tail = tmp;
    }
    //tail->next = head->next->next->next;
    return head;
}
