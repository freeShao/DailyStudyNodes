/*
// 将s1，s2所在链表均逆置，对逆置后s1‘和s2’从头开始比对元素，
// 直至出现不同时，该位置的前一个位置就是共同后缀的起始位置。
void ReverseList (LinkList &L){
    // 若链表为空或只有一个元素，则无需逆置
    if (L == NULL || L->next==NULL || L->next->next==NULL){return;}

    LNode *p = L->next; // 记录首个结点
    L->next = NULL; //断开链表
    while (p != NULL){// 若当前p非最后一个元素时
        LNode *q = p->next; //暂存p的后继
        p->next = L->next; //头插法
        p = q; //处理p的下一个结点
    }
    return L;
}

void FindBack(LinkList &S1, LinkList &S2){
    // 对S1和S2逆置
    ReverseList(S1);
    ReverseList(S2);
    //暂存S1和S2首个结点
    LNode *t1 = S1->next;
    LNode *t2 = S2->next;
    while (t1->data == t2->data && t1->next != NULL && t2->next !=NULL){
        //二者相同时，当前值时后缀一部分，且t1和t2均不是最后一个
        t1 = t1->next; // t1 后移
        t2 = t2->next; // t2 后移
    }
    return t1, t2; //返回结点位置
}


// 时间复杂度O(S1+S2)【S1为Str1的长度，S2为Str2的长度】
// 空间复杂度O(1)
*/

LNode* FindBack(LinkList S1, LinkList S2) {
    if (S1 == NULL || S2 == NULL) return NULL;
    ReverseList(S1);
    ReverseList(S2);

    LNode *t1 = S1->next, *t2 = S2->next;
    LNode *lastSame = NULL;

    while (t1 != NULL && t2 != NULL && t1->data == t2->data) {
        lastSame = t1;        // 记录最后一个相同结点
        t1 = t1->next;
        t2 = t2->next;
    }

    ReverseList(S1);          // 恢复原链表
    ReverseList(S2);

    return lastSame;          // 原链中共同后缀的起始结点；无则NULL
}