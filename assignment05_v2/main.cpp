/*************************************
Jason Davis
July 18, 2016
CS 161
Assignment 5: Mersenne Primes
Write a C++ program to calculate...
and display all the Mersenne primes..
from 2 through 1,000,000.
Sources: Textbook, Class Documents, Internet Resources
*************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

 // Function protypes
bool isPrime(unsigned long long n);
unsigned long long power2(unsigned long long n);

int  main()
{
	// Variable declaration
	unsigned long long i = 1;
	unsigned long long n = 1;

	// Title + column header formatting 
	cout << "Mersenne Primes by Jason Davis" << "\n\n";
	cout << setw(2) << left << "n" << setw(25) << right << "Mersenne Prime" << "\n";
	cout << setw(2) << left << "==" << setw(25) << right << "==============" << "\n\n";
	cout << setfill(' ');

	// For loop + If logic to identify and output Mersenne Primes
	if (isPrime(n) == 1) {
		for (n = 2; n <= 1000; n++)
		{
			i = power2(n) - 1;
			if (isPrime(n) == 1) {
				cout << setw(2) << left << n << setw(25) << right << i << "\n";
			}
		}
		
	}



	cout << "\n\n";
	// Pause console for output review
	system("pause");
}

// Function to identify and output prime numbers
// Returns true if n is a prime, else false
bool isPrime(unsigned long long n) {

	if (n < 2) return false;
	if (n == 2) return true;
	if (n == 11) return false;
	if (n % 2 == 0) return false;
	for (int i = 3; (i*i) <= n; i += 2){
		if (n % i == 0) return false;
	}
	return true;
}

// Power function to determine Mersenne Prime above
// Returns 2 raised to the power of n.
unsigned long long power2(unsigned long long n)
{
	if (n == 0)
		return 1;

	if (n == 1)
		return 2;

	return 2 * power2(n - 1);
}