#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>

using namespace std;

class Employce
{
private:
	int Id;
	string Name;
	string Employee_type;
	int tm_day;
	int tm_month;
	int tm_year;
public:
	//Ham tao mac dinh
	Employce()
	{
		Id = 0;
		Name = "unlnow";
		Employee_type = "unknow";
		tm_day = 0;
		tm_month = 0;
		tm_year = 0;
	}

	//Ham tao 4 tham so
	Employce(int a, string b, string c, int d, int e, int f)
	{
		Id = a;
		Name = b;
		Employee_type = c;
		tm_day = d;
		tm_month = e;
		tm_year = f;
	}


};