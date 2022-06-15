#include <iostream>
int main()
{
	const short s = 5;
	short n[5];

	for (int i = 0; i < s; i++)
	{
		scanf_s("%hi", &n[i]);
	}

	short m, i,
		a, j;

	__asm
	{
		xor ECX, ECX
		movsx EAX, n[ECX]
		mov m, AX
		mov a, AX
		mov i, 0
		add ECX, 2

		my_loop:

		mov AX, n[ECX]
			cmp m, AX
			jle endm

			mov m, AX
			mov i, CX

			endm :
		cmp a, AX
			jnl enda

			mov AX, n[ECX]
			mov a, AX
			mov j, CX

			enda :
		add ECX, 2

			movsx EAX, s
			imul EAX, 2
			cmp EAX, ecx
			jne my_loop

			movsx EAX, j
			mov BX, m
			mov n[EAX], BX
			movsx EAX, i
			mov BX, a
			mov n[EAX], BX

	}

	for (int i = 0; i < 5; i++)
	{
		printf_s("%hi ", n[i]);
	}

	return 0;
}