public class Player
{
	int number=0;
	String name="";
	Player(String s)
	{
		name=s;
	}
	public void guess()
	{
		number=(int)(Math.random()*10);
		
	}
}	