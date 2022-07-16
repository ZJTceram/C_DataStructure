//
//  ListInsert.c
//  shangan
//  顺序表动态分配
//  Created by 赵俊陶 on 2022/7/16.
//

#include <stdio.h>
#include <stdlib.h>

#define ElemType int

#define AddSize 10
#define InitSize 10
#define true 1
#define false 0


typedef int bool;

typedef struct {
    int *data;
    int MaxSize, length;
}SqList;

void InitSqList(SqList *L){
    L->data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
    L->length = 0;
    L->MaxSize = InitSize;
}

void IncreaseSize(SqList *L, int len) {
    int *p = L->data;
    L->data = (int *)malloc((L->MaxSize+len)*sizeof(int));
    
    for (int i = 0; i<L->length; ++i) {
        L->data[i] = p[i];
    }
    
    L->MaxSize = L->MaxSize+len;
    free(p);
}

int main(){
    SqList L;
    InitSqList(&L);
    IncreaseSize(&L, 5);
    printf("现在的长度为%d\n",L.MaxSize);
    return 0;
}




