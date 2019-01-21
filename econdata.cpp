/****************************************
******* Program:analysedata
******** Author:Kingsley C. Chukwu
****** Date: 1/20/2019
****** Description:Reads a data from a text file and allow the user to explore the data.
****** Input: string
****** Output: Sorts the data and output the sorted data from the file
******************************************/

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
*************** Structure:Declaration of the county structure
*************** Function:store data of different primitive for different counties
*****************************************************************/


/******************************************************
**************** Structure:Declaration of the state structure
**************** Function:store data of different primitive type for different states
******************************************************************/


/******************************************************
*************** Function:allocate_states
*************** Description:used to allocate an array of struct state
************** Parameters:number of states in the text_data.txt
*************** Pre-Conditions:accepts an integer, which is the number of states
*************** Post-Conditions: returns an array of struct state.
*****************************************************************/


struct state* allocate_states(int num_states) {
       struct state* d_state = new struct state [num_states];
       return d_state;
} 

/******************************************************
*************** Function:allocate_counties
*************** Description:used to allocate an array of struct county
************** Parameters:number of counties
*************** Pre-Conditions:accepts an integer, which is the number of counties
*************** Post-Conditions: return an array of struct county
*****************************************************************/

struct county* allocate_counties(int num_counti) {
    struct county* n_count = new struct county [num_counti];
    return n_count; 

}

/******************************************************
*************** Function:state_sort_med_income
*************** Description:it is used compare household income of different states
************** Parameters:two struct state 
*************** Pre-Conditions:accepts two different struct state variable
*************** Post-Conditions: return false or true 
*****************************************************************/

bool state_sort_med_income(const struct state &s1, const struct state &s2) {
     return (s1.med_income < s2.med_income);
}


/******************************************************
**************** Function:state_sort_unemployed_2015
**************** Description:it is used compare 2015 unemployment rate of different states
*************** Parameters:two struct state
**************** Pre-Conditions:accepts two different struct state variable
**************** Post-Conditions: return false or true
******************************************************************/

bool state_sort_unemployed_2015(const struct state &s1, const struct state &s2) {
      return (s1.unemployed_2015 < s2.unemployed_2015);
}


/******************************************************
**************** Function:state_sort_unemployed_diff
**************** Description:it is used compare change in unemployement from 2007 to 2015 for different states
*************** Parameters:two struct state
**************** Pre-Conditions:accepts two different struct state variable
**************** Post-Conditions: return false or true
******************************************************************/

bool state_sort_unemployed_diff(const struct state &s1, const struct state &s2) {
      return (abs(s1.unemployed_2015-s1.unemployed_2007) < abs(s2.unemployed_2015-s2.unemployed_2007));    
}
/******************************************************
**************** Function:county_sort_med_income
**************** Description:it is used compare household income of different counties
*************** Parameters:two struct county
**************** Pre-Conditions:accepts two different struct county variable
**************** Post-Conditions: return false or true
******************************************************************/


bool county_sort_med_income(const struct county &s1, const struct county &s2) {
     return (s1.med_income < s2.med_income);
}
/******************************************************
***************** Function:county_sort_unemployed_2015
***************** Description:it is used compare 2015 unemployment rate of different counties
**************** Parameters:two struct counties
***************** Pre-Conditions:accepts two different struct county variables
***************** Post-Conditions: return false or true
*******************************************************************/


bool county_sort_unemployed_2015(const struct county &s1, const struct county &s2) {
      return (s1.unemployed_2015 < s2.unemployed_2015);
}

/******************************************************
***************** Function:county_sort_unemployed_diff
***************** Description:it is used compare change in unemployement from 2007 to 2015 for different counties
**************** Parameters:two struct county
***************** Pre-Conditions:accepts two different struct county variables
***************** Post-Conditions: return false or true
*******************************************************************/

bool county_sort_unemployed_diff(const struct county &s1, const struct county &s2) {
      return (abs(s1.unemployed_2015-s1.unemployed_2007) < abs(s2.unemployed_2015-s2.unemployed_2007));
}

