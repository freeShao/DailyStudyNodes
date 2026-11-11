// 顺序表
# define maxsize 50
typedef struct {
    int data[maxsize];
    int length;
} SqList;

// 一般使用方法：
void func(int a[], int n){ // 等价于 [SqList &L]
    // a[] 表示传入数组，n可以代指a[]的长度/其他相关变量(循环次数等)
    return;
}


// 1. 原地逆置【O(n), O(1)】
void Reverse (SqList &L) {
    for (int i=0, j=L.length-1; i<j; i++, j--) {
        ElemType t = L.data[i];
        L.data[i] = L.data[j];
        L.data[j] = t;
    }
}
// ==========================

// 2. 删除所有值为x的元素【O(n), O(1)】
void DelX(SqList &L, ElemType x) {
    int k=0;
    for (int i=0; i<L.length; i++){
        if (L.data[i] != x){
            L.data[k++] = L.data[i];
        }
    }
    L.length = k;
}
// ==========================

// 3. 有序表合并（归并）【O(m+n), O(1)】
void Merge(SqList A, SqList B, SqList &C) { // C 用来存放合并后的顺序表
// void Merge(int R1[], int R2[], int R3[]){} 同样可以，属于C语言的语法格式
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while (i < A.length) C.data[k++] = A.data[i++];
    while (j < B.length) C.data[k++] = B.data[j++];
    C.length = k;
}
// ==========================
