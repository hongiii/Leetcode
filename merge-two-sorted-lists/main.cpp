#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        ListNode *res = nullptr;
        if(l1->val < l2->val)
        {
            res = l1;
            res->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            res = l2;
            res->next = mergeTwoLists(l1, l2->next);
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
