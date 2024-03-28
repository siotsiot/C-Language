#include <stdio.h>
#define MAX_SIZE 100

// element 타입 정의
typedef struct {
	int coef;
	int expo;
} element;

// polynominal 타입 정의
typedef struct {
	element terms[MAX_SIZE];
	int nums; // 다항식에 포함된 항의 개수
} polynominal;

// 2개의 다항식을 계산하는 함수
polynominal poly_add(polynominal p, polynominal q)
{
	polynominal r = { 0 };
	int ip = 0, iq = 0, ir = 0; // 다항식 p, q, r의 배열의 인덱스
	int pn = p.nums; // 다항식 p의 항의 개수
	int qn = q.nums; // 다항식 q의 항의 개수

	while (ip < pn && iq < qn) // 다항식 p와 q의 배열 인덱스가 다항식 p, q의 항의 개수보다 작을 때
	{
		if (p.terms[ip].expo == q.terms[iq].expo) // 차수가 같을 때
		{
			r.terms[ir].coef = p.terms[ip].coef + q.terms[iq].coef; // ip번째의 계수와 iq번째의 계수를 더하기
			r.terms[ir].expo = p.terms[ip].expo; // ir에 차수 저장
			ir++;
			ip++;
			iq++;
		}

		else if (p.terms[ip].expo > q.terms[iq].expo) // 다항식 p의 차수가 더 클 때
		{
			r.terms[ir].coef = p.terms[ip].coef;
			r.terms[ir].expo = p.terms[ip].expo;
			ir++;
			ip++;
		}

		else // 다항식 q의 차수가 더 클 때
		{
			r.terms[ir].coef = q.terms[iq].coef;
			r.terms[ir].expo = q.terms[iq].expo;
			ir++;
			iq++;
		}
		r.nums++; // 다항식 r의 항 추가
	}

	if (ip < pn) // 다항식 p의 항이 남아있는 경우
	{
		for (int i = ip; i < pn; i++)
		{
			r.terms[ir].coef = p.terms[ip].coef;
			r.terms[ir].expo = p.terms[ip].expo;
			ir++;
			ip++;
			r.nums++;
		}
	}

	else if (iq < qn) // q의 항이 남아있는 경우
	{
		for (int i = iq; i < qn; i++)
		{
			r.terms[ir].coef = q.terms[iq].coef;
			r.terms[ir].expo = q.terms[iq].expo;
			ir++;
			iq++;
			r.nums++;
		}
	}

	return r;
}

// 계산된 다항식 r을 출력하는 함수
void print(polynominal r)
{
	for (int i = 0; i < r.nums; i++)
	{
		printf("%d", r.terms[i].coef);

		if (r.terms[i].expo != 0)
		{
			printf("x");
			if (r.terms[i].expo != 1)
			{
				printf("^");
				printf("%d", r.terms[i].expo);
			}
		}

		if (i < r.nums - 1)
			printf("+");
	}
}

// main() 함수
int main(void)
{
	// p, q 다항식 선언 및 초기화
	polynominal p = { { { 5, 3 }, { 2, 2 }, { 3, 1 }, { 1, 0 } }, 4 };
	polynominal q = { { { 10, 5 }, { 3, 3 }, { 5, 2 } }, 3 };
	
	polynominal r; // r 다항식 선언

	r = poly_add(p, q);
	print(r);

	return 0;
}
