// 2013
// 1. 初始化第一个数组元素为之元素，使用count记录（动态）数量变化，realcount记录该元素总出现次数。动态记录初始化为1，循环遍历数组，若a[i]与主元素k（当前）相等，则count和realcount均加一；否则count减1。若count==0时，将当前a[i]设为主元素，同时realcount初始化为1。最后判断realcount是否>n/2，若大于则输出k，否则输出-1。

// 2. 代码
void find_main(int a[], int n) {
    if (n==0 || n==1) { // 若数组为空或仅有一个元素，则不存在主元素
        printf("-1");
        return; 
    }

    int k =a[0]; // 记录主元素
    int count = 1; // 初始化主元素动态记录个数
    int realcount = 1; // 主元素个数

    for (int i = 1; i<n; i++) {
        if (a[i] == k) { // 若当前元素与主元素相同，则count与realcount均增1
            count++;
            realcount++;
        } else { // 若不等，则count减1，realcount不变
            count--;
            if (count == 0) { // 若 count 减为0，则更换主元素并重新初始化count和realcount
                k = a[i];
                count = 1;
                realcount = 1;
            }
        }
    }
    
    if (realcount > n/2) { // 若 realcount > n/2，则输出主元素，否则输出-1
        printf("%d", k);
    } else {
        printf("-1");
    }

    return;
}

// 3. 时空复杂度
// 时间复杂度：O(n)；空间复杂度：O(1)。




// ==========正确解法============
// realcount是累赘，无需使用。
void find_main(int a[], int n) {
    if (n <= 0) { printf("-1"); return; }

    // 第一阶段：找候选
    int cand = a[0], count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == cand) count++;
        else {
            count--;
            if (count == 0) {
                cand = a[i];
                count = 1;
            }
        }
    }

    // 第二阶段：验证候选是否真的 > n/2
    int realcount = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == cand) realcount++;

    if (realcount > n / 2) printf("%d", cand);
    else printf("-1");
}