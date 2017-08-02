import java.util.Scanner;
public  class GuessGame
{
	Player p1;
	Player p2;
	Player p3;
	
	public static void main(String args[]) {
        GuessGame game1 = new GuessGame();
            game1.startGame();
    }
	
	public void startGame()
	{	
		Scanner sc=new Scanner(System.in);
		p1=new Player("Sayan");
		p2=new Player("Rounak");
		p3=new Player("Sagnik");
		
		int guessp1,guessp2,guessp3;
		guessp1=guessp2=guessp3=0;
		
		boolean p1isRight,p2isRight,p3isRight;
		p1isRight=p2isRight=p3isRight=false;
		
		
		System.out.println("Computer::I'm thinking of a number between 0 and 9");
		while(true)
		{
			int targetNumber=(int)(Math.random()*10);
			System.out.println("Computer::Number to guess is "+targetNumber);
			p1.guess();
			p2.guess();
			p3.guess();
			
			
			guessp1=p1.number;
			System.out.println(p1.name+" Guessed: "+guessp1);
			guessp2=p2.number;
			System.out.println(p2.name+" Guessed: "+guessp2);
			guessp3=p3.number;
			System.out.println(p3.name+" Guessed: "+guessp3);
			
			if(guessp1==targetNumber)
			p1isRight=true;
			if(guessp2==targetNumber)
			p2isRight=true;
			if(guessp3==targetNumber)
			p3isRight=true;
			
			if(p1isRight||p2isRight||p3isRight)
			{
				System.out.println("We Have a Winner! and he is: ");
                if(p1isRight)
                    System.out.println("Sayan");
                else if (p2isRight)
                    System.out.println("Rounak");
                else
                    System.out.println("Sagnik");
				System.out.println("Continue Game? (y/n)");
				if(sc.next().charAt(0)!='y')
				break;
				
			}
			else
			System.out.println("Players will have to try Again!");
		}	
	}

}					 
