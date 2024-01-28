#include <iostream>

using namespace std;

// RBLNode structure for Red-Black Tree
struct RBLNode {
    int SensorNodeID; // Mimicking the Sensory Node Position given to us as Implementation
    char color;        // 'R' for red, 'B' for black
    RBLNode* left;     // The connection to left node
    RBLNode* right;    // The connection to right node
    RBLNode* parent;   // The parent node of the node (NULL/NIL for Root Node)
};

// Denotes head usually called "SENTINEL" Node
RBLNode* NILL;

// List of Function definitions so that there is no compromise in the order of the Function call

// INSERT Node Functions
void insert(RBLNode** root, int SensorNodeID);
void insertFixup(RBLNode** root, RBLNode* z);

// ROTATION of given Node Functions
void leftRotate(RBLNode** root, RBLNode* x);
void rightRotate(RBLNode** root, RBLNode* y);

// Minimum Element Node in Right Sub Tree of x Function
RBLNode* treeMinimum(RBLNode* x);

// DELETE Functions
void deleteRBLNode(RBLNode** root, int SensorNodeID);
void deleteFixup(RBLNode** root, RBLNode* x);
void transplant(RBLNode** root, RBLNode* u, RBLNode* v);

// SEARCH Function
RBLNode* search(RBLNode* root, int SensorNodeID);

// IN ORDER TRAVERSAL Function
void inorderPrint(RBLNode* root);

int main() {

    // Initialize Black "SENTINEL" Root Node
    NILL = new RBLNode();
    NILL->color = 'B';  // Root RBLNode is always black
    NILL->left = NILL->right = NILL->parent = nullptr;

    // Initialize root
    RBLNode* root = NILL;

    // Insert RBLNodes
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 15);

    // Print the RBL Tree Structure
    cout << "Inorder Traversal: ";
    inorderPrint(root);
    cout << endl;

    // Search for a RBLNode
    int searchSensorNodeID = 20;
    RBLNode* searchResult = search(root, searchSensorNodeID);
    if (searchResult != NILL) {
        cout << "RBLNode with SensorNodeID " << searchSensorNodeID << " found in the tree." << endl;
    } else {
        cout << "RBLNode with SensorNodeID " << searchSensorNodeID << " not found in the tree." << endl;
    }

    // Delete a RBLNode
    int deleteSensorNodeID = 20;
    deleteRBLNode(&root, deleteSensorNodeID);
    cout << "After deleting RBLNode with SensorNodeID " << deleteSensorNodeID << ":" << endl;

    // Printing to validate Deletion
    inorderPrint(root);
    cout << endl;

    delete NILL;

    return 0;
}

// Searching the given element node
RBLNode* search(RBLNode* root, int SensorNodeID) {
    if (root == nullptr || root == NILL) {
        return nullptr;
    }
    if (root->SensorNodeID == SensorNodeID) {
        return root;
    } else if (root->SensorNodeID < SensorNodeID) {
        return search(root->right, SensorNodeID);
    } else {
        return search(root->left, SensorNodeID);
    }
}

// IN ORDER TRAVERSAL
// Prints the nodes in the form of LNR (Left, Node, Right)
// Also prints the color of the tree
void inorderPrint(RBLNode* root) {
    if (root != nullptr && root != NILL) {
        inorderPrint(root->left);
        cout << root->SensorNodeID << "(" << root->color << ") ";
        inorderPrint(root->right);
    }
}

// Finds the Minimum most Node in the left subtree
RBLNode* treeMinimum(RBLNode* x) {
    while (x->left != nullptr && x->left != NILL) {
        x = x->left;
    }
    return x;
}

