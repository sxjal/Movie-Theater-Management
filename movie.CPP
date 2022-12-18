#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#define tax 0.4

struct seat
{
	char seat[5][8][11];
/*a 3-D to simplify the code where 2nd nd 3rd bracket is for seats
and 1st bracket is for the movie which user will select*/
};

struct shtime
{
	seat time[6];
/* an array for shows available */
};

void welcm(int succ)
/* function for the display for welcome scrren,which displays
only welcome screen*/
{
	clrscr();
	if( succ == 0 )
	/* a value 'succ' is being passed to the function by main function
	here if succ is 1 then the user has already logged in and then the
	welcome thing wont be displayed*/
	{
		cout<<"\n WELCOME TO IMAX SOHAR ";
	}
	else if( succ == 1 )
	{
		cout<<"\n IMAX, SOHAR ";
	}
	else
	{
		//do nothing
	}
}

void asg(shtime (&date)[6],int d,int t,int m)
/* this function initializes the seats(3-D Array) as avaialble*/
{
	int i,j;
	while(1)
	{
	for( d=1;d<=5;d++)                 // for loop for the day
	{
		for(t=1 ; t<=5 ; t++)     //loop for the show time
		{

			for( i=1;i<=7;i++) // loop for the row of seat map
			{
				for(j=1 ; j<=10 ; j++) // loop for the column of seat map
				{

					date[d].time[t].seat[m][i][j]='A';
					 /* value 'A' which shows
					that the seat is available */

				}  // end of j loop
			}   // end of i loop
		}    // end of t loop
	}      // end of d loop
	m++;
	/* value m is being changed so that the
	array will be initialized fo every movie*/
		if(m>5)
		{
			break;
		}    // end of if
	}  // end of the while loop
}     // end of function


void disp(shtime (&date)[6],int d,int t,int m)
/* this function dislayes the seat map
of the movie,show time & date selected*/
{
	int i,j;

	cout<<"\n ---------------------------";
	cout<<"\n SEAT :";
	for( i=1 ; i<=10 ; i++)
	{
		cout<<" "<<i;
	}

	for( i=1 ; i<=7 ; i++)
	{       cout<<endl;
		cout<<" ---------------------------";
		cout<<"\n ROW "<<(char)(64+i)<<" ";
		for( j=1 ; j<=10 ; j++)
		{

			cout<<"|"<<date[d].time[t].seat[m][i][j];
		}
		cout<<"|";
		if( i >=2 && i <= 6 )
		{
			if( i == 2 )
			{
				cout<<"\t Price : ";
			}

			else if( i == 3 )
			{
				cout<<"\t Row A - Row B, price = 3.00 OMR";
			}

			else if( i == 4 )
			{
				cout<<"\t Row C - Row D, price = 2.50 OMR";
			}

			else if( i == 5 )
			{
				cout<<"\t Row E - Row F, price = 2.20 OMR";
			}

			else if( i == 6 )
			{
				 cout<<"\t Row G , Price = 2.00 OMR ";
			}

			else
			{
				//do nothing
			}
		}
	}

	cout<<"\n ---------------------------";

}

void mov_disp(char movie[6][30],int (&m) )
/* this function is being used to display the
movies available and it takes the input of
variable m which is corresponding to movie
and also the variable '&' will automatically udate the value
of variable m without any return statement*/
{
	clrscr();
	int succ=1;
	welcm(succ);
	cout<<"\n--------------------------";
	cout<<"\n** * AVAILABLE MOVIES * **";
	cout<<"\n--------------------------";

	for(int i=1 ; i<=4 ; i++)
	{
		cout<<"\n"<<movie[i];
	}

	cout<<"\n ------------------------";

	cout<<"\n Make your selection, Enter movie code : ";
	while(1)
	{       /* a while loop which assures that the enter
		value of m is under given criteria*/
		cin>>m;
		if( m>=1 && m<=4)
		{
			break;
		}
		else
		{
			cout<<"\n ------------";
			cout<<"\n Invalid Code  ";
			cout<<"\n Enter again :";
			continue;
		}
	}
}

