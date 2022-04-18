/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key; //node의 data field
	struct Node* link; //node의 link field
} listNode; //node 구조체 listNode 선언

typedef struct Head {
	struct Node* first; //Node 구조체를 가리키는 포인터 first
}headNode; //Head 구조체 headNode 선언


/* 함수 리스트 */
headNode* initialize(headNode* h); //headNode를 초기화하는 함수
int freeList(headNode* h); //headNode에 연결된 모든 노드를 free시키는 함수

int insertFirst(headNode* h, int key); //key값을 가진 노드를 list의 처음에 삽입하는 함수
int insertNode(headNode* h, int key); //key값 보다 큰 노드 앞에 노드를 삽입하는 함수
int insertLast(headNode* h, int key); //key값을 가진 노드를 list의 마지막에 삽입하는 함수

int deleteFirst(headNode* h); //list의 첫 번째 노드를 삭제하는 함수
int deleteNode(headNode* h, int key); //key값을 가지고 있는 노드를 삭제하는 함수
int deleteLast(headNode* h); //list의 마지막 노드를 삭제하는 함수
int invertList(headNode* h); //list의 노드들을 역순으로 바꾸는 함수

void printList(headNode* h); //list의 모든 노드를 순서대로 출력하는 함수

int main()
{
	char command; //command를 입력받을 변수
	int key; //key값을 입력받을 변수
	headNode* headnode=NULL; //headNode 구조체를 가리키는 headnode 선언 및 초기화(NULL)
	
	printf("[----- 김주훈 2020039027 -----]\n\n");//이름 학번 출력

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
		//명령어 메뉴 출력
		printf("Command = ");
		scanf(" %c", &command); //command 입력

		switch(command) {
		case 'z': case 'Z': //command가 z 일때
			headnode = initialize(headnode);
			//initialize 함수로 headnode에 있는 값을 초기화 하고
			//메모리를 할당 받는다.
			break;
		case 'p': case 'P': //command가 p 일때
			printList(headnode);
			//printlist 함수로 headnode에 연결되어있는 모든 노드를 출력한다. 
			break;
		case 'i': case 'I': //command가 i 일때
			printf("Your Key = ");
			scanf("%d", &key); //key값을 입력받는다.
			insertNode(headnode, key);
			//insertNode 함수로 key값보다 큰 node의 앞에 
			//key값을 가진 노드를 삽입한다.
			break;
		case 'd': case 'D': //command가 d 일때
			printf("Your Key = ");
			scanf("%d", &key); //key값을 입력받는다.
			deleteNode(headnode, key);
			//deleteNode 함수로 key값과 같은 노드를 삭제한다.
			break;
		case 'n': case 'N': //command가 n 일때
			printf("Your Key = ");
			scanf("%d", &key); //key값을 입력받는다.
			insertLast(headnode, key);
			//insertLast 함수로 list의 마지막에 key값을 가진 노드를 삽입한다.
			break;
		case 'e': case 'E': //command가 e 일때
			deleteLast(headnode);
			//deleteLast 함수로 list의 마지막에 있는 노드를 삭제한다.
			break;
		case 'f': case 'F': //command가 f 일때
			printf("Your Key = ");
			scanf("%d", &key); //key값을 입력받는다.
			insertFirst(headnode, key);
			//insertFirst 함수로 list의 처음에 key값을 가진 노드를 삽입한다.
			break; 
		case 't': case 'T': //command가 t 일때
			deleteFirst(headnode); 
			//deleteFirst 함수로 list의 첫 번째 노드를 삭제한다.
			break;
		case 'r': case 'R': //command가 r 일때
			invertList(headnode);
			//invertList 함수로 list의 노드들의 순서를 반대로 바꾼다.
			break;
		case 'q': case 'Q': //command가 q 일때
			freeList(headnode);
			//freeList 함수로 list의 모든 노드들에 할당된 메모리를 free시킨다.
			break;
		default: //위의 경우가 모두 아닐 때
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');
	//command가 q 또는 Q가 될 때까지 반복

	return 1;
}

headNode* initialize(headNode* h) {
	//매개변수로 headNode를 가리키는 포인터(주소)를 받는다.
	/* headNode가 NULL이 아니면, freelist를 호출하여 할당된 메모리 모두 해제 */
	if(h != NULL)
		freeList(h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp; //주소를 할당 받은 포인터를 리턴
}

int freeList(headNode* h){
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) { //list의 처음부터 끝까지 반복
		prev = p; //현재의 주소 값을 할당
		p = p->link; //다음 노드의 주소 값을 할당
		free(prev); //현재의 주소에 할당된 메모리를 free 시킨다.
	}
	free(h); //headNode* h에 할당된 메모리를 free 시킨다.
	return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	node->link = NULL;
	//key값을 할당받고, link 값이 NULL인 노드를 생성한다.

	if (h->first == NULL) //first값이 NULL일 때
	{
		h->first = node; //first에 입력받은 노드를 할당
		return 0;
	}

	listNode* n = h->first;
	listNode* trail = h->first;

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL) {
		if(n->key >= key) {
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->first) {
				h->first = node;
				node->link = n;
			} else { /* 중간이거나 마지막인 경우 */
				node->link = n;
				trail->link = node;
			}
			return 0;
		}

		trail = n;
		n = n->link;
	}

	/* 마지막 노드까지 찾지 못한 경우 , 마지막에 삽입 */
	trail->link = node;
	return 0;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {
	//매개변수로 list의 첫 번째 노드 주소와 key값을 받는다.

	listNode* node = (listNode*)malloc(sizeof(listNode));
	//노드 생성
	node->key = key;
	//key값 할당
	node->link = NULL;
	//link값에 NULL할당
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
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	//node 생성
	node->key = key;
	//key값 할당
	node->link = h->first;
	//해당 노드를 첫 번째 노드로 한다.
	h->first = node;

	return 0;
}

