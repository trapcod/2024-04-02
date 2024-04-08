#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 101 // 다항식의 최대차수 + 1

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

// 다항식 출력 함수
void print_poly(polynomial p) {
    int isFirstTerm = 1; // 첫 번째 항인지 확인하는 플래그
    for (int i = p.degree; i >= 0; i--) {
        if (p.coef[i] != 0) { // 계수가 0이 아닌 항만 출력
            if (isFirstTerm) {
                isFirstTerm = 0; // 첫 번째 항이 아니게 설정
            }
            else {
                printf(" + ");
            }
            if (i == 0) { // 상수항 출력
                printf("%3.1f", p.coef[i]);
            }
            else if (i == 1) { // x의 1승 출력
                printf("%3.1fx", p.coef[i]);
            }
            else { // 그 외의 경우
                printf("%3.1fx^%d", p.coef[i], i);
            }
        }
    }
    if (isFirstTerm) { // 모든 계수가 0인 경우 0을 출력
        printf("0");
    }
    printf("\n");
}

// 다항식 곱셈 함수
polynomial poly_multiply(polynomial A, polynomial B) {
    polynomial C; // 결과 다항식
    C.degree = A.degree + B.degree; // 결과 다항식의 최대 차수는 두 다항식의 차수의 합

    // 결과 다항식의 계수 초기화
    for (int i = 0; i <= C.degree; i++) {
        C.coef[i] = 0;
    }

    // 다항식 곱셈 수행
    for (int i = 0; i <= A.degree; i++) {
        for (int j = 0; j <= B.degree; j++) {
            C.coef[i + j] += A.coef[i] * B.coef[j]; // 곱셈 결과를 해당하는 차수의 계수에 더함
        }
    }

    return C;
}

int main(void) {
    polynomial a = { 7,0, 6 } , {5.
    polynomial b = { 2, {5, 2, 8} }; // 5x^2 + 2x + 8
    polynomial c;

    printf("다항식 A: ");
    print_poly(a);

    printf("다항식 B: ");
    print_poly(b);

    c = poly_multiply(a, b);
    printf("----------------------------------------------------------------------------\n");
    printf("다항식 A*B: ");
    print_poly(c);

    return 0;
}
