class Solution {
public:
    ListNode* rev(ListNode* &leftnode, ListNode* &rightend) {
        ListNode* prev = NULL;
        ListNode* curr = leftnode;
        ListNode* forward = NULL;
        while (curr !=rightend) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL || left == right) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* leftnode = head;
        int i = 1;
        while (i != left) {
            prev = leftnode;
            leftnode = leftnode->next;
            if (leftnode == NULL) {
                return head;
            }
            i++;
        }

        ListNode* rightnode = head;
        i = 1;
        while (i != right) {
            rightnode = rightnode->next;
            if (rightnode == NULL) {
                return head;
            }
            i++;
        }


        ListNode* rightend = rightnode->next;

        if (prev == NULL) {
            head = rev(leftnode, rightend);
        } else {
            prev->next = rev(leftnode, rightend);
        }

        leftnode->next = rightend;

        return head;
    }
};