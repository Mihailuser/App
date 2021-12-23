#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <locale.h>
typedef struct 
{
	int numerator;
	int denominator;
} fract;

fract plus(fract fro,fract frt)
{
	fract res  = {0,0};
	if (fro.denominator != frt.denominator)
	{
		printf("the denominators are not equal\n");
	}
	else
	{
	res.numerator = fro.numerator + frt.numerator;
	res.denominator = fro.denominator;
	}
	return res;
}
fract minus(fract fro,fract frt)
{
	fract res  = {0,0};
	if (fro.denominator != frt.denominator)
	{
		printf("the denominators are not equal\n");
	}
	else
	{
	res.numerator = fro.numerator - frt.numerator;
	res.denominator = fro.denominator;
	}
	return res;
}
fract devide(fract fro,fract frt)
{
	int frtn = frt.numerator;
	int frtd = frt.denominator;
	frt.numerator = frtd;
	frt.denominator = frtn;
	fract res = {fro.numerator * frt.numerator,fro.denominator * frt.denominator};
	return res;
}
fract multiply(fract fro,fract frt)
{
	fract res = {fro.numerator * frt.numerator,fro.denominator * frt.denominator};
	return res;
}



typedef char *string;
typedef char cstring[1000000];
int create();
int write();
int read();
int append();
int appendn();
double Calculator();
fract FractCalc();
double fractToDouble();
double Ft();
double V();
double Fu();
double Fr();
double p();
void help();

int main(int argc,char *argv[])
{
	setlocale(LC_ALL, "Rus");
	char command[20];

	while(command[0]!='e'&&command[1]!='n'&&command[2]!='d')
	{
    printf("\n>");
	scanf("%s",command);
	   if(command[0]=='h'&&command[1]=='e'&&command[2]=='l'&&command[3]=='p')
	   {
		   help();
	   }
	   else if(command[0]=='F'&&command[1]=='t')
	   {
		   Ft();
	   }
	   else if(command[0]=='V')
	   {
		   V();
	   }
	   else if(command[0]=='F'&&command[1]=='u')
	   {
		   Fu();
	   }
	   else if(command[0]=='F'&&command[1]=='r')
	   {
		   Fr();
	   }
	   else if(command[0]=='p')
	   {
		   p();
	   }
	   
	   else if(command[0]=='c'&&command[1]=='r'&&command[2]=='e'&&command[3]=='a'&&command[4]=='t'&&command[5]=='e')
	   {
		   create();
	   }
      else if(command[0]=='w'&&command[1]=='r'&&command[2]=='i'&&command[3]=='t'&&command[4]=='e')
	   {
		 
		   write();
	   }
	    else if(command[0]=='r'&&command[1]=='e'&&command[2]=='a'&&command[3]=='d')
	   {
		   read();
	   }
	    else if(command[0]=='a'&&command[1]=='p'&&command[2]=='p'&&command[3]=='e'&&command[4]=='n'&&command[5] =='d')
	   {
		   append();
	   }
	    else if(command[0]=='c'&&command[1]=='a'&&command[2]=='l'&&command[3]=='c')
	   {
		   Calculator();
	   }
	    else if(command[0]=='f'&&command[1]=='r'&&command[2]=='a'&&command[3]=='c'&&command[4]=='t'&&command[5]=='c'&&command[6]=='a'&&command[7]=='l'&&command[8]=='c')
	   {
		   FractCalc();
	   }
	   else if(command[0]=='a'&&command[1]=='p'&&command[2]=='p'&&command[3]=='e'&&command[4]=='n'&&command[5] =='d'&&command[6]=='n')
	   {
		   appendn();
	   }
	   
	
	   else 
	   {
		  
		   system("pause");
		   return 1;
	   }
	}
	system("pause");
	return 0 ;
}

int create()
{
	cstring path ;
    printf("Print full path \n");
    scanf("%s", &path);
	FILE *file  = fopen(path,"a");
	fclose(file);
	return 0;
}

