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


// declare states
enum state {A,B,C,D};
state s = A;

int main()
{
	char c;
	while (scanf("%c", &c) == 1){
		switch (s) {
			case A:
				if (c == '\n'){
					s = case B;
				} else {
					cout << c;
				}
				break;
			case B: //precomment
				if (c == '/'){
					s = case C;
				}
				break;
			case C:
				if (c == '/'){
					s = case D:
				}
				break;
			case D:
				if (c == '\n'){
					s = case A;
				} else {
					c = '\0';
				}
				break;

	}
 }
 cout << "\n";
 return 0;

 a = b; // this comment \\\
}