// Insertion Function Body
void insert(RBLNode** root, int SensorNodeID) {
    // Inserting node is Z
    RBLNode* z = new RBLNode();
    z->SensorNodeID = SensorNodeID;
    z->left = z->right = z->parent = NILL;
    // Color it Red
    z->color = 'R';

    RBLNode* y = NILL;
    // Dummy node
    RBLNode* x = *root;

    while (x != NILL) {
        y = x;
        if (z->SensorNodeID < x->SensorNodeID) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;

    if (y == NILL) {
        *root = z;
    } else if (z->SensorNodeID < y->SensorNodeID) {
        y->left = z;
    } else {
        y->right = z;
    }

    insertFixup(root, z);
}

// Makes Fixups In edge cases where order is disturbed
// Makes Fixups In edge cases where order is disturbed after insertion
void insertFixup(RBLNode** root, RBLNode* z) {
    while (z->parent->color == 'R') {
        // When Z's parent is left child
        if (z->parent == z->parent->parent->left) {
            // Y node denotes Z's Uncle
            RBLNode* y = z->parent->parent->right;

            // Case 2
            // Node Z has a red uncle
            if (y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            }

            // Case 3
            // Node Z has a black uncle and forms a triangle hence needs rotations 
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                rightRotate(root, z->parent->parent);
            }
        }
        // When Z's parent is the right child
        else {
            RBLNode* y = z->parent->parent->left;
            if (y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                leftRotate(root, z->parent->parent);
            }
        }
    }
    // CASE 1
    // Z is colored Black since it is treated as a root
    (*root)->color = 'B';
}

// Rotations Function Body
// Rotations do not affect the order of the Binary Search Tree Representation
// Instead helps in self-balancing the Red-Black Hierarchy
void leftRotate(RBLNode** root, RBLNode* x) {
    RBLNode* y = x->right;
    x->right = y->left;

    if (y->left != NILL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NILL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void rightRotate(RBLNode** root, RBLNode* y) {
    RBLNode* x = y->left;
    y->left = x->right;

    if (x->right != NILL) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == NILL) {
        *root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

// Deletion of Node Function Body
void deleteRBLNode(RBLNode** root, int SensorNodeID) {
    RBLNode* z = search(*root, SensorNodeID);
    if (z == NILL) {
        return;
    }

    RBLNode* y = z;
    char yOriginalColor = y->color;
    RBLNode* x;

    // Case 1
    // Z has ONLY RIGHT CHILD
    if (z->left == NILL) {
        x = z->right;
        transplant(root, z, z->right);
    }
    // Case 2
    // Z has ONLY LEFT CHILD
    else if (z->right == NILL) {
        x = z->left;
        transplant(root, z, z->left);
    }
    // Case 3
    // Z has both LEFT & RIGHT CHILD
    else {
        y = treeMinimum(z->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    // Delete Fixup is called only if the OG color of the Labeled element is BLACK 
    if (yOriginalColor == 'B') {
        deleteFixup(root, x);
    }

    delete z;
}

// Helps in Handling edge cases of Deletion where the order of the RBL tree isn't maintained
void deleteFixup(RBLNode** root, RBLNode* x) {
    while (x != *root && x->color == 'B') {
        if (x == x->parent->left) {
            // W is X's Sibling
            RBLNode* w = x->parent->right;

            // Case 1
            // W is Red
            if (w->color == 'R') {
                w->color = 'B';
                x->parent->color = 'R';
                leftRotate(root, x->parent);
                w = x->parent->right;
            }
            // Case 2
            // W.Left is Black and W.right is Black too
            if (w->left->color == 'B' && w->right->color == 'B') {
                w->color = 'R';
                x = x->parent;
            } else {
                // Case 3
                // W is Black, W.left is red and W.right is Black
                if (w->right->color == 'B') {
                    w->left->color = 'B';
                    w->color = 'R';
                    rightRotate(root, w);
                    w = x->parent->right;
                }
                // Case 4
                // W is Black, W.right is Red
                // Case 3 involves Case 4
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->right->color = 'B';
                leftRotate(root, x->parent);
                x = *root;
            }
        } else {
            RBLNode* w = x->parent->left;
            if (w->color == 'R') {
                w->color = 'B';
                x->parent->color = 'R';
                rightRotate(root, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == 'B' && w->left->color == 'B') {
                w->color = 'R';
                x = x->parent;
            } else {
                if (w->left->color == 'B') {
                    w->right->color = 'B';
                    w->color = 'R';
                    leftRotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->left->color = 'B';
                rightRotate(root, x->parent);
                x = *root;
            }
        }
    }
    // Color it black again
    x->color = 'B';
}

// Transplant that is used for changing the color of the nodes passed in case of DELETION
void transplant(RBLNode** root, RBLNode* u, RBLNode* v) {
    // Case 1
    // U is the root / sentinel node
    if (u->parent == NILL) {
        *root = v;
    }
    // Case 2
    // U is the left child of its parent
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    // Case 3
    // U is the right child of its parent
    else {
        u->parent->right = v;
    }
    // should be done for all
    v->parent = u->parent;
}

