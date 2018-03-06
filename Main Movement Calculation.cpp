#include <iostream>
#include <iomanip>
#include <math.h>
using std::cout;
using std::endl;
using std::setprecision;

#define PI 3.14159265

double move(double degrees);

int main()
{
	/*			|
	{-30,45}X	|
				|
	------------|-------------
				|
				|
				|
	{horizontal degrees, vertical degrees}


			 ___2___
		   1|		|3	
			|   /\	|
			|		|
			|		|
		   6|_______|4
			    5

	thrust would be negative for 3 and 6 while positive for 3 and 6 when turning. */
			
	for (int ii = -180; ii < 180; ii = ii + 5)
	{
		cout << "Horizontal Degrees = " << ii << " Thrusting " << setprecision(2) << move(ii) << " to side thrusters" << endl;
	}
	for (int jj = -180; jj < 180; jj = jj + 5)
	{
		cout << "Vertical Degrees = " << jj << " Thrusting " << move(jj) << " to vertical thrusters" << endl;
	}
	int target[2] = { -30,45 };
	cout << endl << "Force needed for {-30,45}:" << endl;
	cout << "Horizontal Degrees = " << target[0] << " Thrusting: [" << move(target[0]) << ", 0, " << -move(target[0]) << ", " << move(target[0]) << ", 0, " << -move(target[0]) << "]" << endl;
	cout << "Vertical Degrees = " << target[1] << " Thrusting: [0, " << move(target[1]) << ", 0, 0, " << move(target[1]) << ", 0]" << endl;

	return 0;
}
double move(double degrees)
{
	double thrust = (tan(degrees * (PI / 360)));

	if (thrust > 1)
		thrust = 1;
	if (thrust < -1)
		thrust = -1;

	return thrust;
}
