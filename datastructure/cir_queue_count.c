#include <stdio.h>
#include <stdlib.h>

// ===== ����ť �ڵ� ���� ======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // ť Ÿ��
	int front, rear, count, capacity;
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
	// capacity�� MAX_QUEUE_SIZE�� �Ҵ�
	q->capacity = MAX_QUEUE_SIZE;
}
// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	// q�� count�� 0�� �񱳽��� �״�� return�Ͽ� evaluation �Ǿ��� ��� count�� 0�϶� true, �̿��� ���� false�� return
	return q->count == 0;
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	// count�� capacity�� ���ϴ� ������ �״�� return�Ͽ� ���� ���, full ���·� �ν�
	return q->count == q->capacity;
}

// resize �Լ�
// realloc�� Ȱ���Ͽ� ������ �Ҵ��ߴ� ũ���� 2�踦 ���Ҵ�
void resize(QueueType* q) {
	// �����Ҵ�ũ���� 2�踦 data�� ���Ҵ�
	q->data = (element*)realloc(q->data, sizeof(element) * q->capacity * 2);
	q->capacity *= 2;
}

// ����ť ��� �Լ�
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d count=%d) = ", q->front, q->rear, q->count);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			printf("%d | ", q->data[i]);
			i++;
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

	// for���� Ȱ���Ͽ� queue�� ������ 100���� ����
	for(int i=1; i<=100; i++)
	{
		if (is_full(&queue)) {
			resize(&queue);
		}
		enqueue(&queue, i);
		queue_print(&queue);
	}
	
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
