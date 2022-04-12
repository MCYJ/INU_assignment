// 202101544 ������
// stack calculator

/*
	������ �Է�
	1
	��ȣ ����
	�� ����
	2
	�������� ����������
	�������� ����������
	3
	�������� ���

	* �Ҽ���ó��
*/

#include <stdio.h>
#include <stdlib.h>


typedef char element;

// �ڱ���������ü ����
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

// init �ʱ�ȭ �Լ�
void init(LinkedStackType* s) {
	s->top = NULL;
}

// isEmpty
int isEmpty(LinkedStackType* s) {
	return (s->top == NULL);
}

// pop
element pop(LinkedStackType* s) {
	if (isEmpty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

// push
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

// peek
element peek(LinkedStackType* s) {
	if (isEmpty(s)) {
		// stack�� ����ִ� ��� NULL return
		return NULL;
	}
	else {
		// stack�� top�� ��ġ�� data return
		return s->top->data;
	}
}

// isFull
int isFull(LinkedStackType* s) {
	// linkedlist���� �̷л����� full���´� �߻����� ���� (�ٸ� �޸𸮿����� ħ���ϴ� ��� ����)
	return 0;
}

// ��ȣ�˻��Լ�
int bracketCheck(char* ch) {
	LinkedStackType s;
	init(&s);

	int i = 0;
	while (ch[i] != NULL) {
		//	printf("%d %c\n", i, ch[i]);
		switch (ch[i])
		{
		case '(': case '[': case '{':
			push(&s, ch[i]);
			break;
		case ')': case ']': case '}':
			if (isEmpty(&s)) {
				return 0;
			}
			else {
				element data = pop(&s);
				switch (data)
				{
				case '(':
					if (ch[i] != ')') {
						return 0;
					}
					break;
				case '[':
					if (ch[i] != ']') {
						return 0;
					}
					break;
				case '{':
					if (ch[i] != '}') {
						return 0;
					}
				}
			}
			break;
		}
		i++;
	}
	if (isEmpty(&s)) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void) {
	char *ch = (char *)malloc(sizeof(char)*100);

	
	printf("�������� �Է��ϼ���: ");
	scanf("%s", ch);
	
	

	// ��ȣ �˻�
	if (bracketCheck(ch)) {
		printf("��ȣ�� ��������\n");
	}
	else {
		fprintf(stderr, "��ȣ�� ��������\n");
		exit(1);
	}

	// ������->������
	// ch4 37page
	
	// ������->������
	// �������̶� �ݴ밳��

	// ������ ���
	// ch4 31page

	// *** 1. ��ȣ�˻�/���ڿ��˻� 2. �Ҽ���ó��

	return 0;
}