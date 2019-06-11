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
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        RandomListNode* pNode = pHead;
        
        while(pNode != NULL)
        {
            RandomListNode * newNode = new RandomListNode(pNode->label);
            newNode->next = pNode->next;
            pNode->next = newNode;
            pNode = newNode->next;
        }
        
        pNode = pHead;
        while(pNode != NULL)
        {
            if(pNode->random != NULL)
            {
                pNode->next->random = pNode->random->next;
            }
            else
                pNode->next->random = NULL;
            pNode = pNode->next->next;
        }
        
        pNode = pHead;
        RandomListNode* pret = pNode->next;
        RandomListNode* cur = pret;
        while(pNode != NULL)
        {
            if(cur->next != NULL)
            {
                pNode->next = cur->next;
                cur->next = cur->next->next;
                pNode = pNode->next;
                cur = cur->next;
            }
            else
            {
                pNode->next = NULL;
                break;
            }
        }
        return pret;
    }
};
