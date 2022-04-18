/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* �ʿ��� ������� �߰� */

typedef struct Node {
	int key; //node�� data field
	struct Node* link; //node�� link field
} listNode; //node ����ü listNode ����

typedef struct Head {
	struct Node* first; //Node ����ü�� ����Ű�� ������ first
}headNode; //Head ����ü headNode ����


/* �Լ� ����Ʈ */
headNode* initialize(headNode* h); //headNode�� �ʱ�ȭ�ϴ� �Լ�
int freeList(headNode* h); //headNode�� ����� ��� ��带 free��Ű�� �Լ�

int insertFirst(headNode* h, int key); //key���� ���� ��带 list�� ó���� �����ϴ� �Լ�
int insertNode(headNode* h, int key); //key�� ���� ū ��� �տ� ��带 �����ϴ� �Լ�
int insertLast(headNode* h, int key); //key���� ���� ��带 list�� �������� �����ϴ� �Լ�

int deleteFirst(headNode* h); //list�� ù ��° ��带 �����ϴ� �Լ�
int deleteNode(headNode* h, int key); //key���� ������ �ִ� ��带 �����ϴ� �Լ�
int deleteLast(headNode* h); //list�� ������ ��带 �����ϴ� �Լ�
int invertList(headNode* h); //list�� ������ �������� �ٲٴ� �Լ�

void printList(headNode* h); //list�� ��� ��带 ������� ����ϴ� �Լ�

int main()
{
	char command; //command�� �Է¹��� ����
	int key; //key���� �Է¹��� ����
	headNode* headnode=NULL; //headNode ����ü�� ����Ű�� headnode ���� �� �ʱ�ȭ(NULL)
	
	printf("[----- ������ 2020039027 -----]\n\n");//�̸� �й� ���

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");
		//��ɾ� �޴� ���
		printf("Command = ");
		scanf(" %c", &command); //command �Է�

		switch(command) {
		case 'z': case 'Z': //command�� z �϶�
			headnode = initialize(headnode);
			//initialize �Լ��� headnode�� �ִ� ���� �ʱ�ȭ �ϰ�
			//�޸𸮸� �Ҵ� �޴´�.
			break;
		case 'p': case 'P': //command�� p �϶�
			printList(headnode);
			//printlist �Լ��� headnode�� ����Ǿ��ִ� ��� ��带 ����Ѵ�. 
			break;
		case 'i': case 'I': //command�� i �϶�
			printf("Your Key = ");
			scanf("%d", &key); //key���� �Է¹޴´�.
			insertNode(headnode, key);
			//insertNode �Լ��� key������ ū node�� �տ� 
			//key���� ���� ��带 �����Ѵ�.
			break;
		case 'd': case 'D': //command�� d �϶�
			printf("Your Key = ");
			scanf("%d", &key); //key���� �Է¹޴´�.
			deleteNode(headnode, key);
			//deleteNode �Լ��� key���� ���� ��带 �����Ѵ�.
			break;
		case 'n': case 'N': //command�� n �϶�
			printf("Your Key = ");
			scanf("%d", &key); //key���� �Է¹޴´�.
			insertLast(headnode, key);
			//insertLast �Լ��� list�� �������� key���� ���� ��带 �����Ѵ�.
			break;
		case 'e': case 'E': //command�� e �϶�
			deleteLast(headnode);
			//deleteLast �Լ��� list�� �������� �ִ� ��带 �����Ѵ�.
			break;
		case 'f': case 'F': //command�� f �϶�
			printf("Your Key = ");
			scanf("%d", &key); //key���� �Է¹޴´�.
			insertFirst(headnode, key);
			//insertFirst �Լ��� list�� ó���� key���� ���� ��带 �����Ѵ�.
			break; 
		case 't': case 'T': //command�� t �϶�
			deleteFirst(headnode); 
			//deleteFirst �Լ��� list�� ù ��° ��带 �����Ѵ�.
			break;
		case 'r': case 'R': //command�� r �϶�
			invertList(headnode);
			//invertList �Լ��� list�� ������ ������ �ݴ�� �ٲ۴�.
			break;
		case 'q': case 'Q': //command�� q �϶�
			freeList(headnode);
			//freeList �Լ��� list�� ��� ���鿡 �Ҵ�� �޸𸮸� free��Ų��.
			break;
		default: //���� ��찡 ��� �ƴ� ��
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');
	//command�� q �Ǵ� Q�� �� ������ �ݺ�

	return 1;
}

headNode* initialize(headNode* h) {
	//�Ű������� headNode�� ����Ű�� ������(�ּ�)�� �޴´�.
	/* headNode�� NULL�� �ƴϸ�, freelist�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
	if(h != NULL)
		freeList(h);

	/* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp; //�ּҸ� �Ҵ� ���� �����͸� ����
}

int freeList(headNode* h){
	/* h�� ����� listNode �޸� ����
	 * headNode�� �����Ǿ�� ��.
	 */
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) { //list�� ó������ ������ �ݺ�
		prev = p; //������ �ּ� ���� �Ҵ�
		p = p->link; //���� ����� �ּ� ���� �Ҵ�
		free(prev); //������ �ּҿ� �Ҵ�� �޸𸮸� free ��Ų��.
	}
	free(h); //headNode* h�� �Ҵ�� �޸𸮸� free ��Ų��.
	return 0;
}


