
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

static int nodecount;

struct Node_LL
{
	int data;
	struct Node_LL* next;
}*linkedlist[5];

struct Node_LL *linkedlist1 = NULL, *linkedlist2 = NULL;

struct Node_Tree
{
	int data;
	struct Node_Tree* left;
	struct Node_Tree* right;
	//static int nodecount;
};

//int Node_Tree::nodecount = 0;

struct Node_Tree* Insert(struct Node_Tree*, int);
struct Node_Tree* GetNewNode(int);
void InOrderArray(struct Node_Tree*, int*, int*);
int* merge(int arr1[], int arr2[], int, int);
void InOrderLinkedList(struct Node_Tree*, int);
void displayLinkedList(struct Node_LL*);
void linkedListInsert0(int);
void linkedListInsert1(int);
void linkedListInsert2(int);
void linkedListInsert3(int);
void linkedListInsert4(int);
struct Node_LL* linkedListInsert(struct Node_LL*, int);
struct Node_LL* MergerLinkedList(struct Node_LL*, struct Node_LL*);


int  main()
{
	// create Binary Search Tree
	struct Node_Tree* root1 = NULL; // pointer to root node. Setting Tree as Empty.
	root1 = Insert(root1, 8);
	root1 = Insert(root1, 2);
	root1 = Insert(root1, 1);
	root1 = Insert(root1, 10);

	int nodecount1 = nodecount;
	printf(" nodecount1 = %d", nodecount1);


	struct Node_Tree* root2 = NULL; // pointer to root node. Setting Tree as Empty.
	root2 = Insert(root2, 15);
	root2 = Insert(root2, 13);
	root2 = Insert(root2, 6);
	root2 = Insert(root2, 0);
	root2 = Insert(root2, 4);
	root2 = Insert(root2, 7);
	root2 = Insert(root2, 9);

	int nodecount2 = nodecount - nodecount1;
	printf(" nodecount2 = %d", nodecount2);

	struct Node_Tree* root3 = NULL; // pointer to root node. Setting Tree as Empty.
	root3 = Insert(root3, 5);
	root3 = Insert(root3, 3);
	root3 = Insert(root3, 16);
	root3 = Insert(root3, 18);
	root3 = Insert(root3, 14);

	int nodecount3 = nodecount - (nodecount1 + nodecount2);
	printf(" nodecount3 = %d", nodecount3);

	int* arr1 = (int*)malloc(nodecount1 * sizeof(int));
	int* arr2 = (int*)malloc(nodecount2 * sizeof(int));
	int* arr3 = (int*)malloc(nodecount3 * sizeof(int));
	int* arr;
	int index1 = 0, index2 = 0, index3 = 0;

	for (int i = 0; i < 5; i++)
	{
		linkedlist[i] = NULL;
	}

	// memset(arr1, 0, 10*sizeof(int));
	// memset(arr2, 0, 10*sizeof(int));

	InOrderArray(root1, arr1, &index1);
	InOrderArray(root2, arr2, &index2);
	InOrderArray(root3, arr3, &index3);

	printf("\n\nArray1 : ");
	for (int i = 0; i < nodecount1; i++)
		printf("%d ", *(arr1 + i));

	printf("\nArray2 : ");
	for (int i = 0; i < nodecount2; i++)
		printf("%d ", *(arr2 + i));

	printf("\nArray3 : ");
	for (int i = 0; i < nodecount3; i++)
		printf("%d ", *(arr3 + i));


	printf("\n\nMerged Array (1+2) : \n ");
	arr = merge(arr1, arr2, nodecount1, nodecount2);
	for (int i = 0; i < (nodecount1 + nodecount2); i++)
		printf("%d ", *(arr + i));

	printf("\nMerged Array (1+2+3): \n ");
	arr = merge(arr, arr3, nodecount1 + nodecount2, nodecount3);
	for (int i = 0; i < (nodecount1 + nodecount2 + nodecount3); i++)
		printf("%d ", *(arr + i));

	printf("\n\nLinked List 1 : \n ");
	InOrderLinkedList(root1, 0);
	displayLinkedList(linkedlist[0]);

	printf("\nLinked List 2 : \n ");
	InOrderLinkedList(root2, 1);
	displayLinkedList(linkedlist[1]);

	printf("\nLinked List 3 : \n ");
	InOrderLinkedList(root3, 2);
	displayLinkedList(linkedlist[2]);


	linkedlist[3] = MergerLinkedList(linkedlist[0], linkedlist[1]);
	printf("\n\nLinked List 1  <merge> Linked List 2 : \n ");
	displayLinkedList(linkedlist[3]);

	linkedlist[4] = MergerLinkedList(linkedlist[2], linkedlist[3]);
	printf("\n\nLinked List 1  <merge> Linked List 2 <merge> Linked List 3 : \n ");
	displayLinkedList(linkedlist[4]);

	_getch();
}


