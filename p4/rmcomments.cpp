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
	enum state {normal,slash,slashtar}; // setup three states
	state s = normal; // initialzie state - assume we are not in any comment initially (first character is newline)
	char c;
	vector<char> code;
	// next loop will read each character of the code input and store it into vector named "code"
	while (scanf("%c", &c) == 1){
	code.push_back(c);
	}

	size_t codechars;
	codechars = code.size(); // size of the code vector

	// i will loop through the code to determine conditions to enter states
	for (size_t i=0; i<codechars; i++){ // loop through the vector
		switch (s) {
			case normal: // representing normal code (no comments)
				if ((code[i]=='/') && (code[i-1]=='/') && (code[i-2]!='"')){ //detect "//" when there is no quotation before
					s = slash;
				} else if ((code[i]=='*') && (code[i-1]=='/') && (code[i-2]!='"')){
					s = slashtar;
				}
				break; // break from case
			case slash: // representing // style comments
				// j will go through comment and check for new line character to exit state
				for(size_t j=i-2;j<codechars;j++){
					// check for new line character
					if (code[j]=='\n'){
							/* If previous character before comment started was newline or empty character and
								 the previous to those was not \ , then we will delete newline to compress code.
							*/
							if (((code[i-3]=='\n') || (code[i-3]=='\0')) && (code[i-4]!='\\')){
								code[j]='\0'; // deletes new line at the end of
							}
							s = normal;
							break;
					}
					code[j]='\0'; //delete all characters inside comment
				}
				break;
			case slashtar: // representing /* */ style comments
				for (size_t l=i-2; l<codechars; l++){
					if ((code[l+1]=='*') && (code[l+2]=='/')){ // detect "*/"
						code[l+1]='\0';
						code[l+2]='\0';
						s=normal;
						break;
					}
					if (code[l]!='\n'){
						code[l]='\0';
					}
				}
				break;
		}
	}

		for (size_t k=0; k<codechars; k++){
			cout << code[k];
		}
	cout << "\n";

    return 0;
}
