// #include <stdio.h>
// #include <stdlib.h>
// struct Node {
//     int data;
//     struct Node* left;
//     struct Node* right;
// };
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }
// struct Node* insert(struct Node* root, int data) {
//     if (root == NULL) {
//         return createNode(data);
//     }
//     if (data < root->data) {
//         root->left = insert(root->left, data);
//     } else if (data > root->data) {
//         root->right = insert(root->right, data);
//     }
//     return root;
// }
// struct Node* deleteNode(struct Node* root, int data) {
//     if (root == NULL) return root;
//     if (data < root->data) {
//         root->left = deleteNode(root->left, data);
//     } else if (data > root->data) {
//         root->right = deleteNode(root->right, data);
//     } else {
//         if (root->left == NULL) {
//             struct Node* temp = root->right;
//             free(root);
//             return temp;
//         } else if (root->right == NULL) {
//             struct Node* temp = root->left;
//             free(root);
//             return temp;
//         }
//         struct Node* successorParent = root;
//         struct Node* successor = root->right;

//         while (successor->left != NULL) {
//             successorParent = successor;
//             successor = successor->left;
//         }
//         root->data = successor->data;

//         if (successorParent != root) {
//             successorParent->left = deleteNode(successorParent->left, successor->data);
//         } else {
//             successorParent->right = deleteNode(successorParent->right, successor->data);
//         }
//     }
//     return root;
// }
// void inorder(struct Node* root) {
//     if (root != NULL) {
//         inorder(root->left);
//         printf("%d ", root->data);
//         inorder(root->right);
//     }
// }

// int main() {
//     struct Node* root = NULL;
//     int choice, value;
//     while (1) {
//         printf("\n1. Insert nodes");
//         printf("\n2. Delete a node");
//         printf("\n3. Display tree (Inorder)");
//         printf("\n4. Exit");
//         printf("\nEnter your choice: ");
//         scanf("%d", &choice);
//         switch (choice) {
//             case 1: {
//                 int n;
//                 printf("Enter the number of nodes to insert: ");
//                 scanf("%d", &n);              
//                 for (int i = 0; i < n; i++) {
//                     printf("Enter value %d: ", i + 1);
//                     scanf("%d", &value);
//                     root = insert(root, value);
//                 }
//                 break;
//             }
//             case 2:
//                 printf("Enter the value to delete: ");
//                 scanf("%d", &value);
//                 root = deleteNode(root, value);
//                 break;
//             case 3:
//                 printf("Inorder traversal of tree: ");
//                 inorder(root);
//                 printf("\n");
//                 break;
//             case 4:
//                 exit(0);
//             default:
//                 printf("Invalid choice!\n");
//         }
//     }
//     return 0;
// }
// c prgm to delete a node in binary search tree



#include <stdio.h>
#include <stdlib.h>
struct BinaryTreeNode {
  int key;
  struct BinaryTreeNode *left, *right;
};
struct BinaryTreeNode* newNodeCreate(int value)
{
  struct BinaryTreeNode* temp = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
  temp->key = value;
  temp->left = temp->right = NULL;
  return temp;
}
struct BinaryTreeNode* searchNode(struct BinaryTreeNode* root, int target)
{
  if (root == NULL || root->key == target) {
    return root;
  }
  if (root->key < target) {
    return searchNode(root->right, target);
  }
  return searchNode(root->left, target);
}
struct BinaryTreeNode* insertNode(struct BinaryTreeNode* node, int value)
{
  if (node == NULL) {
    return newNodeCreate(value);
  }
  if (value < node->key) {
    node->left = insertNode(node->left, value);
  }
  else if (value > node->key) {
    node->right = insertNode(node->right, value);
  }
  return node;
}
void postOrder(struct BinaryTreeNode* root)
{
  if (root != NULL) {
    postOrder(root->left);
    postOrder(root->right);
    printf(" %d ", root->key);
  }
}
void inOrder(struct BinaryTreeNode* root)
{
  if (root != NULL) {
    inOrder(root->left);
    printf(" %d ", root->key);
    inOrder(root->right);
  }
}
void preOrder(struct BinaryTreeNode* root)
{
  if (root != NULL) {
    printf(" %d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
  }
}
int main()
{
  struct BinaryTreeNode* root = NULL;
  int choice, value;
  while (1) {
        printf("\n1. Insert Node");
  printf("\n2. Search Node");
  printf("\n3. In-Order Traversal");
  printf("\n4. Pre-Order Traversal");
  printf("\n5. Post-Order Traversal");
  printf("\n6. Exit");
  printf("\nEnter your choice: ");
  scanf("%d", &choice);
  switch (choice) {
  case 1:
    int n; 
          printf("Enter the no of nodes to insert: "); 
    scanf("%d", &n);  
    for (int i = 0; i < n; i++) 
          { 
            printf("Enter value %d: ", i + 1); 
      scanf("%d", &value); 
      root = insertNode(root, value); 
          }
                        
  case 2:
    printf("Enter value to search: ");
          scanf("%d", &value);
    if (searchNode(root, value) != NULL) 
    {
      printf("%d found in the tree.\n", value);
    }
    else 
    {
      printf("%d not found in the tree.\n", value);
    }
    break;
  case 3:
    printf("In-Order Traversal: ");
    inOrder(root);
    printf("\n");
    break;
  case 4:
    printf("Pre-Order Traversal: ");
    preOrder(root);
    printf("\n");
    break;
  case 5:
    printf("Post-Order Traversal: ");
    postOrder(root);
    printf("\n");
    break;
  case 6:
    exit(0);
  default:
    printf("Invalid choice!\n");
  }
  }
  return 0;
}