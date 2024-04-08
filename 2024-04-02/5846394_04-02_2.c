#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 101 // ���׽��� �ִ����� + 1

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

// ���׽� ��� �Լ�
void print_poly(polynomial p) {
    int isFirstTerm = 1; // ù ��° ������ Ȯ���ϴ� �÷���
    for (int i = p.degree; i >= 0; i--) {
        if (p.coef[i] != 0) { // ����� 0�� �ƴ� �׸� ���
            if (isFirstTerm) {
                isFirstTerm = 0; // ù ��° ���� �ƴϰ� ����
            }
            else {
                printf(" + ");
            }
            if (i == 0) { // ����� ���
                printf("%3.1f", p.coef[i]);
            }
            else if (i == 1) { // x�� 1�� ���
                printf("%3.1fx", p.coef[i]);
            }
            else { // �� ���� ���
                printf("%3.1fx^%d", p.coef[i], i);
            }
        }
    }
    if (isFirstTerm) { // ��� ����� 0�� ��� 0�� ���
        printf("0");
    }
    printf("\n");
}

// ���׽� ���� �Լ�
polynomial poly_multiply(polynomial A, polynomial B) {
    polynomial C; // ��� ���׽�
    C.degree = A.degree + B.degree; // ��� ���׽��� �ִ� ������ �� ���׽��� ������ ��

    // ��� ���׽��� ��� �ʱ�ȭ
    for (int i = 0; i <= C.degree; i++) {
        C.coef[i] = 0;
    }

    // ���׽� ���� ����
    for (int i = 0; i <= A.degree; i++) {
        for (int j = 0; j <= B.degree; j++) {
            C.coef[i + j] += A.coef[i] * B.coef[j]; // ���� ����� �ش��ϴ� ������ ����� ����
        }
    }

    return C;
}

int main(void) {
    polynomial a = { 7,0, 6 } , {5.
    polynomial b = { 2, {5, 2, 8} }; // 5x^2 + 2x + 8
    polynomial c;

    printf("���׽� A: ");
    print_poly(a);

    printf("���׽� B: ");
    print_poly(b);

    c = poly_multiply(a, b);
    printf("----------------------------------------------------------------------------\n");
    printf("���׽� A*B: ");
    print_poly(c);

    return 0;
}
