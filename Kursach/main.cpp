#include "Header.h"

int** create_arr(int n)
{
	int** Arr2 = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		Arr2[i] = (int*)malloc(n * sizeof(int));

		for (int j = 0; j < n; j++)
		{
			if (rand() % 100 > 70)
			{
				Arr2[i][j] = 0;
			}
			else
			{
				Arr2[i][j] = rand() % n;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		Arr2[i][i] = 0;
		for (int j = 0; j < n; j++)
		{
			if (Arr2[i][j] > 0)
				Arr2[j][i] = 0;
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("V%d ", i + 1);
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < n; j++)
			printf("%2d ", Arr2[i][j]);
	}
	return Arr2;
}

int** zapolny_arr(int n)
{
	int x, s = 1, ** A = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		A[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
			A[i][j] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			system("cls");
			printf("Введите элемент %d строки %d столбца: ", i + 1, j + 1);
			cin >> x;
			A[i][j] = x;
			for (int i = 0; i < n; i++)
				printf("V%d ", i + 1);
			for (int i = 0; i < n; i++)
			{
				printf("\n");
				for (int j = 0; j < n; j++)
					printf("%2d ", A[i][j]);
			}
			printf("\n");
			system("pause");
		}
	}	
	return A;
}

int** create_matrix()
{
	int ** A = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		A[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
			A[i][j] = 0;
	}
	return A;
}

//void Sigismund_Dijkstra(int** A, int n, int x)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("\n");
//		for (int j = 0; j < n; j++)
//		{
//			if (A1[i][j] == SHRT_MAX)
//				printf("%2d ", 0);
//			else
//				printf("%2d ", A1[i][j]);
//		}
//	}
//	int* dist = (int*)malloc(n * sizeof(int));
//	for (int i = 0; i < n; i++)
//		dist[i] = SHRT_MAX;
//	dist[x] = 0;
//	list<int> lst;
//	list<int> ls;
//	for (int i = 0; i < n; i++)
//		ls.push_back(i);
//	ls.remove(x);
//	while (!ls.empty())
//	{
//		int a, l = SHRT_MAX;
//		for (int k : ls)
//			if (k != x && A[x][k] != 0 && A[x][k] < l)
//			{
//				l = A[x][k];
//				a = k;
//			}
//		lst.push_back(a);
//		ls.remove(a);
//		x = a;
//		for (int k : ls)
//			printf("%d ", k);
//		for (int i = 0; i < n; i++)
//		{
//			if (A[a][i] > 0)
//			{
//				if (dist[i] > dist[a] + A[a][i])
//				{
//					dist[i] = dist[a] + A[a][i];
//					//printf("%d ", a);
//				}
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//		printf("%d ", dist[i]);
//	printf("Алгоритм выполнен!");
//	system("pause");
//	menu1();
//}

void Sigismund_Dijkstra(int** A, int n, int x, int* dist)
{
	int* num = (int*)(malloc(n * sizeof(int)));
	int minR, minV;
	for (int i = 0; i < n; i++)
	{
		num[i] = 0;
	}
	dist[x] = 0;
	do
	{
		minR = SHRT_MAX;
		minV = SHRT_MAX;
		for (int i = 0; i < n; i++)
		{
			if (num[i] == 0 && dist[i] <= minR)
			{
				minR = dist[i];
				minV = i;
			}
		}
		if (minV != SHRT_MAX)
		{
			for (int i = 0; i < n; i++)
			{
				if (A[minV][i] > 0 && dist[i] > minR + A[minV][i])
				{
					dist[i] = minR + A[minV][i];
				}
			}
			num[minV] = 1;
		}
	} while (minV < SHRT_MAX);
}

void create_db()
{
	char name[16];
	printf("Создание БД.\nВведите имя БД: ");
	scanf("%s", name);
	OemToCharBuffA(name, name, strlen(name));
	char folder[26] = "DB\\", format[5] = ".txt";
	strcat(name, format);
	strcat(folder, name);
	DB = fopen(folder, "w");
	fclose(DB);
	system("PAUSE");
	menu();
}

