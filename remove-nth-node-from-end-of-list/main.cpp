#include <iostream>

using namespace std;

/*
�ҵ�˼·���ȼ��������ȣ�����Ҫɾ�������ڼ����Ļ�����֪������Ҫɾ���ڼ�������ˡ�
��������ת��������δ�������ɾ����K��Ԫ��
��K-1��Ԫ��ǰͣ���������ָ��ָ���K+1����㣬ͬʱ����K�����ָ��delete����
ע�⵱�����ȵ���nʱ����ζ��ɾ��ͷ��㣬����head->next���ɡ�

�Ż���
���Բ����ر���������ȣ��������·�����
������ͬʱ��n--����ô�ȱ�����������ôn�ľ���ֵ�Ͷ�ӦҪɾ������ǰһ�������
��1->2->3->4->5, n=2,����һ��õ�n=-3��n�ľ���ֵΪ3��ǡ��������Ҫɾ������ǰһ����
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

/*�Ż�*/
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
