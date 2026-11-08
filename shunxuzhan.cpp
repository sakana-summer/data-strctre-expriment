#include <stdio.h>
#define MAXSIZE 100 // 栈的最大容量

// 1. 定义顺序栈结构
typedef struct {
    int data[MAXSIZE];
    int top; // 栈顶指针
} SqStack;

// 2. 初始化
void InitStack(SqStack* S) {
    S->top = -1; // -1表示栈空
}

// 3. 入栈
int Push(SqStack* S, int x) {
    if (S->top == MAXSIZE - 1) return 0; // 栈满
    S->top++;
    S->data[S->top] = x;
    return 1;
}

// 4. 出栈
int Pop(SqStack* S, int* x) {
    if (S->top == -1) return 0; // 栈空
    *x = S->data[S->top];
    S->top--;
    return 1;
}

// 5. 进制转换功能
void Conversion(int number, int base) {
    SqStack S;
    InitStack(&S);
    int rem; // 余数

    // 核心：除基取余，余数入栈
    while (number > 0) {
        rem = number % base;
        Push(&S, rem);
        number = number / base;
    }

    // 出栈并打印结果
    while (S.top != -1) {
        Pop(&S, &rem);
        printf("%d", rem);
    }
    printf("\n");
}

// 主函数测试
int main() {
    int num = 10, base = 2;
    printf("十进制 %d 转 %d 进制为: ", num, base);
    Conversion(num, base); 
    return 0;
}