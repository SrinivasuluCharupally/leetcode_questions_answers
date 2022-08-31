#include <bits/stdc++.h>
using namespace std;
struct listNode
{
    int value;
    listNode* next;
    listNode(int x)
    {
        value = x;
        next = NULL;
    }
};

void print(listNode* head)
{
    if(head == NULL) {
        cout << "Empty List\n";
        return;
    }
    while(head)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << '\n';
    return;
}

listNode* removeElements(listNode* head, int val) {
    if(head == NULL) {
        return head;
    }
    if(head->value == val) {
        listNode* temp = head->next;
        head->next = NULL;
        delete(head);
        return removeElements(temp , val);
    }
    head->next = removeElements(head->next , val);
    return head;
}

int main() {
    listNode* head = new listNode(1);
    head->next = new listNode(2);
    head->next->next = new listNode(2);
    head->next->next->next = new listNode(3);
    head->next->next->next->next = new listNode(4);
    int val = 2;
    print(removeElements(head , val));
    return 0;
}

