// 结构体定义

// 1. 顺序表
# define maxsize 50
typedef struct {
    int data[maxsize];
    int length;
} SqList;

// 2. 单链表（带头结点）[* 可能考手写结构体]
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 3. 栈与队列
// 3.1. 顺序栈
#define MaxSize 100
typedef struct {
    ElemType data[MaxSize];
    int top; // 指向栈顶元素下标，初值-1
} SqStack;

// 3.2. 循环队列
#define MaxSize 100
typedef struct {
    ElemType data[MaxSize];
    int front, rear; // front 指向队头，rear 指向队尾下一个位置
} SqQueue;

// 4. 二叉树
typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 5. 图
// 5.1. 邻接矩阵
#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vex[MaxVertexNum];
    EdgeType edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} MGraph;

// 5.2. 邻接表
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
    // int weight;
} ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[MaxVertexNum];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

