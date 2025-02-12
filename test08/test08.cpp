#include<iostream>
#include<string>
using namespace std;

struct Process{
	string process;
	bool notChecked;
	int Aa, Ba, Ca;
	int Am, Bm, Cm;
};

int available[3];
int Need[5][3];
Process p[5];
string SafeSequence = "";

void input()
{
	cout << "Enter the A B C for available: ";
	cin >> available[0] >> available[1] >> available[2];

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter A B C for allocation of P" << i << ": " << endl;
		cin >> p[i].Aa >> p[i].Ba >> p[i].Ca;
		p[i].process = "P" + to_string(i);
		p[i].notChecked = true;

		cout << "Enter A B C for maximum of P" << i << ": " << endl;
		cin >> p[i].Am >> p[i].Bm >> p[i].Cm;

		Need[i][0] = p[i].Am - p[i].Aa;
		Need[i][1] = p[i].Bm - p[i].Ba;
		Need[i][2] = p[i].Cm - p[i].Ca;
	}
}

void calculation()
{
	int temp;
	int count1 = 0;

	while (count1 < 5)
	{
		temp = 0;

		for (int i = 0; i < 5; i++)
		{
			bool condition1 = Need[i][0] <= available[0];
			bool condition2 = Need[i][1] <= available[1];
			bool condition3 = Need[i][2] <= available[2];
			bool AllConditions = condition1 && condition2 && condition3;

			if (AllConditions && p[i].notChecked)
			{
				available[0] += p[i].Aa;
				available[1] += p[i].Ba;
				available[2] += p[i].Ca;

				SafeSequence += p[i].process + " ";
				p[i].notChecked = false;
				count1++;
				temp++;
			}
		}

		if (temp == 0)
			break;
	}

	if (temp == 0)
		cout << "Dead Lock exists in the sequence.";
	else
		cout << "Safe Sequence: " << SafeSequence << endl;

}


int main()
{
	input();
	calculation();

	system("pause>0");
	return 0;
}