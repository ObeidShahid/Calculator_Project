#include "Calculations.h"

//1. Declerations Section
//Variables
double Value;
unsigned char input;
unsigned char input2;
unsigned char input3;
char TString[50];
double SumArray[100];
char SignArray[100];
double MultipleArray[100];
double DivideArray[100];
int i;
int j;
int k;
int l;
int m;
double Total_Value;
double F_Value;
int value_change_flag;

//Function Prototypes
void Reset_Calc(void);
double Get_Value(void);
void Calculations(void);


//2. Function Declerations
void Calculations(void){	
	switch(input2){
					case 'A':						//'+' Operation	
					printf("\n Case = A Operand = + ||\n");
					F_Value = Get_Value();				//Get_Value into Temporary variable					
					SumArray[i] = F_Value;				//Save value in SumArray at position i
					SignArray[i] = '+';						//Save operator value in SignArray in position i
					printf("\n value_change_flag = %d\n",value_change_flag);										
					if((value_change_flag == 0) &&( input3 == 'A' ||input3 =='B' ||input3 == 'C' || input3 == 'D') && (Value == 0))
					{
						lcdClearScreen();					//clear Screen
						lcdWriteString("SYNTAX ERROR");	//Write Message Invalid entry
						lcdWriteCommand(0xC0);						//Goto second line first position
						lcdWriteString("RESETTING...");		//Write Message resetting
						SysTick_Wait_1us(3000000);				//3s Delay
						Reset_Calc();											//Reset_Calc function to reset calculator variables
					}
					i++;																//increment i by one for next run
					Value = 0;													//reset Value to 0 for next number entry
					value_change_flag = 0;
					printf("\n First Value = %f",F_Value);	//Testing
					printf("\n Total Value = %f",Total_Value);	//Testing
					break;
					
					
					case 'B':									//'-' Operation
					printf("\n Case = B Operand = - ||\n");
					F_Value = Get_Value();				//Get_Value into Temporary variable
					SumArray[i] = (-1*F_Value);		//Save negative value in SumArray at position i
					SignArray[i] = '-';						//Save operator value in SignArray in position i
					if((value_change_flag == 0) &&( input3 == 'A' ||input3 =='B' ||input3 == 'C' || input3 == 'D') && (Value == 0))
					{
						lcdClearScreen();					//clear Screen
						lcdWriteString("SYNTAX ERROR");	//Write Message Invalid entry
						lcdWriteCommand(0xC0);						//Goto second line first position
						lcdWriteString("RESETTING...");		//Write Message resetting
						SysTick_Wait_1us(3000000);				//3s Delay
						Reset_Calc();											//Reset_Calc function to reset calculator variables
					}
					Value = 0;										//reset Value for next number entry
					i++;													//increment i by one for next run
					
					printf("\n First Value = %f",F_Value); //tbr
					printf("\n Total Value = %f",Total_Value);	//tbr
					break;
					
					
					case 'C':									//'*' Operation
					printf("\n Case = C Operand = * ||\n");
//					S_Value = Get_Value(0);
					F_Value = Get_Value();			//Get_Value into Temporary variable
					SumArray[i]=0;							//Save a 0 in sum array at position i
					SignArray[i] = '*';					//Save operator value in SignArray at position i
					MultipleArray[j] = F_Value;	//Save stored value in Multiple Array at position j
					if((value_change_flag == 0) &&( input3 == 'A' ||input3 =='B' ||input3 == 'C' || input3 == 'D') && (Value == 0))
					{
						lcdClearScreen();					//clear Screen
						lcdWriteString("SYNTAX ERROR");	//Write Message Invalid entry
						lcdWriteCommand(0xC0);						//Goto second line first position
						lcdWriteString("RESETTING...");		//Write Message resetting
						SysTick_Wait_1us(3000000);				//3s Delay
						Reset_Calc();											//Reset_Calc function to reset calculator variables
					}
					Value = 0;									//reset Value for next number entry
					j++;												//increment j for next run
					i++;												//increment i for next run
					
					printf("\n First Value = %f",F_Value); //tbr
//					printf("\n Second Value = %f",S_Value); //tbr
//					Total_Value = F_Value * S_Value;	//tbr
					printf("\n Total Value = %f",Total_Value); //tbr
					break;
				
					case 'D':									//'/' Operation
					printf("\n Case = D Operand = / ||\n");
					F_Value = Get_Value();			//Get_Value into Temporary variable
					
					
					printf("\n First Value = %f",F_Value);
	//				printf("\n Second Value = %f",S_Value);
			
					if (F_Value == 0){					//if number entered is 0, a number that cannot be divided by
						lcdClearScreen();					//clear Screen
						lcdWriteString("INVALID ENTRY");	//Write Message Invalid entry
						lcdWriteCommand(0xC0);						//Goto second line first position
						lcdWriteString("RESETTING...");		//Write Message resetting
						SysTick_Wait_1us(3000000);				//3s Delay
						Reset_Calc();											//Reset_Calc function to reset calculator variables
					}
					DivideArray[k] = F_Value;						//Save Value in divide Array at position k
					SignArray[i] = '/';									//Save operator in Sign Array at position i
					SumArray[i] = 0;										//Save 0 in SumArray position i
					if((value_change_flag == 0) &&( input3 == 'A' ||input3 =='B' ||input3 == 'C' || input3 == 'D') && (Value == 0))
					{
						lcdClearScreen();									//clear Screen
						lcdWriteString("SYNTAX ERROR");		//Write Message Invalid entry
						lcdWriteCommand(0xC0);						//Goto second line first position
						lcdWriteString("RESETTING...");		//Write Message resetting
						SysTick_Wait_1us(3000000);				//3s Delay
						Reset_Calc();											//Reset_Calc function to reset calculator variables
					}
					Value = 0;													//Reset Value for next number entry
					k++;																//increment k for next run
					i++;																//increment i for next run
					//Total_Value = F_Value;							//tbr
					printf("\n Total Value = %f",Total_Value); //tbr
					break;
					
					case '#':									//'=' Operation
					printf("\n Case = = Operand = = ||\n");
					//S_Value = Get_Value(0);
					int p;
					m=0;																//m is initialized at zero before the for loop
					for(p=0;p<100;p++) {                //Run a for loop from p=0 to p=100 increment p by one each time
						l=p;															//save current value of p in variable l to be used later
						if(SignArray[l]=='/'){						//Most important operator is checked first
							while(SumArray[l]==0)						//Checks if placeholder value is correct in SumArray
							{ l= l-1;												//decrease l by 1 to check the value before until the Value is no longer the placeholder value, which is 0
							}
							SumArray[l] = (SumArray[l] /DivideArray[m]);	//Save Value of divided variable back at same position as the original number
							m++;																					//increment m for next loop so DivideArray finds the next corresponding Divide number
								
							
					}
				}
					m = 0;//m is initialized at zero before the for loop
					for(p=0;p<100;p++) {                //Run a for loop from p=0 to p=100 increment p by one each time
						l=p;															//save current value of p in variable l to be used later
						if(SignArray[l]=='*'){						//Next important operator is checked next
							while(SumArray[l]==0)						//Checks if placeholder value is correct in SumArray
							{ l= l-1;												//decrease l by 1 to check the value before until the Value is no longer the placeholder value, which is 0
							}
							SumArray[l] = (SumArray[l] *MultipleArray[m]);//Save Value of divided variable back at same position as the original number
							m++;																					//increment m for next loop so Multiple finds the next corresponding Multiple number
																
							
					}
				}
									Total_Value = 0;             //Divide and Multiply are complete at this point
									for(p=0;p<100;p++){					//Run a for loop from p=0 to p=100 increment p by one each time
										Total_Value+=SumArray[p]; //Add each number to the variable Total_Value (basically sum the array)
									}
				
					printf("\n Total Value = %f",Total_Value);
//								if(Total_Value!= 0){					//checks that total Value has been changed
									lcdClearScreen();						//clear LCD screen
					sprintf(TString,"%f",Total_Value);			// Turn Answer variable into a String
					lcdWriteCommand(0xC0);						//Set to second line first position
					lcdWriteString(TString);					//Write Total Value string to lcd
					lcdWriteCommand(0x02);						//Set lcd back to first line first position
									F_Value = 0;						//Reset Temporary Value
//									S_Value = 0;							//tbr
									Value = 0;								//Reset Value for next number entry
										int z;									
	for(z=0;z<100;z++) 												//for loop to reset the array
	{	
		SumArray[z] = 0;												//Set all Values of SumArray to 0 as a sum of zero and another number will leave you with the original number
		SignArray[z] = '+';
		DivideArray[z] = 1;											//Similar to above but for Divide so set all values to 1
		MultipleArray[z] = 1;										//Same as above for Multiply
	}
	//							}
								SumArray[0]=Total_Value;
									i = 0;
									j = 0;
									k = 0;
									l = 0;
									m = 0;
								input2 = 0;												//Reset input2 for the switch
								input3 = 0;									//Reset placeholder variable input3 to save the value of input 2 in
								input = 'G';								//tbr
								i = 0;
					break;
					case '*':						//clear Operation
					printf("\n Case = Clear Screen\n");	
					Reset_Calc();				//Reset the Calculator
					break;
					case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:						//Number Entry
					
					printf("\n Case = input Operand = IN ||\n");	
					F_Value = Get_Value();							//Save first Value in Temporary variable
					i = 0;
					if(F_Value !=0){
					SumArray[i] = F_Value;						//Write first value to SumArray at position i
					}
						i++;																//increment i
					printf("\n First Value = %f",F_Value);	//tbr
					Value = 0;                          //reset Value for next number entry
					value_change_flag=0;
//					if (input3 == 'A' ||input3 =='B' ||input3 == 'C' || input3 == 'D' 
//					|| input3 == '#' ||input3 == '*' ){
//						input3 = input2;
//						printf("\n First Value = %f",F_Value);
//					}
					input2 = input3;										//Get Saved input value from Get_Value function to be used in next switch run
					break;
}
}

