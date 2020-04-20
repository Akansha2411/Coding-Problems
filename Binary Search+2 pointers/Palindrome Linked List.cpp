/* https://leetcode.com/problems/palindrome-linked-list/
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //Algo :  Traverse ll and store everything in stack. Then traverse ll again compare with the top element of the stack.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        stack<int>s;
        int count = 0;
        bool flag = true;
        ListNode* temp;
        temp = head;
        while(temp!=NULL)
        {
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        
        int i;
        while(temp != NULL)
        {
            i = s.top();
            s.pop();
            if(i != temp->val)
            {
                flag = false;
                break;
            }
            temp = temp->next;
        }
        return flag;
    }
};
