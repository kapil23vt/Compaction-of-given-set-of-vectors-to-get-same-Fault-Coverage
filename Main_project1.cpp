#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Vtop.h"
#include "Vtop__Syms.h"
using namespace std;

int main () {
  int x;
  int branch_not_cov=0; int vectors = 0;
  Vtop* circuit = new Vtop();
  string line;
  float coverage; float coverage2;

  ifstream myfile ("lev_vec.vec");
  ofstream myfile2 ("output.vec");

  getline(myfile, line);
  int n= atoi(line.c_str());
  myfile2 << n <<endl; // number of inputs added to output file
  
  getline(myfile, line);
  string set_vector = line;
  //myfile2 << set_vector << endl; //1st set_vector sent to output file
  
  vector<bool> bitset(n, false);
  vector< vector<bool> > vectorset; //vectorset will be used for flagging 
  
  circuit->sim_init();

  while (line!="END"){
	 
char *fileName = (char*)line.c_str();
for(int s=0;s<n;s++)
{
if(fileName[s]=='0')
{
	bitset[s]= false;
}
else
{
	bitset[s]=true;
}	
}
vectorset.push_back(bitset); // saving all the vectors in vectorset

circuit-> set_input_with_reset(bitset);
circuit-> eval();
circuit-> toggle_clock();
circuit-> eval();
circuit->toggle_clock();

	  getline(myfile, line);
	  vectors++;
	}
	int cov_pts=circuit->num_branch_cov_pts();
	
	for(int branch=0;branch<cov_pts;branch++){
		
			x=circuit->get_cov_pt_value(branch)	;
			if(x==0) {branch_not_cov++; }
				
	}
	//cout << "cov_pts =" << cov_pts << endl;
	//cout << "branch_not_cov =" << branch_not_cov << endl;
	
	coverage=(float)(((float)cov_pts-(float)branch_not_cov)/(float)cov_pts)*(float)100;
    cout << "Branch coverage of the circuit in % = " << coverage << endl;
    //cout << "Vectors are : " << vectors << endl;
    //vector 
    circuit->clear_coverage();
    vector<bool> array((vectors), false);// array = false false false
    
    for (int b = 1; b< (vectors -1); b++){ 
		
		circuit->sim_init();
		circuit->clear_coverage();

		for (int a =0; a<vectors; a++){
				if ((a==b) || (array[a]==true)) 
				continue;
				else
				{
					circuit-> set_input_with_reset(vectorset[a]);
					circuit-> eval();
					circuit-> toggle_clock();
					circuit-> eval();
					circuit->toggle_clock();
				}
			}
		cov_pts=circuit->num_branch_cov_pts();
		branch_not_cov = 0;
	
	for(int branch=0;branch<cov_pts;branch++){
	x=circuit->get_cov_pt_value(branch)	;
	if(x==0){ branch_not_cov++; } }
	
	coverage2=(float)(((float)cov_pts-(float)branch_not_cov)/(float)cov_pts)*(float)100;
	//cout << "Branch coverage of the circuit in % = " << coverage2 << endl;	

if (coverage2==coverage){
	
		array[b] = true;
		// if the coverage is same after skipping that vector, 
		// making it true, to skip it from further calculation
		}

}
	
	for (int m =0;m<vectors;m++)
	{
		if (array[m]==false)
		{
			for (int k=0;k<n;k++)
			{
				myfile2 << vectorset[m][k]; // vectors are added bit by bit to output file
			}
			myfile2<<endl; 
		}
		

	}
	  myfile2 << "END" << endl;	// output file ended with "END"

	  cout << "Please open output.vec to find new test set with the same file format" << endl; 	
}



