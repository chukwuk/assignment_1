/****************************************
******** Program:encondata.hpp
********* Author:Kingsley C. Chukwu
******* Date: 1/20/2019
******* Description:Reads a data from a text file and allow the user to explore the data.
******* Input: string
******* Output: Sorts the data and output the sorted data from the file
*******************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <climits>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;


/******************************************************
 * *************** Structure:Declaration of the county structure
 * *************** Function:store data of different primitive for different counties
 * *****************************************************************/

struct county {
    string name;
    float unemployed_2007;
    float unemployed_2015;
    int med_income;
};

/******************************************************
 * **************** Structure:Declaration of the state structure
 * **************** Function:store data of different primitive type for different states
 * ******************************************************************/

struct state {
    string name;
    float unemployed_2007;
    float unemployed_2015;
    int med_income;
    int num_counties;
    struct county* counties;
};

/******************************************************
 * *************** Function:allocate_states
 * *************** Description:used to allocate an array of struct state
 * ************** Parameters:number of states in the text_data.txt
 * *************** Pre-Conditions:accepts an integer, which is the number of states
 * *************** Post-Conditions: returns an array of struct state.
 * *****************************************************************/


struct state* allocate_states(int num_states);

/******************************************************
 * *************** Function:allocate_counties
 * *************** Description:used to allocate an array of struct county
 * ************** Parameters:number of counties
 * *************** Pre-Conditions:accepts an integer, which is the number of counties
 * *************** Post-Conditions: return an array of struct county
 * *****************************************************************/

struct county* allocate_counties(int num_counti);

/******************************************************
 * *************** Function:state_sort_med_income
 * *************** Description:it is used compare household income of different states
 * ************** Parameters:two struct state
 * *************** Pre-Conditions:accepts two different struct state variable
 * *************** Post-Conditions: return false or true
 * *****************************************************************/

bool state_sort_med_income(const struct state &s1, const struct state &s2);

/******************************************************
 * **************** Function:state_sort_unemployed_2015
 * **************** Description:it is used compare 2015 unemployment rate of different states
 * *************** Parameters:two struct state
 * **************** Pre-Conditions:accepts two different struct state variable
 * **************** Post-Conditions: return false or true
 * ******************************************************************/

bool state_sort_unemployed_2015(const struct state &s1, const struct state &s2);

/******************************************************
 * **************** Function:state_sort_unemployed_diff
 * **************** Description:it is used compare change in unemployement from 2007 to 2015 for different states
 * *************** Parameters:two struct state
 * **************** Pre-Conditions:accepts two different struct state variable
 * **************** Post-Conditions: return false or true
 * ******************************************************************/

bool state_sort_unemployed_diff(const struct state &s1, const struct state &s2);

/******************************************************
 * **************** Function:county_sort_med_income
 * **************** Description:it is used compare household income of different counties
 * *************** Parameters:two struct county
 * **************** Pre-Conditions:accepts two different struct county variable
 * **************** Post-Conditions: return false or true
 * ******************************************************************/


bool county_sort_med_income(const struct county &s1, const struct county &s2);

/******************************************************
 * ***************** Function:county_sort_unemployed_2015
 * ***************** Description:it is used compare 2015 unemployment rate of different counties
 * **************** Parameters:two struct counties
 * ***************** Pre-Conditions:accepts two different struct county variables
 * ***************** Post-Conditions: return false or true
 * *******************************************************************/


bool county_sort_unemployed_2015(const struct county &s1, const struct county &s2);

/******************************************************
 * ***************** Function:county_sort_unemployed_diff
 * ***************** Description:it is used compare change in unemployement from 2007 to 2015 for different counties
 * **************** Parameters:two struct county
 * ***************** Pre-Conditions:accepts two different struct county variables
 * ***************** Post-Conditions: return false or true
 * *******************************************************************/

bool county_sort_unemployed_diff(const struct county &s1, const struct county &s2);

/******************************************************
 * ****************** Function:data_to_explore
 * ****************** Description:it is used to print out different option of data the user can explore for the states
 * ***************** Parameters:nothing
 * ****************** Pre-Conditions:nothing
 * ****************** Post-Conditions: prints out different option of data the user can explore
 * ********************************************************************/


void data_to_explore();

/******************************************************
 * ******************* Function:data_to_explore_county
 * ******************* Description:it is used to print out different option of data the user can explore for the different counties in a state
 * ****************** Parameters:struct state
 * ******************* Pre-Conditions:accepts a struct state variable
 * ******************* Post-Conditions: prints out different option of data the user can explore
 * *********************************************************************/


