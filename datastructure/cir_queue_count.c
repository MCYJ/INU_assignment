#include <stdio.h>
#include <stdlib.h>

// ===== ����ť �ڵ� ���� ======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // ť Ÿ��
	int front, rear, count;
	element* data;
} QueueType;
// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
	q->count = q->front = q->rear = 0;
	q->data = (element*)malloc(sizeof(element)*MAX_QUEUE_SIZE);
}
// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	// ������´� count�� �״�� return�Ͽ�, count�� 0�ΰ�� false, �� ���� ��� ���� true�� ������
	// return q->count;
	return (q->front == q->rear);
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	// return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
	return q->count == sizeof(q->data) / sizeof(element);
}

// resize �Լ�
void resize(QueueType* q) {
	q->data = (element*)realloc(q->data, sizeof(MAX_QUEUE_SIZE) * 2);
}

// ����ť ��� �Լ�
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d count=%d) = ", q->front, q->rear, q->count);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			printf("%d | ", q->data[i]);
			i = (i + 1) % (MAX_QUEUE_SIZE);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// ���� �Լ�
void enqueue(QueueType* q, element item)
{

	if (is_full(q)) {
		// queue�� ��ȭ������ ���, resize �Լ� ȣ��
		resize(q);
	}

	q->count++;
	q->data[q->rear] = item;
	q->rear = (q->rear + 1) ;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->count--;

	int deq = q->data[q->front];
	q->front = q->front + 1;
	
	return deq;
}


int main(void)
{
	QueueType queue;
	int element;
	init_queue(&queue);
	printf("--������ �߰� �ܰ�--\n");
//	while (!is_full(&queue))
	for(int i=0; i=10; i++)
	{
		if (is_full(&queue)) {
			resize(&queue);
		}
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");
	printf("--������ ���� �ܰ�--\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("������ ����: %d \n", element);
		queue_print(&queue);
	}
	printf("ť�� ��������Դϴ�.\n");
	return 0;
}