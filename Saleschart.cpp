//Michaelangelo Bullard 
//Lab1out
//program that process a set of sale data onto a chart 


#include<iostream>
#include"graph1.h"

using namespace std; 

//function prototypes 
int getNoMonths(); 
void getSales(int[], int);
int getMax(int[], int); 
int getMin(int[], int);
double getAverage(int [], int); 
void displayResults(int[], int, int, int, double);  

//const varible for array 
const int MaxMonths = 6; 


int main() {

	// variables 
	int no_months, max, min; 
	double avg; 
	int sales[MaxMonths] = { 0 }; 
	
	

	//calling functions 
	no_months = getNoMonths(); 
	getSales( sales, no_months); 
	max = getMax(sales, no_months); 
	min = getMin(sales, no_months);
	avg = getAverage(sales, no_months); 
	displayResults(sales,no_months, max, min,  avg);


	
	

}


//function to get number of months 
int getNoMonths() {

	int no_months = 0; 

	do {
		cout << "Enter number of  months to process: <between 3 and 6 inclusive>: "; 
		cin >> no_months; 

	} while (no_months < 3 || no_months >  6); 
	cout << endl; 

	return no_months; 
}

//function to prompt user for the sale data 
void getSales(int sales[], int no_months) {

	int i; 

	for (i = 0; i < no_months; i++) {

		do {
			cout << "Enter sales for month #" << i + 1 << ": ";
			cin >> sales[i]; 

			/*if (sales[i] == 0) {
				sales[i]=1; 
			}*/
	  
		} while (sales[i] < 0); 


	}
}

//function to determine the maxium value 
int getMax(int sales[], int no_months) {

	int i; 
	int max = 0; 


	for (i = 0; i < no_months; i++) {
		if (sales[i] > max) {
			max = 0; 
			max += sales [i]; 
		}
	}

	return max; 
}



//function to determine the min value 
int getMin(int sales[], int no_months) {

	int i;
	int min = sales[1]; 


	for (i = 0; i < no_months; i++) {
		if (sales[i] < min) {
			min = 0;
			min += sales[i];
		}
	}

	return min;
}

//function to calculate the average 
double getAverage(int sales[], int no_months) {
	int i; 
	double total = 0; 
	double average = 0; 
	for (i = 0; i < no_months; i++) {
		total += sales[i]; 

	}

	average = (total / no_months); 

	return average; 
}

//function to display to results 
void displayResults(int sales[], int no_months, int max, int min, double avg) {
	

	displayGraphics(); 

	displayBMP("sales1.bmp", 250, 25);

	gout << setPos(375, 66) << setColor(0, 255, 0) << "Sales for " << no_months << " months"
		<< setPrecision(2) << endg;

	gout << setPos(200, 335) << setColor(0, 255, 0) << "Sales Statistics " 
		<< setPrecision(2) << endg;

	gout << setPos(205, 380) << setColor(0, 255, 0) << "Max Sales: $" << max  << 
		setPrecision(2) << endg;

	gout << setPos(205, 400) << setColor(0, 255, 0) << "Min Sales: $" << min <<
		setPrecision(2) << endg;

	gout << setPos(205, 420) << setColor(0, 255, 0) << "Avg Sales: $" << (int)avg <<
		setPrecision(2) << endg;

	gout << setPos(355, 290) << setColor(0, 255, 0) << "Months" <<
		setPrecision(2) << endg;

	gout << setPos(135, 220) << setColor(0, 255, 0) << "Monthly" <<
		setPrecision(2) << endg;
	gout << setPos(138, 230) << setColor(0, 255, 0) << "Sales" <<
		setPrecision(2) << endg;
	
	 
	
	drawLine(200, 150, 200, 280, 1); 
	drawLine(200, 280, 700, 280, 1);

	//for rectangle box 
	drawLine(200, 345, 400, 345 ,1);
	drawLine(200, 345, 200, 450, 1);
	drawLine(400, 450, 400, 345, 1);
	drawLine(200, 450, 400, 450, 1);


	// for loop for chart rectangles
	int i = 0; 
	int height; 
	int xaxis = 200;
	int yaxis[MaxMonths] = {0};

	for (i = 0; i < no_months; i++) {
		height = 1; 
		height = ((double)sales[i] / max) * 100.0 *-1; 
		if (sales[i] == 0) {
			height= 1;
		}
		yaxis[i] += 280 + height;
		int obj_no = drawRect(xaxis, 280, 50, height );

		// switch statement to change bar for different months 
		switch (i) {
		case 0:gout << setPos(xaxis, yaxis[i] ) << setColor(0, 255, 0) << "Jan" <<
			setPrecision(2) << endg;
			setColor(obj_no, 255, 0, 0);
			break;

		case 1: gout << setPos(xaxis, yaxis[i]) << setColor(0, 255, 0) << "Feb" <<
			setPrecision(2) << endg;
			setColor(obj_no, 0, 255, 0);
			break;

		case 2:gout << setPos(xaxis, yaxis[i]) << setColor(0, 255, 0) << "Mar" <<
			setPrecision(2) << endg;
			setColor(obj_no, 0, 0, 255);
			break;

		case 3: gout << setPos(xaxis, yaxis[i]) << setColor(0, 255, 0) << "Apr" <<
			setPrecision(2) << endg;
			setColor(obj_no, 255, 255, 0);
			break;
		case 4: gout << setPos(xaxis, yaxis[i]) << setColor(0, 255, 0) << "May" <<
			setPrecision(2) << endg;
			setColor(obj_no, 255, 0, 255);
			break;

		case 5: gout << setPos(xaxis, yaxis[i]) << setColor(0, 255, 0) << "Jun" <<
			setPrecision(2) << endg;
			setColor(obj_no, 0, 255, 255);
			break;
		}
		xaxis+=75; 
		
		
	
	}
	

	
}
