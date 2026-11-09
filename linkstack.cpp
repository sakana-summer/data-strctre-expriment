#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct node
{
	char data;
	struct node* next;
} Node, LinkStack;
void InitStack(LinkStack** s)
{
	*s = (LinkStack*)malloc(sizeof(Node));
	(*s)->next = NULL;
}
bool StackEmpty(LinkStack* s)
{
	return s->next == NULL;
}
int Push(LinkStack* s, char e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p)
		return 0;
	p->data = e;
	p->next = s->next;
	s->next = p;
	return 1;
}
int Pop(LinkStack* s, char* e)
{
	if (StackEmpty(s))
		return 0;
	Node* p = s->next;
	*e = p->data;
	s->next = p->next;
	free(p);
	return 1;
}
int GetTop(LinkStack* s, char* e)
{
	if (StackEmpty(s))
		return 0;
	*e = s->next->data;
	return 1;
}
void DestroyStack(LinkStack* s)
{
	Node* p;
	while (s)
	{
		p = s;
		s = s->next;
		free(p);
	}
}
int pipei(const char* str)
{
	LinkStack* s;
	InitStack(&s);
	int flag = 1;
	char top;
	for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
				Push(s, str[i]);
			else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
			{
				if (StackEmpty(s))
				{
					flag = 0;
					break;
				}
				GetTop(s, &top);
				if ((str[i] == ')' && top == '(') || (str[i] == ']' && top == '[') || (str[i] == '}' && top == '{'))
					Pop(s, &top);
				else
				{
					flag = 0;
					break;
				}
			}
		}
	if (!StackEmpty(s))
		flag = 0;
	DestroyStack(s);
	return flag;
}
int main(void) {
	char buf[MAX];
	printf("«Î ‰»Î◊÷∑˚¥Æ£∫");
	if (fgets(buf, sizeof(buf), stdin) == NULL) return 0;
	size_t n = strlen(buf);
	if (n > 0 && buf[n - 1] == '\n') buf[n - 1] = '\0';
	if (pipei(buf))
		printf("∆•≈‰\n");
	else
		printf("≤ª∆•≈‰\n");

	return 0;}
