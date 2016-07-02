#pragma once


void FindContinueSequence(int sum)
{
	if (sum < 3)
		return;

	int small = 1;
	int big = 2;
	int cursum = small+big;		//先把当前的值求出来
	while (big<=(sum/2+1))
	{
		int i = small;
		if (cursum == sum)		//如果当前的和等于目标值，那么直接输出
		{
			for (i=small; i < big; i++)
			{
				cout << i << "+" << " ";
			}
			cout << big << "=" << sum<<endl;
			big++;				
			cursum += big;		//输出完以后继续加一个大的值，然后逐个去除小的数，使small++然后继续寻找
		}
		else if (cursum > sum)	//如果大于的话，减去small的值，然后small向上走一下
		{
			cursum -= small;
			small++;
		}
		else					//如果小于的话，继续加上一个Big值，继续判断
		{
			big++;
			cursum += big;
		}
	}
	
}

void TestFindContinueSequence()
{
	FindContinueSequence(15);
}