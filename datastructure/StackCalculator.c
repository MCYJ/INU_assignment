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
#include <string.h>

// int type�� element��� �̸����� ���
typedef int element;

// �ڱ���������ü ����
// stack ����� ���� node ����ü����
typedef struct StackNode {
	element data;
	double fdata;
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
	// ������ ���ڿ��� ��ȸ�ϴµ�, ���ڿ��� ������ ���ڰ� NULL�̹Ƿ�, ���� NULL�� �ƴѵ��� ��ȸ�� �Ѵ�.
	while (ch[i] != NULL) {
		// index�� ���� ������ ���ڿ��� ���� switch���� Ȱ���Ͽ� �Ǵ�
		switch (ch[i])
		{
		// ch[i]�� �������� ���
		case '+': case '-': case '/': case '*':
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
			// ���� data�� �ڿ� �Ҽ����� ���縦 �ǹ��ϴ� '.'�� �ִ� ���, 
			if (ch[i + 1] == '.') {
				strncat(str, &ch[i], 1);
				i++;
				strncat(str, &ch[i], 1);
				while (ch[i+1] != NULL && ch[i+1] >= 48 && ch[i+1] <= 57) {	
					i++;
					strncat(str, &ch[i], 1);
				}
				strcat(str, " ");
			}
			else {
				strncat(str, &ch[i], 1);
				strcat(str, " ");
			}
			
			break;
		}
		i++;
	}
	while (!isEmpty(&s)) {
		e = pop(&s);
	//	printf("%c", e);
		if (!isEmpty(&s)) {
			strncat(str, &e, 1);
			strcat(str, " ");
		}
		else {
			strncat(str, &e, 1);
		}
		
	}
	return str;
}

char* infix_to_prefix(char* ch) {
	LinkedStackType* s;
	LinkedStackType* op;
	LinkedStackType* dt;

	init(&s);
	init(&op);
	init(&dt);
	char* pre_str = (char*)malloc(sizeof(char) * 100);
	strcpy(pre_str, "");
	element data, oper;
	int i = 0;

	// �� ������ �뵵�� stack �ϳ� �����Ұ�
	while (ch[i] != NULL) {
		if (ch[i+1] == '.') {
			push(&s, ch[i]);
			i++;
			push(&s, ch[i]);
			while (ch[i+1] != NULL && ch[i+1] >= 48 && ch[i+1] <= 57) {
				i++;
				push(&s, ch[i]);
			}
			push(&s, NULL);
		}
		else {
			push(&s, ch[i]);
		}
		i++;
	}
	while (!isEmpty(&s)) {
		data = pop(&s);
		switch (data)
		{
		// ������/��ȣ�ΰ��
		case '+': case '-': case '/': case '*':
			// ������ ������ �ֻ��� ���� �켱���� ��
			while (!isEmpty(&op) && (prec(data) <= prec(peek(&op)))) {
				oper = pop(&op);
				push(&dt, oper);
			}
			push(&op, data);
			break;
		case ')': case ']': case '}':
			push(&op, data);
			break;
		case '(': case '[': case '{':
			oper = pop(&op);
			push(&dt, oper);
			while (oper != ')' && oper != ']' && oper != '}') {
				oper = pop(&op);
				push(&dt, oper);
			}
			break;
		// ������ ���
		default:
			push(&dt, data);
			break;
		}
	}
	while (!isEmpty(&op)) {
		oper = pop(&op);
		push(&dt, oper);
	}

	while (!isEmpty(&dt)) {
		data = pop(&dt); 
		if (data != '(' && data != '[' && data != '{' && data != ')' && data != ']' && data != '}') {
			if (peek(&dt) == '.') {
				strncat(pre_str, &data, 1);
				// '.' pop���� data�� �Ҵ�
				data = pop(&dt);
				strncat(pre_str, &data, 1);
				// ���� ������ peek���� ������ ���, space���� pre_str�� �߰�
				while (!isEmpty(&dt) && peek(&dt) >= 48 && peek(&dt) <= 57) {
					data = pop(&dt);
					strncat(pre_str, &data, 1);
				}
			//	strcat(pre_str, " ");
			}
			else {
				strncat(pre_str, &data, 1);
				strcat(pre_str, " ");
			}
		}
	}

	return pre_str;
}

double postfix_calculate(char* ch) {
	LinkedStackType* s;
	init(&s);
	double op1, op2, value;
	int i = 0;
	while (ch[i] != NULL) {
		// �׸��� �ǿ�����
		if (ch[i] != '+' && ch[i] != '-' && ch[i] != '*' && ch[i] != '/' && ch[i] != ' ') {
			value = ch[i] - '0';
			if (ch[i + 1] == '.') {
				// i�� �������Ѽ� '.'���� index �̵�
				i++;
				int decimal = 1;
				double d_value;
				while (ch[i+1] != NULL && ch[i+1] >= '0' && ch[i+1] <= '9') {
					i++;
					d_value = ch[i] - '0';
					for (int j = 1; j <= decimal; j++) {
						d_value *= 0.1;
					}
					value += d_value;
					decimal++;
				}
				fpush(&s, value);
			}
			else {
				fpush(&s, value);
			}
			
		}
		else if (ch[i] == ' ') {

		}
		// �׸��� ������
		else {
			op2 = fpop(&s);
			op1 = fpop(&s);
			switch (ch[i])
			{
			case '+': fpush(&s, op1 + op2); break;
			case '-': fpush(&s, op1 - op2); break;
			case '*': fpush(&s, op1 * op2); break;
			case '/': fpush(&s, op1 / op2); break;
			}
		}
		i++;
	}

	return fpop(&s);
}

int main(void) {
	char *ch = (char *)malloc(sizeof(char)*100);

	
	printf("�������� �Է��ϼ���: ");
	scanf("%s", ch);
//	strcpy(ch, "(123+b)*c");
//	strcpy(ch, "5*(3.5-2)+4.68/3");

	// ��ȣ �˻�
	if (bracketCheck(ch)) {
		printf("��ȣ�� ��������\n");
	}
	else {
		fprintf(stderr, "��ȣ�� ��������\n");
		exit(1);
	}

	// ������->������
	// �������̶� �ݴ밳��
	printf("������: ");
	printf("%s", infix_to_prefix(ch));
	printf("\n");

	// ������->������
	// ch4 37page
	printf("������: ");
	printf("%s", infix_to_postfix(ch));
	printf("\n");
	
	// ������ ���
	// ch4 31page
	printf("�����: ");
	printf("%lf", postfix_calculate(infix_to_postfix(ch)));
//	postfix_calculate("5 3.5 2 - * 4.68 3 / +");
	printf("\n");
	// 1. ��ȣ�˻�/���ڿ��˻� 
	// 2. �Ҽ���ó��
	// 3. ����� ����
	// 4. ���ڸ��� ó��

	return 0;
}

/*
	�Լ��� : 
	�� �� : 
	������ : 
	�� �� : 
*/