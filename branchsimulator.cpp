#include<iostream>
#include<string>
#include<vector>
#include<bitset>
#include<fstream>
#include<iomanip>
#include <string>
#include <list>
#include<math.h>
using namespace std;
#define MemSize 1000 // memory size, in reality, the memory size should be 2^32, but for this lab, for the space resaon, we keep it as this large number, but the memory is still 32-bit addressable.
int m;
int k;
char rf = '1';
int NM;
int lenn = 0;
bitset<8> BHR(0xff);
string flag;
list<string> con;
//int binaryToDecimal(int n)
//{
//	int num = n;
//	int decim = 0;
//
//	// Initializing base value to 1, i.e 2^0 
//	int base = 1;
//
//	int temp = num;
//	while (temp) {
//		int last_digit = temp % 10;
//		temp = temp / 10;
//
//		decim += last_digit * base;
//
//		base = base * 2;
//	}
//
//	return decim;
//}
int binaryToDecimal(string B_, int k) {
	int n__ = 0;
	for (int i = 0; i < k; i++)
	{
		n__ = n__ * 2 + (B_[i] - '0');
	}
	return n__;
}
int main(int argc, char* argv[])
{


	ifstream in("trace.txt");
	string filename;
	string line;
	/*list<string> instr;*/
	int l = 0;
	vector<string> Ins_;
	if (in)
	{
		while (getline(in, line))
		{

			/*l++;*/
			/*if (l == 162) {
				int hj = 0;
			}
			if (l == 68) {
				int hj = 0;
			}
			if (l == 139) {
				int hj = 0;
			}*/
			

			
			Ins_.push_back(line);


			

			lenn++;
		}


	}
	


	vector<int> ConfigM;
	ConfigM.resize(2);
	ifstream configmem;
	string line_;
	int i = 0;
	configmem.open("config.txt");
	if (configmem.is_open())
	{
		while (getline(configmem, line_))
		{

			ConfigM[i] = stoi(line_);
			i++;

		}
	}
	else cout << "Unable to open file";
	configmem.close();
	m = ConfigM[0];
	k = ConfigM[1];
	string B = BHR.to_string();
	string B_ = B.substr(0, k);
	/*int NM = pow(2, k) - 1;*/
	
	vector<vector<bitset<2>>>PHT(pow(2, m), vector<bitset<2>>(pow(2, k), bitset<2>(3)));
	
	
	
	

	
	
	
			

			
		for (int i = 0; i < lenn; i++) {
			if (i == 5) {
				int jh = 0;
			}
			if (B_ != "") {


				NM = binaryToDecimal(B_, k);
			}
			else {
				NM = 0;
			}

			string Ins = Ins_[i];
			unsigned long pc_ulValue = 0;
			int brchresult_ulValue = 0;
			bitset<32> PC;
			sscanf(Ins.substr(0, 8).c_str(), "%x", &pc_ulValue);
			PC = bitset<32>(pc_ulValue);
			string index = PC.to_string();
			string Index = index.substr(32 - m, m);


			bitset<32> val_ = bitset<32>(Index);
			int val = val_.to_ulong();
			
			bitset<2> f = PHT[val][NM];
			if (f == 3 || f == 2) {
				flag = "1";
			}
			else {
				flag = "0";
			}
			ofstream printstate;
			printstate.open("trace.txt.out", std::ios_base::app);
			if (printstate.is_open())
			{
				string Ins_ =flag;
				printstate << Ins_ << endl;
			}
			printstate.close();

			//update
			int mm = 0;
			char rf = Ins[10- 1];
			if (rf == '1') {
				if (f == 2 || f == 0) {
					PHT[val][NM] = bitset<2>(f.to_ulong() + 1);
				}
				if (f == 1) {
					PHT[val][NM] = bitset<2>(f.to_ulong() + 2);
				}


				
			}
			else if(rf == '0') {
				//update BHR and PHT
				
				

				if (f == 3 || f == 1) {
					PHT[val][NM] = bitset<2>(f.to_ulong() - 1);
				}
				if (f == 2) {
					PHT[val][NM] = bitset<2>(f.to_ulong() - 2);
				}

				




			}
			/*for (int u = 0; u < k - 1; u++) {
				B_[u + 1] = B_[u];
			}
			B_[0] = rf;
			cout << B_[0] << endl;*/
			B_ = B_.substr(0, B_.length() - 1);
			B_ = rf + B_;


		}
		return 0;
	}











	




















