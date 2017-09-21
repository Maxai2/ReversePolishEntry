#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

void main()
{
	Stack<int> numbers(100);
	Stack<char> operators(100);

	string math = "4*3*3*3-6*7*5+6-6/3+5-2/2";

	int index = 0, ans = 0, temp = 0;
	char cTemp;

	while (math[index] != '\0')
	{
		if ((int)math[index] >= 49 && 57 >= (int)math[index])
			numbers.push((int)math[index] - 48);
        else
        {
            if (((int)operators.peek() == '*' || (int)operators.peek() == '/') && ((int)math[index] == '-' || (int)math[index] == '+'))
            {
				while (operators.peek() == '*' || operators.peek() == '/')
				{
					if ((int)operators.peek() == '*') // *
					{
						ans = numbers.pop();
						ans *= numbers.pop();
						operators.pop();
					}
					else
						if ((int)operators.peek() == '/') // /
						{
							ans = numbers.pop();
							temp = ans;
							ans = numbers.pop();
							ans /= temp;
							operators.pop();
						}				

					numbers.push(ans);
				}
			}
            operators.push(math[index]);
	   }

		index++;
	}

	for (int i = numbers.getCount() - 1; !operators.isEmpty(); i--)
	{
		if (operators.peek() == '+')
		{
			cTemp = operators.pop();
			if (operators.peek() == '-')
			{
				ans = numbers.pop();
				ans += -numbers.pop();
				if (ans > 0)
				{
					operators.pop();
					operators.push('+');
				}
				else
					ans = -ans;
				operators.push(cTemp);
			}
			else
			{
				operators.push(cTemp);
				ans = numbers.pop();
				ans += numbers.pop();
			}
		}
		else
			if (operators.peek() == '-')
			{
				cTemp = operators.pop();
				if (operators.peek() == '-')
				{
					ans = numbers.pop();
					ans -= -numbers.pop();
					operators.push(cTemp);
				}
				else
				{
					operators.push(cTemp);
					ans = numbers.pop();
					temp = ans;
					ans = numbers.pop();					
					temp < 0 ? ans += temp : ans -= temp;
				}
			}
			else
			if (operators.peek() == '*')
			{
				ans = numbers.pop();
				ans *= numbers.pop();
			}
			else
			if (operators.peek() == '/')
			{
				ans = numbers.pop();
				ans /= numbers.pop();
			}

		operators.pop();
		numbers.push(ans);
	}

	//	printf("%s = %i\n", math, numbers.peek());
	cout << math << " = " << numbers.peek() << endl;
}
