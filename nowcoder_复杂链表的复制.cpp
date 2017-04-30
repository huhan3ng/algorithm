/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
    RandomListNode* pNewHead=NULL;
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* pCur = pHead;
        RandomListNode* pCur2 = NULL;
        RandomListNode* tmp;
        while(pCur){
            tmp = new RandomListNode(pCur->label);
            tmp->next = NULL;
			tmp->random = pCur->random;
            if(pCur2 != NULL){
                pCur2->next = tmp;
            } else {
                pNewHead = tmp;
            }
            pCur2 = tmp;
            //pCur->random = pCur2;
            pCur = pCur->next;
        }
       // pCur2 = pNewHead;
        //while(pCur2){
        //    tmp = pCur2->random;
       //     pCur2->random = pCur2->random->random;
       //     pCur->random = tmp;
       //     pCur2=pCur2->next;
       //     pCur = pCur->next;
      //  }
        return pNewHead;
    }
};