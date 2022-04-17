// 202101544 ������
// stack calculator

// ������� �ۼ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int type�� element��� �̸����� ���
typedef int element;

// stack ����� ���� node ����ü����
typedef struct StackNode {
	element data;
	double fdata;
	// �ڱ���������ü ����
	struct StackNode* link;
} StackNode;

// node�� linked list�ν��� ����� ���� linkedstacktype ����ü����
typedef struct {
	StackNode* top;
} LinkedStackType;

/*
	�Լ��� : init
	�� �� : LinkedStackType pointer
	������ : void
	�� �� : Stack�� top�� null�� �Ҵ��Ͽ�, LinkedStackType�� �ʱ�ȭ �Ѵ�.
*/
void init(LinkedStackType* s) {
	s->top = NULL;
}


/*
	�Լ��� : isEmpty
	�� �� : LinkedStackType pointer
	������ : element(int)
	�� �� : stack�� ����ִ��� Ȯ���ϴ� �Լ��ν�, top���� NULL���� �񱳽��� return �Ѵ�.
*/
element isEmpty(LinkedStackType* s) {
	return (s->top == NULL);
}

/*
	�Լ��� : pop
	�� �� : LinkedStackType pointer
	������ : element(int)
	�� �� : stack�� top�� ��ġ�ϰ� �ִ� ���� return�ϰ�, stack�� ���� ���� ��� error �޽����� ����Ѵ�.
*/
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

/*
	�Լ��� : fpop
	�� �� : LinkedStackType pointer
	������ : double
	�� �� : �Ǽ����� ������ ���� ������� �Լ���, type�� ������ ������ ������ pop�Լ��� �����ϴ�.
*/
double fpop(LinkedStackType* s) {
	if (isEmpty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		double fdata = temp->fdata;
		s->top = s->top->link;
		free(temp);
		return fdata;
	}
}

/*
	�Լ��� : push
	�� �� : 1) LinkedStackType pointer 2) item(element)
	������ : void
	�� �� : stack�� ���� �����ϱ� ���� ��ȵ� �Լ��ν�, StackNode pointer type�� temp�� �޸��Ҵ��� �޾�, node�� data�� �����ϰ�, stack�� top�� node�� �ּҸ� �Ҵ��Ų��.
*/
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

/*
	�Լ��� : fpush
	�� �� : 1) LinkedStackType pointer 2) item(double)
	������ : void
	�� �� : double�� data�� �����ϱ� ���� ��ȵ� �Լ��ν�, push�� ������ �������� �����Ѵ�.
*/
void fpush(LinkedStackType* s, double item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->fdata = item;
	temp->link = s->top;
	s->top = temp;
}

/*
	�Լ��� : peek
	�� �� : LinkedStackType pointer
	������ : element(int)
	�� �� : stack�� top�� ��ġ�� data�� return�ϴ� �Լ��ν�, stack�� ���������, NULL�� return �Ѵ�.
*/
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

/*
	�Լ��� : fpeek
	�� �� : LinkedStackType
	������ : double
	�� �� : stack�� top�� ��ġ�� fdata�� return�ϴ� �Լ��ν�, stack�� ���������, NULL�� return �Ѵ�.
*/
double fpeek(LinkedStackType* s) {
	if (isEmpty(s)) {
		// stack�� ����ִ� ��� NULL return
		return 0;
	}
	else {
		// stack�� top�� ��ġ�� data return
		return s->top->fdata;
	}
}

/*
	�Լ��� : isFull
	�� �� : LinkedStackType pointer
	������ : int
	�� �� : stack�� ����á���� ���θ� return �Ѵ�, ������, �̷л� full���´� �߻����� �����Ƿ�, 0�� ��ȯ
*/
int isFull(LinkedStackType* s) {
	// linkedlist���� �̷л����� full���´� �߻����� ���� (�ٸ� �޸𸮿����� ħ���ϴ� ��� ����)
	return 0;
}

