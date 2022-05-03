/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* mergedList = nullptr, *last;
        
        int allEmpty = 0;
        
        priority_queue < pair< int, ListNode*>, vector <  pair< int, ListNode*> >, greater <  pair< int, ListNode*> > > fila;
            
        for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i] != nullptr)fila.push({lists[i]->val, lists[i]});
        }

        int minVal = -100000, list;
        while(fila.size()){

            ListNode *top = fila.top().second;
            fila.pop();
            if(top == nullptr) continue;
            if(top->next != nullptr) fila.push({top->next->val, top->next});

            if(mergedList == nullptr){
                mergedList = top;
                last = top;
            }
            else{
                last->next = top;
                last = top;
            }
        }
        
        return mergedList;
    }
};