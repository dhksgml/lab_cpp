//#include <stdio.h>
//#include <stdlib.h>
//using namespace std;
//
//int* p;
//int** start;
//unsigned char Byte[100];
//
//void insert(int num)
//{
//	if (sizeof(Byte)/sizeof(int) <= (int**)p - start)
//		return;
//
//	*p = num; // 주소에 값을 넣어준 거(틀림)
//
//	/*printf("%d", p);*/
//	for (int* i = (int*)start; i <= p; i++)
//	{
//		printf("%d ", *i);
//	}
//	printf("\n");
//	for (int* i = (int*)start; i <= p; i++)
//	{
//		printf("%d ", i);
//	}
//	printf("\n");
//
//	p++;
//}
//
//int main()
//{
//
//	p = (int*)Byte;
//	start = (int**)Byte;
//	
//	//while ((*start - p) < sizeof(Byte))
//	while (true)
//	{
//		int input;
//		scanf_s("%d", &input);
//		//printf("%d", input);
//		insert(input);
//	}
//}

//메모리풀을 구현할 때 가장 확인할 점 -> 메모리 주소
//바이트 배열 선언을 동적으로 해야함..

#include <iostream>
using namespace std;
using BYTE = unsigned char;

int main()
{
	int input;
	BYTE* arr = new BYTE[100];
	BYTE** Current = reinterpret_cast<BYTE**>(arr);
	BYTE* Next = arr;
	//cout << Current << endl;
	//cout << (int)Next << endl;

	for (int i = 0; i < 100; i++)
	{
		cin >> input;
		Next += sizeof(input);
		*Current = Next;
		Current = reinterpret_cast<BYTE**>(Next);
		cout << Current << endl;
	}
}