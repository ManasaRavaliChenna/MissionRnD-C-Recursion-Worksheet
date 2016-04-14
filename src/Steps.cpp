/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"

int calculate_steps(int steps, int noOfTwos,int noOfWays);
int factorial(int number);
int get_steps(int s)
{
	if (s <= 0)
		return 0;
	else
		return (calculate_steps(s, 1, 0) + 1);
}
int calculate_steps(int steps, int noOfTwos, int noOfWays)
{
	if (steps / 2 == noOfTwos)
		if (noOfTwos * 2 == steps)
			//+1 for arranging 2s
			return noOfWays+1;
		else
			//all the arrangements except 1,2,2,2,2.. are calculated till here
			//so we add no. of ways to arrange 1 is no.of twos+1
		{
			int p = (noOfWays + noOfTwos + 1);
			return (noOfWays + noOfTwos + 1);
		}

	else
	{
		int rem = steps - noOfTwos;
		return calculate_steps(steps, noOfTwos + 1, noOfWays + (factorial(rem) / (factorial(noOfTwos)*factorial(rem - noOfTwos))));
	}
}
int factorial(int n)
{
	if (n == 0)
		return 0;
	else
		return n*factorial(n - 1);
}