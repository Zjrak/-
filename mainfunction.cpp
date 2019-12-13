#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>

using namespace std;
const int MAXNUM = 100;
#define random(a,b) (((double)rand()/RAND_MAX)*(b-a)+a) //生成范围 （a,b）的随机数
double *creat_rand(int a, int b, int num); //定义函数 生成 int 范围（a,b）个数为 MAXNUM 的随机数
double **creat_z_rand(int a, double b, int num); //定义函数 生成 int 范围（a,b）个数为 MAXNUM 的随机数
double get_max_num(double **a); //定义函数 得到值域内的最大值
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
	double * x_num_rand; //生成x随机数组
	double * y_num_rand; //生成y随机数组
	double ** z_num_rand = new double *[MAXNUM]; //定义z 关于x y 得到的函数值
	double ** z_temp_rand = new double *[MAXNUM];

	x_num_rand = creat_rand(x_a, x_b, MAXNUM); //生成在 x_a x_b 的随机数
	y_num_rand = creat_rand(y_a, y_b, MAXNUM);

	for (int i = 0; i < MAXNUM; ++i)
	{
		z_num_rand[i] = new double[MAXNUM];
		for (int j = 0; j < MAXNUM; ++j)
			z_num_rand[i][j] = 4 * x_num_rand[i] + y_num_rand[j] * 3;  //定义函数 为 z=4*x*x+3*y;
		//4 * x_num_rand[i] * x_num_rand[i] + y_num_rand[j] * 3;

	} //生成 函数值 z 函数以 x y 为自变量 
	temp_MAX_z = get_max_num(z_num_rand) + 5; //得到 z 二维数组的最大值 + 5赋值给temp_MAX_z
	z_temp_rand = creat_z_rand(0, temp_MAX_z, MAXNUM);
	// 在 （0，temp_MAX_z）范围内取随机数，得到二维数组，赋值给z_temp_rand
	number = count_num(z_num_rand,z_temp_rand); //比较 两个二维数组 返回术语积分范围的数字的个数赋值给number
	integration = (x_b - x_a) * (y_b - y_a) * temp_MAX_z *(double(number) / (MAXNUM * MAXNUM));//计算积分
	/*********************************************************/
	//以下为测试内容，函数返回值是否正确
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
	//删除 z_num_rand 的堆空间
	for (int i = 0; i < MAXNUM; ++i)
		delete[] z_temp_rand[i];
	delete z_temp_rand;
	//删除 z_temp_rand 的二维 堆空间
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