void Reset_Calc(void){
	lcdClearScreen();											//clear LCD screen
	F_Value = 0;													//reset first Value
//	S_Value = 0;													//reset second Value(to be removed)
//	T_Value = 0;													//"				Third "      " "  "
	Total_Value = 0;											//reset Total Value
	input = 0;														//reset input for first switch
	input2 = 0;														//Reset input for next switch 
	Value = 0;														//Reset Value for next number entry
	value_change_flag = 0;								//reset value change flag for syntax issues
	input3 = 'H';													//Placeholder variable
	i = 0;
	j = 0;
	k = 0;
	l = 0;
	m = 0;
	int z;																
	for(z=0;z<100;z++)										//for loop to reset all array values
	{
		SumArray[z] = 0;										//Sum array values set to 0
		DivideArray[z] = 1;									//DivideArray values set to 1
		MultipleArray[z] = 1;								//MultipleArray values set to 1
	}

}

double Get_Value(void){
	while	(1){
		input2=readKeypad();			//Read Keypadinput into input2, to be used with the switch
		while (input2 == 'G'){		//'G' is the placeholder value that was given to the keypad in case of no new key presses
			input2=readKeypad();		//Keeps reading in the input to keypad until it is not equal to the placeholder
		}
		//value_change_flag = 0;
		while(input2 >=0 && input2 <= 9){		//While loop to detect number inputs
			if (Value == 0) {									//If Value = 0, so a new number entry
				Value += input2;								//Add input to value
				value_change_flag = 1;
				}																	
				else if (Value != 0)						//In case of a number entry having began
				{																	
				Value = (Value * 10);						//Value *10 for proper number entry
				Value+= input2;									//New Value add the input
				}
				value_change_flag = 1;
				input2 = readKeypad();					
			}
		
		if (input2 == 'A' ||input2 =='B' ||input2 == 'C' || input2 == 'D' 		//check If input is one of the operators or the clear and equals functions
					|| input2 == '#' ||input2 == '*' ){
						input3 = input2;						//If that is the case, save the value of the operator to be used in the next variation of the switch
		
				printf("GET VALUE RUNNING");	
				break;													//break while loop
}	
			
		}
return Value;														//Return the Final Value
}

void Calc_Init(void){
	input2 = 0;
	Total_Value = 0;
}