/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {

	if (h->first == NULL) //노드가 없을 때
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first; //첫 번째 노드의 주소 할당
	listNode* trail = NULL; //NULL할당(이전 노드의 주소를 할당받을 포인터)

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL) {
		if(n->key == key) {
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->first) {
				h->first = n->link;
			} else { /* 중간인 경우거나 마지막인 경우 */
				trail->link = n->link;
			}
			free(n);
			return 0;
		}

		trail = n; //이전의 노드 주소 할당
		n = n->link; //다음 노드 주소 할당
	}

	/* 찾지 못 한경우 */
	printf("cannot find the node for key = %d\n", key);
	return 0;

}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {

	if (h->first == NULL) //노드가 없을 때
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first; //첫 번째 노드의 주소 할당
	listNode* trail = NULL; //NULL 할당(이전의 노드 주소를 할당할 포인터)

	/* 노드가 하나만 있는 경우, 즉 first node == last node인  경우 처리 */
	if(n->link == NULL) {
		h->first = NULL;
		free(n);
		return 0;
	}

	/* 마지막 노드까지 이동 */
	while(n->link != NULL) {
		trail = n;
		n = n->link;
	}

	/* n이 삭제되므로, 이전 노드의 링크 NULL 처리 */
	trail->link = NULL;
	free(n);

	return 0;
}
/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {

	if (h->first == NULL) //노드가 없을 때
	{
		printf("nothing to delete.\n");
		return 0;
	}
	listNode* n = h->first; //첫 번째 노드의 주소 할당

	h->first = n->link; //첫 번째 노드의 주소에 다음 노드의 주소 할당
	free(n); //첫 번째 노드에 할당된 메모리 free

	return 0;
}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {


	if(h->first == NULL) { //노드가 없을 때
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->first;
	listNode *trail = NULL;
	listNode *middle = NULL;

	while(n != NULL){
		trail = middle; //이전 노드의 주소 할당
		middle = n; //현재 노드의 주소 할당
		n = n->link; //다음 노드의 주소 할당
		middle->link = trail; //역순으로 주소를 할당
	}

	h->first = middle; //마지막 주소를 할당

	return 0;
}


void printList(headNode* h) {
	int i = 0; //몇 번째 노드인지 알려줄 변수 선언 및 초기화(0)
	listNode* p; //노드를 출력할 때 쓸 포인터 변수 선언

	printf("\n---PRINT\n");

	if(h == NULL) {
		//h가 NULL이면 노드가 없으므로 출력 X
		printf("Nothing to print....\n");
		return;
	}

	p = h->first; //첫 번째 노드의 주소 할당

	while(p != NULL) { //p가 NULL이 될 때까지 반복
		printf("[ [%d]=%d ] ", i, p->key); //key값 출력
		p = p->link; //다음 노드의 주소 할당
		i++;
	}

	printf("  items = %d\n", i);
}

