#include <iostream>

using namespace std;

/*
我的思路是先计算链表长度，给定要删除倒数第几个的话，就知道正向要删除第几个结点了。
这个问题就转化成了如何从链表中删除第K个元素
到K-1个元素前停下来，后继指针指向第K+1个结点，同时将第K个结点指针delete掉。
注意当链表长度等于n时，意味着删除头结点，返回head->next即可。

优化：
可以不用特别计算链表长度，采用以下方法；
遍历的同时令n--，那么等遍历结束，那么n的绝对值就对应要删除结点的前一个结点了
如1->2->3->4->5, n=2,遍历一遍得到n=-3，n的绝对值为3，恰好是我们要删除结点的前一个。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return NULL;

        unsigned int cnt = 0;
        ListNode *tmp = head;
        while(tmp != NULL)
        {
            cnt++;
            tmp = tmp->next;
        }
     //   cout << cnt << endl;
        if(cnt == n)
        {
            return head->next;
        }
        tmp = head;
        for(int i = 1; i < cnt-n; i++)
        {
            tmp = tmp->next;
        }
        ListNode *otherTmp = tmp->next;
        tmp->next = otherTmp->next;
        delete otherTmp;
        return head;
    }
};

/*优化*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return NULL;
        ListNode *frontP, *backP;
        frontP = backP = head;
        while(frontP != NULL)
        {
            frontP = frontP->next;
            if(n < 0)
                backP = backP->next;
            n--;
        }
        if(n == 0)
            return head->next;
        else
            backP->next = backP->next->next;
        delete frontP;
        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
