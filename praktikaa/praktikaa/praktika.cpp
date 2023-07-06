#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>

int n;//���������� ���������� ��� ����������� ����������� �������
void writeRandomNumbersToFile(const char* ik, int count) {
	FILE* file = fopen("inputt.txt", "w");
	if ("inputt.txt" == NULL) {
		printf("������ �������� �����.\n");
		return;
	}

	srand(time(NULL)); // ������������� ���������� ��������� �����

	for (int i = 0; i < count; i++) {
		int randomNumber = rand() % 2001 - 1000; // ��������� ���������� ����� � ��������� �� -1000 �� 1000
		fprintf(file, "%d\n", randomNumber); // ������ ����� � ����
	}

	fclose(file);
}
void vivod(int* arr)//������� ��� ������ �� �����
{
	FILE* in = fopen("inputt.txt", "r");//�������� ����� � �������� ������
	if (in == NULL)//�������� �� ������ ����
	{
		printf("Error!\n");//����� "������"
	}
	else
	{
		for (int i = 0; i < n; i++)//����
		{
			fscanf_s(in, "%d ", &arr[i]);//������ �� ����� � ���������� �������
		}
		fclose(in);//�������� �����
		printf("\n");
	}

}
int binarySearch(int a[], int item, int low, int high)//������� �������� ����������
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (item == a[mid])
			return mid + 1;
		else if (item > a[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return low;
}


void insertionSort(int arr[], int n)
{
	int i, loc, j, selected;

	for (i = 1; i < n; i++)
	{
		j = i - 1;
		selected = arr[i];

		// ����� ����� ,���� ������ ���� ��������� selected
		loc = binarySearch(arr, selected, 0, j);

		// ���������� �������� ����� ���������� loc, ����� ������� ��������� ������������
		while (j >= loc)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = selected;
	}
}

void preob(int* arr)
{
	FILE* out = fopen("output.txt", "w");

	for (int i = 0; i < n; i++)
	{
		fprintf(out, "%d ", *(arr + i));
	}
	fclose(out);
}

// �������� ���� ���������
int main()
{
	system("color F0");
	setlocale(0, "");

	printf("������� ������ �������:");
	scanf("%d", &n);
	writeRandomNumbersToFile("random_numbers.txt", n);
	int* arr = new int[n];

	clock_t start;
	double duration;

	vivod(arr);
	start = clock();
	insertionSort(arr, n);
	preob(arr);
	printf("��������������� ������ ������� � ���� output.txt \n");
	duration = (double)(clock() - start) / CLOCKS_PER_SEC;


	delete[] arr;

	printf("\n����� ����������:%f sec\n", duration);
	return 0;
}