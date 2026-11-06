// 2011
// 1、分别用一个指针指向两序列起始处，比较所指元素大小。使用min_num记录小值，令小值的指针后移一位，循环序列长度L次即可。

// 2、
int find_mid(int S1[], int S2[], int n){
    int index1 = 0; // 初始化两个指针
    int index2 =0; 
    int mid_num; // 初始化记录中位数

    for (int i=0; i<n; i++){ // 循环序列长度次
        if (S1[index1] <= S2[index2]){ // 记录小值，并且指针后移
            mid_num = S1[index1];
            index1++;
        } else{
            mid_num = S2[index2];
            index2++;
        }
    }    
    printf("%d", &mid_num); // 输出中位数
    return;
}

// 3、时间复杂度O(n)；空间复杂度O(1)。
