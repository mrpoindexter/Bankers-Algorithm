#include<iostream>
#include<string>
using namespace std;

struct Process{
	string process;
	bool notChecked;
	int Aa, Ba, Ca;
	int Am, Bm, Cm;
};

void BankersAlgorithm()
{
	string SafeSequence = "";
	int count = 0;
	int iterator;
	int temp;

	int numberOfProcess;
	cout << "Enter the number of process: ";
	cin >> numberOfProcess;

	int* available = new int[3];
	Process* p = new Process[numberOfProcess];
	
	int** Need = new int* [numberOfProcess];
	for (int i = 0; i < numberOfProcess; i++)
	{
		Need[i] = new int[3];
	}

	int** Work = new int* [numberOfProcess];
	for (int i = 0; i < numberOfProcess; i++)
	{
		Work[i] = new int[3];
	}

	cout << "Enter the A B C for available: ";
	cin >> available[0] >> available[1] >> available[2];

	Work[0][0] = available[0];
	Work[0][1] = available[1];
	Work[0][2] = available[2];

	for (int i = 0; i < numberOfProcess; i++)
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

	iterator = 1;

	while (count < numberOfProcess)
	{
		temp = 0;

		for (int i = 0; i < numberOfProcess; i++)
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

				if (iterator < numberOfProcess)
				{
					Work[iterator][0] = available[0];
					Work[iterator][1] = available[1];
					Work[iterator][2] = available[2];
					iterator++;
				}

				SafeSequence += p[i].process + " ";
				p[i].notChecked = false;
				count++;
				temp++;
			}
		}

		if (temp == 0)
			break;
	}

	cout << endl << "Process \t Allocation \t Max \t Available(Work) \t Need" << endl;
	for (int i = 0; i < numberOfProcess; i++)
	{
		cout << p[i].process << "   \t\t" << p[i].Aa << " " <<
			p[i].Ba << " " << p[i].Ca << "\t\t" << p[i].Am << " " <<
			p[i].Bm << " " << p[i].Cm << "\t\t" << Work[i][0] << " " <<
			Work[i][1] << " " << Work[i][2] << "\t\t" << Need[i][0] << " "
			<< Need[i][1] << " " << Need[i][2] << endl;
	}

	if (temp == 0 && count < numberOfProcess)
		cout << endl << "Dead Lock exists in the sequence.";
	else
		cout << endl << "Safe Sequence: " << SafeSequence << endl;

	for (int i = 0; i < numberOfProcess; i++) 
	{
		delete[] Need[i];
	}
	for (int i = 0; i < numberOfProcess; i++) {
		delete[] Work[i];
	}
	delete[] Work;
	delete[] Need;
	delete[] available;
	delete[] p;
}

int main()
{
	BankersAlgorithm();
	system("pause>0");
	return 0;
}