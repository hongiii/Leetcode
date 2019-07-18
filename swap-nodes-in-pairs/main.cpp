#include <iostream>
using namespace std;


/*
解决思路：

1、两两交换，跟数组一样，不过注意保证结点前后指向。引入辅助结点

2、递归写法
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head == NULL)
            return head;
        ListNode *newNode = new ListNode(0);
        newNode->next = head;

        ListNode *tmp1, *tmp2;
        for(ListNode *temp = newNode; temp->next && temp->next->next;)
        {
            tmp1 = temp->next;
            tmp2 = temp->next->next;

            temp->next = temp->next->next;
            tmp1->next = tmp2->next;
            tmp2->next = tmp1;
            temp = temp->next->next;
        }
        return newNode->next;
    }
};

/*
递归写法
*/
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *newNode = head->next;
        head->next = swapPairs(head->next->next);
        newNode->next = head;
        return newNode;
    }
};
*/
int main()
{
    return 0;
}
