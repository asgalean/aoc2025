#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct s_box
{
	double x;
	double y;
	double z;
	int  circuit;
} t_box;


double dist(t_box array, int a, int b)
{
	
	return (sqrt((array[a].x - array[b].x)*(array[a].x - array[b].x)
			+ (array[a].y - array[b].y)*(array[a].y - array[b].y)
			+ (array[a].z - array[b].z)*(array[a].z - array[b].z));

}



int main()
{

	char *input = "162,817,812;57,618,57;906,360,560;592,479,940;352,342,300;466,668,158;542,29,236;431,825,988;739,650,466;52,470,668;216,146,977;819,987,18;117,168,530;805,96,715;346,949,466;970,615,88;941,993,340;862,61,35;984,92,344;425,690,689";
	
	//char *input = "";

	int i = 0;
	int box_ammount = 0;
	int pair_ammount = 10;
	while (input[i] != '\0')
	{
		if (input[i] == ';')
			box_ammount++;
		i++;
	}
	box_ammount++;
	t_box array[box_ammount];
	
	
	i = 0;
	
	int arr_pos = 0;
	//Parseo
	while (input[i] != '\0')
	{
		if (arr_pos != 0)
			i++;
		array[arr_pos].x = atol(&input[i]);
		while (input[i] != ',')
			i++;
		i++;
		array[arr_pos].y = atol(&input[i]);
		while (input[i] != ',')
			i++;
		i++;
		array[arr_pos].z = atol(&input[i]);
		while(input[i] != ';' && input[i] != '\0')
			i++;
		array[arr_pos].circuit = 0;
		
		arr_pos++;
	}
	
	
	//printeo del array
	i = 0;
	while (i < box_ammount)
	{
		printf("Box %d:\t(%ld,%ld,%ld)\t--> Circuit %d\n", i, array[i].x, array[i].y, array[i].z, array[i].circuit);
		i++;
	}
	
	

	int a = 0;
	int b = 0;
	int j = 0;
	while (j < pair ammount)
	{
		double temp_dist = 1000000;
		int temp_box1 = -1;
		int temp_box2 = -1;
		a = 0;
		while (a < box_ammount) //para encontrar la distancia mas corta
		{
			b = a + 1;
			while (b < box_ammount)
			{
				if (dist(array,a,b) <= temp_dist && (array[a].circuit != array[b].circuit || array[a].circuit == 0 || array[b].circuit == 0))
				{
					temp_dist = dist(array,a,b);
					temp_box1 = a;
					temp_box2 = b;
				}
				b++;
			}
			a++;
		}
		if (array[a].circuit == 0 && array[b].circuit == 0) //ninguno enlazado
		{
			array[a].circuit == j;
			array[b].circuit == j;
		}
		else if (array[a].circuit != 0 && array[b] == 0)	//a enlazado y b no
			array[b].circuit == array[a].circuit;
		else if (array[b].circuit != 0 && array[a] == 0)	//b enlazado y a no
			array[a].circuit == array[b].circuit;
		else if (array[a].circuit != 0)		//si a y b estan conectados, pero no entre si
		{									//transformamos todo el circuito de b al circuito de a
			int w = 0;
			
			while (w < box_ammount)
			{
				if (w != b && array[w].circuit == array[b].circuit)
					array[w].circuit = array[a].circuit;
				w++;
			}
			array[b].circuit = array[a].circuit;
		}
		j++;
	}
	
	
	
	
	
	
}