/*
	�Լ��� : bracketCheck
	�� �� : char pointer ch
	������ : int
	�� �� : �־��� ���ڿ����� ��ȣ�˻縦 �����Ͽ� ������ ������ 1 return, �����߻��� 0 return
*/
int bracketCheck(char* ch) {
	// stack ����
	LinkedStackType s;
	// stack �ʱ�ȭ
	init(&s);
	// ���ڿ� ��ȸ�� ���� index ����
	int i = 0;
	// �־��� ���ڿ��� ��ȸ�ϸ� ��ȣ�˻縦 �����Ѵ�
	// ���ڿ��� ���������� NULL�̹Ƿ�, NULL�� �ƴ� �̻� ��ȸ�� �����Ѵ�.
	while (ch[i] != NULL) {
		// ch ���ڿ��� �� ���� Ȱ���Ͽ� �б⺰�� �Ǵ��ϱ� ���� switch���� ���
		switch (ch[i])
		{
		// ���� ��ȣ�� ���, ��ȣ�� �״�� stack�� push�Ѵ�.
		case '(': case '[': case '{':
			push(&s, ch[i]);
			break;
		// �ݴ� ��ȣ�� ���, �߰����� ������ ����Ͽ� �˻縦 �����Ѵ�.
		case ')': case ']': case '}':
			// �ݴ� ��ȣ�� ������ �� stack�� ����ִ� ���, �̴� �ݴ� ��ȣ �Ѱ��� ���� ��Ȳ�̹Ƿ� ������ 0�� return �Ѵ�.
			if (isEmpty(&s)) {
				return 0;
			}
			// stack�� ���� �����ϴ� ��� �� ���� pop�Ͽ� �˻縦 �����Ѵ�.
			else {
				// pop�� �� data������ �Ҵ�
				element data = pop(&s);
				// switch���� ����Ͽ�, stack�� ���� �Ǵ�
				switch (data)
				{
				// ������ ¦�� ��ȣ�� �ƴ� ��� ������ 0�� return
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
			// ������ ��ȣ�� ��� ������ �Ҵ���� break
			break;
		default:
			// �����Է� ����, ASCII TABLE���� �����Է¿� �ش��ϴ� 65~90, 97~122 ������ ���� �Էµ� ���, ��������
			if ((ch[i]>=65 && ch[i] <= 90) || (ch[i]>=97 && ch[i]<=122)) {
				printf("�Ŀ� ���ڿ��� ���ԵǾ� �ֽ��ϴ�!\n");
				exit(1);
			}
			break;
		}
		// index�� ������Ű�� ch���ڿ��� ��ȸ�Ѵ�.
		i++;
	}
	// ��ȣ �˻� ��, stack�� �����ִ� data�� ���� ��� ������ 1�� return
	if (isEmpty(&s)) {
		return 1;
	}
	// ��ȣ �˻� ��, stack�� ���� �����ִ� ���, ��ȣ�� ¦�� �����ʴ� ���̹Ƿ� ������ 0�� return
	else {
		return 0;
	}
}

/*
	�Լ��� : prec
	�� �� : char op
	������ : int
	�� �� : �������� �켱������ ��ȯ�ϱ� ���� �Լ�
*/
int prec(char op) {
	switch (op) {
	// ��ȣ�� ���, 0�� �켱������ ��ȯ
	case '(': case ')': return 0;
	// +-�� ���, 1�� �켱������ ��ȯ
	case '+': case '-': return 1;
	// */�� ���, 2�� �켱������ ��ȯ
	case '*': case '/': return 2;
	}
	// �̿� �������� ��� -1�� �켱������ ��ȯ
	return -1;
}

/*
	�Լ��� : infix_to_postfix
	�� �� : char pointer ch
	������ : char pointer
	�� �� : ������ ���ڿ��� �Է¹޾Ƽ� ������ ���ڿ��� return �ϴ� �Լ�
*/
char* infix_to_postfix(char* ch) {
	// ������ ���ڿ��� ������ char pointer�� ������
	char* str = (char*)malloc(sizeof(char) * 100);
	// strcpy�� Ȱ���Ͽ� str �ʱ�ȭ
	strcpy(str, "");
	// �������� ������ ��ȯ�� ���� stack����
	LinkedStackType* s;
	// stack �ʱ�ȭ
	init(&s);
	// ������ ���� ���� element(int) type ���� ����
	element e;
	// ������ ���ڿ��� ��ȸ�� ���� index ���� ����
	int i = 0;
	// ���۰��� ��ȣ�ΰ��, ��ȣ�����߻����� �Ǵ�, -1 return
	if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/') {
		strcpy(str, "��ȣ�����߻�");
		return -1;
	}
	// ������ ���ڿ��� ��ȸ�ϴµ�, ���ڿ��� ������ ���ڰ� NULL�̹Ƿ�, ���� NULL�� �ƴѵ��� ��ȸ�� �Ѵ�.
	while (ch[i] != NULL) {
		// index�� ���� ������ ���ڿ��� ���� switch���� Ȱ���Ͽ� �Ǵ�
		switch (ch[i])
		{
		// ch[i]�� �������� ���
		case '+': case '-': case '/': case '*':
			// ������ ���Ŀ� �����ڰ� ���ų� �ݴ°�ȣ�� ���� ���, ��ȣ�����߻����� �Ǵ�, -1 return
			if (ch[i + 1] == '+' || ch[i + 1] == '-' || ch[i + 1] == '/' || ch[i + 1] == '*'
				|| ch[i + 1] == ')' || ch[i + 1] == '}' || ch[i + 1] == ']') {
				strcpy(str, "��ȣ�����߻�");
				return -1;
			}
			// stack�� ����ִ��� ���θ� Ȯ���ϰ�, �������� �켱������ prec�Լ��� ���� ���Ͽ� peek�� ���� Ȯ���� stack�� top�� �����ϴ� �������� �켱������ ū ���, stack�� �����ϴ� �����ڸ� pop�Ͽ�, �����Ĺ��ڿ��� �߰��Ѵ�.
			while (!isEmpty(&s) && (prec(ch[i]) <= prec(peek(&s)))) {
				// stack�� top�� ��ġ�� data pop
				e = pop(&s);
				// ������ ���ڿ��� �߰�
				strncat(str, &e, 1);
				// ���� ������ ���� ���鵵 �߰�
				strcat(str, " ");
			}
			// ch[i]�� stack���� push
			push(&s, ch[i]);
			break;
		// ���� ��ȣ�� ���, stack���� push
		case '(': case '[': case '{':
			// ���� ��ȣ �ٷ� �ڿ� �����ڰ� ���� ��� ��ȣ�����߻����� �Ǵ�, -1 return
			if (ch[i + 1] == '+' || ch[i + 1] == '-' || ch[i + 1] == '*' || ch[i + 1] == '/') {
				strcpy(str, "��ȣ�����߻�");
				return -1;
			}
			push(&s, ch[i]);
			break;
		// �ݴ� ��ȣ�� ���, stack���� ���� ���� ��ȣ�� ���ö����� pop�� �ݺ��Ѵ�.
		case ')': case ']': case '}':
			e = pop(&s);
			// ���� ��ȣ�� �ƴѵ��ȿ��� pop�� ���� ��� �����Ĺ��ڿ��� �ٿ��ִ´�.
			while (e != '(' && e != '[' && e != '{') {
				strncat(str, &e, 1);
				strcat(str, " ");
				e = pop(&s);
			}
			break;
		// �����ڿ� ��ȣ�� �ƴѰ���� ���� default������ ���� ó���Ѵ�.
		default:
			if (ch[i+1] >= '0' && ch[i+1] <= '9') {
				strncat(str, &ch[i], 1);
				while (ch[i + 1] != NULL && ch[i + 1] >= 48 && ch[i + 1] <= 57) {
					i++;
					strncat(str, &ch[i], 1);
				}
				if (ch[i + 1] != NULL && ch[i + 1] == '.') {

				}
				else {
					// ���� �߰�
					strcat(str, " ");
				}
			}
			// ���� data�� �ڿ� �Ҽ����� ���縦 �ǹ��ϴ� '.'�� �ִ� ���, 
			else if (ch[i + 1] == '.') {
				// data�� ������ ���ڿ��� �߰�
				strncat(str, &ch[i], 1);
				// index�� '.' ��ġ�� ����
				i++;
				// '.'�� ������ ���ڿ��� �߰�
				strncat(str, &ch[i], 1);
				// data�� ���� ���� NULL �Ǵ� ���� �̿��� ���� �ƴ� �̻�, �ڿ� ���� ��� ���� �Ҽ��� �Ʒ��ڸ���� �����ϰ� ���ڿ��� �߰�
				while (ch[i+1] != NULL && ch[i+1] >= 48 && ch[i+1] <= 57) {	
					// index ����
					i++;
					// ���ڿ��� ch[i] �� �߰�
					strncat(str, &ch[i], 1);
				}
				// ���� �߰�
				strcat(str, " ");
			}
			else {
				// �Ϲ����� ������ ���, ���ڿ��� �߰�
				strncat(str, &ch[i], 1);
				// ���� �߰�
				strcat(str, " ");
			}
			
			break;
		}
		// index ����
		i++;
	}
	// ���������� ��ȣ�ΰ��, ��ȣ�����߻����� �Ǵ�, -1 return
	if (ch[i-1] == '+' || ch[i-1] == '-' || ch[i-1] == '*' || ch[i-1] == '/') {
		strcpy(str, "��ȣ�����߻�");
		return -1;
	}
	// stack�� ���� �����ִ� ���, ������ ���� �� ��ȯ�Ͽ� ���ڿ��� �߰�
	while (!isEmpty(&s)) {
		e = pop(&s);
		// stack���� pop�� �� stack�� data�� �����ִ� ��� ���� �߰�
		if (!isEmpty(&s)) {
			strncat(str, &e, 1);
			strcat(str, " ");
		}
		// stack�� ���� ���� ��쿡�� ���⸦ �߰����� �ʴ´�.
		else {
			strncat(str, &e, 1);
		}
		
	}
	// ������ ���ڿ� ��ȯ
	return str;
}

/*
	�Լ��� : infix_to_prefix
	�� �� : char pointer ch
	������ : char pointer
	�� �� : ������ ���ڿ��� ������ ���ڿ��� �ٲ��ִ� �Լ�
*/
char* infix_to_prefix(char* ch) {
	// ���ڿ��� ���������� ���� stack ����
	LinkedStackType* s;
	// �����ڸ� �����ϱ� ���� stack ����
	LinkedStackType* op;
	// data�� �����ϱ� ���� stack ����
	LinkedStackType* dt;
	// stack �ʱ�ȭ
	init(&s);
	init(&op);
	init(&dt);
	// ������ ���ڿ��� �����ϱ� ���� char pointer ����
	char* pre_str = (char*)malloc(sizeof(char) * 100);
	// ������ ���ڿ� �ʱ�ȭ
	strcpy(pre_str, "");
	// data�� �����ڸ� �ٷ�� ���� ���� ����
	element data, oper;
	// index ��������
	int i = 0;
	// ���۰��� ��ȣ�ΰ��, ��ȣ�����߻����� �Ǵ�, -1 return
	if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/') {
		strcpy(pre_str, "��ȣ�����߻�");
		return -1;
	}
	// ������ ���ڿ��� ���� �������� ������ ���� ���� ��ȸ, ���ڿ��� �������� NULL�� ���� ������ ��ȸ�Ѵ�.
	while (ch[i] != NULL) {
		if ((ch[i] >= '0' && ch[i] <= '9') || ch[i] == '.') {
			// ���ڸ��� �̻��� ������ ��� ó��
			if (ch[i + 1] >= '0' && ch[i + 1] <= '9') {
				push(&s, ch[i]);
				i++;
				push(&s, ch[i]);
				while (ch[i + 1] != NULL && ch[i + 1] >= '0' && ch[i + 1] <= '9') {
					i++;
					push(&s, ch[i]);
				}
				if (ch[i+1] != NULL && ch[i+1] == '.') {

				}
				else {
					push(&s, NULL);
				}
			}
			// data�� �������� �Ҽ����� ��Ÿ���� '.'�� ���, ������ ó���� �Ѵ�
			else if (ch[i + 1] == '.') {
				// ���� data�� stack�� push
				push(&s, ch[i]);
				// index�� '.'��ġ�� ����
				i++;
				// '.'�� push
				push(&s, ch[i]);
				// data�� �������� NULL�� �ƴϸ鼭 ������ ���, �� push
				while (ch[i + 1] != NULL && ch[i + 1] >= 48 && ch[i + 1] <= 57) {
					// index ����
					i++;
					// data push
					push(&s, ch[i]);
				}
				// �� 1���� data ������ ������, NULL �� push�Ͽ� ����
				push(&s, NULL);
			}
			else {
				// data�� '.'�� �ƴѰ��, data push
				push(&s, ch[i]);
			}
		}
		else {
			// data�� '.'�� �ƴѰ��, data push
			push(&s, ch[i]);
		}
		// index ����
		i++;
	}
	// ���������� ��ȣ�ΰ��, ��ȣ�����߻����� �Ǵ�, -1 return
	if (ch[i-1] == '+' || ch[i-1] == '-' || ch[i-1] == '*' || ch[i-1] == '/') {
		strcpy(pre_str, "��ȣ�����߻�");
		return -1;
	}
	// stack�� �������� �ݺ�
	while (!isEmpty(&s)) {
		// s stack�� top���� data pop
		data = pop(&s);
		// data�� ������ switch�� Ȱ���Ͽ� ������������ ��ȯ
		switch (data)
		{
		// ������/��ȣ�ΰ��
		case '+': case '-': case '/': case '*':
			// ������ ���Ŀ� �����ڰ� ���ų� ���°�ȣ�� ���� ���, ��ȣ�����߻����� �Ǵ�, -1 return
			if (peek(&s) == '+' || peek(&s) == '-' || peek(&s) == '/' || peek(&s) == '*'
				|| peek(&s) == '(' || peek(&s) == '{' || peek(&s) == '[') {
				strcpy(pre_str, "��ȣ�����߻�");
				return -1;
			}
			// ������ ������ �ֻ��� ���� �켱���� ��
			while (!isEmpty(&op) && (prec(data) <= prec(peek(&op)))) {
				// ������ stack�� top�� ��ġ�� data�� �켱������ ū ��� stack���� data pop
				oper = pop(&op);
				// ������ stack���� ������ push
				push(&dt, oper);
			}
			// data�� ������ stack���� push
			push(&op, data);
			break;
		case ')': case ']': case '}':
			// �ݴ� ��ȣ ���Ŀ� �����ڰ� ���� ���, ��ȣ�����߻����� �Ǵ�, -1 return
			if (peek(&s) == '+' || peek(&s) == '-' || peek(&s) == '*' || peek(&s) == '/') {
				strcpy(pre_str, "��ȣ�����߻�");
				return -1;
			}
			// �ݴ� ��ȣ�� ���, ������ stack�� data push
			push(&op, data);
			break;
		case '(': case '[': case '{':
			
			// ���� ��ȣ�� ���, ������ stack���� data pop
			oper = pop(&op);
			// ������ data�� ������ stack�� push
			push(&dt, oper);
			// �ݴ� ��ȣ�� ���ö����� ������ stack���� �� pop�Ͽ� ������ stack�� �� push
			while (oper != ')' && oper != ']' && oper != '}') {
				oper = pop(&op);
				push(&dt, oper);
			}
			break;
		// �����ڿ� ��ȣ�� ������ ���, ������ stack�� �� push
		default:
			push(&dt, data);
			break;
		}
	}
	// ������ stack�� ���� ��� pop�Ͽ� ������ stack�� push
	while (!isEmpty(&op)) {
		oper = pop(&op);
		push(&dt, oper);
	}
	// ������ stack�� �������� �ݺ�
	while (!isEmpty(&dt)) {
		// ������ stack�� top�� �� pop
		data = pop(&dt); 
		// ��ȣ�� ��� ����
		if (data != '(' && data != '[' && data != '{' && data != ')' && data != ']' && data != '}') {
			if (data != '+' && data != '-' && data != '*' && data != '/' && peek(&dt) >= '0' && peek(&dt) <= '9') {
				strncat(pre_str, &data, 1);
				while (!isEmpty(&dt) && peek(&dt) >= 48 && peek(&dt) <= 57) {
					data = pop(&dt);
					strncat(pre_str, &data, 1);
				}
				if (!isEmpty(&dt) && peek(&dt) == '.') {

				}
				else {
					strcat(pre_str, " ");
				}
			}
			// ������ stack�� top���� �Ҽ����� ���
			else if (peek(&dt) == '.') {
				// �����Ŀ� data �߰�
				strncat(pre_str, &data, 1);
				// '.' pop���� data�� �Ҵ�
				data = pop(&dt);
				// �����Ŀ� �Ҽ��� �߰�
				strncat(pre_str, &data, 1);
				// ���� ������ peek���� ������ ���, space���� pre_str�� �߰�
				while (!isEmpty(&dt) && peek(&dt) >= '0' && peek(&dt) <= '9') {
					data = pop(&dt);
					strncat(pre_str, &data, 1);
				}
				strcat(pre_str, " ");
			}
			else {
				// ������ stack�� top���� �Ҽ����� �ƴ� ���
				strncat(pre_str, &data, 1);
				strcat(pre_str, " ");
			}
		}
	}
	// ������ ���ڿ� return
	return pre_str;
}

