/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public://p1,p1停下的位置距离入口为m，起点距离入口也为m
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		ListNode *p1=pHead, *p2=pHead;
        do{
            if(p1==NULL || p2==NULL || p2->next==NULL){
                return NULL;
            }
            p1=p1->next;
            p2=p2->next->next;
        }while(p1!=p2);
        while(p1!=pHead){
            p1=p1->next;
            pHead=pHead->next;
        }
        return pHead;
    }
};