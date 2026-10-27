/*
// 初始化一个数组s，其下标对应为链表值的绝对值，其中内容初始化为0，遍历链表，对每个结点对应值对应数组下标的内容+1。
// 同时比对当前下标，若是0，则内容记为1；若非0，则跳过当前结点，指针后移。

typedef int ElemType;
typedef struct LNode{
    ElemType data; // 数据域
    struct LNode *next; //指针域
} LNode, *LinkList;

void RemoveSame (LinkLIst &L, int n) {
    s = (int*) malloc(n * sizeof(int)); //初始化大小为n的数组s
    for (int i =0;i<n;i++){
        s[i]=0; // 初始化均为0
    }

    // 若L初始为空，或仅有一个结点时，不必删除
    if (L == NULL || L->next==NULL || L->next->next==NULL){return;} 
    LNode *p = L->next; //记录首个结点
    LNode *temp; // 临时结点

    s[abs(p->data) - 1]; //首个元素记录为1
    while (p->next != NULL) {
        if (s[abs(p->data) - 1] == 0){// 当前元素未被记录
            s[abs(p->data) - 1] == 1; //记录为1
            temp->next = p; //记录下一个指针
            p = p->next; //指针后移    
        } else{
            temp = p; // 记录当前临时结点
        }
    }
}

// 时间复杂度O(m)，m是元素个数
// 空间复杂度O(n)，n是绝对值最大值
*/

void RemoveSame(LinkList L, int n) {
    if (L == NULL || L->next == NULL) return;

    int *s = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) s[i] = 0;

    LNode *pre = L, *p = L->next;
    while (p != NULL) {
        int idx = abs(p->data);        // 用 1..n 作下标，避免 -1 混淆
        if (s[idx] == 0) {             // 第一次出现，保留
            s[idx] = 1;
            pre = p;
            p = p->next;
        } else {                       // 重复，删除
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
    }
    free(s);
}