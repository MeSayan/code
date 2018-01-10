#include <stdio.h>
#include <math.h>

/*======================================================================
 * ===================================================================*/

struct BLOCK_DATA {
	int l,r;
	int ans;
	int left_ones,right_ones;
};

class SQRTBlocks {
	public:
	int N;
	int * A;
	BLOCK_DATA * BLOCKS ;
	int BLOCK_SIZE;
	
	SQRTBlocks(int n) {
		A = new int[n];
		N = n;
		BLOCK_SIZE = (int) ceil(sqrt(N));
		BLOCKS = new BLOCK_DATA[BLOCK_SIZE];
	}
	
	void MoveInData(int src[]) {
		int i;
		for( i = 0; i < N; i++)
			A[i] = src[i];
	}
	
	void SetUpBlocks() {
		int i,j,k,c=0;
		for( i = 0; i < BLOCK_SIZE; i++) {
			BLOCKS[i].l = 0 + i*BLOCK_SIZE;
			BLOCKS[i].r = (BLOCK_SIZE-1) + i*BLOCK_SIZE;
			BLOCKS[i].ans = 0;
			BLOCKS[i].left_ones = BLOCKS[i].right_ones = 0;
		}
	    // Last Block
	    BLOCKS[BLOCK_SIZE-1].r = N-1;
	    
	    for( i = 0; i <BLOCK_SIZE; i++) {	
			// calculate ans for each block
			for( j = BLOCKS[i].l; j <= BLOCKS[i].r; j++) {
				if ( A[j] == 1) {
					for( k = j; k <= BLOCKS[i].r && A[k] != 0; k++) 
						c++;
					BLOCKS[i].ans += (c*(c+1))/2;
					j = k;
					c = 0;
				}
			}
			//Calculate left and right ones
			for( j = BLOCKS[i].l; j <= BLOCKS[i].r && A[j] != 0; j++)
				BLOCKS[i].left_ones++;
			for( j = BLOCKS[i].r; j >= BLOCKS[i].l && A[j] != 0; j--)
			    BLOCKS[i].right_ones++;
	  }
  }
	  
	void Update(int position, int value) {
		  int i, j, c =0;
		  A[position] = value;
		  BLOCK_DATA current_block = BLOCKS[position/BLOCK_SIZE];
		  current_block.ans = 0;
		  
		  
		  //Worst Case O(sqrt(N)))
		  
		  // Recompute Current Block Again
		  for(i = current_block.l; i <= current_block.r; i++) {
			  for( j = i; j <= current_block.r && A[j] != 0; j++)
					c++;
			  current_block.ans += (c*(c+1))/2;
			  i = j;
			  c = 0;
		  }
		  // Compute Left ones
		  for( i = current_block.l; i <= current_block.r && A[i] != 0; i++) 
				current_block.left_ones++;
		  // Compute Right ones
		  for( i = current_block.r; i >= current_block.l && A[i] != 0; i--) 
				current_block.right_ones++;
		
	}
	
	void PrintBlocks() {
		
		int i;
		for( i = 0; i < BLOCK_SIZE; i++) {
			printf("%d %d  %d \n",BLOCKS[i].l, BLOCKS[i].r,BLOCKS[i].ans);
			printf("Left Ones = %d and Right Ones = %d \n",
					BLOCKS[i].left_ones,BLOCKS[i].right_ones);
		}
	}
	
	BLOCK_DATA Merge(BLOCK_DATA i, BLOCK_DATA j) {
		
		//Computes and returns result of combination of blocks i and j
		BLOCK_DATA temp = new BLOCK_DATA;
		temp.ans = i.ans + j.ans 
			       + i.right_ones * j.left_ones);
	    temp.l = i.l;
	    temp.r = j.r;
	    
	    // Merging for Left Ones
	    if( i.left_ones == BLOCK_SIZE )
			temp.left_ones = i.left_ones + j.right_ones;
		else
			temp.left_ones = i.left_ones;
		
		// Merging for Right Ones
		if( j.right_ones == BLOCK_SIZE)
			temp.right_ones = j.right_ones + i.right_ones;
		else
			temp.right_ones = j.right_ones;
		
		return temp;
	}
	
	int Query(int L, int R) {
		int start_block = L/BLOCK_SIZE;
		int end_block = R/BLOCK_SIZE;
		
		BLOCK_DATA start, end;
		
		//Combine intermediate blocks first
		int i = start_block + 1;
		for( ;i <= end_block-2; i++) {
			temp = Merge(temp,BLOCKS[i+1]);
		
		//Combine firt block
		start.l = L;
		start.r = start_block.r;
		start.ans = start.left_ones = start.right_ones = 0;
		
		for( i = start.l, i <= start.r; i++) {
			for( j = i; j <= start.r && A[j] != 0; j++) 
					c++;
			start.ans += (c*(c+1))/2;
		}
		// Calculate right ones
		for(i = start_block.r; i >= L && A[i] != 0; i--)
			start.right_ones++;
		
		temp = Merge(start,temp);
			
		//Combine last block
		end.l = BLOCKS[end_block].l;
		end.r = R;
		end.ans = end.left_ones = end.right_ones = 0;
		c = 0;
		for( i = end.l, i <= R; i++) {
			for( j = i; j <= R && A[j] != 0; j++) 
					c++;
			end.ans += (c*(c+1))/2;
		}
		// Calculate left ones
		for(i = start_block.r; i >= L && A[i] != 0; i--)
			start.right_ones++;
		
		temp = Merge(start,temp);
		
		
};

/*======================================================================
 * ===================================================================*/
		
int main() {
	SQRTBlocks a(9);
	int A[9] = {1,1,0,1,0,1,0,1,1};
	a.MoveInData(A);
	a.SetUpBlocks();
	a.PrintBlocks();
	return 0;
}

