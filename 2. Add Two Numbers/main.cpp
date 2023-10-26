#include <iostream>
#include <vector>

//Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

    ~ListNode() {
        std::cout << "ListNode Destroyed" << std::endl;
    }
};

ListNode* generate_listNode(std::vector<int> list) {
    ListNode* outputNode = new ListNode{ list[0] };
    ListNode* nextNode = new ListNode{};
    outputNode->next = nextNode;
    for (int i = 1; i < list.size(); ++i)
    {
        nextNode->val = list[i];
        if (i == (list.size() - 1)) {
            break;
        }
        nextNode->next = new ListNode{};
        nextNode = nextNode->next;
    }
    return outputNode;
}

void outputNodeList(ListNode* Node) {
    std::cout << Node->val << std::endl;
    while (Node->next != nullptr) {
        Node = Node->next;
        std::cout << Node->val << std::endl;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp_head = new ListNode();
        ListNode* tail = temp_head;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int num1 = (l1 != nullptr) ? l1->val : 0;
            int num2 = (l2 != nullptr) ? l2->val : 0;

            int sum = num1 + num2 + carry;
            carry = sum / 10;
            ListNode* next_node = new ListNode(sum % 10);
            tail->next = next_node;

            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        ListNode* sum_node = temp_head->next;
        delete temp_head;
        return sum_node;
    }
};

int main(){
    ListNode* l1 = generate_listNode({ 1,2,3,4 });
    ListNode* l2 = generate_listNode({ 1,2,3,4 });
    Solution s{};
  
    ListNode* sumlist = s.addTwoNumbers(l1, l2);
    outputNodeList(sumlist);
}
