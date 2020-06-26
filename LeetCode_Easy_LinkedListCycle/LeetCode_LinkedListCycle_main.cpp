/*
141. Linked List Cycle
Easy

Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to.
If pos is -1, then there is no cycle in the linked list.



Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

*/
#include <iostream>

using namespace std;

//Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x)
        :val(x), next(NULL)
    {}
};

#define Sol_2

#ifdef Sol_1
/*
Success
Details
Runtime: 28 ms, faster than 8.47% of C++ online submissions for Linked List Cycle.
Memory Usage: 10.3 MB, less than 5.07% of C++ online submissions for Linked List Cycle.

*/
#include <unordered_map>


class Solution {
public:
    bool hasCycle(ListNode* head) {
        //싸이클이 있으면 true, 없으면 false

        //Can you solve it using O(1) (i.e. constant) memory?
        //O(1)이 나오기 위해선 데이터량에 상관없이 로직이 일정한 시간으로 실행될 수 있어야함
        //n번 만큼의 루프를 사용하는 로직은 피하는게 좋음

        unordered_map<ListNode*, int> hashMap;
        
        while (head != nullptr)
        {
            if (hashMap.count(head) == 0)
            {
                hashMap.insert(unordered_map<ListNode*, int>::value_type(head, head->val));
                head = head->next;
            }
            else // 싸이클 발생
            {
                return true;
            }
        }
        return false;
    }
};
#endif // Sol_1

#ifdef Sol_2 //GuideCode
/*
Intuition

Imagine two runners running on a track at different speed. What happens when the track is actually a circle?

Algorithm

The space complexity can be reduced to O(1) by considering two pointers at different speed - 
a slow pointer and a fast pointer. The slow pointer moves one step at a time while the fast pointer moves two steps at a time.

If there is no cycle in the list, the fast pointer will eventually reach the end and we can return false in this case.

Now consider a cyclic list and imagine the slow and fast pointers are two runners racing around a circle track. 
The fast runner will eventually meet the slow runner. Why? Consider this case (we name it case A) - The fast runner is just one step behind the slow runner.
In the next iteration, they both increment one and two steps respectively and meet each other.

How about other cases? For example, we have not considered cases where the fast runner is two or three steps behind the slow runner yet. 
This is simple, because in the next or next's next iteration, this case will be reduced to case A mentioned above.



Time complexity : O(n). Let us denote n as the total number of nodes in the linked list. To analyze its time complexity, we consider the following two cases separately.

List has no cycle:
The fast pointer reaches the end first and the run time depends on the list's length, which is O(n).

List has a cycle:
We break down the movement of the slow pointer into two steps, the non-cyclic part and the cyclic part:

The slow pointer takes "non-cyclic length" steps to enter the cycle. At this point, the fast pointer has already reached the cycle. 
Number of iterations = non-cyclic length = N

Both pointers are now in the cycle. Consider two runners running in a cycle - the fast runner moves 2 steps while the slow runner moves 1 steps at a time. 
Since the speed difference is 1, it takes 

distance between the 2 runners / difference of speed
​
  loops for the fast runner to catch up with the slow runner. As the distance is at most "cyclic length K" and the speed difference is 1, 
  we conclude that "Number of iterations" = almost "cyclic length K".

Therefore, the worst case time complexity is O(N+K), which is O(n).

Space complexity : O(1). We only use two nodes (slow and fast) so the space complexity is O(1).
*/

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
#endif // Sol_2


int main()
{
    ListNode* head = new ListNode(1);
    /*head->next = new ListNode(2);
    ListNode* pos = head->next;

    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    head->next->next->next->next = pos;*/

    Solution sol;
    printf("%s", sol.hasCycle(head) ? "true" : "false");

    
    return 0;
}