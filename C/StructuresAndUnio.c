/*Unlike Structures unions are capable of storing only one field.
 * During compile time the compiler searches through all fields of the union and finds the field that requires largest memory and reserves this 
 * amount of memory for the union
 * So if an union contains a char and a float the space allocated will be sizeof(float) irrespective of wether we are storing a char or a float
 * What is the use of a  union
 * Structs and unions are enums are used to represent data structures found in real world.
 * Such structures are often not as simple as a single integer or floating point value.
 * Take the instance of an apple.
 * An apple is a data system and has plethora of parameteres required to describe it completely and all of the parameters need not be of same data type.
 * To cope with such problems of complex and real data structures in C We use either struc , union or enum  as required by problem.
 * 
 * Unions are used when we want to represent a  parameter or property found in real world but its data type in C cannot be explicitly defined.
 * Take for instance the parameter quantity.
 * Depending upon the context of its use it may be linear, 2D or even 3d as in volume .The corresponding data types end up being integer and floats.
 * Thus one fixed parameter has multiple data types.
 * To solve this problem use unions.
 * 
 * SYNTAX
 * union union_name
 * {
 *    data type union_field1;
 *    data type union_field2;
 *    ..
 *   ...
 * };
 * To Acces the fields use either
 *a) Designated Initializers
 * b)Dot convention 
 * 
 * BitFields allow you to store a field with a custom number of bits
 * Bit Fields should be decalared as unsigned int
 * EXAMPLES
 * 
 * 
 * 
 * 
 */
#include <stdio.h>

typedef enum
{  
	COUNT,POUNDS,PINTS
}units_of_measure;

typedef union
{
	short count;
	float weight;
	float volume;
}quantity;

typedef struct
{
	const char * name;
	const char* country;
	quantity amount;
	units_of_measure units;
}fruit_order;

typedef struct
{
	unsigned int first_visit:1; //For true or false check 1 bit is enough
	unsigned int come_again:1; //For true or false check 1 bit is enough
	unsigned int fingers_lost:3;// 3 bits sufficient to represent five fingers
	unsigned int shark_attack:1;
	unsigned int days_a_week:3;//3 bits can store values from 0 to 7
n}bitfields_example;

void display(fruit_order order)
{
	printf("This fruit order contains\n");
	
	if(order.units==PINTS)
	printf("%2.2f pints of %s\n",order.amount.volume,order.name);
	else if(order.units==POUNDS)
	printf("%2.2f lbs of %s\n",order.amount.weight,order.name);
	
	else if(order.units==COUNT)
	printf("%i %s\n",order.amount.count,order.name);
	
}
int main()
{
	fruit_order apples={"Apples","England",.amount.count=144,.units=COUNT}; //Using Designated Initialiser for union
    fruit_order strawberries={"Strawberries","Spain",.amount.weight=17.6,POUNDS};//Using designated Initializer  for union amount
	fruit_order orange_juice={"Orange Juice","U.S.A",.amount.volume=10.5,PINTS};	
	display(apples);
	display(strawberries);
	display(orange_juice);
	
	return 0;
}
			
