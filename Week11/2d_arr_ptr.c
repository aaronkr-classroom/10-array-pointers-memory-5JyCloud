// 2d_arr_ptr.c
#include <stdio.h>

#define ROWS 3
#define COLS 5

void printArr(char arr[ROWS][COLS])
{
    // printf("배열의 상태 : \n");
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    char data[ROWS][COLS] = { 0 };    // 모든 요소를 0으로 채움
    char (*p)[COLS];    // COLS 개의 char를 가지는 배열을 가리키는 포인터

    p = data;
    printf("시작 전 : \n");
    printArr(data);
    printf("Press any key to continue...");
    getchar();

    (*p)[1] = 3;
    (*(p+1))[2] = 4;
    (*(p+2))[4] = 5;

    printf("초기 배열의 상태 : \n");
    printArr(data);
    printf("Press any key to continue...");
    getchar();

    p = data;
    p++;
    (*p)[0] = 7;
    (*p)[4] = 8;
    (*(p-1))[3] = 9;

    printf("두 번째 수정 후 배열의 상태 : \n");
    printArr(data);
    printf("Press any key to continue...");
    getchar();

    char* ptr = &data[0][0];
    *(ptr + 6) = 10;
    *(ptr + 10) = 11;
    *(ptr + 14) = 28;
    // *(ptr + 15) = 100;   // 오류 배열의 끝으로 넘어감

    printf("포인터 산술 연산 후 배열의 상태 : \n");
    printArr(data);
    printf("Press any key to continue...");
    getchar();

    // 첫 번째와 세 번째 행 바꾸기
    char temp[COLS];
    for(int i = 0; i < COLS; i++)
    {
        temp[i] = data[0][i];
        data[0][i] = data[2][i];
        data[2][i] = temp[i];
    }

    printf("첫 번째 행과 세 번째 행 교환 후 배열의 상태 : \n");
    printArr(data);
    printf("Press any key to continue...");
    getchar();

    return 0;
}