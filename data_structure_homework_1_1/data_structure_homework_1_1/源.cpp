//1．	编写递归函数计算Fibonacci数列，能避免重复计算
//输入：input.txt，仅包含一个整数n（0－90）
//输出：程序应能检查输入合法性，若有错误，输出错误提示“WRONG”；否则输出F(n)。两种情况都输出一个回车（形成一个空行）。所有实例均应在30秒内输出结果。
//
//提示：可用一数组保存Fibonacci数列，用一个特殊值表示还未计算出Fibonacci数，递归调用前先检查数组，若已计算，直接取用，不进行递归调用；若未计算，调用递归函数，计算完成后保存入数组。实际上，这种方法得到了F(1)－F(n)，而不仅是F(n)。
//另外，注意数据类型取值范围问题。VC 6.0中，长整型为LONGLONG，而其输出用 % I64d。
#include<iostream>
using namespace std;
long long int  feibo[91] = { 0,1,1 };
long long int fei_solve(int n, long long int fei[])
{
	if (n <= 90 && n >= 0.00000)
	{
		if (n == 1 || n == 2 || n == 0)
		{
			if (n == 0)
				return 0;
			else
				return 1;
		}
		else
		{
			if (fei[n])
			{
				return fei[n];
			}
			else
			{
				if (fei[n - 1] && fei[n - 2])
				{
					fei[n] = fei[n - 1] + fei[n - 2];
					return fei[n];
				}
				else
				{
					return fei_solve(n - 1, fei) + fei_solve(n - 2, fei);
				}

			}
		}
	}
	else
	{
		throw exception("WRONG!");
		return 0;
	}
}
int main()
{
	try
	{
		int n;
		cin >> n;
		cout << fei_solve(n, feibo);
		printf("%l", fei_solve(n, feibo));
		cout << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}



}