/*
	�Լ��� : postfix_calculate
	�� �� : char pointer ch
	������ : double
	�� �� : ������ �������� return �ϱ� ���� �Լ�
*/
double postfix_calculate(char* ch) {
	// ������ ������ ���� stack ����
	LinkedStackType* s;
	// stack �ʱ�ȭ
	init(&s);
	// �ǿ����ڸ� �����ϱ� ���� ���� op1, op2, ������� �����ϱ� ���� value ����
	double op1, op2, value;
	// ���ڿ� ��ȸ�� ���� index ����
	int i = 0;
	// �Ҽ��� ó���� ���� decimal ����
	int decimal;
	// �Ҽ����� �����ϱ� ���� d_value ����
	double d_value;
	// ���ڿ� ��ü�� ��ȸ
	while (ch[i] != NULL) {
		// �׸��� �ǿ������� ���
		if (ch[i] != '+' && ch[i] != '-' && ch[i] != '*' && ch[i] != '/' && ch[i] != ' ') {
			// value�� �� �Ҵ�
			value = (ch[i] - '0');
			if (ch[i + 1] >= '0' && ch[i+1] <= '9') {
				while (ch[i + 1] != NULL && ch[i + 1] >= '0' && ch[i] <= '9') {
					i++;
					// �ڸ��� ����
					value *= 10;
					value += (ch[i] - '0');
					
				}
				if (ch[i + 1] != NULL && ch[i + 1] == '.') {
					// i�� �������Ѽ� '.'���� index �̵�
					i++;
					// �Ҽ��� ó���� ���� decimal ����
					decimal = 1;
					// �Ҽ����� �����ϱ� ���� d_value ����
					d_value = 0;
					// data�� NULL�� �ƴϸ鼭, ���� ���� ��� �Ҽ����� �Ʒ��ڸ��� ó��
					while (ch[i + 1] != NULL && ch[i + 1] >= '0' && ch[i + 1] <= '9') {
						// index ����
						i++;
						// d_value�� char��-'0'�� �Ͽ� char���� ���ڷ� �� ��ȯ
						d_value = ch[i] - '0';
						// decimal�� ������ŭ �Ҽ��� �ڸ��̵��� ���� for����
						for (int j = 1; j <= decimal; j++) {
							// ������ �ѹ� ��ȸ�Ҷ����� d_value�� ���� 10^(-1)�谡 �ȴ�.
							d_value *= 0.1;
						}
						// value�� �Ҽ��������� �� d_value�� ������
						value += d_value;
						// decimal ����
						decimal++;
					}
					// ������ ���� stack�� �� fpush
					fpush(&s, value);
				}
				else {
					fpush(&s, value);
				}
			}
			else if (ch[i + 1] == '.') {
				// i�� �������Ѽ� '.'���� index �̵�
				i++;
				// �Ҽ��� ó���� ���� decimal ����
				decimal = 1;
				// �Ҽ����� �����ϱ� ���� d_value ����
				d_value = 0;
				// data�� NULL�� �ƴϸ鼭, ���� ���� ��� �Ҽ����� �Ʒ��ڸ��� ó��
				while (ch[i+1] != NULL && ch[i+1] >= '0' && ch[i+1] <= '9') {
					// index ����
					i++;
					// d_value�� char��-'0'�� �Ͽ� char���� ���ڷ� �� ��ȯ
					d_value = ch[i] - '0';
					// decimal�� ������ŭ �Ҽ��� �ڸ��̵��� ���� for����
					for (int j = 1; j <= decimal; j++) {
						// ������ �ѹ� ��ȸ�Ҷ����� d_value�� ���� 10^(-1)�谡 �ȴ�.
						d_value *= 0.1;
					}
					// value�� �Ҽ��������� �� d_value�� ������
					value += d_value;
					// decimal ����
					decimal++;
				}
				// ������ ���� stack�� �� fpush
				fpush(&s, value);
			}
			else {
				// �Ҽ����� �ƴ� ��� �ٷ� �� fpush
				fpush(&s, value);
			}
			
		}
		// ������ ���� �����ϱ� �����̹Ƿ�, ������ �������� ����
		else if (ch[i] == ' ') {

		}
		// �׸��� ������
		else {
			// stack�� ���� ��ġ�� ���� ������ �ǿ����ڷ� ���
			op2 = fpop(&s);
			// ������ �ǿ������� �Ʒ� ��ġ�� ���� ���� �ǿ����ڷ� ���
			op1 = fpop(&s);
			// ������ Ȯ��
			switch (ch[i])
			{
			// �����ڿ� �´� ���������Ͽ� stack�� fpush�Ͽ� �� ����
			case '+': fpush(&s, op1 + op2); break;
			case '-': fpush(&s, op1 - op2); break;
			case '*': fpush(&s, op1 * op2); break;
			case '/': fpush(&s, op1 / op2); break;
			}
		}
		// index ����
		i++;
	}
	// fpop�� ����� return
	return fpop(&s);
}

