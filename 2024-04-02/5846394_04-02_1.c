#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
struct {
	float coef;
	int expon;
} terms[MAX_TERMS] = { {4.0, 3 }, {3.0, 2}, {2.0, 1},
	{1.0, 0}, {3.0, 2}, {2.0, 1}, {8.0, 0 } };
int avail = 7;

// �� ���� ������ ��
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

// ���ο� ���� ���׽Ŀ� �߰��Ѵ�.
void attach(float coef, int expon)
{
	if (avail >= MAX_TERMS) {
		fprintf(stderr, "���� ������ �ʹ� ����\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

// ���׽��� ������ �����ϴ� �Լ�
void poly_multiply(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
	*Cs = avail;
	for (int i = As; i <= Ae; i++) {
		for (int j = Bs; j <= Be; j++) {
			float coef = terms[i].coef * terms[j].coef;
			int expon = terms[i].expon + terms[j].expon;
			// ���� coef�� expon���� ���ο� ���� �߰��ϱ� ����, �̹� �����ϴ� ������ �׿� ����� ���ؾ� �մϴ�.
			// ���⿡ �� ������ �߰��ؾ� �մϴ�. (�Ʒ��� ���� �����̸�, ���� �������� ����ȭ�� �ʿ��� �� �ֽ��ϴ�.)
			int k;
			for (k = *Cs; k < avail; k++) {
				if (terms[k].expon == expon) {
					terms[k].coef += coef;
					break;
				}
			}
			// ���ο� ������ ���̶�� �߰�
			if (k == avail) {
				attach(coef, expon);
			}
		}
	}
	*Ce = avail - 1;
}

void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main(void)
{
	int As = 0, Ae = 3, Bs = 4, Be = 6, Cs, Ce;
	poly_multiply(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("-----------------------------------------------------------------------------\n");
	print_poly(Cs, Ce);
	return 0;
}
