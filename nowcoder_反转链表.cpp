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
    ListNode* ReverseList(ListNode* pHead) {
		struct ListNode* pNext=NULL;
        struct ListNode* tmp=NULL;
        if(pHead==NULL){
            return pHead;
        }
        while(pHead->next){
            tmp = pHead;
            pHead = pHead->next;
            tmp->next=pNext;
            pNext = tmp;
        }
        pHead->next = pNext;
        tmp = pHead;
        while(tmp){
            cout<<tmp->val<<endl;
            tmp = tmp->next;
        }
        return pHead;
    }
};