/******************************************************
****************** Function:data_to_explore
****************** Description:it is used to print out different option of data the user can explore for the states
***************** Parameters:nothing
****************** Pre-Conditions:nothing
****************** Post-Conditions: prints out different option of data the user can explore
********************************************************************/


void data_to_explore() {
   cout <<" "<<endl; cout<<"Enter between 1-7 to Choose a data to explore"<<endl; cout <<" "<<endl;
   cout <<"Print the state with the highest median household income (1) "<<endl; cout <<" "<<endl;
   cout <<"Print the state with the lowest  median household income (2) "<<endl; cout <<" "<<endl;
   cout <<"Print the state with the highest unemployment in 2015 (3) "<<endl; cout <<" "<<endl;
   cout <<"Print the state with the lowest unemployment in 2015 (4) "<<endl; cout <<" "<<endl;
   cout <<"Print the state in sorted order by change in unemployment from 2007 to 2015 (5) "<<endl; cout <<" "<<endl;
   cout <<"Print the state in sorted order based on median household income (6) "<<endl; cout <<" "<<endl;
   cout <<"To explore different counties in different states (7) "<<endl; cout <<" "<<endl;
}

/******************************************************
******************* Function:data_to_explore_county
******************* Description:it is used to print out different option of data the user can explore for the different counties in a state
****************** Parameters:struct state
******************* Pre-Conditions:accepts a struct state variable
******************* Post-Conditions: prints out different option of data the user can explore
*********************************************************************/


void data_to_explore_county(struct state d_state) {
   cout <<" "<<endl; cout<<"Enter between 1-7 to explore data for the different counties in "<<d_state.name<<endl; cout <<" "<<endl;
   cout <<"Print the county with the highest median household income (1) "<<endl; cout <<" "<<endl;
   cout <<"Print the county with the lowest  median household income (2) "<<endl; cout <<" "<<endl;
   cout <<"Print the county with the highest unemployment in 2015 (3) "<<endl; cout <<" "<<endl;
   cout <<"Print the county with the lowest unemployment in 2015 (4) "<<endl; cout <<" "<<endl;
   cout <<"Print the county in sorted order by change in unemployment from 2007 to 2015 (5) "<<endl; cout <<" "<<endl;
   cout <<"Print the county in sorted order based on median household income (6) "<<endl; cout <<" "<<endl;
}

/******************************************************
******************* Function:data_to_explore_state
******************* Description:it is used to print out states in which the user can explore the data for different counties in the state
****************** Parameters:nothing
******************* Pre-Conditions:nothing
******************* Post-Conditions: prints out different states in which the user can explore
*********************************************************************/


void data_to_explore_state() {
   cout <<"To explore counties data in different states, enter 0 for Oregon,1 for Pennsylvania,2 for  Calfornia"<<endl; cout <<" "<<endl;
}

/******************************************************
******************** Function:check_err
******************** Description:it is used to check for invalid input when a user input a value to explore data for the states
******************* Parameters:nothing
******************** Pre-Conditions:nothing
******************** Post-Conditions: returns the input of the user if the input is valid and if it is an invalid input, it will prompt the user again for a  valid input
**********************************************************************/


int check_err() {
   int r_w = 0; string uzo; int num_input;
 do {
       if (r_w > 0) {
          cout << " " << endl;
          cout << "Oops!, Invalid Input, Please enter a valid input"<<endl;
       }
       r_w++;
       cout << " " <<endl;
       data_to_explore();
       getline (cin, uzo);
       cout << " "<<endl;
    }  while  ((uzo != "1") && (uzo != "2") && (uzo != "3") && (uzo != "4") && (uzo != "5") && (uzo != "6") && (uzo != "7"));
    num_input = atoi(uzo.c_str()); 
    return num_input;
}
/******************************************************
********************* Function:two_check_err
********************* Description:it is used to check for invalid input when a user input a value to explore data for the counties in state
******************** Parameters:struct state
********************* Pre-Conditions:struct state variable
********************* Post-Conditions: returns the input of the user if the input is valid and if it is an invalid input, it will prompt the user again for a valid input
***********************************************************************/


