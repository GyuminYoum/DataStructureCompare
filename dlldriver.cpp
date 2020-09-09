#include "dll.hpp"
#include <iostream>
#include <fstream>
#include<chrono>
#include <ctime>
#include <thread>
#include <unistd.h>
#include <cstdlib>
using namespace std;


/* This function takes a string of multiple objects separated by a separator and splits them up and saves them to an array separately.
* the function then returns the value of number of variables.
* parameters: string s1(string given), char sep1(a separator used within the string), string string_array(an array capable of storing string type data), int size(size of the custom array)
*return: number of pieces the string was split to  */

int split (string s1, char sep1, string string_array[], int size)
{
    //n is the number of pieces the string was split to, and it is initialized at 0.
    int n=0;
    // string s2 will serve as a variable that will temporarily store the values of characters of string s1. It is initialized with empty space.
    string s2= "";
    
    
    /* this method also works as it adds the separator at the end of the string and it will fall under the if statement below.
    s1= s1+ sep1;
    */
    
    //for loop was created from 0 to length of the string s1, while i was incrementing by 1 to show every character.
    for (int i=0; i < s1.length(); i++)
    {
        // if character of string s1 at the index i is not the separator given by user, the character is added to the string s2.
        if (s1[i] != sep1)
        {
            s2 += s1[i];
        }
        
        //if character of string s1 at the index i is the separator given by user, 
        else if (s1[i] == sep1)
        {
            //if else statement to test if it is a case of multiple separator next to each other or not. 
            //In the case of multiple separator next to each other, value wouldnt be stored in string s2, thus we tested for the length of s2.
            if (s2.length() != 0)
            {
                 // put string 2's value in to the array at value of n which is initialized at 0.
                string_array[n] = s2;
              // string s2 is then emptied
               s2 = "";
               // then the value of n is increased by 1.
               n++;
            }
            // else statement for the case of  multiple separators next to each other.
            else
            {
                // value of n stays the same.
                n=n;
            }
        }
        
    }
    
    // if the size of the array is big enough to store all the separated pieces of the string, and if the stored string has value of more than 0 indicating that its not the caes of multiple separators,
    // this particular if statement is for the last piece of the string to be split since it doesnt necessarily have the separator.
    if (n < size && s2.length() !=0)
    {
        // the string of the last split is stored in the array at index n, and n i incremented by 1.
        string_array[n]= s2;
        n++;
    }
    
    //if size of the array is not big enough to store all the separated pieces of the string, n=-1
    if (n > size)
    {
        n=-1;
    }
    
    // value of n is returned.
    return n;
}

