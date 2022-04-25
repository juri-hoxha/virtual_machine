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
enum state {normal, precomment, slash,comment_backslash, slashstar, poststar, doublequote,doubleq_backslash, singlequote,singleq_backslash};
state s = normal;
int main()
{
	char c;
	while (scanf("%c", &c) == 1){
		switch (s) {
			case normal:
				if (c == '/'){
					s = precomment;
				} else if (c == '"') {
					cout << '"';
					s = doublequote;
				} else if (c == '\''){
					cout << '\'';
					s = singlequote;
				} else {
					cout << c;
				}
				break;
			case precomment:
				if (c == '/'){
					s = slash;
				} else if (c == '*'){
					s = slashstar;
				} else {
					cout << '/';
					cout << c;
					s = normal;
				}
				break;
			case slash:
				if (c == '\\'){
					s = comment_backslash;
				} else if (c == '\n'){
					s = normal;
					cout << '\n';
				}
				break;
			case comment_backslash:
				if (c == '\\'){
					s = comment_backslash;
				} else {
					s = slash;
				}
				break;
			case slashstar:
				if (c == '*'){
					s = poststar;
				} else {
					s = slashstar;
				}
				break;
			case poststar:
				if (c == '/'){
					s = normal;
				} else if ( c == '*'){
					s = poststar;
				} else {
					s = slashstar;
				}
				break;
			case doublequote:
				if (c == '\\'){
					cout << '\\';
					s = doubleq_backslash;
				} else if (c == '"'){
					cout << c;
					s = normal;
				} else {
					cout << c;
				}
				break;
			case doubleq_backslash:
				s = doublequote;
				break;
			case singlequote:
				if (c == '\\'){
					cout << '\\';
					s = singleq_backslash;
				} else if (c == '\''){
					cout << c;
					s = normal;
				} else {
					cout << c;
				}
				break;
			case singleq_backslash:
				s = singlequote;
				break;
	}

 }
 cout << '\n';
 return 0;

}
