//Chinmay Satpanthi (Professor Todd Gibson)
//CSCI 511
//Function Pointers.cpp

#include <iostream>

//Simple arithmetic functions 
float add(float a, float b)
{
	return a + b;
}

float subtract(float a, float b)
{
	return a - b;
}

float divide(float a, float b)
{
	return (a / b);
}

float multiply(float a, float b)
{
	return a * b;
}

//functions that will assign 4.14 to the element in the 3D array
void assign_pi_to_dyn_1D(float *var, int z)
{
	var[z] = 3.14;
}
void assign_pi_to_dyn_2D(float **var, int y, int z)
{
	var[y][z] = 3.14;
}

void assign_pi_to_dyn_3D(float ***var, int x, int y, int z)
{
	var[x][y][z] = 3.14;
}

//static version of assigning element to 3D array
void assign_pi_to_stat_3D(float var[][4][3], int x, int y, int z)
{
	var[x][y][z] = 3.14;
}


////////////////// MAIN /////////////////////

int main()
{
	///// GROUP ACTIVITY ////////////

	float (*array_pointer[4])(float, float);		//initialize arraoy of function pointers

	//assign the functions the pointer array
	array_pointer[0] = subtract;
	array_pointer[1] = add;
	array_pointer[2] = multiply;
	array_pointer[3] = divide;

	//print out each operator with values 7 and three using the pointer array
	for (int i = 0; i < 4; i++){
		std::cout << array_pointer[i](7,3) << std::endl; 
	}

	///////// PART 1 /////////////////

	int user_x;
	int user_y;
	int user_z;

	std::cout << "Enter X value: ";
	std::cin >> user_x;
	std::cout << std::endl;
	std::cout << "Enter Y value: ";
	std::cin >> user_y;
	std::cout << std::endl;
	std::cout << "Enter Z value: ";
	std::cin >> user_z;
	std::cout << std::endl;

	//User generated 3D array depending on what size is selected.	
	float *array1D = new float[user_z]; //z
	assign_pi_to_dyn_1D(array1D, user_z-1);

	float **array2D = new float *[user_y]; //y
	for (int y = 0; y < user_y; ++y)
		array2D[y] = new float[user_z]; //z

	float ***array3D = new float **[user_x]; //x
	for (int x = 0; x < user_x; ++x)
	{
		array3D[x] = new float *[user_y];
		for (int y = 0; y < user_y; ++y)
			array3D[x][y] = new float[user_z]; //z
	}

	assign_pi_to_dyn_2D(array2D, user_y-1, user_z-1);
	assign_pi_to_dyn_3D(array3D, user_x-1, user_y-1, user_z-1);

	//std::cout << "array3D =" << array3D << std::endl;
	std::cout << "array3D at any is = " << array3D[user_x-1][user_y-1][user_z-1] << std::endl;

	//alternative method of printing the statement above
	//std::cout << *(*(*(array3D + user_x - 1) + user_y - 1) + user_z - 1) << std::endl;

	//deallocates the memory
	delete[] array1D;
	delete[] array2D;
	delete[] array3D;

	/////////////// PART 2 //////////////

	//static array of [2][4][3]

	float static1D[3] = {1.1, 1.2, 1.3};
	float static2D[4][3] = {
		{1.1, 1.2, 1.3},
		{2.1, 2.2, 2.3},
		{3.1, 3.2, 3.3},
		{4.1, 4.2, 4.3}};

	float static3D[2][4][3] = {
		{{1.1, 1.2, 1.3},
		 {2.1, 2.2, 2.3},
		 {3.1, 3.2, 3.3},
		 {4.1, 4.2, 4.3}},
		{{5.1, 5.2, 5.3},
		 {6.1, 6.2, 6.3},
		 {7.1, 7.2, 7.3},
		 {8.1, 8.2, 8.3}}};


	//assign Pi to static array
	static3D[1][3][2] = 3.14;

	std::cout << "Static PI = " << static3D[1][3][2] << std::endl;
	assign_pi_to_stat_3D(static3D, 1, 3, 2);
	int x = 1;
	int y = 3;
	int z = 2;

	//std::cout << *((float *)static3D + 3 * 4 * x + 3 * y + z)  << std::endl;

	return 0;
}
