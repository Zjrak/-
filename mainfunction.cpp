#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>

using namespace std;
const int MAXNUM = 100;
#define random(a,b) (((double)rand()/RAND_MAX)*(b-a)+a) //���ɷ�Χ ��a,b���������
double *creat_rand(int a, int b, int num); //���庯�� ���� int ��Χ��a,b������Ϊ MAXNUM �������
double **creat_z_rand(int a, double b, int num); //���庯�� ���� int ��Χ��a,b������Ϊ MAXNUM �������
double get_max_num(double **a); //���庯�� �õ�ֵ���ڵ����ֵ
int count_num(double **a, double **b);

int main()
{
	int x_a, x_b;
	int y_a, y_b;
	double temp_MAX_z;
	int number = 0;
	double integration = 0;
	cout << "enter x range\n";
	cin >> x_a >> x_b;
	cout << "enter y rang\n";
	cin >> y_a >> y_b;
	double * x_num_rand; //����x�������
	double * y_num_rand; //����y�������
	double ** z_num_rand = new double *[MAXNUM]; //����z ����x y �õ��ĺ���ֵ
	double ** z_temp_rand = new double *[MAXNUM];

	x_num_rand = creat_rand(x_a, x_b, MAXNUM); //������ x_a x_b �������
	y_num_rand = creat_rand(y_a, y_b, MAXNUM);

	for (int i = 0; i < MAXNUM; ++i)
	{
		z_num_rand[i] = new double[MAXNUM];
		for (int j = 0; j < MAXNUM; ++j)
			z_num_rand[i][j] = 4 * x_num_rand[i] + y_num_rand[j] * 3;  //���庯�� Ϊ z=4*x*x+3*y;
		//4 * x_num_rand[i] * x_num_rand[i] + y_num_rand[j] * 3;

	} //���� ����ֵ z ������ x y Ϊ�Ա��� 
	temp_MAX_z = get_max_num(z_num_rand) + 5; //�õ� z ��ά��������ֵ + 5��ֵ��temp_MAX_z
	z_temp_rand = creat_z_rand(0, temp_MAX_z, MAXNUM);
	// �� ��0��temp_MAX_z����Χ��ȡ��������õ���ά���飬��ֵ��z_temp_rand
	number = count_num(z_num_rand,z_temp_rand); //�Ƚ� ������ά���� ����������ַ�Χ�����ֵĸ�����ֵ��number
	integration = (x_b - x_a) * (y_b - y_a) * temp_MAX_z *(double(number) / (MAXNUM * MAXNUM));//�������
	/*********************************************************/
	//����Ϊ�������ݣ���������ֵ�Ƿ���ȷ
	/*for (int i = 0; i < MAXNUM; ++i)
	{
		cout << x_num_rand[i] << " \t ";
	}
	cout << endl;
	for (int i = 0; i < MAXNUM; ++i)
	{
		cout << y_num_rand[i] << " \t ";
	}
	cout << endl;
	for (int i = 0; i < MAXNUM; ++i)
	{
		for (int j = 0; j < MAXNUM; ++j)
			cout << z_num_rand[i][j] << " \t ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < MAXNUM; ++i)
	{
		for (int j = 0; j < MAXNUM; ++j)
			cout << z_temp_rand[i][j] << " \t ";
		cout << endl;
	}
	cout << endl;*/
	/************************************************************/
	cout << number<<endl;
	cout << temp_MAX_z;
	cout << endl << integration;
	for (int i = 0; i < MAXNUM; ++i)
		delete[] z_num_rand[i];
	delete z_num_rand;
	//ɾ�� z_num_rand �Ķѿռ�
	for (int i = 0; i < MAXNUM; ++i)
		delete[] z_temp_rand[i];
	delete z_temp_rand;
	//ɾ�� z_temp_rand �Ķ�ά �ѿռ�
	delete[] y_num_rand;
	delete[] x_num_rand;
}

double *creat_rand(int a, int b, int MAXNUM)
{
	srand((int)time(0));
	double *num_rand = new double [MAXNUM];
	for (int i = 0; i < MAXNUM; ++i)
		num_rand[i] = random(a, b);
	return num_rand;

}
double **creat_z_rand(int a, double b, int MAXNUM)
{
	srand((int)time(0));
	double **num_rand = new double * [MAXNUM];
	for (int i = 0; i < MAXNUM; ++i)
	{
		num_rand[i] = new double[MAXNUM];
		for (int j = 0; j < MAXNUM; ++j)
			num_rand[i][j] = random(a, b);
	}
	return num_rand;

}

double get_max_num(double **a)
{
	double temp = 0;
                temp = a[0][0]
	for (int i = 0; i < MAXNUM; ++i)
	{
		for (int j = 0; j < MAXNUM; ++j)
		{
			if (a[i][j] > a[i][j])
			    temp = a[i][j];
		}

	}
	return temp;
}
int count_num(double **a, double **b)
{
	int count = 0;
	for (int i = 0; i < MAXNUM; ++i)
	{
		for (int j = 0; j < MAXNUM; ++j)
			if (a[i][j] > b[i][j])
				++count;
	}
	return count;
}