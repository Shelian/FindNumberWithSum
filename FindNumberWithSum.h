#pragma once

bool FindNumberWithSum(int* a,int size,int sum,int& num1,int& num2)
{
	int left = 0;
	int right = size - 1;
	while (left < right && a[right] >= sum)
		right--;

	while (left < right)
	{
		while (left < right && a[left] + a[right] < sum)
			left++;

		if (a[left] +a[right] == sum)
		{
			num1 = a[left];
			num2 = a[right];
			return true;
		}
		else
		{
			right--;
		}
	}

	return false;

}

bool FindNumberWithSum1(int* a, int size, int sum, int& num1, int& num2)
{
	int left = 0;
	int right = size - 1;

	while (left < right)
	{
		int cursum = a[left] + a[right];
		if (cursum == sum)			//�����Ⱦͷ�����
		{
			num1 = a[left];
			num2 = a[right];
			return true;
		}

		else if (cursum > sum)//�����߽��ֵ��Ӹ���Ļ���˵���ұߵ�ֵ��Ҫ������ƶ�����Ϊ��ߵ�ֵ�Ѿ�����С���ˣ�������Ҳ������������
			right--;

		else				//����ͬ��
		{
			left++;
		}
			
	}

	return false;
}

void TestFind1()
{
	int a[] = { 1, 2, 4, 7, 11,12,13, 15 };
	int x = 0;
	int y = 0;
	cout<<FindNumberWithSum1(a, sizeof(a) / sizeof(a[0]), 17, x, y)<<endl;
	cout << x << " " << y << endl;
}

void MergePartSort(int* a, int* copy, int left, int mid, int right)
{
	int begin1 = left;
	int begin2 = mid + 1;
	int end1 = mid;
	int end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			copy[i++] = a[begin1++];
		}
		else
		{
			copy[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
		copy[i++] = a[begin1++];

	while (begin2 <= end2)
		copy[i++] = a[begin2++];

	for (int j = left; j < right; j++)
	{
		a[j] = copy[j];
	}
}

void MergeSort(int* a, int* copy, int left, int right)
{
	if (left < right)
	{
		int mid = left+(right-left)/2;
		MergeSort(a, copy, left, mid);
		MergeSort(a, copy, mid+1, right);

		MergePartSort(a, copy, left, mid, right);
	}
}

void MergeSort_NonR(int* a, int size)
{
	assert(a);
	int* copy = new int[size];

	int left = 0;
	int right = size - 1;
	MergeSort(a, copy, left, right);
	delete[] copy;
}


void Print(int* a,int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void TestMerge()
{
	int a[] = { 1, 8, 6, 3, 5, 9, 4, 7, 2 };
	int* copy = new int[sizeof(a) / sizeof(a[0])];
	MergeSort_NonR(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
