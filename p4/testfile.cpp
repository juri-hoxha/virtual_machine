/*
 * CSc103 Project 4: uncommenting C/C++
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:
 */
#include <iostream>
#include <cstdio> // printf and friends
// strings might help if you want to do a nice job removing whitespace
#include <string>
using std::string;
using std::cout;
#include <vector>
using std::vector;

int main()
{
	char c;
	vector<char> code;
	while (scanf("%c", &c) == 1){
	code.push_back(c);
	}

	size_t codechars;
	codechars = code.size();
	for (size_t i=0; i<codechars, i++){
		cout << code[i];
	}


 /*
    char a; // first character
    a = '_';
    char b; // second character
    char c; // represents character being read
        while (scanf("%c", &c) > 0) {
        b = a; // represents pervous char
        a = c; // represents current char
        cout << "Previous letter: " << b << "\n";
        cout << "Next letter: " << a << "\n";
          if ((a=='/') && (b=='/')){
           cout << "This is a comment" << "\n";
          }

       }
 */
    return 0;
}
