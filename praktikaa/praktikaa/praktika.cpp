#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>

int n;//глобальная переменная для определения размерности массива
void writeRandomNumbersToFile(const char* ik, int count) {
	FILE* file = fopen("inputt.txt", "w");
	if ("inputt.txt" == NULL) {
		printf("Ошибка открытия файла.\n");
		return;
	}

	srand(time(NULL)); // Инициализация генератора случайных чисел

	for (int i = 0; i < count; i++) {
		int randomNumber = rand() % 2001 - 1000; // Генерация случайного числа в диапазоне от -1000 до 1000
		fprintf(file, "%d\n", randomNumber); // Запись числа в файл
	}

	fclose(file);
}
void vivod(int* arr)//функция для чтения из файла
{
	FILE* in = fopen("inputt.txt", "r");//открытие файла с функцией чтения
	if (in == NULL)//проверка на пустой файл
	{
		printf("Error!\n");//вывод "Ошибка"
	}
	else
	{
		for (int i = 0; i < n; i++)//цикл
		{
			fscanf_s(in, "%d ", &arr[i]);//чтение из файла и заполнение массива
		}
		fclose(in);//закрытие файла
		printf("\n");
	}

}
int binarySearch(int a[], int item, int low, int high)//функция бинарной сортировки
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

		// Поиск места ,куда должно быть вставлено selected
		loc = binarySearch(arr, selected, 0, j);

		// Перемещаем элементы после нахождения loc, чтобы создать свободное пространство
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

// Основное тело программы
int main()
{
	system("color F0");
	setlocale(0, "");

	printf("Введите размер массива:");
	scanf("%d", &n);
	writeRandomNumbersToFile("random_numbers.txt", n);
	int* arr = new int[n];

	clock_t start;
	double duration;

	vivod(arr);
	start = clock();
	insertionSort(arr, n);
	preob(arr);
	printf("Отсортированный массив записан в файл output.txt \n");
	duration = (double)(clock() - start) / CLOCKS_PER_SEC;


	delete[] arr;

	printf("\nВремя сортировки:%f sec\n", duration);
	return 0;
}