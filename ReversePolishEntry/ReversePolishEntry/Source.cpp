#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

void main()
{
	Stack<int> numbers(100);
	Stack<char> operators(100);

	string math = "3*3+4-6-1";

	int index = 0, ans = 0, temp = 0;

	while (math[index] != '\0')
	{
		if ((int)math[index] >= 49 && 57 >= (int)math[index])
			numbers.push((int)math[index] - 48);
		else
		{
			if (((int)operators.peek() == 42 || (int)operators.peek() == 47) && ((int)math[index] == 43 || (int)math[index] == 45))
			{
				if ((int)operators.peek() == 42) // *
				{
					ans = numbers.pop();
					ans *= numbers.pop();
					operators.pop();
				}
				else
				if ((int)operators.peek() == 47) // /
				{
					ans = numbers.pop();
					ans /= numbers.pop();
					operators.pop();
				}

				numbers.push(ans);
			}
			operators.push(math[index]);
		}

		index++;
	}

	for (int i = numbers.getCount() - 1; !operators.isEmpty(); i--)
	{
		if (operators.peek() == '+')
		{
			ans = numbers.pop();
			ans += numbers.pop();
			operators.pop();
		}
		else
		if (operators.peek() == '-')
		{
			ans = numbers.pop();
			temp = ans;
			ans = numbers.pop();
			ans -= temp;
			operators.pop();
		}

		numbers.push(ans);
	}

//	printf("%s = %i\n", math, numbers.peek());
	cout << math << " = " << numbers.peek() << endl;
}