#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
	int expo;
	float coef;
} element;

typedef struct {
	element terms[MAX_SIZE];
	int nums; // 다항식에 포함된 항의 개수
} polynominal;

int main(void)
{
	polynominal p = { { { 5, 3 }, { 2, 2 }, { 3, 1 }, { 1, 0 } }, 4 };
	polynominal q = { { { 10, 5 }, { 3, 3 }, { 5, 2 } }, 3 };

	poly_add(p, q);



	return 0;
}

polynominal poly_add(polynominal p, polynominal q)
{
	polynominal r;
	int ip = 0, iq = 0, ir = 0; // 방정식 p, q, r의 배열 p의 인덱스
	int pn = p.nums; // p방정식의 항의 개수
	int qn = q.nums; // q방정식의 항의 개수
	int nums = 0;

	while (ip < pn && iq < qn)
	{
		if (p.terms[ip].expo = q.terms[ip].expo) // p항의 ip번째 
		{
			r.terms[ir].coef = p.terms[ip].coef + q.terms[iq].coef;
			r.terms[ir].expo = p.terms[ip].expo + q.terms[iq].expo;
			ir++; ip++; iq++;
		}

		else if (p.terms[ip].expo > q.terms[ip].expo)
		{
			r.terms[ir].coef = p.terms[ip].coef;
			r.terms[ir].expo = p.terms[ip].expo;
			ir++; ip++;
		}

		else
		{
			r.terms[ir].coef = q.terms[iq].coef;
			r.terms[ir].expo = q.terms[iq].expo;
			ir++; iq++;
		}
		nums++;
	}

	if (ip < pn)
	{
		for (int i = ip; i < pn; i++)
		{
			r.terms[ir].coef = p.terms[ip].coef;
			r.terms[ir].expo = p.terms[ip].expo;
			ir++; nums++;
		}
	}

	else if (iq < qn)
	{
		for (int i = iq; i < qn; i++)
		{
			r.terms[ir].coef = q.terms[iq].coef;
			r.terms[ir].expo = q.terms[iq].expo;
			ir++; nums++;
		}
	}
	r.nums = nums;

	return r;
}