void data_to_explore_county(struct state d_state);

/******************************************************
 * ******************* Function:data_to_explore_state
 * ******************* Description:it is used to print out states in which the user can explore the data for different counties in the state
 * ****************** Parameters:nothing
 * ******************* Pre-Conditions:nothing
 * ******************* Post-Conditions: prints out different states in which the user can explore
 * *********************************************************************/


void data_to_explore_state();

/******************************************************
 * ******************** Function:check_err
 * ******************** Description:it is used to check for invalid input when a user input a value to explore data for the states
 * ******************* Parameters:nothing
 * ******************** Pre-Conditions:nothing
 * ******************** Post-Conditions: returns the input of the user if the input is valid and if it is an invalid input, it will prompt the user again for a  valid input
 * **********************************************************************/


int check_err(); 

/******************************************************
 * ********************* Function:two_check_err
 * ********************* Description:it is used to check for invalid input when a user input a value to explore data for the counties in state
 * ******************** Parameters:struct state
 * ********************* Pre-Conditions:struct state variable
 * ********************* Post-Conditions: returns the input of the user if the input is valid and if it is an invalid input, it will prompt the user again for a valid input
 * ***********************************************************************/


int two_check_err(struct state d_state);

/******************************************************
 * ********************** Function:one_check_err
 * ********************** Description:it is used to check for invalid input when a user input a value to explore counties in a state
 * ********************* Parameters:nothing
 * ********************** Pre-Conditions:nothing
 * ********************** Post-Conditions: returns the input of the user if the input is valid and if it is an invalid input, it will prompt the user again for a valid input
 * ************************************************************************/


int one_check_err();

/******************************************************
 * *********************** Function:four_check_err
 * *********************** Description:it is used to check for invalid input when a user enter an input to decide if the user want to continue exploring the data or stop exploring the data
 * ********************** Parameters:nothing
 * *********************** Pre-Conditions:nothing
 * *********************** Post-Conditions: returns the input of the user if the input is valid and if it is an invalid input, it will prompt the user again for a valid input
 * *************************************************************************/


int four_check_err();

/******************************************************
 * *********************** Function:read_county_data
 * *********************** Description:it is used to store data of different counties into an array of struct county
 * ********************** Parameters:struct county, integer,  and ifstream
 * *********************** Pre-Conditions:accepts an array of struct county, number of counties, and an open file
 * *********************** Post-Conditions: fills the array of struct county with data of different counties
 * *************************************************************************/


void read_county_data(struct county* counties, int num_count, ifstream& rd_text);

/******************************************************
 * ************************ Function:read_state_data
 * ************************ Description:it is used to store data of different state  into an array of struct state
 * *********************** Parameters:struct state, integer,  and ifstream
 * ************************ Pre-Conditions:accepts an array of struct state, number of states, and an open file
 * ************************ Post-Conditions: fills the array of state with data of different state
 * **************************************************************************/


void read_state_data(struct state* d_state, int num_states, std::ifstream& rd_text);

/******************************************************
 * ************************ Function:data_to_be_explored
 * ************************ Description:it is used to print the data for different states requested by the user
 * *********************** Parameters:struct state, integers
 * ************************ Pre-Conditions:accepts an array of struct state, the user input, and number of states
 * ************************ Post-Conditions: prints out the data requested by the user
 * **************************************************************************/


void data_to_be_explored (struct state* d_state, int num_count, int num_states);

/******************************************************
 * ************************* Function:county_data_to_be_explored
 * ************************* Description:it is used to print the data for different counties in state, which was  requested by the user
 * ************************ Parameters:struct state, integers
 * ************************* Pre-Conditions:accepts an array of struct state, the user input, and number of states
 * ************************* Post-Conditions: prints out the data requested by the user
 * ***************************************************************************/


void county_data_to_be_explored (struct county* d_state, int num_count, int num_county, struct state dd_state); 

/******************************************************
 * ************************* Function:free_state_data
 * ************************* Description:it is used to free up memory
 * ************************ Parameters:struct state, integers
 * ************************* Pre-Conditions:accepts an array of struct state and number of states
 * ************************* Post-Conditions: frees up the memory
 * ***************************************************************************/


void free_state_data(struct state* d_state, int num_states);

 
 
