//1��	��д�ݹ麯������Fibonacci���У��ܱ����ظ�����
//���룺input.txt��������һ������n��0��90��
//���������Ӧ�ܼ������Ϸ��ԣ����д������������ʾ��WRONG�����������F(n)��������������һ���س����γ�һ�����У�������ʵ����Ӧ��30������������
//
//��ʾ������һ���鱣��Fibonacci���У���һ������ֵ��ʾ��δ�����Fibonacci�����ݹ����ǰ�ȼ�����飬���Ѽ��㣬ֱ��ȡ�ã������еݹ���ã���δ���㣬���õݹ麯����������ɺ󱣴������顣ʵ���ϣ����ַ����õ���F(1)��F(n)����������F(n)��
//���⣬ע����������ȡֵ��Χ���⡣VC 6.0�У�������ΪLONGLONG����������� % I64d��
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