int write()
{
	char path[100];
	printf("Print full path \n");
	scanf("%s", &path);
	
    FILE *fp;
    if((fp= fopen(path, "w"))==NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    char text[1000000] ;
	printf("Print message\n");
	scanf("%s",&text);
    fprintf(fp,"%s",text);
     
    fclose(fp);
    return 0;
}

int  read()
{
	cstring path ;
    printf("Print full path \n");
    scanf("%s", &path);
	FILE *file ;
	char c;

    if((file= fopen(path, "r"))==NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    
    while((c = getc(file))!= EOF)
    {
	
        printf("%c", c);
    }
    fclose(file);
    return 0;
}

int append()
{
	char path[100];
	printf("Print full path \n");
	scanf("%s", &path);
	
	FILE *file = fopen(path,"a");
    char text[1000000];
	printf("Print message\n");
	scanf("%s",&text);
    fprintf(file,"%s",text);
	fclose(file);
	return 0;
}

int appendn()
{
	char path[23];
	printf("Print full path \n");
	scanf("%s", &path);
	
	FILE *file = fopen(path,"a");
    char text[1000000] = "dd";
	printf("Print message\n");
	scanf("%s",&text);
    fprintf(file,"%s\n",text);
	fclose(file);
	return 0;

	
}
double Calculator()
{

    double a, b, res;
    res = 0;
    cstring sign= "";

    printf("Print first number \t");
    scanf("%lf", &a);
    printf("Print second number \t");
    scanf("%lf", &b);
    printf("Print sign \t");
    scanf("%s", sign);
    switch (sign[0])
    {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        res = a / b;
        break;
    }

    printf("Result =%lf \n", res);
    

    return res;

}

fract FractCalc()
{
	fract a, b;
    fract res = {0,0};
    cstring sign= "";

    printf("Print numerator of first fraction \t");
    scanf("%i", &a.numerator);
	 printf("Print denominator of first fraction \t");
    scanf("%i", &a.denominator);
   printf("Print numerator of second fraction \t");
    scanf("%i", &b.numerator);
	 printf("Print denominator of second fraction \t");
    scanf("%i", &b.denominator);
    printf("Print sign \t");
    scanf("%s", sign);
    switch (sign[0])
    {
    case '+':
        res = plus(a,b);
        break;
    case '-':
        res = minus(a,b);
        break;
    case '*':
        res = multiply(a,b);
        break;
    case '/':
        res = devide(a,b);
        break;
    }

    printf("Result =%i/%i \n", res.numerator,res.denominator);
    

    return res;
}
double Ft()
{
    double m;
    double res;
    printf("Get m\t");
    scanf("%lf",&m);
    res = 10*m;
    printf("%lf",res);
    return 10*m;
	}
double V()
{   double m;
    double res;
    printf("Get m\t");
    scanf("%lf",&m);
    res = 10*m;
    printf("%lf",res);
    return 10*m;
}
double Fu()
{
    double k;
    double dl;
    double res ;
    printf("Print k \t");
    scanf("%lf", &k);
    printf("Print dl \t");
    scanf("%lf", &dl);
    res = k * dl;
    printf("%lf",res);
    return k * dl;
}
double Fr()
{
    double ju;
    double m;
    double res;
    printf("Print ju \t");
    scanf("%lf", &ju);
    printf("Print m \t");
    scanf("%lf", &m);
    res = ju*10*m;
    printf("%lf",res);
    return ju * 10*m;

}
double p()
{
	double F;
    double S;
    double res;
    printf("Print F \t");
    scanf("%lf", &F);
    printf("Print S \t");
    scanf("%lf", &S);
    res = F/S;
    printf("%lf",res);
    return F/S;

}
void help()
{
	int n =13;
	string commands[13] = {"create - create a file","write - write in file(last letter will be deleted)",
	"read - show text in file ","append - write in file, but without deleting","calc - calculator",
	"fractcalc - calculator for fractions","appendn - write in file with new line"
	,"Ft - count gravity power ","V - count of heft ","Fu - count elastic strength"
	,"Fr - count fiction power ","p - pressure","end - end of work" };
	for(int i = 0; i<n ;i++)
	{
		printf("%s\n",commands[i]);
	}
}
