#include <iostream>
using namespace std;

//解决方案：快慢指针，如果有环，则会相遇；使用hash存储，需要额外申请空间

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//方法1
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

//方法2
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