void date_disp(char date_db[6][10],int (&d),char movie[5][30],int m)
/* A Function which displays and takes the input of
   the date which has to be
   selected by the user */
{
	clrscr();
	int i;
	int succ=1;
	welcm(succ);
	cout<<"\n ------------------------------------";
	cout<<"\n** *SELECTED MOVIE* ** : "<<movie[m];
	cout<<"\n ------------------------------------";
	cout<<"\n AVAILABLE DATE(s) : ";
	cout<<"\n -------------------";
	for( i=1; i<=4 ; i++)
	{
		cout<<"\n"<<date_db[i];
	}
	cout<<"\n ------------";
	cout<<"\n Enter Code : ";
	while(1)              /*while loop which checks that the enter
				code is under given criteria*/
	{
		cin>>d;

			if( d>=1 && d<=4 )
			{
				break;
			}
			else
			{
				cout<<"\n Invalid Code Entered,please enter a valid code : ";
				continue;
			}
	}    // end fo while loop


}

void time_disp(char show[6][30],char movie[6][30],int m,int (&t),int d,char date_db[6][10] )
/* A time function whic displays the available show time,
   for every movie different show time is given and if
   the user enter a time out of the given codes so the program
   will give an error and the user has to enter the selection again */
{

	clrscr();
	int i;
	int succ=1;
	welcm(succ);
	cout<<"\n -------------------------------";
	cout<<"\n SELECTED MOVIE : "<<movie[m];
	cout<<"\n -------------------------------";
	cout<<"\n SELECTED DATE : "<<date_db[d];
	cout<<"\n -------------------------------";
	cout<<"\n AVAILABLE SHOW(s) : ";
	cout<<"\n ------------------";

	switch(m)   /* switch case so that we can
		display different show times for different movies where every number corresponds
		the movie asgined in that position in the movie array */
	{
	case 1:

		for( i=1; i<=5 ; i=i+2)
		{
			cout<<"\n"<<show[i];

		}
		break;

	case 2:
		for( i=2; i<=4 ; i=i+2)
		{
			cout<<"\n"<<show[i];

		}
		break;

	case 3:

		for( i=1; i<=3 ; i=i+2)
		{
			cout<<"\n"<<show[i];
		}
		break;

	case 4:
		for( i=2; i<=5 ; i=i+2)
		{
			cout<<"\n"<<show[i];
			if( i>= 4 && i<5)
			{
				cout<<"\n"<<show[5];
			}

		}
		break;
	}
	cout<<"\n -------------------------";
	cout<<"\n Enter Show Code : ";

/* a while loop which ensures that the user enters the desired input only,
if he/she give an inut out of the given times,the user will get an error
and user has to given the input again */
	while(1)
	{
		cin>>t;

		if( m == 1 )
		{
			if( t==1 || t==3 || t==5 )
			{
				break;
			}
			else
			{
				cout<<"\n ---------------------------";
				cout<<"\n Invalid code , Enter again: ";
				cout<<"\n ---------------------------";
				continue;
			}
		}

		else if( m == 2)
		{
			if( t==2 || t==4 )
			{
				break;
			}
			else
			{
				cout<<"\n ---------------------------";
				cout<<"\n Invalid code , Enter again: ";
				cout<<"\n ---------------------------";
				continue;
			}
		}

		else if( m == 3 )
		{
			if( t==1 || t==3 )
			{
				break;
			}
			else
			{
				cout<<"\n ---------------------------";
				cout<<"\n Invalid code , Enter again: ";
				cout<<"\n ---------------------------";
				continue;
			}
		}

		else if( m == 4 )
		{
			if( t==2 || t==5 || t==4)
			{
				break;
			}
			else
			{
				cout<<"\n ---------------------------";
				cout<<"\n Invalid code , Enter again: ";
				cout<<"\n ---------------------------";
				continue;
			}
		}

		else
		{
			//do nothing
		}
	} // end of while loop
}

