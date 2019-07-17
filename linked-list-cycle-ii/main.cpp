/*
解决方法：

一种方法是用之前的哈希表，第一次出现重复的那个结点即是环开始的地方。但是会需要额外O(n)的空间

但是，如何不申请额外空间，就找到环开始的地方呢？

看了别人的分析，在使用快慢指针时，可以找到两指针的相遇点。然后再用两个指针分别从链头和相遇点出发，相同速度一步步推进，那么两指针将会在环开始的地方相遇。

a+b = b+c

推导公式参考：https://www.nowcoder.com/questionTerminal/6e630519bf86480296d0f1c868d425ad

*/

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
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return NULL;
        if(head->next == head)
            return head;
        unordered_map<ListNode*, bool> m;
        static ListNode *res = NULL;
        while(head != NULL)
        {
            if(m.find(head) != m.end())
            {
                res = head;
                return res;
            }
            m[head] = true;
            head = head->next;
        }
        return NULL;
    }
};

//方法2
/*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        static ListNode *res = head;
        if(head == NULL)
            return NULL;
        ListNode *fast, *slow;
        fast = slow = head;
        //链表较短的时候，情况有限，可以直接处理(优化)
        if(fast->next == NULL)
            return NULL;
        do
        {
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL)
                fast = fast->next;
            else
                return NULL;
        }while(slow != fast && fast != NULL);
       if(fast == slow)
       {
            while(head != slow)
            {
                head = head->next;
                slow = slow->next;
            }
            res = head;
            return res;
       }
       else
           return NULL;
    }
};
*/
int main()
{
    return 0;
}
