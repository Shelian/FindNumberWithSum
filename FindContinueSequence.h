#pragma once


void FindContinueSequence(int sum)
{
	if (sum < 3)
		return;

	int small = 1;
	int big = 2;
	int cursum = small+big;		//�Ȱѵ�ǰ��ֵ�����
	while (big<=(sum/2+1))
	{
		int i = small;
		if (cursum == sum)		//�����ǰ�ĺ͵���Ŀ��ֵ����ôֱ�����
		{
			for (i=small; i < big; i++)
			{
				cout << i << "+" << " ";
			}
			cout << big << "=" << sum<<endl;
			big++;				
			cursum += big;		//������Ժ������һ�����ֵ��Ȼ�����ȥ��С������ʹsmall++Ȼ�����Ѱ��
		}
		else if (cursum > sum)	//������ڵĻ�����ȥsmall��ֵ��Ȼ��small������һ��
		{
			cursum -= small;
			small++;
		}
		else					//���С�ڵĻ�����������һ��Bigֵ�������ж�
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