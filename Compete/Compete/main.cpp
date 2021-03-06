#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "Compete.h"

using namespace std;

unsigned long timeA;
unsigned long timeB;

void determineResult(int res, int& aWin, int& bWin, int& tie){
	switch(res){
		case 0:
			tie++;	//ƽ��
			cout << "A and B tied" << endl;
			break;
		case 1:
			aWin++;	//AӮ
			cout << "A - won" << endl;
			break;
		case 2:
			bWin++;	//BӮ
			cout << "B - won" << endl;
			break;
		case 3:
			bWin++;	//A����,��BӮ
			cout << "A - bug occurred" << endl;
			break;
		case 4:
			bWin++;	//A�����Ƿ�����,��BӮ
			cout << "A - made illegal step" << endl;
			break;
		case 5:
			aWin++;	//B����,��AӮ
			cout << "B - bug occurred" << endl;
			break;
		case 6:
			aWin++;	//B�����Ƿ�����,��AӮ
			cout << "B - made illegal step" << endl;
			break;
		case 7:
			bWin++;	//A��ʱ,��BӮ
			cout << "A - timed out" << endl;
			break;
		case 8:
			aWin++;	//B��ʱ,��AӮ
			cout << "B - timed out" << endl;
			break;
		case -1:
			cout << "Load File A Error" << endl;
			break;
		case -2:
			cout << "Load File B Error" << endl;
			break;
		case -3:
			cout << "Function Interface Error in A" << endl;
			break;
		case -4:
			cout << "Function Interface Error in B" << endl;
			break;
		default:
			cout << "Platform Error" << endl;
			break;
	}
}

int main(int argc, char* argv[]){
	if(argc < 5){
		cout << "Usage:" << endl;
		cout << "Compete <StrategyA.dll> <StrategyB.dll> <result file name> <times to compete>" << endl;
		cout << argc <<endl;
		for(int i=0;i<argc;++i)
			cout << "[" << i << "]" << argv[i] << endl;
		cout<<endl;
		//system("pause");
		return 0;
	}
	bool simpleInfo = (argc == 6);
	int res;
	ofstream out;
	if(!simpleInfo) out.open(argv[3]);
	else out.open(argv[3],ios::app);

	int aWin = 0, bWin = 0, tie = 0;
	int numRounds = atoi(argv[4]);
	
	for(int i = 0; i < numRounds; i++){
		cout << "Round " << i << ":" << endl;
		if(!simpleInfo) out << i << ":" << endl;
		
		Data* data = new Data();

		cout << "A first:" << endl;
		timeA = 0;
		timeB = 0;
		//data->reset();
		res = compete(argv[1], argv[2], true, data);
		determineResult(res, aWin, bWin, tie);
		if(!simpleInfo) out << res << "\t" << timeA << "\t" << timeB << endl;
		
		cout << "B first:" << endl;
		timeA = 0;
		timeB = 0;
		data->reset();
		res = compete(argv[1], argv[2], false, data);
		determineResult(res, aWin, bWin, tie);
		if(!simpleInfo) {
			out << res << "\t" << timeA << "\t" << timeB << endl;
			out << endl;
		}
		cout << endl;

		delete data;
	}
	
	double rioAWin = (1.0 * aWin) / (2.0 * numRounds);
	double rioBWin = (1.0 * bWin) / (2.0 * numRounds);
	double rioTie = (1.0 * tie) / (2.0 * numRounds);

	if(!simpleInfo)		{
		out << "Stat:" << endl;
		out << "ratio of A wins : " << rioAWin << endl;
		out << "ratio of B wins : " << rioBWin << endl;
		out << "ratio of Tie : " << rioTie << endl;
		out << endl;
	}
	else {
		out << "fight " << atoi(argv[5]) <<" level:" << endl;
	}
	out << "ratio of (A wins + tie) : " << rioAWin + rioTie << endl;
	if(!simpleInfo) out << "ratio of (B wins + tie) : " << rioBWin + rioTie << endl;
	
	out.close();
	
	cout << "Stat:" << endl;
	cout << "ratio of A wins : " << rioAWin << endl;
	cout << "ratio of B wins : " << rioBWin << endl;
	cout << "ratio of Tie : " << rioTie << endl;
	cout << endl;
	cout << "ratio of (A wins + tie) : " << rioAWin + rioTie << endl;
	cout << "ratio of (B wins + tie) : " << rioBWin + rioTie << endl;
	//system("pause");
	return 0;
}
