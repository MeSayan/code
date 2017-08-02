import java.util.Scanner;
public class MarketingPro
{	
	public static void main(String args[])
	{	Scanner sc=new Scanner(System.in);
		String wordListOne[]={"24/7","multi-Tier","30,000 foot","B-to-B"
							,"win-win","front-end","web-based","pervasive","smart","six-sigma","critical-path","dynamic"};
		String wordListTwo[]={"empowered","sticky","value-added","oriented","distributed","clustered","branded","outside-the-box","positioned","networked","focused","leveraged","aligned","targeted","shared","cooperative","accelarated"};
		
		String wordListThree[]={"process","tipping-point","solution"
		,"architechure","core competency","strategy","mindshare","portal","space","vison","paradigm","mission"};
		int oneLength=wordListOne.length;
		int twoLength=wordListTwo.length;
		int threeLength=wordListThree.length;
		
		/*Generate Random Numbers.
		
			Math.random() gives a double value between 0  and 1.
			to get random number between 0 and n1 we multiply Math.random with n1 and then type-cast to integer values
		*/
		int rand1=(int)(Math.random()*oneLength);
		int rand2=(int)(Math.random()*twoLength);
		int rand3=(int)(Math.random()*threeLength);
		String phrase=wordListOne[rand1]+" "+wordListTwo[rand2]+" "+wordListThree[rand3];
		System.out.println(phrase);
		System.out.println("Want to continue our chit-chat?(y/n)");
		if(sc.next().charAt(0)=='y')
		main(null);
	}
}
