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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {	//性能存在问题，有更好的解法
    	int i=0,j=0;
        ListNode* pCur=pListHead;
        while(pCur){
            pCur = pCur->next;
            i++;
        }
        if(i>=k){
            j=i-k;
        	pCur = pListHead;
            while(j>0){
                pCur = pCur->next;
                j--;
            }
            return pCur;
        } else {
            return NULL;
        }
    }
};