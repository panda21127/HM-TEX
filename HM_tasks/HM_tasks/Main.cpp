#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

void Task1();
void Task2();
void Task3();

int main(int N,char *Args[]) {
	setlocale(LC_ALL, "Rus");//переключаем вывод в консоли на русский язык
	srand(time(0));// обновляем для функции рандома
	std::cout << "Простой уровень" << std::endl;
	Task1();
	std::cout << "Средний уровень" << std::endl;
	Task2();
	std::cout << "Сложный уровень" << std::endl;
	Task3();
	system("pause");
	return 0;
}

//---------------------Task1---------------------
//Программа, реализующая алгоритм быстрой сортировки для массива.
template <typename T1>
void swap_elements(T1* a, T1* b)
//Функция для обмена значениями двух любых переменных одного типа
{
	T1 c = *a;
	*a = *b;
	*b = c;
}

int separation(int arr[], int low, int high)
//поиск индекса элемента для разделения массива на два лагеря(левых и правых)
//и обмен местами значений так чтоб:слева все числа меньше заданного,справа-больше
{
	int compared_number = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++){
		if (arr[j] <= compared_number){
			i++;
			swap_elements(&arr[i], &arr[j]);
		}
	}
	swap_elements(&arr[i + 1], &arr[high]);
	return (i + 1);

}

void quick_sort(int arr[], int low, int high)
{
	if (low < high){
		int separable_number = separation(arr, low, high);
		quick_sort(arr, low, separable_number - 1);//левая часть
		quick_sort(arr, separable_number + 1, high);//правая часть
	}
}

void print_array(int arr[], int size)
//печатает массив
{
	int i;
	for (i = 0; i < size; i++)
	{
		std::cout<<arr[i]<<"  ";
	}
	std::cout << std::endl << std::endl;

}

void Task1() {
	const int N = 100;//кол-во элементов в массиве
	int arr[N];
	for (int i = 0; i < N; i++) {
		arr[i] = rand();
	}
	print_array(arr, N);
	
	//clock_t start = clock();
	quick_sort(arr, 0, N - 1);
	/*
	clock_t end = clock();
	double seconds = (double)(end - start);// подсчёт времени выполнения сортировки
	std::cout <<"The time:"<<seconds<<", seconds"<<std::endl;
	*/
	std::cout << "The sorted array is:"<<std::endl;
	print_array(arr, N);
	std::cout << std::endl;
}

//---------------------Task2---------------------
//Написать функцию, которая принимает на вход число и находит его разложение на простые множители.
//Вывести результат на экран.

bool check(int number)
//Проверка на дурака
{
	if ((number == 0) || (number == 1)) {
		std::cout << "Число не может быть разложенно на простые";
		return false;
	}
	return true;
}

bool cheeck_simple_number(int N) 
//функция, проверяющая является ли число простым или нет
{
	bool flag = true;
	for (int i = 2; i <= N / 2; i++) {
		if ((N % i) == 0)
		// условие кратности заданного числа N на ряд чисел из промежутка "1<i<N"
		{
			flag = false;
			break;
		}
	}
	return flag;
}

std::vector <int> decomposition_simple_numbers(int number_2) {
	std::vector <int> arr;
	// вектор из простых чисел
	while (!cheeck_simple_number(number_2))
	//пока число не простое выполняем цикл
	{
		for (int i = 2; i <= number_2 / 2; i++) {
			if ((number_2 % i) == 0)
			{
				number_2 = number_2 / i;//если число кратно, то делим на i
				arr.push_back(i);
				break;
			}
		}
	}
	arr.push_back(number_2);
	return arr;
}

void Task2() {
	int number_2;
	// число, раскладываемое на простые числа
	std::cout << "Введите число, чтобы разложить его на произведения простых чисел" << std::endl;
	std::cin >> number_2;
	if (check(abs(number_2))){
		std::vector <int> arr = decomposition_simple_numbers(abs(number_2));
		// функция, возвращающая вектор простых чисел,полученных в ходе разложения
		if (number_2 < 0) {
			std::cout <<"-";
		} //знак перед числом
		for (int i = 0; i < arr.size(); i++) {
		if (i != arr.size() - 1) {
			std::cout << arr[i] << "*";
		} else {
			std::cout << arr[i];
		}
	}//вывод простых чисел в виде их произведения
		arr.clear();
	}
	std::cout << std::endl << std::endl;
}

//---------------------Task3---------------------
//Написать программу для решения дифференциальных уравнений методом Эйлера.

double func(double x, double y) {
	return (y-pow(x,2));
	//наша функция
}

void Euler(double x0, double y, double h, double x) {
	//f(x, y) = dy / dx.
	//y(n+1) = y(n) + h * f(x(n),y(n))
	//h = (x(n) - x(0)) / n
	while (x0 < x) {
		y = y + h * func(x0, y);
		x0 = x0 + h;
	}
	std::cout << "Решение дифференциального уравнения y-x^2, при x = " << x << " с шагом  h = "<< h <<", является f(x, y) = " << y;
}

void Task3() {
	double x0 = 0; //начальное значение x(n)
	double y0 = 1; //начально значени y(n)
	double h = 1; //шаг
	double x = 2; //значение, при котором мы ищем нашу функцию f(x,y)
	Euler(x0, y0, h, x);
	std::cout << std::endl << std::endl;
}