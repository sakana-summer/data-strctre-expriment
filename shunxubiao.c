#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;

void InitList(SqList *L) {
    L->length = 0;
}

void CreateList(SqList *L, int n) {
    if (n > MAXSIZE) {
        printf("元素个数超过最大容量！\n");
        return;
    }
    printf("请输入 %d 个元素：\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &L->data[i]);
    }
    L->length = n;
    printf("顺序表创建成功！\n");
}

bool IsEmpty(SqList L) {
    return L.length == 0;
}

int GetLength(SqList L) {
    return L.length;
}

void PrintList(SqList L) {
    if (IsEmpty(L)) {
        printf("顺序表为空。\n");
        return;
    }
    printf("顺序表当前元素为：");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

bool GetElem(SqList L, int position, int *e) {
    if (position < 0 || position >= L.length) {
        printf("获取失败：位置不合法！\n");
        return false;
    }
    *e = L.data[position];
    return true;
}

int LocateElem_Seq(SqList L, int value) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == value) {
            return i;
        }
    }
    return -1;
}

int LocateElem_Bin(SqList L, int value) {
    int low = 0, high = L.length - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (L.data[mid] == value) {
            return mid;
        } else if (L.data[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

bool ListInsert(SqList *L, int position, int x) {
    if (position < 0 || position > L->length) {
        printf("插入失败：插入位置不合法！\n");
        return false;
    }
    if (L->length >= MAXSIZE) {
        printf("插入失败：顺序表已满！\n");
        return false;
    }
    for (int i = L->length; i > position; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[position] = x;
    L->length++;
    return true;
}

bool ListDelete_Pos(SqList *L, int position, int *e) {
    if (position < 0 || position >= L->length) {
        printf("删除失败：删除位置不合法！\n");
        return false;
    }
    *e = L->data[position];
    for (int i = position; i < L->length - 1; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->length--;
    return true;
}

void ListDelete_Value(SqList *L, int value) {
    int i = 0;
    int count = 0;
    while (i < L->length) {
        if (L->data[i] == value) {
            for (int j = i; j < L->length - 1; j++) {
                L->data[j] = L->data[j + 1];
            }
            L->length--;
            count++;
        } else {
            i++;
        }
    }
    if (count > 0) {
        printf("共删除了 %d 个值为 %d 的元素。\n", count, value);
    } else {
        printf("未找到值为 %d 的元素。\n", value);
    }
}

int main() {
    SqList L;
    int e;
    
    InitList(&L);
    
    CreateList(&L, 5);
    
    if (IsEmpty(L)) printf("表为空\n");
    else printf("表不为空，长度为：%d\n", GetLength(L));
    
    PrintList(L);
    
    if (GetElem(L, 1, &e)) printf("位置 1 的元素值为：%d\n", e);
    
    int pos_seq = LocateElem_Seq(L, 3);
    if (pos_seq != -1) printf("顺序查找：元素 3 在位置 %d\n", pos_seq);
    else printf("顺序查找：未找到元素 3\n");
    
    printf("在第 1 个位置插入 99...\n");
    ListInsert(&L, 1, 99);
    PrintList(L);
    
    printf("删除位置 0 的元素...\n");
    ListDelete_Pos(&L, 0, &e);
    printf("被删除的元素是：%d\n", e);
    PrintList(L);
    
    printf("删除所有值为 2 的元素...\n");
    ListDelete_Value(&L, 2);
    PrintList(L);

    return 0;
}