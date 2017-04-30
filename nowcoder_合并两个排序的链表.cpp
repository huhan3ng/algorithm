/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        struct ListNode head(0);
        struct ListNode* pRet = &head;
        struct ListNode* pTmp = pRet;
        while(pHead1 || pHead2){
            if(pHead1==NULL){
                pTmp->next = pHead2;
                pTmp = pHead2;
                pHead2=pHead2->next;
            } else if(pHead2==NULL){
                pTmp->next = pHead1;
                pTmp = pHead1;
                pHead1=pHead1->next;
            } else if(pHead1->val < pHead2->val){
                pTmp->next = pHead1;
                pTmp = pHead1;
                pHead1=pHead1->next;
            } else {
                pTmp->next = pHead2;
                pTmp = pHead2;
                pHead2=pHead2->next;
            }
        }
        return pRet->next;
    }
};