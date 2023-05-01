#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

void Task1();
void Task2();
void Task3();

int main(int N,char *Args[]) {
	setlocale(LC_ALL, "Rus");//����������� ����� � ������� �� ������� ����
	srand(time(0));// ��������� ��� ������� �������
	std::cout << "������� �������" << std::endl;
	Task1();
	std::cout << "������� �������" << std::endl;
	Task2();
	std::cout << "������� �������" << std::endl;
	Task3();
	system("pause");
	return 0;
}

//---------------------Task1---------------------
//���������, ����������� �������� ������� ���������� ��� �������.
template <typename T1>
void swap_elements(T1* a, T1* b)
//������� ��� ������ ���������� ���� ����� ���������� ������ ����
{
	T1 c = *a;
	*a = *b;
	*b = c;
}

int separation(int arr[], int low, int high)
//����� ������� �������� ��� ���������� ������� �� ��� ������(����� � ������)
//� ����� ������� �������� ��� ����:����� ��� ����� ������ ���������,������-������
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
		quick_sort(arr, low, separable_number - 1);//����� �����
		quick_sort(arr, separable_number + 1, high);//������ �����
	}
}

void print_array(int arr[], int size)
//�������� ������
{
	int i;
	for (i = 0; i < size; i++)
	{
		std::cout<<arr[i]<<"  ";
	}
	std::cout << std::endl << std::endl;

}

void Task1() {
	const int N = 100;//���-�� ��������� � �������
	int arr[N];
	for (int i = 0; i < N; i++) {
		arr[i] = rand();
	}
	print_array(arr, N);
	
	//clock_t start = clock();
	quick_sort(arr, 0, N - 1);
	/*
	clock_t end = clock();
	double seconds = (double)(end - start);// ������� ������� ���������� ����������
	std::cout <<"The time:"<<seconds<<", seconds"<<std::endl;
	*/
	std::cout << "The sorted array is:"<<std::endl;
	print_array(arr, N);
	std::cout << std::endl;
}

//---------------------Task2---------------------
//�������� �������, ������� ��������� �� ���� ����� � ������� ��� ���������� �� ������� ���������.
//������� ��������� �� �����.

bool check(int number)
//�������� �� ������
{
	if ((number == 0) || (number == 1)) {
		std::cout << "����� �� ����� ���� ���������� �� �������";
		return false;
	}
	return true;
}

bool cheeck_simple_number(int N) 
//�������, ����������� �������� �� ����� ������� ��� ���
{
	bool flag = true;
	for (int i = 2; i <= N / 2; i++) {
		if ((N % i) == 0)
		// ������� ��������� ��������� ����� N �� ��� ����� �� ���������� "1<i<N"
		{
			flag = false;
			break;
		}
	}
	return flag;
}

std::vector <int> decomposition_simple_numbers(int number_2) {
	std::vector <int> arr;
	// ������ �� ������� �����
	while (!cheeck_simple_number(number_2))
	//���� ����� �� ������� ��������� ����
	{
		for (int i = 2; i <= number_2 / 2; i++) {
			if ((number_2 % i) == 0)
			{
				number_2 = number_2 / i;//���� ����� ������, �� ����� �� i
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
	// �����, �������������� �� ������� �����
	std::cout << "������� �����, ����� ��������� ��� �� ������������ ������� �����" << std::endl;
	std::cin >> number_2;
	if (check(abs(number_2))){
		std::vector <int> arr = decomposition_simple_numbers(abs(number_2));
		// �������, ������������ ������ ������� �����,���������� � ���� ����������
		if (number_2 < 0) {
			std::cout <<"-";
		} //���� ����� ������
		for (int i = 0; i < arr.size(); i++) {
		if (i != arr.size() - 1) {
			std::cout << arr[i] << "*";
		} else {
			std::cout << arr[i];
		}
	}//����� ������� ����� � ���� �� ������������
		arr.clear();
	}
	std::cout << std::endl << std::endl;
}

//---------------------Task3---------------------
//�������� ��������� ��� ������� ���������������� ��������� ������� ������.

double func(double x, double y) {
	return (y-pow(x,2));
	//���� �������
}

void Euler(double x0, double y, double h, double x) {
	//f(x, y) = dy / dx.
	//y(n+1) = y(n) + h * f(x(n),y(n))
	//h = (x(n) - x(0)) / n
	while (x0 < x) {
		y = y + h * func(x0, y);
		x0 = x0 + h;
	}
	std::cout << "������� ����������������� ��������� y-x^2, ��� x = " << x << " � �����  h = "<< h <<", �������� f(x, y) = " << y;
}

void Task3() {
	double x0 = 0; //��������� �������� x(n)
	double y0 = 1; //�������� ������� y(n)
	double h = 1; //���
	double x = 2; //��������, ��� ������� �� ���� ���� ������� f(x,y)
	Euler(x0, y0, h, x);
	std::cout << std::endl << std::endl;
}