int two_check_err(struct state d_state) {
   int r_w = 0; string uzo; int num_input;
 do {
       if (r_w > 0) {
          cout << " " << endl;
          cout << "Oops!, Invalid Input, Please enter a valid input"<<endl;
       }
       r_w++;
       cout << " " <<endl;
       data_to_explore_county(d_state);
       getline (cin, uzo);
       cout << " "<<endl;
    }  while  ((uzo != "1") && (uzo != "2") && (uzo != "3") && (uzo != "4") && (uzo != "5") && (uzo != "6") && (uzo != "7"));
    num_input = atoi(uzo.c_str());
    return num_input;
}

/******************************************************
********************** Function:one_check_err
********************** Description:it is used to check for invalid input when a user input a value to explore counties in a state
********************* Parameters:nothing
********************** Pre-Conditions:nothing
********************** Post-Conditions: returns the input of the user if the input is valid and if it is an invalid input, it will prompt the user again for a valid input
************************************************************************/


int one_check_err() {
   int r_w = 0; string uzo; int num_input;
 do {
       if (r_w > 0) {
          cout << " " << endl;
          cout << "Oops!, Invalid Input, Please enter a valid input"<<endl;
       }
       r_w++;
       cout << " " <<endl;
       data_to_explore_state();
       getline (cin, uzo);
       cout << " "<<endl;
    }  while  ((uzo != "0") && (uzo != "1") && (uzo != "2"));
    num_input = atoi(uzo.c_str());
    return num_input;
}

/******************************************************
*********************** Function:four_check_err
*********************** Description:it is used to check for invalid input when a user enter an input to decide if the user want to continue exploring the data or stop exploring the data 
********************** Parameters:nothing
*********************** Pre-Conditions:nothing
*********************** Post-Conditions: returns the input of the user if the input is valid and if it is an invalid input, it will prompt the user again for a valid input
*************************************************************************/


int four_check_err() {
   int r_w = 0; string uzo; int num_input;
 do {
       if (r_w > 0) {
          cout << " " << endl;
          cout << "Oops!, Invalid Input, Please enter a valid input"<<endl;
       }
       r_w++;
       cout << " " <<endl;
       cout <<"Do you want to explore more data enter 1 for yes and 0 for no"<<endl;
       getline (cin, uzo);
       cout << " "<<endl;
    }  while  ((uzo != "0") && (uzo != "1"));
    num_input = atoi(uzo.c_str());
    return num_input;
}

/******************************************************
*********************** Function:read_county_data
*********************** Description:it is used to store data of different counties into an array of struct county
********************** Parameters:struct county, integer,  and ifstream
*********************** Pre-Conditions:accepts an array of struct county, number of counties, and an open file
*********************** Post-Conditions: fills the array of struct county with data of different counties
*************************************************************************/


void read_county_data(struct county* counties, int num_count, ifstream& rd_text) {
     for (int k = 0; k < num_count; k++) {
       rd_text>>counties[k].name>>counties[k].unemployed_2007>>counties[k].unemployed_2015>>counties[k].med_income;
       }
}

/******************************************************
************************ Function:read_state_data
************************ Description:it is used to store data of different state  into an array of struct state
*********************** Parameters:struct state, integer,  and ifstream
************************ Pre-Conditions:accepts an array of struct state, number of states, and an open file
************************ Post-Conditions: fills the array of state with data of different state 
**************************************************************************/


void read_state_data(struct state* d_state, int num_states, std::ifstream& rd_text) {
    for (int i = 0; i < num_states; i++) {
       rd_text>>d_state[i].name>>d_state[i].unemployed_2007>>d_state[i].unemployed_2015>>d_state[i].med_income>>d_state[i].num_counties;
       d_state[i].counties = allocate_counties(d_state[i].num_counties);
       read_county_data(d_state[i].counties, d_state[i].num_counties, rd_text);
}
}

/******************************************************
************************ Function:data_to_be_explored
************************ Description:it is used to print the data for different states requested by the user
*********************** Parameters:struct state, integers
************************ Pre-Conditions:accepts an array of struct state, the user input, and number of states
************************ Post-Conditions: prints out the data requested by the user
**************************************************************************/


