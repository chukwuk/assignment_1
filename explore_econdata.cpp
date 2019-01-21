/****************************************
 * ******* Program:explore_encodata.cpp
 * ******** Author:Kingsley C. Chukwu
 * ****** Date: 1/20/2019
 * ****** Description:Reads a data from a text file and allow the user to explore the data.
 * ****** Input: string
 * ****** Output: Sorts the data and output the sorted data from the file
 * ******************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <climits>
#include <cstring>
#include <fstream>
#include <algorithm>
#include "econdata.hpp"

using namespace std;






/******************************************************
 * ************************** Function:main
 * ************************** Description:it uses the combination of the different function to perform task
 * ************************* Parameters:text_data.txt file
 * ************************** Pre-Conditions:test_data.txt file
 * ************************** Post-Conditions: continue to output data for the user until the user decide not continue exploring data
 * ****************************************************************************/

int main(int argc, char* argv[]) {
   int repeter = 1;
   if (argc!=2) { cout <<"Invalid argument, Please input just one argument"<<endl; return 0;  }
   while (repeter == 1) {
   ifstream rd_text(argv[1]);
   if  (!rd_text) {
   cout <<"Uh no, kele_data.txt could not be opened for reading!"<<endl;
   return 0;
   }
   int num_count;  int num_states; struct state* d_state; int count_num; int num_counties;
   rd_text >> num_states;
   d_state = allocate_states(num_states);
   read_state_data(d_state, num_states, rd_text);
   num_count = check_err();
   if (num_count > 0 && num_count < 7) {
      data_to_be_explored(d_state, num_count, num_states);
   }
   if (num_count == 7) {
      count_num = one_check_err();
      num_counties = two_check_err(d_state[count_num]);
      county_data_to_be_explored(d_state[count_num].counties, num_counties, d_state[count_num].num_counties, d_state[count_num]);
   }
   repeter = four_check_err();
   free_state_data(d_state, num_states);
   }
   cout <<" "<<endl; cout <<"Thank you for exploring the data"<<endl; cout<<" "<<endl;
   return 0;
}

