#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
void read(string filename, string array[1000], int &count)
{
    fstream din;
    din.open(filename.c_str());
    if(din.fail())
        {cout << " OPENING FILE NAME " << filename << " FAILED. " << endl; return;}
    else
        {cout << " OPENING FILE NAME " << filename << " SUCCEEDED. " << endl;}
    
    string word, word2;
    count = 0; // for counting number of array's element
    
    while(din >> word)
    {   
        //if there are non alphanumeric characters in array, then check become true.
        bool check = false;  
        int k = 0;         
     
        //Check if there are non alphabetical letter on string  
        for(int i =0; i < word.length(); i++)
        {    
            //to make sting to lower case
            word[i] = tolower(word[i]);
            if(!isalpha(word[i]))
            {                   
                if(k == 0)
                    word2 = word.substr(k,i-k);        
                else
                    word2 = word.substr(k+1,i-k-1);
                k = i;
                check = true;           
                //Save the removed non-alphanumeric characters word to array
                if(check)
                {
                    if(!word2.empty())
                    {
                        array[count] = word2;
                        count++;                  
                    }
                }               
            }          
        }
        //Save the not removed non-alphanumeric characters word to array
        if(!check)
        {   
            array[count] = word;
            count++;
        }        
       if(din.eof()) break;   
    } 
    cout << "TOTAL WORDS = " << count << endl;
	din.close();
}
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
void selection_sort(string data[], int low, int high)
{
   // Put largest unsorted value at end of sorted list
   for (int last = high; last > low; last--)
   {
      // Find index of largest value in unsorted array
      int largest = low;
      for (int index = low + 1; index <= last; index++)
	 if (data[index] > data[largest])
	    largest = index;

      // Swap with last element in unsorted array
      string temp = data[last];
      data[last] = data[largest];
      data[largest] = temp;
   }
}
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//bubble_sort is for sorting 2 arrays of word and count
void bubble_sort(string data[] ,int data1[], int count)
{
   int pass = 1;
   int exchange = 1;
    
   while ((pass < count) && (exchange > 0))
   {
      // Scan unsorted part of data array
      exchange = 0;
      for (int index = 0; index < count - pass; index++)
      {
	 // Swap two data values if out of order
	 if (data1[index] < data1[index + 1])
	 {
	    int temp = data1[index];
	    data1[index] = data1[index + 1];
	    data1[index + 1] = temp;
            
            string temp1 = data[index];
	    data[index] = data[index + 1];
	    data[index + 1] = temp1;
                             
	    exchange++;
	 }
      }
      pass++;
   }
}
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
void analyzing_array(string array[] , int count)
{
    string find;
    string wordarray[100];
    int countarray[100];
    
    int i = 0;   
    int N = 0;
    while(i < count)
    {
        int k = 1;
        find = array[i];
        while(find == array[i+1])
        {
           k++;
           i++;
        }
        cout << "{ "<< setw(4)<< k << setw(4)<<" . " << setw(4)<<find <<setw(4)<< " }" << endl;
        wordarray[N] = find;
        countarray[N] = k;
        N++;
        i++;
    }
    cout << " Total number of word types = " << N << endl;
   
    bubble_sort(wordarray, countarray, N);
   
    
    //for user input for printing Top used word
    int Input;
    
    cout << "How many most often used words do you want to check?" << endl;
    cin >>Input;
    
    if(Input > N)
        {Input = N;}
    for(int i = 0; i < Input; i++)
        cout<<"{ "<<setw(4)<< countarray[i] <<setw(4)<< " . " << setw(4)<<wordarray[i]<<setw(4) <<" }" << endl;    
}
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
void print_array(string array[])
{
    int q = 0;
    while (!array[q].empty())
    {
        cout << array[q] << endl;
        q++;
    }
    cout << "Array length = " << q << endl; 
}
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------

int main() {

    string filename;  
    cout << "Type filename for reading!" << endl;
    cin >> filename;
    string array[1000];
    
    int count;
    read(filename, array,count);
    selection_sort(array,0,count-1); 
    analyzing_array(array, count);

    return 0;
}