void input(shtime (&date)[6],int d,int t,int m,int (&n),int (&st)[11],char (&row))
/* this function takes the input of the seats to be booked
where the user can book 10 seats at max */
{
	cout<<"\n -------------------------------";
	cout<<"\n Enter the no of seats you want : ";

	while(1)    /* a while loop which ensures that
		the user enters a value under 10 only,otheerwise
		the user will get an error and he has to given
		the input again */
	{
		cin>>n;      /* where n is the no of seats
		the user wants to book */
		if(n>10)       // checking the condition if it is true
		{
			cout<<"\n ------------------------------------";
			cout<<"\n You can only book 10 seats at a time  ";
			cout<<"\n ------------------------------------";
			cout<<"\n Enter again :";
			continue;
		}
		else
		{
			break;
		}
	}   // end of while loop

	cout<<"\n ----------";
	cout<<"\n Enter row : ";

	    /* A while loop which ensures that
		the input of row is given under the available rows*/
	while(1)
	{
		cin>>row;
		if( row == 'A' || row == 'B' || row == 'C' || row == 'D' || row == 'E' || row == 'F' || row == 'G' )
		{
			break;
			  /* checking condition
			if given input is valid */
		}
		else
		{
			cout<<"\n ------------";
			cout<<"\n Invalid code";
			cout<<"\n Enter again : ";
			continue;
		}
	}
	row = (int)row - 64;
	 /* Changing the entered value to
	 numerical value as positioning in an array is done with numbers*/

	for(int i=1 ; i<=n ; i++)
	{
	/* a loop which will be
	executed n number of times,
	in which the input of the seats has been taken*/
	while(1)
	{
/* A while loop which takes the input of the seat to be booked and
then it checks if the seat is available,if not then it will display
an error message regarding that and the inout will be taken again,and
then again the same process will be done,if the seat will be available
then that particular seat will be changed to book and then the while loop
will be closed*/

			cout<<"\n ----------- ";
			cout<<"\n Enter seat : ";
			while(1)
			{
				cin>>st[i];
				/* an array of size 11 which stores
			the seat number as the seat number has to be
			displayed in the ticket */
				if( st[i] <= 10 )
				{
					break;
				}
				else
				{
					cout<<"\n ============= ";
					cout<<"\n Invalid seat ";
					cout<<"\n Enter again : ";
					continue;
				}
			}

			if( date[d].time[t].seat[m][row][st[i]] == 'B')
			{       // error message
				cout<<"\n ------------------------------------------------";
				cout<<"\n Sorry Seat already booked, Select another seat :";
			}
			else  //changing to booked
			{
				date[d].time[t].seat[m][row][st[i]] = 'B';
				break;
			}
		}  // end of while loop
	}   // end of for loop
}

void login(char log_db[6][20] , char pass_db[6][20], int (&succ) )
/* The function is being used as sighining in thing which
takes the input of login id and password of the user and then
it checks both with the password and login database arrays inside the loop,
if the program finds them in the same postion and matching
,the program allows the user to book tickets or else
the user wont be able to enter the program */
{
	clrscr();
	char log[20],pass[20];   /* where log is being used for
	taking the input of login id and the pass
	array is being used to take the input of password */
	cout<<"\n --------------------------------------------------------";
	cout<<"\n Enter you username and password to book tickets to login ";
	cout<<"\n --------------------------------------------------------";
	cout<<"\n Enter 'guest' as id and password both if u want to login as guest : ";
	cout<<"\n        -----     " ;
	cout<<endl;
	/* Suppose the user is new,
	then he/she can use a general id and password which is 'guest'*/


  while(1)  /* this while loop takes the input of the login id and password
  and then checks it with the two arrays,if the user will enter
   correct credentials then the program will come  out of the while
   loop else the user will asked to give the input(s) again untill
    the match is found */
  {
	cout<<"\n ---------------";
	cout<<"\n Enter login id :";
	fflush(stdin);
	gets(log);

	cout<<"\n ---------------";
	cout<<"\n Enter password :";
	fflush(stdin);
	gets(pass);

	for(int i=0 ; i<6 ; i++) // checking with database
	{
		if( !strcmp(log_db[i],log) && !strcmp(pass_db[i],pass) )
		{
			cout<<"\n ------------";
			cout<<"\n user found !";
			cout<<"\n Login Sucessfull ";
			cout<<"\n -----------------";
			getch();
			clrscr();
			succ=1;
			break;
		}

		else
		{
			cout<<endl;
			continue;
		}
	}

	if(succ == 1)
	{
		break;
	}
	clrscr();
  } // end of while loop
}

