#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;


/*Goals:

1. Filter lines longer than 20 characters
2. Output number and percentage of lines filtered to total
3. Output number and percentage of characters filtered

*/
int main(){

/*Variables needed:
  * number of lines in original -> nlines
  * number of chars in one line -> nchars
  * total characters -> tchars
  * number of lines removed-> rmlines
  * number of chars removed -> rmchars
  */
  string line;
  size_t nlines, nchars, rmchars, tchars, rmlines,rmcharsP,rmlinesP;
  nlines = 0;
  rmchars=0;
  rmlines=0;
  nchars = 0;
  tchars = 0;

while (getline(cin,line)) { //reads lines from standard input
  nlines++;
  tchars+=line.size();
  nchars = line.size();
  if (nchars>=20){
    cout << line << "\n";
  } else {
    rmchars+=line.size();
    rmlines++;
  }

}
rmlinesP=(double)rmlines/nlines*100;
rmcharsP=(double)rmchars/tchars*100;
cout << "~~~~~~~~~~~~~~~~~~~~~" << "\n";
cout << rmlines << " lines removed ( " << rmlinesP << "%)" << "\n";
cout << rmchars << " characters removed ( " << rmcharsP << "%)" << "\n";

return 0;
}