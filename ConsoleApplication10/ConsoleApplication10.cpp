#include <string>
#include <iostream>
#include <vector>     // vector
#include <algorithm>

using namespace std;

struct entrant
{
	string FullName;
	double mark;
	double mark2;
	double mark3;
	double mark4;
	double averageMark;
};


int main()
{
	setlocale(LC_ALL, "rus");

	const int size = 4;


	double PassingScore = 0;

	entrant students[size];

	students[0] = { "Nochevny Maksin Yurievich", 5,2,3,5 };
	students[1] = { "Lorin Ivan Nagievich", 2,3,2,5 };
	students[2] = { "Lazarev Nikita Sergeevich", 4,5,5,5 };
	students[3] = { "Voron Nikita Gordeevich", 2,3,5,3 };

	for (int i = 0; i < size; i++)
	{
		students[i].averageMark = (students[i].mark + students[i].mark2 + students[i].mark3 + students[i].mark4) / 4;
		PassingScore += students[i].averageMark;
	}

	PassingScore /= 4;
	cout << "Проходной балл:" << PassingScore;
	cout << endl;


	entrant temp;

	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
		{
			if (students[i].averageMark < students[i + 1].averageMark)
			{

				temp = students[i];
				students[i] = students[i + 1];
				students[i + 1] = temp;

			}
		}
	}


	for (int i = 0; i < size; i++)
	{
		if (students[i].averageMark > PassingScore)
			cout << "ФИО: " << students[i].FullName << "\tБалл: " << students[i].averageMark << endl;
	}

	cout << "-----------------" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "ФИО: " << students[i].FullName << "\tБалл: " << students[i].averageMark << endl;
	}


	system("pause");
	return 0;
}