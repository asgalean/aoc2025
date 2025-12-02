#include <stdio.h>
#include <stdlib.h>

//67494362633  - too high
//49046150754 - swet spot
//el cambio de art1 a part2 es el num_cpr,, la logiac cambia
//para el part2, hacemos que busque gruposde numeros, de tamaño 1 hasta len/2 y ver si hay un patron


int num_cpr(char number[50])
{

	int repeats = 1;

	int len = 0;
	char sequence[25];
	
	
	while (number[len] != '\0')
		len++;
		
		
	int sequence_len = 1;
	
	while (sequence_len <= len/2)
	{
	
		if (len%sequence_len != 0)
		{
			sequence_len++;
			continue;
		}
	
	
		int i=0;
		repeats = 1;
		while (i < sequence_len) //guardamos la secuencia en cada paso (primero tamaño 1, luego 2, etc)
		{
			sequence[i] = number[i];
			i++;
		}
		sequence[i] = '\0';
		
		
		i=0;
		while (number[i] != '\0') //recorremos number, checkeando que coincida modularmente con la secuencia
		{
			if (number[i] != sequence[i%sequence_len])
			{
				repeats = 0;
				break;
			}
			i++;
		}
		if (repeats)
			return (623);
		sequence_len++;
	}
	
	return (0);

}

int main()
{

	char *input = "3737332285-3737422568,5858547751-5858626020,166911-236630,15329757-15423690,753995-801224,1-20,2180484-2259220,24-47,73630108-73867501,4052222-4199117,9226851880-9226945212,7337-24735,555454-591466,7777695646-7777817695,1070-2489,81504542-81618752,2584-6199,8857860-8922218,979959461-980003045,49-128,109907-161935,53514821-53703445,362278-509285,151-286,625491-681593,7715704912-7715863357,29210-60779,3287787-3395869,501-921,979760-1021259";

	//char *input = "11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124";

	int i = 0;
	
	long min;
	long max;
	
	long total = 0;
	char number[50];
	while (input[i] != '\0')
	{
		if (i != 0)
			i++;
		min = atol(&input[i]); 	//coge el min
		while (input[i] != '-')	//recorre el primer numero
			i++;				
		i++;					//uno mas ara pillar el numero siguiente
		max = atol(&input[i]);	//coge el max
		
		while (min <= max)		//recorre cada numero del rango y hace el checkeo
		{
			
			sprintf(number, "%ld", min);
			
			if (num_cpr(number))
				total+=atol(number);
			
			min++;
		}
		
		while (input[i] != ',' && input[i] != '\0') // recorre le segundo numero
			i++;
		
	}
	
	printf("%ld\n", total);

}
