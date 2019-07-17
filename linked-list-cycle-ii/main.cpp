/*
���������

һ�ַ�������֮ǰ�Ĺ�ϣ����һ�γ����ظ����Ǹ���㼴�ǻ���ʼ�ĵط������ǻ���Ҫ����O(n)�Ŀռ�

���ǣ���β��������ռ䣬���ҵ�����ʼ�ĵط��أ�

���˱��˵ķ�������ʹ�ÿ���ָ��ʱ�������ҵ���ָ��������㡣Ȼ����������ָ��ֱ����ͷ���������������ͬ�ٶ�һ�����ƽ�����ô��ָ�뽫���ڻ���ʼ�ĵط�������

a+b = b+c

�Ƶ���ʽ�ο���https://www.nowcoder.com/questionTerminal/6e630519bf86480296d0f1c868d425ad

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

//����2
/*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        static ListNode *res = head;
        if(head == NULL)
            return NULL;
        ListNode *fast, *slow;
        fast = slow = head;
        //����϶̵�ʱ��������ޣ�����ֱ�Ӵ���(�Ż�)
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
