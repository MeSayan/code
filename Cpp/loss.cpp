#include <iostream>
#include <cmath>

using namespace std;

double cumulativeLossCoefficient(int Day,double P) {
	return (1.0 - pow((1-P),Day));
}


int main() {
	int N = 6,i,j;
	int V[N+1] = {0,1,1,1,1,1,1};
	double P[N+1] = {0.0,0.1,0.2,0.3,0.1,0.4,0.5};
	
	
	for( i = 1; i <= N; i++) {
		// Calculate cumulative loss till N-i Days
		double min_loss = cumulativeLossCoefficient(N-i,P[i])
						  * (double) V[i];
		int p = i;
		
		for( j = i+1; j <= N; j++) {
			double loss_j = cumulativeLossCoefficient(N-i,P[j])
							* (double)V[j];
			if (loss_j < min_loss) {
				min_loss = loss_j;
				p = j;
			}
		}
		
		//Swap 
		swap(V[i],V[p]);
		swap(P[i],P[p]);
	}
	
	for( i = 1; i <= N; i++) {
		cout << V[i] << " " << P[i] << " ";
	}
	
	cout << endl;
	
	//Calculating Total volume of goods left
	double result = 0;
	for( i = N; i >= 1; i--) {
		result += V[i]*pow(1-P[i],N-i);
	}
	
	cout << "Volume of goods left at the end of day " << N << " is "
		 << result << endl;
		 
	return 0;
}

	

