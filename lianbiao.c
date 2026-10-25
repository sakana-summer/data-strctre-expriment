#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Node {
    DataType data;      
    struct Node* next;  
} Node;

// 1. 初始化一个带有头结点的单链表
Node* InitList() {
    Node* head = (Node*)malloc(sizeof(Node)); 
    if (head == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    head->next = NULL;
    return head;
}

// 2. 采用头插法建立单链表
void CreateListHead(Node* head) {
    DataType x;
    printf("请输入数据（输入 -1 结束建立）：\n");
    scanf("%d", &x);
    while (x != -1) {
        Node* newNode = (Node*)malloc(sizeof(Node)); 
        newNode->data = x;
        newNode->next = head->next; 
        head->next = newNode;       
        scanf("%d", &x);
    }
}

// 3. 采用尾插法建立单链表
void CreateListTail(Node* head) {
    DataType x;
    Node* tail = head; 
    printf("请输入数据（输入 -1 结束建立）：\n");
    scanf("%d", &x);
    while (x != -1) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = NULL;

        tail->next = newNode; 
        tail = newNode;       
        scanf("%d", &x);
    }
}

// 4. 判断链表是否为空
// 返回值：1表示空，0表示非空
int IsEmpty(Node* head) {
    if (head->next == NULL) {
        return 1;
    }
    return 0;
}

// 5. 计算链表的长度
int GetLength(Node* head) {
    int length = 0;
    Node* p = head->next; // 从第一个存放有效数据的结点开始
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

// 6. 输出链表的内容
void PrintList(Node* head) {
    Node* p = head->next;
    if (p == NULL) {
        printf("该链表为空！\n");
        return;
    }
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void DestroyList(Node* head) {
    Node* p = head;
    while (p != NULL) {
        Node* temp = p;
        p = p->next;
        free(temp);
    }
}

// 主函数
int main() {
    // --- 测试头插法 ---
    printf("========== 测试头插法 ==========\n");
    Node* head1 = InitList();
    printf("初始化后，链表是否为空(1是/0否): %d\n", IsEmpty(head1));

    CreateListHead(head1);
    printf("头插法链表内容: ");
    PrintList(head1);
    printf("当前链表长度: %d\n\n", GetLength(head1));

    DestroyList(head1); // 用完释放内存

    // --- 测试尾插法 ---
    printf("========== 测试尾插法 ==========\n");
    Node* head2 = InitList();
    printf("初始化后，链表是否为空(1是/0否): %d\n", IsEmpty(head2));

    CreateListTail(head2);
    printf("尾插法链表内容: ");
    PrintList(head2);
    printf("当前链表长度: %d\n", GetLength(head2));

    DestroyList(head2); // 用完释放内存

    return 0;
}