struct Node_Tree* GetNewNode(int value)
{
	struct Node_Tree* newnode = (struct Node_Tree*)malloc(sizeof(struct Node_Tree));
	newnode->data = value;
	newnode->left = newnode->right = NULL;
	nodecount++;
	return newnode;
};

struct Node_Tree* Insert(struct Node_Tree *root, int value)
{
	if (root == NULL) // empty tree
		root = GetNewNode(value);

	else if (value <= root->data)
		root->left = Insert(root->left, value);

	else
		root->right = Insert(root->right, value);

	return root;
}

void InOrderArray(struct Node_Tree* t_root, int* i_arr, int *index)
{
	if (t_root == NULL)
		return;
	else
	{
		InOrderArray(t_root->left, i_arr, index);
		i_arr[*index] = t_root->data;
		(*index)++;
		InOrderArray(t_root->right, i_arr, index);
	}
}

int* merge(int arr1[], int arr2[], int m, int n)	// A utility unction to merge two sorted arrays into one 
{
	int *mergedArr = (int *)malloc((m + n) * sizeof(int));
	int i = 0, j = 0, k = 0;

	// Traverse through both arrays 
	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])		// Pick the smaler element and put it in mergedArr 
		{
			mergedArr[k] = arr1[i];
			i++;
		}
		else
		{
			mergedArr[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i < m)		// If there are more elements in first array 
	{
		mergedArr[k] = arr1[i];
		i++; k++;
	}

	while (j < n)		// If there are more elements in second array 
	{
		mergedArr[k] = arr2[j];
		j++; k++;
	}

	return mergedArr;
}

void InOrderLinkedList(struct Node_Tree *t_root, int choice)
{
	if (t_root == NULL)
		return;
	else
	{
		InOrderLinkedList(t_root->left, choice);
		switch (choice)
		{
		case 0:
			linkedListInsert0(t_root->data);
			break;
		case 1:
			linkedListInsert1(t_root->data);
			break;
		case 2:
			linkedListInsert2(t_root->data);
			break;
		case 3:
			linkedListInsert3(t_root->data);
			break;
		case 4:
			linkedListInsert4(t_root->data);
			break;
		default:
			break;
		}

		InOrderLinkedList(t_root->right, choice);
	}
}

void displayLinkedList(struct Node_LL *node)
{
	while (node != NULL)
	{
		printf("%d  ", node->data);
		node = node->next;
	}
}

void linkedListInsert0(int value)
{
	linkedlist[0] = linkedListInsert(linkedlist[0], value);
}

void linkedListInsert1(int value)
{
	linkedlist[1] = linkedListInsert(linkedlist[1], value);
}

void linkedListInsert2(int value)
{
	linkedlist[2] = linkedListInsert(linkedlist[2], value);
}

void linkedListInsert3(int value)
{
	linkedlist[3] = linkedListInsert(linkedlist[3], value);
}

void linkedListInsert4(int value)
{
	linkedlist[4] = linkedListInsert(linkedlist[4], value);
}

struct Node_LL* linkedListInsert(struct Node_LL *node, int value)
{
	if (node == NULL)
	{
		node = (struct Node_LL*)malloc(sizeof(struct Node_LL));
		node->data = value;
		node->next = NULL;
	}
	else
	{
		struct Node_LL* temp = node;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = (struct Node_LL*)malloc(sizeof(struct Node_LL));
		temp->next->data = value;
		temp->next->next = NULL;
	}

	return node;
}

struct Node_LL* MergerLinkedList(struct Node_LL *ll_one, struct Node_LL *ll_two)
{
	struct Node_LL *tempList = NULL;
	if ((ll_one == NULL) && (ll_two == NULL))
		return NULL;
	else
	{
		if (ll_one == NULL)
			return ll_two;
		if (ll_two == NULL)
			return ll_one;
		else
		{

			while (ll_one != NULL && ll_two != NULL)
			{
				if (ll_one->data < ll_two->data)
				{
					tempList = linkedListInsert(tempList, ll_one->data);
					ll_one = ll_one->next;
				}
				else
				{
					tempList = linkedListInsert(tempList, ll_two->data);
					ll_two = ll_two->next;
				}
			}

			while (ll_one != NULL)
			{
				tempList = linkedListInsert(tempList, ll_one->data);
				ll_one = ll_one->next;
			}
			while (ll_two != NULL)
			{
				tempList = linkedListInsert(tempList, ll_two->data);
				ll_two = ll_two->next;
			}

		}
	}
	return tempList;
}
