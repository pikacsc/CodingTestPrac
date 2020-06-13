/*
https://leetcode.com/problems/design-linked-list/
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.

Input:
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[1],[1]]
Output:
[null,null,null,null,2,null,3]

Explanation:
MyLinkedList linkedList = new MyLinkedList(); // Initialize empty LinkedList
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3


Constraints:
0 <= index,val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex.
*/

#define Sol_1
#define DEBUG

#include <iostream>
#include <string>

#ifdef Sol_1
/*
Success
Runtime: 76 ms, faster than 42.67% of C++ online submissions for Design Linked List.
Memory Usage: 19.5 MB, less than 43.34% of C++ online submissions for Design Linked List.
*/
class MyLinkedList {
    class Node
    {
    public:
        int m_val = 0;
        Node* m_Next = nullptr;

        Node()
        {}

        Node(int _val)
        {
            m_val = _val;
        }
    };

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        m_Head = nullptr;
        m_Tail = nullptr;
        m_Size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= m_Size || index < 0)
        {
            return -1;
        }

        int i = 0;
        Node* tempNode = m_Head;
        while (i < index)
        {
            tempNode = tempNode->m_Next;
            i++;
        }
        return tempNode->m_val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (m_Size == 0)
        {
            m_Head = new Node(val);
            m_Tail = m_Head;
        }
        else
        {
            Node* newNode = new Node(val);
            newNode->m_Next = m_Head;
            m_Head = newNode;
        }
        m_Size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (m_Size == 0)
        {
            m_Head = newNode;
            m_Tail = m_Head;
        }
        else if (m_Size == 1)
        {
            m_Head->m_Next = newNode;
            m_Tail = newNode;
        }
        else
        {
            Node* tempNode = m_Head;
            for (int i = 0; i < m_Size; i++)
            {
                tempNode = tempNode->m_Next == nullptr ? tempNode : tempNode->m_Next;
            }
            tempNode->m_Next = newNode;
            m_Tail = newNode;
        }
        m_Size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > m_Size || index < 0)
        {
            return;
        }


        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        if (index == m_Size)
        {
            addAtTail(val);
            return;
        }

        Node* newNode = new Node(val);

        Node* prevNode = nullptr;
        Node* tempNode = m_Head;
        for (int i = 0; i < index; i++)
        {
            if (tempNode->m_Next == nullptr)
            {
                break;
            }
            else
            {
                prevNode = tempNode;
                tempNode = tempNode->m_Next;
            }
        }
        if (prevNode != nullptr)
        {
            prevNode->m_Next = newNode;
        }
        newNode->m_Next = tempNode;
        m_Size++;

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= m_Size || index < 0)
        {
            return;
        }

        if (index == 0)
        {
            Node* tempNode = m_Head->m_Next;
            delete m_Head;
            m_Head = tempNode;
            m_Size--;
            return;
        }

        Node* prevNode = nullptr;
        Node* targetNode = m_Head;
        Node* nextNode = nullptr;
        for (int i = 0; i < index; i++)
        {
            prevNode = targetNode;
            targetNode = targetNode->m_Next;
            nextNode = targetNode->m_Next;
        }

        delete targetNode;
        targetNode = nullptr;
        prevNode->m_Next = nextNode;
        m_Size--;
    }

    size_t GetSize()
    {
        return m_Size;
    }

#ifdef DEBUG
    void PrintAll()
    {
        if (m_Size == 0)
        {
            return;
        }

        Node* tempNode = m_Head;
        int count = 0;
        for (int i = 0; i < m_Size; i++)
        {
            if (count == 10)
            {
                printf("\n");
                count = 0;
            }
            else
            {
                count++;
            }

            if (tempNode->m_Next)
            {
                printf("%d)%d ¡æ ", i, tempNode->m_val);
            }
            else
            {
                printf("%d)%d", i, tempNode->m_val);
            }
            tempNode = tempNode->m_Next;
        }
    }
#endif // DEBUG

    

private:
    Node* m_Head;
    Node* m_Tail;
    size_t m_Size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

#endif // Sol_1



