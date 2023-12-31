#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX];
int n;
int comparePlus = 0;
int movePlus = 0;

void printArray(int list[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
}

void printStep(int step, int compareCount, int moveCount)
{
    printf("Step %d:\n", step);
    printf("비교 횟수: %d\n", compareCount);
    printf("이동 횟수: %d\n", moveCount);
    printf("현재 배열: ");
    printArray(list, n);
    printf("\n");
}

// 선택정렬렬
void selectionSort(int list[], int n)
{
    int i, j, least, temp;
    int compareCount = 0;
    int moveCount = 0;

    for (i = 0; i < n - 1; i++)
    {
        least = i;
        for (j = i + 1; j < n; j++)
        {
            compareCount++; // 비교 횟수 증가
            if (list[j] < list[least])
            {
                least = j;
            }
        }

        if (least != i) // 최솟값이 현재 위치와 다른 경우에만 이동 횟수 증가
        {
            SWAP(list[i], list[least], temp);
            moveCount++; // 이동 횟수 증가
        }

        printStep(i + 1, compareCount, moveCount);
    }

    printf("\nSelection Sort 결과:");
    printf("\n비교 횟수: %d", compareCount);
    printf("\n이동 횟수: %d", moveCount);
    printf("\n정렬 완료 후 배열: ");
    comparePlus += compareCount;
    movePlus += moveCount;
    printArray(list, n);
}

//삽입정렬
void insertionSort(int list[], int n)
{
    int i, j, key;
    int compareCount = 0;
    int moveCount = 0;

    for (i = 1; i < n; i++)
    {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
        {
            compareCount++; // 비교 횟수 증가
            list[j + 1] = list[j];
            moveCount++; // 이동 횟수 증가
        }
        list[j + 1] = key;
        moveCount++; // 이동 횟수 증가

        printStep(i, compareCount, moveCount);
    }

    printf("Insertion Sort 결과:\n");
    printf("비교 횟수: %d\n", compareCount);
    printf("이동 횟수: %d\n", moveCount);
    printf("정렬 완료 후 배열: ");
    comparePlus += compareCount;
    movePlus += moveCount;
    printArray(list, n);
}


//버블 정렬렬
void bubbleSort(int list[], int n)
{
    int i, j, temp;
    int compareCount = 0;
    int moveCount = 0;

    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            compareCount++; // 비교 횟수 증가
            if (list[j] > list[j + 1])
            {
                SWAP(list[j], list[j + 1], temp);
                moveCount++; // 이동 횟수 증가
            }
        }

        printStep(n - i, compareCount, moveCount);
    }

    printf("Bubble Sort 결과:\n");
    printf("비교 횟수: %d\n", compareCount);
    printf("이동 횟수: %d\n", moveCount);
    printf("정렬 완료 후 배열: ");
    comparePlus += compareCount;
    movePlus += moveCount;
    printArray(list, n);
}

int main(void)
{
    int i, choice;
    n = MAX;
    for (int i = 0; i < n; i++) {
        srand(time(NULL));
        for (i = 0; i < n; i++)
            list[i] = rand() % 100;

        printf("정렬 방법을 선택하세요.\n");
        printf("1. 선택 정렬\n");
        printf("2. 삽입 정렬\n");
        printf("3. 버블 정렬\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            comparePlus = 0;
          movePlus = 0;
            for (i = 0; i < 20; i++)
            {
                for (int j = 0; j < n; j++)
                    list[j] = rand() % 100;
                printf("배열 %d:\n", i + 1);
                printArray(list, n);
                selectionSort(list, n);
                printf("\n");
            }
            printf("평균 비교 횟수 %d", comparePlus/20);
            printf("\n평균 비교 횟수 %d", movePlus/20);
            break;
        case 2:
          comparePlus = 0;
          movePlus = 0;
          for (i = 0; i < 20; i++)
          {
              for (int j = 0; j < n; j++)
                  list[j] = rand() % 100;
              printf("배열 %d:\n", i + 1);
              printArray(list, n);
              insertionSort(list, n);
              printf("\n");
          }
          printf("평균 비교 횟수 %d", comparePlus/20);
          printf("\n평균 비교 횟수 %d", movePlus/20);
            break;
        case 3:
          comparePlus = 0;
          movePlus = 0;
          for (i = 0; i < 20; i++)
          {
              for (int j = 0; j < n; j++)
                  list[j] = rand() % 100;
              printf("배열 %d:\n", i + 1);
              printArray(list, n);
              bubbleSort(list, n);
              printf("\n");
          }
          printf("평균 비교 횟수 %d", comparePlus/20);
          printf("\n평균 비교 횟수 %d", movePlus/20);
            break;
        default:
            printf("잘못된 선택입니다.\n");
            break;
        }
    }
    return 0;
}
