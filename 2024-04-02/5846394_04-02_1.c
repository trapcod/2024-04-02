#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
struct {
	float coef;
	int expon;
} terms[MAX_TERMS] = { {4.0, 3 }, {3.0, 2}, {2.0, 1},
	{1.0, 0}, {3.0, 2}, {2.0, 1}, {8.0, 0 } };
int avail = 7;

// 두 개의 정수를 비교
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

// 새로운 항을 다항식에 추가한다.
void attach(float coef, int expon)
{
	if (avail >= MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

// 다항식의 곱셈을 수행하는 함수
void poly_multiply(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
	*Cs = avail;
	for (int i = As; i <= Ae; i++) {
		for (int j = Bs; j <= Be; j++) {
			float coef = terms[i].coef * terms[j].coef;
			int expon = terms[i].expon + terms[j].expon;
			// 이제 coef와 expon으로 새로운 항을 추가하기 전에, 이미 존재하는 차수의 항에 계수를 더해야 합니다.
			// 여기에 그 로직을 추가해야 합니다. (아래는 예시 로직이며, 실제 구현에는 최적화가 필요할 수 있습니다.)
			int k;
			for (k = *Cs; k < avail; k++) {
				if (terms[k].expon == expon) {
					terms[k].coef += coef;
					break;
				}
			}
			// 새로운 차수의 항이라면 추가
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
