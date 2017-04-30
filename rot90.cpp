//Tyler Crabtree
//rot90

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> lines; // Cochran's Code, Used to read in info

  std::string line;
  while (std::getline(std::cin, line)) {
    lines.push_back(line);
  }         					 // end of Cocrhan's code.


  // Insert code here
  int i =0;   // for character index
  int totalSize = 0; // gets total characters through entire text
  int wordCount = lines.size(); // counts strings seperated by new lines
  int buffer = 0;   // for shorter strings
  unsigned int max = 0; // gets longest individual string, unsigned, I want this to be always positive. 

    for(int x = 0; x < wordCount; x++){  // This function does two things, get the max string length and total size 

      if (x==0){                        // set first string to longest
          max = lines[x].size();
      }
        if ((lines[x].size()) > max){  // set longer strings to longest
          max = lines[x].size();
      }
      totalSize += lines[x].size();   // get total length of string
   } 


  if(totalSize == 0){  // for empty test case, if total size is zero, do nothing
    return 0;
  }

  int s = (wordCount-1); // for individual word count

    for(int y = 0; y <= wordCount;	y++){  // make sure all strings are the same length add blanks to shorter strings haha
	       buffer = (max - lines[y].size()); // get difference
       for(int z =0; z < buffer; z++){       // add to shorter strings
	        lines[z] += "  ";
        }
    }

  while (max != 0 ){          // this was the tricky part, so I look at the longest word and decrement from there
  	
    std::cout << lines[s][i];  // print off first letter from last word, and go from there

  	if(s == 0){                //if this is the first word set back to last word
	     s = (wordCount-1);           // set to word behind 
	     i++;                         // increment index
	     std::cout << "\n";           // add new line
		    max--;                     // decrement max
    }
    else{
  	   s--;                       // if not first word, look at word behind it.
    }
  }


  return 0;
}

