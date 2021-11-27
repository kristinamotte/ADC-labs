#include <stdlib.h>
#include <stdio.h>

typedef struct treeNode {
	struct treeNode * left;
	int key;
	struct treeNode * right;
} tree;

typedef struct stackNode {
   tree* element;
   struct stackNode* next;
} stack ;


tree* addNode(tree*, int);
tree * createTreeNode(int);
void freeTree(tree**);

void preorder(tree*); 
void inorder(tree*); 
void postorder(tree*);
void levelorder(tree*);
int height(tree*);
void printCurrentLevel(tree*, int);
void scanFromFile(int[], int);
int countDeepstNodes(tree*);

stack* push(tree*, stack*);
void pop(stack**);

int main(int argc, char const *argv[]) {
	tree * root = NULL;
    int size = 20;
    int numbers[size];

    scanFromFile(numbers, size);

    for(int i = 0; i < size; i++) {
        root = addNode(root, numbers[i]);
    }

	printf("======= PREORDER ========\n");
	preorder(root); 
	printf("=========================\n");
	printf("======= INORDER =========\n");
	inorder(root); 
	printf("=========================\n");
	printf("======= POSTORDER =======\n");
	postorder(root); 
	printf("=========================\n");
    printf("======= LEVELORDER =======\n");
	levelorder(root); 
	printf("=========================\n");

    printf("\n=========================");
    printf("\nNUMBER OF NODES FROM THE LAST LEVEL WHERE KEY %% 2 == 0: \n%d nodes\n", countDeepstNodes(root));
    printf("=========================\n\n");
	
	freeTree(&root);
	
	printf("======= PREORDER ========\n");
	preorder(root); 
	printf("=========================\n");
	printf("======= INORDER =========\n");
	inorder(root); 
	printf("=========================\n");
	printf("======= POSTORDER =======\n");
	postorder(root); 
	printf("=========================\n");
    printf("======= LEVELORDER =======\n");
	levelorder(root); 
	printf("=========================\n");
	return 0;
}

tree* addNode(tree* root, int key) {
	if (root == NULL) {
		root = createTreeNode(key);
	} else {
		if (key < root->key) {
			root->left = addNode(root->left, key);
		} else {
			root->right = addNode(root->right, key);
		}
	}
	return root;
}

tree * createTreeNode(int key) {
	tree * newTreeNode = (tree*) malloc (sizeof(tree));
	if (newTreeNode == NULL) {
		printf("out of memory :(\n");
		exit(1);
	}
	newTreeNode->key = key;
	newTreeNode->left = NULL;
	newTreeNode->right = NULL;
	return newTreeNode;
}

void preorder(tree* root) { 
	if (root != NULL) {
		printf("%d\n", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(tree* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d\n", root->key);
		inorder(root->right);
	}
}

void postorder(tree* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->key);
	}
}

void levelorder(tree* root) {
    int h = height(root);

    for (int i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int height(tree* root) {
    if (root == NULL)
        return 0;
    else {
        int lheight = height(root->left);
        int rheight = height(root->right);
 
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printCurrentLevel(tree* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d\n", root->key);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void freeTree(tree** root) {
	if (*root != NULL) {
		freeTree(&((*root)->left));
		freeTree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}

void scanFromFile(int array[], int size) {
    FILE *ifp;
    ifp = fopen("Var19.txt", "r");

    for (int i = 0; i < size; i++) {
        fscanf(ifp, "%d", &array[i]);
    }

    fclose(ifp);
}

stack* push(tree* root, stack* top) {
    stack* node = (stack*)malloc(sizeof(stack));

    if(node == NULL) {
        printf("Memory Overflow\n");
		exit(0); //Terminate program execution
    }

    node->element = root;
	node->next = top;

    return node;
}

void pop(stack** top) {
	if (*top != NULL) {
		stack* remove = *top;
        *top = remove->next;
		remove->element = NULL;
		remove->next = NULL;

		free(remove);
		remove = NULL;
	}
}

int countDeepstNodes(tree* root) {
    if(root == NULL) {
        printf("Empty\n");
        return 0;
    }

    stack* top = NULL, *head = NULL;
	tree* temp = root;
    int count = 0;

    while (top != NULL || temp != NULL) {
		if (temp != NULL) {
			if (temp->left == NULL && temp->right == NULL && temp->key % 2 == 0) {
                count += 1;
			}
			top = push(temp, top);	
			temp = temp->left;
		} else {
			temp = top->element;

			pop(&top);
			temp = temp->right;
		}
	}

    return count;
}
