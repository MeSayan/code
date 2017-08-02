import java.io.*;
public class reader
{
	InputStreamReader isr=new InputStreamReader(System.in);
	BufferedReader br=new BufferedReader(isr);
	
	public static void main(String args[]) 
	{
		try
		{
		new reader().writeOut();
		}
		catch(Exception e)
		{
			System.out.println("Exception  found");
		}
	}

void writeOut() throws IOException
{
	String s=br.readLine();
	System.out.println("Hello you have enntered:"+s);
}
}
