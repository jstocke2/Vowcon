// Prints vow and cons using alternating threads from a file
// Project #1 vowcons
// CS 33201
// Jake Stocker
// 10/12/2015









#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <fstream>       // std::filestream  
#include <stdio.h>       // fopen
#include <stdlib.h>      // exit EXIT FAILURE
#include <string>     
	
	
   // PRECONDITION:  Takes word to check
   // POSTCONDITION  Returns True if first letter is a vowel
    bool vowelChecker(std::string checkWord)
    {
        if (checkWord[0] == 'A' || checkWord[0] == 'a')
           { return true; }
        else if (checkWord[0] == 'E' || checkWord[0] == 'e')
           { return true; }
        else if (checkWord[0] == 'I' || checkWord[0] == 'i')
           { return true; }
        else if (checkWord[0] == 'O' || checkWord[0] == 'o')
           { return true; }
        else if (checkWord[0] == 'U' || checkWord[0] == 'u')
           { return true; }
        else 
           {return false;} 


   }
    
    // PRECONDITION:  Takes a string
    // POSTCONDITION: Returns true if there is a period

     bool  checkPeriod(std::string checkWord)
     {
	int i = 0;
        while (checkWord[i] != '\0') 
	{
        	if(checkWord[i] == '.')
		{
			return true;
		}
		i++;
	}
	
	return false;


     }

     
    // PRECONDITION Takes a string
    // POSTCONDITION:  Prints vow and the word if it begins with a vow
     void vow(std::string readWord) 
     {
      if (vowelChecker(readWord) == true)
      {         
        std::cout << "vow:      " << readWord << std::endl;
      }
 
     }
	
      // PRECONDITION:  Takes a string
      // POSTCONDITION:  Prints cons and the string if word begins with a constanant
      void cons(std::string readWord)
      {
         
          if (vowelChecker(readWord) == false)
             { 
                std::cout << "cons:     " << readWord <<std::endl;
             }
          
      }

      int main() 
      {
        // open file and check for read in 
          std::fstream fin;
          fin.open("phrase.txt");
          if (!fin.is_open())
          { 
             std::cout << "File failed to Open." << std::endl;
             exit (EXIT_FAILURE);
          }         


            std::string readWord;
	    bool period = false;   // flag marked true once period encountered
          
	  
	  while (period == false)
            {
	    fin >> readWord;
 
            std::thread first (vow, readWord);     // spawn new thread that calls vow()
            std::thread second (cons, readWord);  // spawn new thread that calls con(0)
        
          
            period = checkPeriod(readWord);
      
            first.join();                // pauses until first finishes
            second.join();               // pauses until second finishes
           }
          fin.close();
      }
