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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int flag = 100000007;
        while(pHead1){
            pHead1->val+=flag;
            pHead1=pHead1->next;
        }
        while(pHead2){
            if(pHead2->val>=flag){
                break;
            }
            pHead2=pHead2->next;
        }
        ListNode* tmp=pHead2;
        while(tmp){
            tmp->val-=flag;
            tmp=tmp->next;
        }
        return pHead2;
    }
};