// C++ program to find the execution time of code
int main()
{
	

    // the sleep methods below are for you to test with to
	// prove that the chrono start and end times are working correctly
	/*
	this_thread::sleep_for (std::chrono::seconds(4));
	sleep(3);
	*/
    dll LL1;
    
   string arr1[10000];
   float insertA[100];
   float searchA[100];
   float insertB[100];
   float searchB[100];
   int index=0;
   int lowerlimit=0;
   int upperlimit=100;
   int indexarrcount=0;
   int loop=0;
   int rng[100];
   int rng_value=0;
   ifstream read_in;
   int value1=0;
   string temp1;
   Node* currnode=NULL;
   ofstream read_out;
   read_in.open("dataSetA.csv");
   if (read_in.fail())
   {
       cout << "no valid file" << endl;
   }
   else
   {
       while(read_in >> temp1)
       {
           split(temp1, ',',arr1,10000);
       }
   }
   //while it hasn't been looped 100 times,
    while(index<100)
    {
        //measuring time, for insertion
        auto start = chrono::steady_clock::now();
       for (int i=lowerlimit; i<upperlimit; i++)
       {   
            currnode=LL1.gettail();
            if (currnode==NULL)
            {
                LL1.insert(stoi(arr1[i]));
            }
            else
            {
                LL1.insert(stoi(arr1[i]));

            }    
           
       }
       
       auto end = chrono::steady_clock::now();
       //end
       insertA[index]=(chrono::duration_cast<chrono::nanoseconds>(end - start).count())/100;
       //record data
       
       /*
        cout << "time: " << insert[index] << endl;
        */

       //random numbers in the range generated
        srand((unsigned)time(0));
        for (int i=0; i<100; i++)
        {
            rng_value=(rand()%upperlimit);
            rng[i]=rng_value;
        }
        
        //start measuring time,
        start = chrono::steady_clock::now();
        
        for (int i=0; i<100; i++)
        {
            value1=rng[i];
            LL1.search(stoi(arr1[value1]));
            /*
            cout << "searched key: " << LL1.search(stoi(arr1[value1]))->key << endl;
            */
        }
        
        end= chrono::steady_clock::now();
        //end measuring time.
        searchA[index]=(chrono::duration_cast<chrono::nanoseconds>(end - start).count())/100;
        //record time.
        
        //increment variables
        lowerlimit=lowerlimit+100;
        upperlimit=upperlimit+100;
        index++;
       
    }
    /*
        for (int i=0; i<100; i++)
        {
            cout << "insert Time: " << /*insert[i]insertA[i] << endl;
            cout << "search Time: " << searchA[i] << endl; 
        }
        */
    /*
    LL1.display();
    cout << "" << endl;
    */
    
    read_in.close();

    dll LL2;
    temp1="";
    index=0;
    lowerlimit=0;
    upperlimit=100;
    currnode=NULL;

    read_in.open("dataSetB.csv");
   if (read_in.fail())
   {
       cout << "no valid file" << endl;
   }
   else
   {
       while(read_in >> temp1)
       {
           split(temp1, ',',arr1,10000);
           /*
           cout << temp1 << endl;
           */
       }
   }
   //while it loops 100 times,
    while(index<100)
    {
        //start measuring time,
        auto start = chrono::steady_clock::now();
        
       for (int i=lowerlimit; i<upperlimit; i++)
       {
            currnode=LL2.gethead();
            if (currnode==NULL)
            {
                LL2.insert(stoi(arr1[i]));
            }
            else
            {
                LL2.insert(stoi(arr1[i]));

            }    
       }
       
       auto end = chrono::steady_clock::now();
       //end 
       insertB[index]=(chrono::duration_cast<chrono::nanoseconds>(end - start).count())/100;
       //record data for insertion
       
       /*
        cout << "time: " << insert[index] << endl;
        */

//randomize number in range.
        srand((unsigned)time(0));
        for (int i=0; i<100; i++)
        {
            rng_value=(rand()%upperlimit);
            rng[i]=rng_value;
        }
        
        //start measuring time,
        start = chrono::steady_clock::now();
        
        for (int i=0; i<100; i++)
        {
            value1=rng[i];
            LL2.search(stoi(arr1[value1]));
            /*
            cout << "searched key: " << LL1.search(stoi(arr1[value1]))->key << endl;
            */
        }
        
        end= chrono::steady_clock::now();
        //end 
        searchB[index]=(chrono::duration_cast<chrono::nanoseconds>(end - start).count())/100;
        //record time for search B
        
        //increment the variables.
        lowerlimit=lowerlimit+100;
        upperlimit=upperlimit+100;
        index++;
       
    }
    /*
    LL2.display();
    */
    /*
        for (int i=0; i<100; i++)
        {
            cout << "insert Time: " << /*insert[i]insertB[i] << endl;
            cout << "search Time: " << searchB[i] << endl; 
        }
    */
    
    //export data.
    read_out.open("result_dll.csv");
    for (int i=0; i<100; i++)
    {
        read_out << insertA[i] << ",";
    }
    read_out << "," << endl;
    for (int j=0; j<100; j++)
    {
        read_out << searchA[j] << ",";
    }
    read_out << "," << endl;
    for (int k=0; k<100; k++)
    {
        read_out << insertB[k] << ",";
    }
    read_out << "," << endl;
    
    for (int l =0; l<100; l++)
    {
        read_out << searchB[l] << ",";
    }
    read_out << "," << endl;
    read_out.close();
    
}
