#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int board[100][100];
int size;
int startRow, startCol;
int counter;

void load() {
	char received;
	counter = 0;
	for(int row =0; row < size; row++)
		for(int col=0; col < size; col++)
			{
				cin >> received;
				if( received == '.' ) board[row][col] = 0;
				else if ( received == 'W' ) {
					board[row][col] = 2;
					startRow=row;
					startCol=col;
				} else board[row][col] = 1;
			}
}

int memo[110][110], gone[110][110];

#define MOD 1000007

int solve(int whiteRow, int whiteCol) {
  int &res = memo[whiteRow][whiteCol];
  if (gone[whiteRow][whiteCol]) return res;
  gone[whiteRow][whiteCol] = 1;

	if( whiteRow == 0 ) {
		res = 1;
		return res;
	}
	
	if( whiteCol-1 >= 0 && board[whiteRow-1][whiteCol-1]== 0) {
		res += solve(whiteRow-1, whiteCol-1);
    res %= MOD;
  }
	else if ( whiteRow-2 >= 0 && whiteCol-2 >=0 && board[whiteRow-1][whiteCol-1]== 1 && board[whiteRow-2][whiteCol-2]== 0) {
		res += solve(whiteRow-2,whiteCol-2); 
    res %= MOD;
  }
	if( whiteCol+1 < size && board[whiteRow-1][whiteCol+1]== 0) {
		res += solve(whiteRow-1, whiteCol+1);
    res %= MOD;
  }
	else if ( whiteRow-2 >= 0 && whiteCol + 2 < size && board[whiteRow-1][whiteCol+1]== 1 && board[whiteRow-2][whiteCol+2]== 0) {
		res += solve(whiteRow-2,whiteCol+2);
    res %= MOD;
  }

  return res;
}

void printMatrix() {
	for(int row =0; row < size; row++) {	
		for(int col=0; col < size; col++)
			cout << board[row][col] << " ";
		cout << endl;
	}
}


int main(){
	int testCases;
	
	cin >> testCases;
	
	for( int i=0; i < testCases; i++)
	{
    memset(memo, 0, sizeof(memo));
    memset(gone, 0, sizeof(gone));
		cin >> size;
		load();
		//printMatrix();
		counter = solve(startRow,startCol);
		cout << "Case " << i+1 << ": " << counter << endl;
	}
	return 0;
}
