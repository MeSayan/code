import java.util.Scanner;
public class MovieTestDrive
{
	public static void main(String args[])
	{	
		Scanner sc=new Scanner(System.in);
		Movie ob1=new Movie();
		ob1.title="Gone With The Stock";
		ob1.genre="Tragic";
		ob1.rating=-2;
		
		Movie ob2=new Movie();
		ob2.title="Lost in Cubic Space";
		ob2.genre="Comedy";
		ob2.rating=5;
		
		Movie ob3=new Movie();
		ob3.title="Byte Club";
		ob3.genre="Tragic but ultimately Uplifting";
		ob3.rating=127;
	 	System.out.println("Enter a number to print a movie(1-3)");
		int input=sc.nextInt();
		if(input==1)
		ob1.playIt();
		else if(input==2)
		ob2.playIt();
		else if(input==3)
		ob3.playIt();	 	
		else
		System.out.println("Wrong Input!");
	}
}		
