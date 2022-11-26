#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

void sort_insert_vozv(vector<int>&  m, int n)
{
	int j, r;
	for (int i = 1; i < n; i++)
	{
		r = m[i]; /*Запоминаем текущий элемент в промежуточной
		переменной*/
			j = i - 1;
		while (j >= 0 && m[j] > r) /*Ищем место вставки*/
		{
			m[j + 1] = m[j]; /*сдвиг на 1 элемент вправо*/
			j--;
		}
		m[j + 1] = r; /*На освободившееся место вставляется текущий
		элемент*/
	}
}

void sort_insert_ub(vector<int>& m, int n)
{
	int j, r;
	for (int i = 1; i < n; i++)
	{
		r = m[i]; /*Запоминаем текущий элемент в промежуточной
		переменной*/
		j = i - 1;
		while (j >= 0 && m[j] < r) /*Ищем место вставки*/
		{
			m[j + 1] = m[j]; /*сдвиг на 1 элемент вправо*/
			j--;
		}
		m[j + 1] = r; /*На освободившееся место вставляется текущий
		элемент*/
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	vector <int> MainVector;
	vector <int> MinVector;
	vector <int> MaxVector;

	int n;
	cout << "Введите длину массива" << endl;
	cin >> n;
	cout << "\n";
	
	int nmax = 0, nmin = 0;
	for (int i = 0; i < n; i++)
	{
		int Num = rand() % 15;
		MainVector.push_back(Num);
		
		if (Num / 10 == 0)
		{
			MinVector.push_back(Num);
			nmin += 1;
		}
		else
		{
			MaxVector.push_back(Num);
			nmax += 1;
		}
		
		cout << Num << "  ";
	}
	
	sort_insert_ub(MaxVector,nmax);
	sort_insert_vozv(MinVector, nmin);

	int k = 0, j = 0;
	cout << "\nОтсортированный массив:\n";
	for (int i = 0; i < n; i++)
	{
		if (MainVector[i] / 10 == 0)
		{
			MainVector[i] = MinVector[k];
			k++;
		}
		else
		{
			MainVector[i] = MaxVector[j];
			j++;
		}

		cout << MainVector[i] << "  ";
	}

	

}

