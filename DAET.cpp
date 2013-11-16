/*
 * Copyright (C) 2012-2013, Ayysir
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib> // needed for system() function
#include <iomanip>

using namespace std;

//Making code look better
void delay();
void frame(int n,char ch);
void AL(); // Archlinux
void UB(); // Ubuntu
void UPD(); //Update script
void extras(); // Misc. Options

int main()
{
	//Colors
    char red[] = "\033[31m ";  //red
    char blue[] = "\033[34m "; //blue
    char white[] = "\033[0m"; // default terminal
    char bold [] =  "\033[1m"; // bold text  

    char distro, repeat;
    system("clear"); 


cout << red << bold << "Main Menu" << white << endl;
frame(20,'-'); // TODO: need to fix alignment
cout << "a. Archlinux Setup" << endl;
cout << "u. Ubuntu Setup" << endl;
cout << "n. Update Scripts" << endl;
cout << "Enter your choice ";
cin >> distro;

// A bit hacky since Using multiple switch..case statments in one program file is a no no
	if (distro == 'a' || distro == 'A'){
	  AL();
	} else if (distro == 'u' || distro == 'U'){
	  UB();
	} else if (distro == 'n' || distro == 'N'){
	  UPD();
	} else 
	
	
	do
	{
		cout << "Invalid response, please re-enter choice\n" << endl;
		delay();
		cout << "Enter your choice ";
		cin >> distro;
		cout << endl;	
	} while (distro == 'a' && distro == 'A' && distro == 'u' && distro == 'U' && distro == 'N' && distro == 'n' ); 

	return 0;
}

void UB()
{
	//Colors
	char red[] = "\033[31m ";  //red
        char blue[] = "\033[34m "; //blue
        char white[] = "\033[0m"; // default terminal
        char bold [] =  "\033[1m"; // bold text  
	int choice;

 do
 {
 	system("clear"); 
 	cout << red << bold << "Distro Android Environment Tool for Ubuntu" << white << endl;
        frame(28,'-'); // TODO: need to fix alignment
	cout << "1. Install Dependencies" << endl;
	cout << "2. Ubuntu 11.10 users" << endl;
	cout << "3. Install Android SDK" << endl;
	cout << "4. Install Android NDK" << endl;
	cout << "5. Install Android Debug Bridge (ADB)" << endl;
	cout << "6. Install 1-5" << endl;
	cout << "7. Fix mtp for Ubuntu 12.04" << endl;
	cout << "8. More" << endl;
	cout << "0. Exit\n" << endl;
	cout << "Enter Choice: ";
	cin >> choice;

	switch (choice)
	{
		case 0:
	        system("clear"); 
		delay();
		exit(0);

		case 1:
		system("/bin/bash -c ./scripts/Dependencies &");

		case 2:
		system("/bin/bash -c ./scripts/11_10 &");

		case 3:
		system("/bin/bash -c ./scripts/NDK &");	
		
		case 4:
		system("/bin/bash -c ./scripts/SDK &");	

		case 5:
		system("/bin/bash -c ./scripts/ADB &");			
		
		case 6:
		system("/bin/bash -c ./scripts/Dependencies &");
		delay();
		system("/bin/bash -c ./scripts/11_10 &");
		delay();
		system("/bin/bash -c ./scripts/NDK &");	
		delay();
		system("/bin/bash -c ./scripts/SDK &");	
		delay();
		system("/bin/bash -c ./scripts/ADB &");		

		case 7:


		case 8:
		delay();
		extras();				

		default:
		cout << "Choice " << choice << " is not valid, please choose again\n " << endl;

	do
	{
		cout << "Invalid response, please re-enter choice\n" << endl;
		delay();
		cout << "Enter your choice ";
		cin >> choice;
		cout << endl;	
	} while (choice >= 9); 

	}
 } while (choice >= 9 );

}


void AL()
{
        system("clear"); 
	char arch_choice;	
	char red[] = "\033[31m ";  //red
        char blue[] = "\033[34m "; //blue
        char white[] = "\033[0m"; // default terminal
        char bold [] =  "\033[1m"; // bold text  

 	cout << red << bold << "Distro Android Environment Tool for Archlinux" << white << endl;
        frame(28,'-'); // TODO: need to fix alignment
	cout << "a. Install Dependencies" << endl;
	cout << "b. Install Android SDK" << endl;
	cout << "c. Install Android Debug Bridge (ADB)" << endl;
	cout << "d. Install 1-3" << endl;
	cout << "m. Main Menu" << endl;
	cout << "e. Exit\n" << endl;
	cout << "Enter Choice: ";
	cin >> arch_choice;
   
   switch (arch_choice)
   {
		case 'e':
	    system("clear"); 
		delay();
		exit(0);

		case 'm':
		delay();
		main();

		case 'a':
		system("/bin/bash -c ./scripts/arch_Dependencies &");

		case 'b':
		system("/bin/bash -c ./scripts/SDK &");	

		case 'c':

		
		case 'd':
		system("/bin/bash -c ./scripts/Dependencies &");
		delay();
		system("/bin/bash -c ./scripts/SDK &");	
		delay();
		system("/bin/bash -c ./scripts/11_10 &");
					



		default:
		cout << "Choice " << arch_choice << " is not valid, please choose again\n " << endl;

	}
}


void UPD()
{
	return;
}

void extras()
{
	return;
}

void delay() // researched and read up about nano sleep, in unix it allows programmer to set a accurate sleep function. Just for kicks and giggles
{
    int milisec = 300; // length of time to sleep, in miliseconds
    struct timespec req = {0};
    req.tv_sec = 0;
    req.tv_nsec = milisec * 1000000L;
    nanosleep(&req, (struct timespec *)NULL);
}

void frame(int n,char ch)
{    
  
        cout << "   ";  // bottom border indent 
        for(int i=0; i<n ;i++)   
            cout << ch; 
            cout << endl;  
}