/*
	�Լ��� : main
	�� �� : void
	������ : int
	�� �� : main �Լ�, ����� ���ʷ� ����Ǵ� �Լ�
*/
int main(void) {
	// ���� �Է¹ޱ� ���� char pointer ch ����
	char *ch = (char *)malloc(sizeof(char)*100);
	// ����ڷκ��� �������� �Է¹���
	printf("�������� �Է��ϼ���: ");
	scanf("%s", ch);

	// 1. �˻�
	// ��ȣ �˻� �� return�� 0�̸� �������� ��� �� �ڿ���ȯ�� �Ѵ�.
	if (bracketCheck(ch)) {
	}
	else {
		fprintf(stderr, "��ȣ�� ��������\n");
		exit(1);
	}

	// 2. ��ȯ
	// ������->������
	// �������̶� �ݴ밳��
	printf("������: ");
	if (infix_to_prefix(ch) == -1) {
		printf("��ȣ�����߻�\n");
	}
	else {
		printf("%s\n", infix_to_prefix(ch));
	}
	

	// ������->������
	printf("������: ");
	if (infix_to_postfix(ch) == -1) {
		printf("��ȣ�����߻�\n");
	}
	else {
		printf("%s\n", infix_to_postfix(ch));
	}
	
	// 3. ���
	// ������ ���
	printf("�����: ");
	if (infix_to_postfix(ch) == -1) {
		printf("��ȣ�����߻�\n");
	}
	else {
		printf("%lf\n", postfix_calculate(infix_to_postfix(ch)));
	}

	return 0;

}
