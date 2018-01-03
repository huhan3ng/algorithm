/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
// 更优解法：两个链表有公共节点，那从公共节点开始后面都一样，包括一样长。也就是让两个链表尾部对其，从短的那条头部开始一对一找
class Solution {	//23333 2B解法
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