void data_to_be_explored (struct state* d_state, int num_count, int num_states) {
    if (num_count==1 || num_count==2 || num_count==6) { 
        sort (d_state, d_state+num_states, state_sort_med_income);
        if (num_count==1) {cout <<"The state with the highest median household income is "<<d_state[num_states-1].name<<endl; }
        else if (num_count==2) { cout <<"The state with the lowest median household income is "<<d_state[0].name<<endl; }
        else { 
        cout <<"State in sorted with the  Median household income " <<endl; cout <<" "<<endl; 
        for (int i = 0; i < num_states; i++) {
              cout<<d_state[i].name<<"                 "<<d_state[i].med_income<<endl;
         }
         }
    }
    if (num_count==3 || num_count==4) {
        sort (d_state, d_state+num_states, state_sort_unemployed_2015);
        if (num_count==3) {cout <<"The state with the highest unemployement in 2015 is "<<d_state[num_states-1].name<<endl; }
        else { cout <<"The state with the lowest unemployment in 2015 is "<<d_state[0].name<<endl; }
    }
    if (num_count==5) {
        sort (d_state, d_state+num_states, state_sort_unemployed_2015);
        cout <<"State in sorted order by change in unemployement from 2007 to 2015 (from smallest to largest) " <<endl; cout <<" "<<endl;
        for (int i = 0; i < num_states; i++) {
              cout<<d_state[i].name<<endl;

    }
    }
}

/******************************************************
************************* Function:county_data_to_be_explored
************************* Description:it is used to print the data for different counties in state, which was  requested by the user
************************ Parameters:struct state, integers
************************* Pre-Conditions:accepts an array of struct state, the user input, and number of states
************************* Post-Conditions: prints out the data requested by the user
***************************************************************************/

         
void county_data_to_be_explored (struct county* d_state, int num_count, int num_county, struct state dd_state) {
    if (num_count==1 || num_count==2 || num_count==6) {
        sort (d_state, d_state+num_county, county_sort_med_income);
        if (num_count==1) {cout <<"The county with the highest median household income in "<< dd_state.name <<" is "<<d_state[num_county-1].name<<endl; }
        else if (num_count==2) { cout <<"The county with the lowest median household income in "<<dd_state.name<<" is "<<d_state[0].name<<endl; }
        else {
        cout <<"Counties in "<<dd_state.name<<" sorted with the Median household income " <<endl; cout <<" "<<endl;
        for (int i = 0; i < num_county; i++) {
              cout<<d_state[i].name<<"                 "<<d_state[i].med_income<<endl;
         }
         }
    }
    if (num_count==3 || num_count==4) {
        sort (d_state, d_state+num_county, county_sort_unemployed_2015);
        if (num_count==3) {cout <<"The county "<<dd_state.name<<" with the highest unemployement in 2015 is "<<d_state[num_county-1].name<<endl; }
        else { cout <<"The county in "<<dd_state.name<<" with the lowest unemployment in 2015 is "<<d_state[0].name<<endl; }
    }
    if (num_count==5) {
        sort (d_state, d_state+num_county, county_sort_unemployed_2015);
        cout <<"counties in "<<dd_state.name<<" sorted by change in unemployement from 2007 to 2015 (from smallest to largest) " <<endl; cout <<" "<<endl;
        for (int i = 0; i < num_county; i++) {
              cout<<d_state[i].name<<endl;

    }
    }
}

/******************************************************
************************* Function:free_state_data
************************* Description:it is used to free up memory
************************ Parameters:struct state, integers
************************* Pre-Conditions:accepts an array of struct state and number of states
************************* Post-Conditions: frees up the memory
***************************************************************************/


void free_state_data(struct state* d_state, int num_states)  {
     for (int i=0; i<num_states; i++) {
         delete [] d_state[i].counties;  
     }
     delete [] d_state;
}


/******************************************************
************************** Function:main
************************** Description:it uses the combination of the different function to perform task
************************* Parameters:text_data.txt file
************************** Pre-Conditions:test_data.txt file
************************** Post-Conditions: continue to output data for the user until the user decide not continue exploring data
****************************************************************************/


