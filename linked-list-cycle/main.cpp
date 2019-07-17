#include <iostream>
using namespace std;

//�������������ָ�룬����л������������ʹ��hash�洢����Ҫ��������ռ�

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//����1
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *slow, *fast;
        slow = head;
        fast = head->next;
        if(fast == NULL)
            return false;
        while(slow != fast && fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL) //important
                fast = fast->next;
            else
                return false;
        }
        if(slow == fast)
            return true;
        return false;
    }
};

//����2
/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
       unordered_map<ListNode*, bool> m;
        while(head)
        {
            if(m.find(head) != m.end())
                return true;
            m[head] = true;
            head = head -> next;
        }
        return false;
    }
};
*/

int main()
{
    return 0;
}