void create_graf()
{
	int x, SW1;
	system("cls");
	printf("1) Создать матрицу смежности.\n2) Ввод матрицы смежности.\n3) Назад.\nВыберите пункт: ");
	do {
		SW1 = _getch();
		switch (SW1)
		{
		default:
			system("cls");
			printf("Такого пункта нет!\n");
			break;
		case '1':
			system("cls");
			printf("Введите размер: ");
			scanf("%d", &n);
			A1 = create_arr(n);
			system("cls");
			menu1();
			break;
		case '2':
			system("cls");
			printf("Введите размер: ");
			scanf("%d", &n);
			A1 = zapolny_arr(n);
			system("cls");
			menu1();
			break;
		case '3':
			menu1();
		}
	} while (SW1 != '3');
}

void menu1()
{
	system("cls");
	int x, * dist = (int*)(malloc(n * sizeof(int))), ** matrix = (int**)(malloc(n * sizeof(int*))), SW;
	printf("1) Создать граф.\n2) Алгоритм Дейкстры.\n3) Просмотр результата.\n4) Сохранить результат.\n5) Загрузить из файла\n6) Назад.\nВыберите пункт: ");
	do {
		SW = _getch();
		switch (SW)
		{
		case '1':
			system("cls");
			create_graf();
			system("cls");
			break;
		case '2':
			system("cls");
			for (int i = 0; i < n; i++)
				matrix[i] = (int*)malloc(n * sizeof(int));
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					dist[j] = SHRT_MAX;
				Sigismund_Dijkstra(A1, n, i, dist);
				for (int j = 0; j < n; j++)
					matrix[i][j] = dist[j];
			}
			printf("Результат: ");
			for (int i = 0; i < n; i++)
			{
				printf("\n");
				for (int j = 0; j < n; j++)
				{
					if (matrix[i][j] == SHRT_MAX)
						printf("%2d ", 0);
					else 
						printf("%2d ", matrix[i][j]);
				}
					
			}
			system("pause");
			break;
		case '3':
			system("cls");
			print();
			break;
		case '4':
			system("cls");
			print_file();
			break;
		case '5':
			system("cls");
			read_file();
			break;
		case '6':
			menu();
		default:
			system("cls");
			printf("Такого пункта нет!\n");
			menu1();
			break;
		}
	} while (SW != '6');
}

void open_db()
{
	char name[16];
	printf("Открытие БД.\nВведите имя БД: ");
	scanf("%s", name);
	OemToCharBuffA(name, name, strlen(name));
	char folder[26] = "DB\\", format[5] = ".txt";
	strcat(name, format);
	strcat(folder, name);
	strcpy(ADRESS, folder);
	DB = fopen(ADRESS, "r+");
	if (fopen(ADRESS, "r+") == 0)
	{
		printf("Такой БД не существует!\n");
		system("PAUSE");
		return;
	}
	fclose(DB);
	menu1();
	system("PAUSE");
}

void print_file()
{
	DB = fopen(ADRESS, "w");
	fprintf(DB, "Размер массива: %d", n);
	for (int i = 0; i < n; i++)
	{
		fprintf(DB, "\n");
		for (int j = 0; j < n; j++)
			if (A1[i][j] == SHRT_MAX)
				fprintf(DB, "%2d ", 0);
			else 
				fprintf(DB, "%2d ", A1[i][j]);
	}
	fclose(DB);
	printf("Файл успешно сохранился!");
	system("pause");
}

void print()
{
	for (int i = 0; i < n; i++)
		printf("V%d ", i + 1);
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < n; j++)
		{
			if (A1[i][j] == SHRT_MAX)
				printf("%2d ", 0);
			else 
				printf("%2d ", A1[i][j]);
		}
	}
	system("pause");
}

void read_file()
{
	DB = fopen(ADRESS, "r");
	fseek(DB, 16, SEEK_SET);
	fscanf(DB, "%d", &n);
	A1 = create_matrix();
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < n; j++)
			fscanf(DB, "%d", &A1[i][j]);
	}
	fclose(DB);
	printf("Файл успешно загружен!");
	_getch();
}

void menu()
{
	system("cls");
	printf("1) Создать базу данных.\n2) Открыть базу данных.\n3) Выход. \nВыберите пункт: ");
	int SW2;
	do {
		SW2 = _getch();
		switch (SW2)
		{
		case '1':
			system("cls");
			create_db();
			system("cls");
			menu();
			break;
		case '2':
			system("cls");
			open_db();
			system("cls");
			break;
		case '3':
			exit(0);
		default:
			system("cls");
			printf("Такого пункта нет!\n");
			break;
		}
	} while (SW2 != '3');
	
}

int main()
{
	setlocale(LC_ALL, "Ru");
	system("cls");
	menu();
}
