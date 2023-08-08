/**********************************************************************
*                                                                     *
* Code written by P Sashwat.                                          *
* More information regarding this code and me can be found on my      *
* Linkedin Profile : https://www.linkedin.com/in/sashwat-p-1952471b1/ *
*                                                                     *
***********************************************************************/


#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void welcome(); // to display the welcome screen
void login(); // to display the login screen
void mainmenu(); // to display the main menu
void add_books(); // to display the add books screen
void delete_books();// to display the delete function
void edit_books(); // to display the edit function
void search_books(); // to display the search function
void view_books();// too display the view books function



int wrong=1, count;//global variable for login function of int type
int i=0, valid=0;
char choice=0 ;

char answer;
int target=0,found=0;

struct books// to call in program
{
	int books_id; // declare the integer data type
	char b_name[20];// declare the character data type
	char a_name[20];// declare the charecter data type
	char s_name[20];// declare the character data type
	char add[15];// declare the character data type
	int days;// declare the integer data type
	int yr; // declare the integer data type

}m;
void gotoxy(short x, short y)// declare the gotoxy function
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void main() // declare main function
{
	welcome(); // call welcome screen
	login();// call login screen
}
// welcomr function
void welcome()
{

	gotoxy(25,6);
printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
gotoxy(25,7);
printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
gotoxy(25,8);
printf("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
gotoxy(25,9);
printf("        =                 WELCOME                   =");
gotoxy(25,10);
printf("        =                   TO                      =");
gotoxy(25,11);
printf("        =                 LIBRARY                   =");
gotoxy(25,12);
printf("        =               MANAGEMENT                  =");
gotoxy(25,13);
printf("        =                 SYSTEM                    =");
gotoxy(25,14);
printf("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
gotoxy(25,15);
printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
gotoxy(25,16);
printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
gotoxy(28,22);
printf(" Enter any key to continue.....");
getch();
}
// login function
void login()
{
	system("cls");
	int L=0;
	char a[30], b[30];
	system("cls");



	printf("------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\tLogin Screen");
	printf("\n------------------------------------------------------------------------------------------------");
	do
	{
		printf("\n\t\t\t\tEnter Username and Password");

		printf("\n\t\t\t\tUsername:");
		scanf("%s" ,a);

		printf("\n\t\t\t\tPassword:");
		scanf("%s" ,b);
		if((strcmp(a,"libraryproject")==0)&& (strcmp(b,"bypsashwat")==0))
		{
			printf("\n\t\t\t\tLogged Into System.");
			printf("\n\t\t\t\tPress any key to go next.....");
			printf("\n------------------------------------------------------------------------------------------------");
			getch();
			mainmenu();
		}
		else
		{

			printf("\t\t\t\tLogin Failed Enter Again Username & Password Again\n\n");
			L++;
		}
	}
		while(L<=3);
	if(L>3){
		system("cls");
		gotoxy(40,15);
		printf("Sorry,Unknown User.");
		getch();
		system("cls");
	}

}
// mainmenu function

void mainmenu(void)
	{
		int choice;

		system("cls");
		printf("\n------------------------------------------------------------------------------------------------");
		gotoxy(20,2);
		printf("MAIN MENU");
		printf("\n------------------------------------------------------------------------------------------------");
		gotoxy(20,5);
		printf("1. Add Books");
		gotoxy(20,7);
		printf("2. Search Books");
		gotoxy(20,9);
		printf("3. View Books");
		gotoxy(20,11);
		printf("4. Edit Book's Record");
		gotoxy(20,13);
		printf("5. Delete Books");
		gotoxy(20,15);
		printf("6. Close Application");
		gotoxy(20,17);
		printf("Please Enter a choice[1-6]:");
		scanf("%i",&choice);
		switch(choice)
			{
				case 1:
				add_books();
				break;
				case 2:
			    search_books();
				break;
				case 3:
				view_books();
				break;
				case 4:
				edit_books();
				break;
				case 5:
				delete_books();
				case 6:
				exit(0);
				break;

				default:
					printf("Wrong Entry!!");
					exit(0);


			}
}
/**********************************************************************
*                                                                     *
* Code written by P Sashwat.                                          *
* More information regarding this code and me can be found on my      *
* Linkedin Profile : https://www.linkedin.com/in/sashwat-p-1952471b1/ *
*                                                                     *
***********************************************************************/
// add books function
void add_books()
{
	int days;
	system("cls");
	FILE *sfile;
	sfile = fopen("BookRecord.txt","a");
	printf("\n\t\t****************************************************");
	printf("\n\t*********************ADD NEW BOOKS*********************");
	printf("\n\t\t******************************************************");
	printf("\n\n\t\t  ENTER YOUR DETAILS BELOW:");
	printf("\n\t\t------------------------------");
	printf("\n\t\tBook ID NO.\t\t:");
	fflush(stdin);
	scanf("%i",&m.books_id);
	do
	{
		printf("\n\t\tBook Name\t\t:");
		fflush(stdin);
		gets(m.b_name);
		m.b_name[0]=toupper(m.b_name[0]);
		for (i=0;i<strlen(m.b_name); ++i)
		{
			if(isalpha(m.b_name[i]))
			{
				valid = 1;
			}
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
	do
	{
		printf("\n\t\tPublication\t\t:");
		fflush(stdin);
		gets(m.a_name);
		m.a_name[0]=toupper(m.a_name[0]);
		for (i=0;i<strlen(m.a_name); ++i)
		{
			if(isalpha(m.a_name[i]))
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
	do
	{
		printf("\n\t\tStudent Name\t\t:");
		fflush(stdin);
		gets(m.s_name);
		m.s_name[0]=toupper(m.s_name[0]);
		for (i=0;i<strlen(m.s_name); ++i)
		{
			if(isalpha(m.s_name[i]))
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
		do
			{
				printf("\n\t\tStudent Address\t\t:");
				fflush(stdin);
				gets(m.add);
				m.add[0]=toupper(m.add[0]);
				for (i=0;i<strlen(m.add); ++i)
				{
					if(isalpha(m.add[i]))
					valid = 1;
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nAddress contain invalid character. Please enter again.");
				}
			}while(!valid);
			printf("\n\t\tEnter Duration To Take Book");

			do
			{
				printf("\n\t\tMaximum [1-15] Days\t:");
				scanf("%i",&m.days);
				if(m.days<1 || m.days>15)
				{
					printf("\n\tYou Cannot take more than 15x Days.Re-Enter.");
				}
			}while(m.days<1 || m.days>15);

	fprintf(sfile,"%i %s %s %s %s %i\n\n",m.books_id, m.b_name, m.a_name, m.s_name,m.add,m.days);
	fclose(sfile);
	printf("\n\t SUCCESFULLY RECORDED.\n");
	getch();
	printf("\n\t\t Do you want to add another book?[Y/N]:");
	scanf("%s",&answer);
	while(toupper(answer)!='Y'&& toupper(answer)!='N')
	{
		printf("Invalid!\n\tDo you want to add book?[Y/N]:");
		scanf("%s",&answer);
	}
	if(toupper(answer)=='Y')
	{
		add_books();
	}
	else
	{
		printf("\n\t\tPress any key to go to mainmenu.....");
		mainmenu();
	}

}
// search books function
void search_books()
{
	int found=0;
	char id[40];
	FILE *sfile;
	system("cls");
	sfile=fopen("BookRecord.txt","rb");
	printf("\n\t\t******************************************************");
	printf("\n\t\t***************** SEARCH BOOKS LIST*******************");
	printf("\n\t\t******************************************************\n\n");

	printf("\nEnter Book Name to search:");
	fflush(stdin);
	scanf("%s",id);
	id[0]=toupper(id[0]);

	printf("                                                                                     \n");
	printf(" Book ID NO. Book Name    Publication    Student Name   Student Address   Due Days");

	printf("\n=====================================================================================\n");
	while(fscanf(sfile,"%i %s %s %s %s %i\n\n",&m.books_id, m.b_name, m.a_name, m.s_name, m.add, &m.days)!=EOF)
	{
		if(strcmp(id,m.b_name)==0)
		{
			found=1;
			gotoxy(1,10);
			printf("%i",m.books_id);
			gotoxy(12,10);
			printf("%s",m.b_name);
			gotoxy(24,10);
			printf(" %s",m.a_name);
			gotoxy(40,10);
			printf(" %s",m.s_name);
			gotoxy(56,10);
			printf("%s",m.add);
			gotoxy(74,10);
			printf("%i",m.days);
			break;
		}
	}
		if(!found) printf("\n\n\tNo Record");
		fclose(sfile);
		printf("\t\t\n\n\nPress any key to go to mainmenu.....");
		getch();
		mainmenu();

}

/**********************************************************************
*                                                                     *
* Code written by P Sashwat.                                          *
* More information regarding this code and me can be found on my      *
* Linkedin Profile : https://www.linkedin.com/in/sashwat-p-1952471b1/ *
*                                                                     *
***********************************************************************/
// view books function
void view_books()
{
	int i,e;
	FILE*sfile;
	system("cls");
	sfile=fopen("BookRecord.txt","r");
	printf("\n\t\t\t*********************************************************");
	printf("\n\t\t\t**************** VIEW ALL BOOK RECORDS *****************");
	printf("\n\t\t\t*********************************************************");
	if(sfile==NULL)
	{
		printf("\n\n\t\t RECORD EMPTY");
		getch();
	}
	else
	{
		gotoxy(1,6);
		printf("Book Id NO.");
		gotoxy(13,6);
		printf("Book Name");
		gotoxy(30,6);
		printf("Publication");
		gotoxy(45,6);
		printf("Students Name");
		gotoxy(63,6);
		printf("Students Address");
		gotoxy(83,6);
		printf("Due Days\n");
		for(i=0;i<95;i++)
		{
			printf("-");
		}
		e=8;
		while(fscanf(sfile,"%i %s %s %s %s %i\n\n",&m.books_id,m.b_name,m.a_name,m.s_name,m.add,&m.days)!=EOF)
		{
			gotoxy(1,e);
			printf("%i",m.books_id);
			gotoxy(13,e);
			printf("%s",m.b_name);
			gotoxy(30,e);
			printf("%s",m.a_name);
			gotoxy(45,e);
			printf("%s",m.s_name);
			gotoxy(63,e);
			printf("%s",m.add);
			gotoxy(83,e);
			printf("%i",m.days);
			e++;
		}
		printf("\n");
		for(i=0;i<95;i++)
		printf("-");
	}
	printf("\n\n\t Press any key for main menu........");
	fclose(sfile);
	getch();
	mainmenu();


}
// delete function
void delete_books()
{

	int target;
	system("cls");
	printf("\n\t\t*************************************************");
	printf("\n\t***************Delete Books Details****************");
	printf("\n\t\t*************************************************");
	FILE *sfile,*mfile;
	sfile=fopen("BookRecord.txt","r");
	printf("\nEnter Book ID NO. for delete:");
	scanf("%i",&target);
	mfile=fopen("TempBook.txt","w+");
	if(sfile==NULL)
	{
		printf("\n\tNo Record in File!");
		printf("\n\t\t\tPress any key to Main Menu..");
		getch();
		mainmenu();
	}
	else
	{
		while(fscanf(sfile,"%i %s %s %s %s %i\n",&m.books_id,m.b_name,m.a_name,m.s_name,m.add,&m.days)!=EOF)
		{
			if(target!=m.books_id)
			{
				fprintf(mfile,"%i %s %s %s %s %i\n",m.books_id,m.b_name,m.a_name,m.s_name,m.add,m.days);
			}
			else
			{
				found=1;
			}
		}
		if(!found)
		{
			printf("\nRecord not found");
		}
		else
		{
			printf("\n\tRecord deleted successfully.....");
		}
		fclose(sfile);
		fclose(mfile);
		remove("BookRecord.txt");
		rename("TempBook.txt","BookRecord.txt");
	}
	getch();
	mainmenu();
}

// edit function
void edit_books()
{
	int i, found,target;
  char ch;
  int books_id;
  FILE *sfile, *modify;
  system("cls");
  printf("\n\t\t********************************************");
  printf("\n\t\t*******Edit Books Details*******************");
  printf("\n\t\t********************************************");

   sfile=fopen("BookRecord.txt","rb+");
   if(sfile==NULL)
   {

		printf("\n\t Can not open file!! ");
		getch();
		mainmenu();
   }
   gotoxy(15,6);
   printf("\tEnter Book ID NO. for edit:");
   scanf("%i",&target);
   gotoxy(15,8);
   modify=fopen("TempBook.txt","a+");
   if (modify==NULL)
   {
   	printf("\n File cannot be open...!");
   	getch();
   	printf("\n\nPress any key to go to main menu.......");
   	mainmenu();
   }
   else
   {
   	while(fscanf(sfile,"%i %s %s %s %s %i\n",&m.books_id,m.b_name,m.a_name,m.s_name,m.add,&m.days)!=EOF)
   	{
   		if(m.books_id==target)
   		{
   			found=1;
   			printf("\n\tBook ID NO.\t:%i\n\tBook Name\t:%s\n\tPublication\t:%s\n\tStudent Name\t:%s\n\tStudent Address\t:%s\n\tDue Days\t:%i\n",m.books_id,
			   															m.b_name,m.a_name,m.s_name,m.add,m.days);
			printf("\n\tEdit With New Records!");
   			do
   			{
   				printf("\n\t\tEnter New Book Name\t\t:");
				fflush(stdin);
				gets(m.b_name);
				m.b_name[0]=toupper(m.b_name[0]);
				for (i=0;i<strlen(m.b_name); ++i)
				{
					if(isalpha(m.b_name[i]))
					{
						valid = 1;
					}
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nBook name contain invalid character. Please enter again.");
				}
			}while(!valid);
			do
			{
				printf("\n\t\tEnter New Publication\t\t:");
				fflush(stdin);
				gets(m.a_name);
				m.a_name[0]=toupper(m.a_name[0]);
				for (i=0;i<strlen(m.a_name); ++i)
				{
					if(isalpha(m.a_name[i]))
					valid = 1;
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nWriter name contain invalid character. Please enter again.");
				}
			}while(!valid);
			do
			{
				printf("\n\t\tEnter New Student Name\t\t:");
				fflush(stdin);
				gets(m.s_name);
				m.s_name[0]=toupper(m.s_name[0]);
				for (i=0;i<strlen(m.s_name); ++i)
				{
					if(isalpha(m.s_name[i]))
					valid = 1;
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nStudent name contain invalid character. Please enter again.");
				}
			}while(!valid);
			do
			{
				printf("\n\t\tEnter New Student Address\t:");
				fflush(stdin);
				gets(m.add);
				m.add[0]=toupper(m.add[0]);
				for (i=0;i<strlen(m.add); ++i)
				{
					if(isalpha(m.add[i]))
					valid = 1;
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nAddress contain invalid character. Please enter again.");
				}
			}while(!valid);
			printf("\n\t\tEnter Duration To Take Book");

			do
			{
				printf("\n\t\tMaximum [1-15] Days\t\t:");
				scanf("%i",&m.days);
				if(m.days<1 || m.days>15)
				{
					printf("\n\tYou Cannot take more than 10 Days.Re-Enter.");
				}
			}while(m.days<1 || m.days>15);

			printf("\nPress 'U' to update and other key to cancel....!");
			ch=getche();
			if(ch=='u'|| ch=='U')
			{
				fprintf(modify,"%i %s %s %s %s %i",m.books_id,m.b_name,m.a_name,m.s_name,m.add,m.days);
				fflush(stdin);
				printf("\n\nBooks has been updated......");
			}
			else
			{
				fprintf(modify,"%i %s %s %s %s %i",m.books_id,m.b_name,m.a_name,m.s_name,m.add,m.days);
				fflush(stdin);
			}
	   }
	   if(!found)printf("\n\tNo record found!");
	   fclose(modify);
	   fclose(sfile);
	   remove("BookRecord.txt");
	   rename("TempBook.txt","BookRecord.txt");

     	printf("\n\t\tPress any key to go to mainmenu.....");
     	getch();
	    mainmenu();
   }
}
}
/**********************************************************************
*                                                                     *
* Code written by P Sashwat.                                          *
* More information regarding this code and me can be found on my      *
* Linkedin Profile : https://www.linkedin.com/in/sashwat-p-1952471b1/ *
*                                                                     *
***********************************************************************/