/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	node->link = NULL;
	//key���� �Ҵ�ް�, link ���� NULL�� ��带 �����Ѵ�.

	if (h->first == NULL) //first���� NULL�� ��
	{
		h->first = node; //first�� �Է¹��� ��带 �Ҵ�
		return 0;
	}

	listNode* n = h->first;
	listNode* trail = h->first;

	/* key�� �������� ������ ��ġ�� ã�´� */
	while(n != NULL) {
		if(n->key >= key) {
			/* ù ��� ���ʿ� �����ؾ��� ��� ���� �˻� */
			if(n == h->first) {
				h->first = node;
				node->link = n;
			} else { /* �߰��̰ų� �������� ��� */
				node->link = n;
				trail->link = node;
			}
			return 0;
		}

		trail = n;
		n = n->link;
	}

	/* ������ ������ ã�� ���� ��� , �������� ���� */
	trail->link = node;
	return 0;
}

/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) {
	//�Ű������� list�� ù ��° ��� �ּҿ� key���� �޴´�.

	listNode* node = (listNode*)malloc(sizeof(listNode));
	//��� ����
	node->key = key;
	//key�� �Ҵ�
	node->link = NULL;
	//link���� NULL�Ҵ�
	if (h->first == NULL)
	{
		h->first = node;
		return 0;
	}

	listNode* n = h->first;
	while(n->link != NULL) {
		n = n->link;
	}
	n->link = node;
	return 0;
}

/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	//node ����
	node->key = key;
	//key�� �Ҵ�
	node->link = h->first;
	//�ش� ��带 ù ��° ���� �Ѵ�.
	h->first = node;

	return 0;
}

/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {

	if (h->first == NULL) //��尡 ���� ��
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first; //ù ��° ����� �ּ� �Ҵ�
	listNode* trail = NULL; //NULL�Ҵ�(���� ����� �ּҸ� �Ҵ���� ������)

	/* key�� �������� ������ ��ġ�� ã�´� */
	while(n != NULL) {
		if(n->key == key) {
			/* ù ��� ���ʿ� �����ؾ��� ��� ���� �˻� */
			if(n == h->first) {
				h->first = n->link;
			} else { /* �߰��� ���ų� �������� ��� */
				trail->link = n->link;
			}
			free(n);
			return 0;
		}

		trail = n; //������ ��� �ּ� �Ҵ�
		n = n->link; //���� ��� �ּ� �Ҵ�
	}

	/* ã�� �� �Ѱ�� */
	printf("cannot find the node for key = %d\n", key);
	return 0;

}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {

	if (h->first == NULL) //��尡 ���� ��
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first; //ù ��° ����� �ּ� �Ҵ�
	listNode* trail = NULL; //NULL �Ҵ�(������ ��� �ּҸ� �Ҵ��� ������)

	/* ��尡 �ϳ��� �ִ� ���, �� first node == last node��  ��� ó�� */
	if(n->link == NULL) {
		h->first = NULL;
		free(n);
		return 0;
	}

	/* ������ ������ �̵� */
	while(n->link != NULL) {
		trail = n;
		n = n->link;
	}

	/* n�� �����ǹǷ�, ���� ����� ��ũ NULL ó�� */
	trail->link = NULL;
	free(n);

	return 0;
}
/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {

	if (h->first == NULL) //��尡 ���� ��
	{
		printf("nothing to delete.\n");
		return 0;
	}
	listNode* n = h->first; //ù ��° ����� �ּ� �Ҵ�

	h->first = n->link; //ù ��° ����� �ּҿ� ���� ����� �ּ� �Ҵ�
	free(n); //ù ��° ��忡 �Ҵ�� �޸� free

	return 0;
}


/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode* h) {


	if(h->first == NULL) { //��尡 ���� ��
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->first;
	listNode *trail = NULL;
	listNode *middle = NULL;

	while(n != NULL){
		trail = middle; //���� ����� �ּ� �Ҵ�
		middle = n; //���� ����� �ּ� �Ҵ�
		n = n->link; //���� ����� �ּ� �Ҵ�
		middle->link = trail; //�������� �ּҸ� �Ҵ�
	}

	h->first = middle; //������ �ּҸ� �Ҵ�

	return 0;
}


void printList(headNode* h) {
	int i = 0; //�� ��° ������� �˷��� ���� ���� �� �ʱ�ȭ(0)
	listNode* p; //��带 ����� �� �� ������ ���� ����

	printf("\n---PRINT\n");

	if(h == NULL) {
		//h�� NULL�̸� ��尡 �����Ƿ� ��� X
		printf("Nothing to print....\n");
		return;
	}

	p = h->first; //ù ��° ����� �ּ� �Ҵ�

	while(p != NULL) { //p�� NULL�� �� ������ �ݺ�
		printf("[ [%d]=%d ] ", i, p->key); //key�� ���
		p = p->link; //���� ����� �ּ� �Ҵ�
		i++;
	}

	printf("  items = %d\n", i);
}

