void createDLLfromTree(TreeNode* root, TreeNode*& head) {
    if (root == nullptr) {
        return;
    }

    createDLLfromTree(root->right, head);

    root->right = head;

    if (head != nullptr) {
        head->left = root;
    }
    head = root;

    createDLLfromTree(root->left, head);
}

TreeNode* mergeTwoLLs(TreeNode* head1, TreeNode* head2) {
    if (!head1) {
        return head2;
    }
    if (!head2) {
        return head1;
    }
    TreeNode* head = nullptr;
    TreeNode* tail = nullptr;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            if (!head) {
                head = head1;
                tail = head1;
            }
            else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
            }
            head1 = head1->right;
        }
        else {
            if (!head) {
                head = head2;
                tail = head2;
            }
            else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
            }
            head2 = head2->right;
        }
    }
    while (head1) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

vector<int> mergeBST(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) {
        return {};
    }

    TreeNode* head1 = nullptr;
    createDLLfromTree(root1, head1);

    TreeNode* head2 = nullptr;
    createDLLfromTree(root2, head2);

    TreeNode* head = mergeTwoLLs(head1, head2);

    vector<int> arr;
    TreeNode* temp = head;
    while (temp) {
        arr.push_back(temp->data);
        temp = temp->right;
    }

    return arr;
}