const char funcArrInput[][20] = { "addAtHead","addAtTail","addAtTail","addAtTail","addAtTail","addAtTail","addAtTail","deleteAtIndex","addAtHead","addAtHead","get","addAtTail","addAtHead","get","addAtTail","addAtIndex","addAtTail","addAtHead","addAtHead","addAtHead","get","addAtIndex","addAtHead","get","addAtHead","deleteAtIndex","addAtHead","addAtTail","addAtTail","addAtIndex","addAtTail","addAtHead","get","addAtTail","deleteAtIndex","addAtIndex","deleteAtIndex","addAtHead","addAtTail","addAtHead","addAtHead","addAtTail","addAtTail","get","get","addAtHead","addAtTail","addAtTail","addAtTail","addAtIndex","get","addAtHead","addAtIndex","addAtHead","addAtTail","addAtTail","addAtIndex","deleteAtIndex","addAtIndex","addAtHead","addAtHead","deleteAtIndex","addAtTail","deleteAtIndex","addAtIndex","addAtTail","addAtHead","get","addAtIndex","addAtTail","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","deleteAtIndex","get","get","addAtHead","get","addAtTail","addAtTail","addAtIndex","addAtIndex","addAtHead","addAtTail","addAtTail","get","addAtIndex","addAtHead","deleteAtIndex","addAtTail","get","addAtHead","get","addAtHead","deleteAtIndex","get","addAtTail","addAtTail" };

int inputArr[][2] =
{
    {38},{66},{61},{76},{26},{37},{8},{5},{4},{45},{4},{85},{37},{5},{93},{10,23},{21},{52},{15},{47},{12},{6,24},{64},{4},{31},{6},{40},{17},{15},{19,2},{11},{86},{17},{55},{15},{14,95},{22},{66},{95},{8},{47},{23},{39},{30},{27},{0},{99},{45},{4},{9,11},{6},{81},{18,32},{20},{13},{42},{37,91},{36},{10,37},{96},{57},{20},{89},{18},{41,5},{23},{75},{7},{25,51},{48},{46},{29},{85},{82},{6},{38},{14},{1},{12},{42},{42},{83},{13},{14,20},{17,34},{36},{58},{2},{38},{33,59},{37},{15},{64},{56},{0},{40},{92},{63},{35},{62},{32}
};

void Func(const char* _funcName,int& _inputIndex, int& _inputValue,int& _output, MyLinkedList* _linkedList)
{
    if (strcmp(_funcName, "addAtHead") == 0)
    {
        _linkedList->addAtHead(_inputValue);
    }
    else if (strcmp(_funcName, "addAtTail") == 0)
    {
        _linkedList->addAtTail(_inputValue);
    }
    else if (strcmp(_funcName, "addAtIndex") == 0)
    {
        _linkedList->addAtIndex(_inputIndex, _inputValue);
    }
    else if (strcmp(_funcName, "get") == 0)
    {
        _output = _linkedList->get(_inputIndex);
    } 
    else if (strcmp(_funcName, "deleteAtIndex") == 0)
    {
        _linkedList->deleteAtIndex(_inputIndex);
    }
}


int main()
{
    MyLinkedList* linkedList = new MyLinkedList;

    int output = 0;
    int nullInput = 0;
    printf("number\tfunction arg\t\toutput\n");
    for (int i = 0; i < 101; i++)
    {
        output = 0;
        if(strcmp(funcArrInput[i],"addAtIndex") == 0)
        {
            Func(funcArrInput[i], inputArr[i][0], inputArr[i][1], output, linkedList);
        }
        else if (strcmp(funcArrInput[i], "get") == 0)
        {
            Func(funcArrInput[i], inputArr[i][0], nullInput, output, linkedList);
        }
        else if (strcmp(funcArrInput[i], "addAtHead") == 0 || strcmp(funcArrInput[i], "addAtTail") == 0)
        {
            Func(funcArrInput[i], nullInput, inputArr[i][0], output, linkedList);
        }
        else
        {
            Func(funcArrInput[i], inputArr[i][0], nullInput, output, linkedList);
        }


        if (strcmp(funcArrInput[i], "addAtIndex") == 0)
        {
            printf("%d. %s( %d, %d ) : \tNULL\n", i, funcArrInput[i], inputArr[i][0], inputArr[i][1]);
        }
        else if (strcmp(funcArrInput[i], "get") == 0)
        {
            printf("%d. %s( %d ) : \t\t\t%d\n", i, funcArrInput[i], inputArr[i][0], output);
        }
        else if (strcmp(funcArrInput[i], "addAtHead") == 0 || strcmp(funcArrInput[i], "addAtTail") == 0)
        {
            printf("%d. %s( %d ) : \t\tNULL\n", i, funcArrInput[i], inputArr[i][0]);
        }
        else
        {
            printf("%d. %s( %d ) : \tNULL\n", i, funcArrInput[i], inputArr[i][0]);
        }
#ifdef DEBUG
        linkedList->PrintAll();
#endif // DEBUG
        printf("\n\n");
    }
    
   
    return 0;
}