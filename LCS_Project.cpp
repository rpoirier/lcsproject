#include<iostream>
#include<vector>
using namespace std;

typedef vector<char> row;
typedef vector<row> matrix;

void printv(vector<char>x);
void printlcs(matrix B, vector<char> X, int i, int j);

int main() {

	vector<char> X(1,'0');
	vector<char> Y(1,'0');

	matrix B;
	matrix C;

	//take and accomodate user input to vector X
	char next;
	cout<<"enter your first sequence. Type # when you are done"<<endl;
	do {
		cin>>next;
		if (next!='#')
			X.push_back(next);
	} while(next!='#');

	//take user's input and accomodate it into vector Y
	
	cout<<"enter your second sequence. Type # when you are done"<<endl;
	do {
		cin>>next;
		if (next!='#')
			Y.push_back(next);
	} while(next!='#');

	//print vector X and Y for debugging

	printv(X);
	printv(Y);
	cout<<endl;

	//construct matricies
	
	const int number_of_rows = Y.size();
	const int number_of_columns = X.size();

	//resize matricies

	B.resize(number_of_rows);
		for (int j=0; j<number_of_rows; j++)
			B[j].resize(number_of_columns);

	C.resize(number_of_rows);
		for (int j=0; j<number_of_rows; j++)
			C[j].resize(number_of_columns);

	//put 0 in every cell in the first column of both matricies

	for(int j=0; j<number_of_columns; j++) {
		B[0][j]='0';
		C[0][j]='0';
	}

	//put 0 in every cell in the first row of both matricies

	for(int j=0; j<number_of_rows; j++) {
		B[j][0]='0';
		C[j][0]='0';
	}

	//dress both matricies

	for(int i=1; i<number_of_rows; i++)
		for(int j=1; j<number_of_columns; j++) {
			if(X[j]==Y[i]) {
				C[i][j]=C[i-1][j-1]+1;
				B[i][j]='D';
			}
			if(X[j]!=Y[i]) {
				if(C[i-1][j]>=C[i][j-1]) {
					C[i][j]=C[i-1][j];
					B[i][j]='U';
				} else {
					//not sure about this logic
					C[i][j]=C[i][j-1];
					B[i][j]='L';
				}
			}
		}

	//print both matrices
	for(int i=0; i<number_of_rows; i++)
		for(int j=0; j<number_of_columns; j++) {
			if(j!=number_of_columns-1) {
				cout<<C[i][j]<<" ";
			} else {
				cout<<C[i][j]<<endl;
			}
		}
	cout<<endl;

	for(int i=0; i<number_of_rows; i++)
		for(int j=0; j<number_of_columns; j++) {
			if(j!=number_of_columns-1) {
				cout<<B[i][j]<<" ";
			} else {
				cout<<B[i][j]<<endl;
			}
		}
	cout<<endl;

	cout<<"Here is your longest common subsequence"<<endl;
	printlcs(B, X, number_of_rows-1, number_of_columns-1);
	cout<<endl;


return 0;
}

void printv(vector<char>x) {
	int i, j=x.size();
	for(i=0; i<j; i++)
		cout<<x[i]<<" ";

	cout<<endl;
}

void printlcs(matrix B, vector<char> X, int i, int j) {
	//if we are at the first row of a column, stop
	if(i==0||j==0)
		return;
	//if we see a diagonal arrow, call printlcs passing the coords of the diag cell and print X[j]
	if(B[i][j]=='D') {
		printlcs(B, X, ????, ????);
		cout<<X[j];
	}
	//if we see an up arrow, call printlcs passing the coordinates of the appropriate cell
	if(B[i][j]=='U') {
		printlcs(B, X, ????, ????);
	}
	//if we see a left arrow, call printlcs passing the coordinates of the appropriate cell
	if(B[i][j]=='L') {
	printlcs(B, X, ????, ????);
	}
}