void snacks(float (&total_snacks),char menu[6][60],float snacks_prc[6])
/* A function which displays the list of snacks
if the user want to book the snacks in advanced
and then it calculates the price if selected*/
{
int n,a=0;
char ch=0;
	again:         /* an goto label if
	the user wants to select the snacks again */
	clrscr();
	cout<<"\n ------------";
	cout<<"\n ** *MENU* ** \n ";
	cout<<"\n ----------------------------------------------";
	cout<<"\n |SN|           ITEM            |    PRICE    |";
	cout<<"\n ----------------------------------------------";

	for(int i=1;i<=5;i++)  /*the for loop will be executed 5
	times of the user cant book more than 5 items */
	{
		cout<<"\n"<<menu[i];      //displayin the menu
		cout<<"\n ----------------------------------------------";
	}
	cout<<"\n Enter how many items you want to book? :";

	while(1)/* the while loop which ensures
	 that the user enters a vlue under 5 */
	{
		cin>>n;  // no of items
		if(n>=1 && n<=5)
		{
			break;
		}
		else
		{
			cout<<"\n ---------------------------";
			cout<<"\n You can only book 5 items  ";
			cout<<"\n ---------------------------";
			cout<<"\n Enter again : ";
			continue;
		}
	}
	total_snacks = 0;  // price fo snacks
	for(i = 1; i <= n ;i++)
	{
		cout<<"\n -----------------";
		cout<<"\n Enter item code : ";

			while(1)/* while loop which
			checks that the entered code is valid */
			{
				cin>>a;
				/*a variable for the item code given in
				 the menu*/

					if(a>=1 && a<=5)
					{
						break;
					}

					else
					{
					cout<<"\n -------------";
					cout<<"\n Invalid code ";
					cout<<"\n -------------";
					cout<<"\n Enter again : ";
					continue;
					}
			}

		total_snacks += snacks_prc[a];  //calculation of price
	}

	clrscr();
	cout<<"\n --------------------------------";
	cout<<"\n Total price for selected meals : "<<total_snacks<<" OMR ";
	cout<<"\n --------------------------------";

cout<<"\n Are you sure you want to book snacks ? \n Press y to procede or else press 'a'to select item(s) again otherwise snacks will  not be booked :";
/* asking the user if he wants to make selections
again or cancel the snacks items*/
	while(1)
	{       /* The while loop check0s weather the enter
		 variable is corrct or no,if not,user will asked to give the input again */
		cin>>ch;

		if( ch == 'A' || ch == 'a' || ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N')
		{
			break;
		}
		else

		{
			cout<<"\n Invalid code, Enter again:";
			continue;
		}
	} // End of while loop

	if( ch == 'Y' || ch == 'y' )
	{
		cout<<"\n Price of snacks will be added to you total amount ";
	}

	else if(ch == 'n' || ch == 'N' )
	{
		total_snacks = 0;
	}

	else if( ch == 'A' || ch == 'a' )
	{
		goto again;
	}
}

void seatprc(char row,int n,float (&price_seat))
/* This function calculates the total price of seats
   according to the row & the no of seats */
{
	int price=0;
	if(row == 'A' || row == 'B')
	{
		price = 3.00;
	}

	else if(row == 'C' || row == 'D')
	{
		price = 2.50;
	}
	else if(row == 'E' || row == 'F')
	{
		price = 2.20;
	}
	else if( row == 'G' )
	{
		price = 2.00;
	}
	else
	{
		//do nothing
	}

price_seat=(n*price);

}

void ticket(char row,int st[11],int n,float price_snacks,float price_seats,int d,int t,int m,char movie[5][30],char date_db[6][10],char show[6][30])
/* This is for the purpose of displaying ticket only,after
all the process of booking and calculating prices, all the values
and seats and all are passed to this function to display the ticket */
{
	clrscr();
	float total = price_snacks + price_seats + (n*tax);
	/* a variable which calculates
	 the overall price including tax */
	cout<<endl;
	cout<<"|=============================================|"<<endl;
	cout<<"|                  IMAX, SOHAR                |"<<endl;
	cout<<"|=============================================|"<<endl;
	cout<<"| Show Details :                              |"<<endl;
	cout<<"| =============                               |"<<endl;
	cout<<"| Movie : "<<movie[m]<<"           "<<endl;
	cout<<"| Date  : "<<date_db[d]<<" 2019                      |"<<endl;
	cout<<"| Show Time : "<<show[t]<<"       |"<<endl;
	cout<<"| --------------------------------------------|"<<endl;
	cout<<"| Booking Details :                           |"<<endl;
	cout<<"| =================                           |"<<endl;
	cout<<"| Row     :  "<<row<<"                                |"<<endl;
	cout<<"| Seat(s) : ";
	for(int i =1; i<=n ; i++)
	{
		cout<<" "<<st[i];
	}
	cout<<endl;
	cout<<"| --------------------------------------------|"<<endl;
	cout<<"| Price Details :                             |"<<endl;
	cout<<"| ==============                              |"<<endl;
	cout<<"| Total Seats Booked : "<<n<<"                      |"<<endl;
	cout<<"| Total [seats(s)] = "<<price_seats<<"                        |"<<endl;
	cout<<"| Total [snack(s)] = "<<price_snacks<<"                        "<<endl;
	cout<<"| Tax : "<<(n*tax)<<" OMR                               |"<<endl;
	cout<<"| Total amount paid : "<<total<<" OMR                "<<endl;
	cout<<"| ============================================|"<<endl;
	cout<<"|  -------  Thanks for choosing Imax   -------|"<<endl;
	cout<<"| ============================================|"<<endl;
getch();

}

void cancel(shtime (&date)[6],int d,int t,int m,int n,int st[11],char row)
/* This function will change the seats back to available
if the user stops the booking process in between */

{
	row = (int)row - 64;
	for(int i = 1 ; i <= n ; i++ )
	{
		for( int j = 1 ; j <= n ; j++ )
		{
			date[d].time[t].seat[m][row][st[i]]='A';
		}
	}
}

void main()
{
clrscr();
shtime date[6];  /* structure element which contains the seating map of
respective date and the show timings and diplays accodingly*/

int i,j,m=0,d=0,t=0,n=0;  /*where i and j are being used for the loops
 d,t,n are used as the day,show time and no of seats respectively*/

int succ=0;
int row=0; /* int succ assures that the user has logged in when succ
is equal to 1 whereas the variable row stores the seat variable which
has been inputed by the user   */

char ch;/* the variable ch is being used as a choice variable,
like to ask users choice in so many different places,only one variable ch is being used */

int st[11]={0};
/* an array of size 11 to store the seat numbers
because we need it at the time of displaying in the ticket */

float price_snacks=0,price_seat=0;
/* variables for the price of snacks and ticket*/

int flag=0;
	/* to initialize teh seat map as available*/
	asg(date,d,t,m);
	char  log_db[6][20]  = /* to store the login credentials*/
			       {
				  {"itz_sajal_"},
				  {"_.calvia_"},
				  {"sajalsahu8"},
				  {"sajal15"},
				  {"sajal16"},
				  {"guest"}
			       };

	char  pass_db[6][20] = {
				 {"#goHOME@143"},
				 {"mujhenahipata"},
				 {"GOhome"},
				 {"SAjal15"},
				 {"SAjal16"},
				 {"guest"},
			       };
	  /* for the movies available*/
	  char movie[5][30] =  { {"     "},
				 {"1. AVENGERS: INFINITY WAR"},
				 {"2. JHONNY ENGLISH"},
				 {"3. BIRD BOX"},
				 {"4. ROBOT 2.O"}
			       };
	 /* show times available*/
	 char show[6][30]  =    {
				 {"      "},
				 {"1. 10:00 A.M to 12:45 P.M"},
				 {"2. 01:00 P.M to 02:30 P.M"},
				 {"3. 03:00 P.M to 05:45 P.M"},
				 {"4. 06:15 P.M to 09:00 P.M"},
				 {"5. 09:20 P.M to 11:50 P.M"},
			       };
	/* dates*/
	char date_db[6][10]  =    {
				 {"      "},
				 {"1. 01 Jan"},
				 {"2. 02 Jan"},
				 {"3. 03 Jan"},
				 {"4. 04 Jan"},
				 {"5. 05 Jan"},
	/*for snacks*/		       };
	char menu[6][60] = {
				{"     "},
				{" |1 |     Popcorn               |  1.00 OMR   |"},
				{" |2 |     Pepsi(250 ML)         |  0.50 OMR   |"},
				{" |3 |     Sweet Corn            |  1.50 OMR   |"},
				{" |4 |     Momos(4 pcs.)         |  2.50 OMR   |"},
				{" |5 |     Combo(popcorn+pepsi)  |  1.20 OMR   |"} };

	// price of snacks
	float snacks_prc[6] = { 0,1.00,0.500,1.50,2.50,1.20 };
while(1)     /* loop for the program to execute infinte times */
{

	/*making the prices zero after user gets out*/
	while(1)    /* for one time login*/
	{

		start :
	       /*goto label*/
		price_snacks=0,price_seat=0;
		m=0,d=0,t=0;
		succ=0;
		welcm(succ);
		     /* function to display "IMAX ,SOHAR"*/

		mov_disp(movie,m);
		/* for the displaying the
		movie and taking the input of it*/
		date_disp(date_db,d,movie,m);
		/* to dislay the available dates and
		take the input of the date*/
		time_disp(show,movie,m,t,d,date_db);
		/* to dislay the available show time(s)
		for a particular movie and
		taking the input of it*/

		clrscr();
		welcm(succ);
		disp(date,d,t,m);
		/* to display the seat map for the user t select */
		cout<<"\n ------------------------------------------";
		cout<<"\n Do you want to book ticktes in this show ?";
		cout<<"\n ------------------------------------------";
		cout<<"\n Enter y to proceede ,\n press m to get directed to main menu,\n or else enter e to exit : ";
		/* asking user's choice if he/she wants to book ticket in
		 this particular movie or no, if yes then the program will go
		 further or else it will allow the user to select
		  the movie again*/
		while(1)
		{
			cin>>ch;
			if( ch == 'y' || ch == 'Y' || ch == 'e' || ch == 'E' || ch == 'M' || ch == 'm' || ch == 's' )
			{
				break;
			}
			else
			{
				cout<<"\n ------------";
				cout<<"\n Invalid code";
				cout<<"\n ------------";
				cout<<"\n Enter again :";
				continue;
			}
		}      // end of while loop

			if( ch == 'y' || ch == 'Y')
			{
				flag = 1;
				/* if the value of flag is one that
				means the user has selected to proceede
				further without any change*/

			}
			else if( ch == 'e' || ch == 'E' )
			{
				exit(0);
			}
			else if(ch == 'm' || ch == 'M' )
			{
				goto start;
			}
			else
			{
				//do nothing
			}

		if( flag == 1 )
		{
			login(log_db,pass_db,succ);
			/* login function*/

			if( succ == 1)
			{
				disp(date,d,t,m);
				getch(); // to hold sreen
				input(date,d,t,m,n,st,row);
				/* this particular function will
				take the input of seats and change
				the selected seats to booked */
				welcm(succ);
				disp(date,d,t,m);
				seatprc(row,n,price_seat);
				/* the function will calculate the
				total amount which has to be paid by the
				 user at the end accordingly */

				welcm(succ);
				cout<<"\n Do you want to book Snacks,\n Press y if yes \n Press E to exit withour booking or else press n :";


				while(1)
				{
					cin>>ch;
					if( ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N'|| ch == 'e' || ch == 'E' )
					{
						break;
					}
					else
					{
						cout<<"\n ==================== ";
						cout<<"\n Inalid code entered : ";
						cout<<"\n Enter again : ";
						continue;
					}
				}

				if( ch == 'y' || ch == 'Y' )
				{
					snacks(price_snacks,menu,snacks_prc);
					/* fumction to display the snacks menu
					and if the user wants to book snacks
					in advanced  and calculation of price
					   */
				}
				else if( ch == 'e' || ch == 'E')
				{
					cancel(date,d,t,m,n,st,row);
					flag=2;
				}
				/* final calculation of price and displaying of ticket */
				if(flag != 2)
				{
					ticket(row,st,n,price_snacks,price_seat,d,t,m,movie,date_db,show);
				}
			}
			 // end of if statement w.r.t "if(supp==1)"
			else
			{
				//do nothing
			}

		}
		// end of if statement w.r.t "if(flag==1)"

		else
		{
			// do nothing
		}
		//to get out of the while loop so that another user can book
		clrscr();
		cout<<"\n -----------------";
		cout<<"\n Press E to exit : ";
		cin>>ch;
		while(1)
		{
			if( ch == 'E' || ch == 'e' )
			{
				break;
			}
			else
			{
				cout<<"\n --------------";
				cout<<"\n Invalid code :";
				continue;
			}
		}

		if( ch == 'E' || ch == 'e' )
		{
			break;
		}

		else
		{
			// do nothing
		}
	}//end of while loop
	/*this exit starement is
	to come out of the program i.e close the program*/
	clrscr();
	cout<<"\n ------------------------------";
	cout<<"\n Enter E to close the program : ";
	cin>>ch;
		if( ch == 'e' || ch == 'E' )
		{
			exit(0);
		}
		else
		{
			continue;
		}

getch();
end:
/* Goto label*/
}// end of while loop
}//end of prog







