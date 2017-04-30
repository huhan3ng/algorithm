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
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
		ListNode head(0),*ph=&head,*pt=pHead;	//ph,pt划分值相同的一段
        head.next=pHead;
        while(ph->next){
            if(pt==NULL || pt->val!=ph->next->val){//值相同的一段结束了
                if(ph->next->next == pt){	//长度等于1,更新ph
                    ph=ph->next;
                } else {//长度超过1,去掉那段
                    ph->next=pt;
                }
            }
            pt && (pt=pt->next);
        }
        return head.next;
    }
};