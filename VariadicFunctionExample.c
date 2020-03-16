
/* Write a program that calculates the avg of the integers
inside a couple of string.

Example:
FindSum(char * count,"Omer demir ,Berkay Gürbüz ,Seyhmus Askar",100,95,20);
//coded by berkay gürbüz//
*/
#include <stdio.h>
#include <stdarg.h>		/* va_list, va_start, va_arg, va_end */
#include <string.h>		/* strlen */
#include <math.h>

float findAvg(char *text,...){
	va_list ap;		//create our va_list which name is ap
	int a;
	int sum=0,count=1;
	int i,j,lentext;
	int tempCount;
	
	
	va_start(ap,text);		//initialize ap to retrieve text
	lentext=strlen(text);	
	
	//check how many "," are inside of the string
	for(j=0;j<lentext;j++){
		if(text[j]==','){
			count++;
		}
	} 
	tempCount=count;
	
	//Print all of the name,and surnames until "," comes
	for(j=0;j<strlen(text);j++){
		if(text[j]==','){
		a=va_arg(ap,int);
		printf("\t\t\tNumber: %d",a);
		printf("\n");
		}else{
		printf("%c",text[j]);
		}
	}
	
	//print last score 
	a=va_arg(ap,int);
	printf("\t\t\tNumber: %d",a);
	printf("\n\n");	
	
	//it becomes the last element so we end list and start again
	va_end(ap); 	
	va_start(ap,text);		
	
	//If score is not 0 to 100,give the error
	for(i=0;i<count;i++){
		a=va_arg(ap,int);
		if(a>100||a<0){
			printf("[%d].student number must be between 0 to 100\n",i+1);
			tempCount--;
		}
		else{
			sum += a;	
		}
	}
	
	va_end(ap); 
	return ((float)(sum) / (float)(tempCount)); 	//return avarage of the scores.
}
int main(void){
	
	printf("\n\nAverage = %.2f",findAvg("John Walker,Adam Micheal,Alan Smith,Berkay Gurbuz",120, 95,20, 58)); 
	/*coded by berkay gürbüz*/
	return 0;
}
