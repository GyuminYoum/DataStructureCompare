#include "hashchain.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
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
    Hashchain LL1(40009);
    
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
   int insertAcollision[100];
   int searchAcollision[100];
   int insertBcollision[100];
   int searchBcollision[100];
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
   //while it loops 100 times
    while(index<100)
    {
        //reset collision counts,
        LL1.setNumOfCollision(0);
        LL1.setSearchCollision(0);
        //start timing
        auto start = chrono::steady_clock::now();
        //add elements in the range
       for (int i=lowerlimit; i<upperlimit; i++)
       {   
            LL1.insertItem(stoi(arr1[i]));
       }
       //stop timing
       auto end = chrono::steady_clock::now();
       //record #collision
       insertAcollision[index]=LL1.getNumOfCollision();
       /*
       cout << LL1.getNumOfCollision() << endl;
       */
      //get time it took to insert in nanoseconds
       insertA[index]=(chrono::duration_cast<chrono::nanoseconds>(end - start).count())/100;
       
       /*
        cout << "time: " << insert[index] << endl;
        */
       //random numbers with in range and store it in array
        srand((unsigned)time(0));
        for (int i=0; i<100; i++)
        {
            rng_value=(rand()%upperlimit);
            rng[i]=rng_value;
        }
        
        //start measuring time
        start = chrono::steady_clock::now();
        
        for (int i=0; i<100; i++)
        {
            value1=rng[i];
            LL1.searchItem(stoi(arr1[value1]));
            /*
            cout << "searched key: " << LL1.search(stoi(arr1[value1]))->key << endl;
            */
        }
        //search for random numbers in the set
        
        end= chrono::steady_clock::now();
        //stop measuring.
        //record searchA collision
        searchAcollision[index]=LL1.getSearchCollision();
        /*
        cout << LL1.getSearchCollision() << endl;
        */
       //record time it took to search
        searchA[index]=(chrono::duration_cast<chrono::nanoseconds>(end - start).count())/100;
        
        //increment lowerlimit, upperlimit and index.
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

    Hashchain LL2(40009);
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
    while(index<100)
    {
        //reset both to 0.
        LL2.setNumOfCollision(0);
        LL2.setSearchCollision(0);
        //start measuring time
        auto start = chrono::steady_clock::now();
        
       for (int i=lowerlimit; i<upperlimit; i++)
       {
          LL2.insertItem(stoi(arr1[i]));
       }
       auto end = chrono::steady_clock::now();
       //end measuring time.
       //record collision and time,
       insertBcollision[index]=LL2.getNumOfCollision();
       insertB[index]=(chrono::duration_cast<chrono::nanoseconds>(end - start).count())/100;
       
       /*
        cout << "time: " << insert[index] << endl;
        */
       //randomize number
        srand((unsigned)time(0));
        for (int i=0; i<100; i++)
        {
            rng_value=(rand()%upperlimit);
            rng[i]=rng_value;
        }
        //start measuring
        start = chrono::steady_clock::now();
        
        //search random number
        for (int i=0; i<100; i++)
        {
            value1=rng[i];
            LL2.searchItem(stoi(arr1[value1]));
            /*
            cout << "searched key: " << LL1.search(stoi(arr1[value1]))->key << endl;
            */
        }
        
        end= chrono::steady_clock::now();
        //end measuring
        //record
        searchBcollision[index]=LL2.getSearchCollision();
        /*
        cout << LL2.getSearchCollision() << endl;
        */
        searchB[index]=(chrono::duration_cast<chrono::nanoseconds>(end - start).count())/100;

        //increment variables.
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
    read_out.open("chain_result.csv");
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
    for (int m=0; m<100; m++)
    {
        read_out << insertAcollision[m] << ",";
    }
    read_out << "," << endl;
    for (int n=0; n<100; n++)
    {
        read_out << searchAcollision[n] << ",";
    }
    read_out << "," << endl;
    for (int i=0; i<100; i++)
    {
        read_out<< insertBcollision[i] << ",";
    }
    read_out << "," << endl;
    for (int i=0; i<100; i++)
    {
        read_out << searchBcollision[i] << ",";
    }
    read_out << "," << endl;
    read_out.close();
    
}

    /*
    Hashchain hash3(103);
    for (int i=0; i<11; i++)
    {
        hash3.insertItem(i);
    }
    hash3.insertItem(104);
    hash3.insertItem(105);
    hash3.printTable();
    */

    
/*
    Hashquad hash2(40010);
    /*
    for(int i=0; i<20005; i++)
    {
        hash2.insertItem(i);
    }
    
    hash2.insertItem(2);
    hash2.insertItem(3);
    hash2.insertItem(6);
    
    for (int i=0; i<200; i++)
    {
        hash2.insertItem(2+(i*i));
    }
    hash2.insertItem(40012);
    hash2.insertItem(80022);
    
    

    hash2.printTable();
    cout << "collision: " << hash2.getNumOfCollision() << endl;
    node* n1=hash2.searchItem(40012);
    cout << "key of interest: " << n1->key << endl;
    */
        

