//spelling
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

const char filename[] = "/usr/share/dict/cracklib-small";

int main()
{
	char data[53000][30];
    char word[100];
	cout << "Enter a word: ";
	cin >> word;
	//strcpy(word, "apple");
   	//strcpy(word, "zebra");
	bool isFound;
	//
	//for (int i=0; i<1; i++) {
		ifstream fin;
		fin.open(filename);
		if (fin.fail()) {
			cout << "error opening file" << endl;
			exit(1);
		}
        int n=0;
        int longest=0;
		isFound = false;
		char line[1000];
		char save[1000]="";
		fin >> line;
		while (!fin.eof()) {
			char*p = strstr(line, "'");
            char *p1= strstr(line, "&");
            char *p2= strstr(line, ".");
            if (p == NULL && p1 == NULL && p2 == NULL) {
                strcpy(data[n++], line);
                int len = strlen(line);
                if (len > longest) {
                 longest = len;
                }
            //cout << line << endl;
                if (strlen(save) > 0) {
				    if (strcmp(save, line) >= 0)
				    	cout << "not sorted at" << save << " " << line << endl;
			    }
			    strcpy(save, line);
			    if (strcmp(line, word) == 0) {
				    isFound = true;
				    //break;
			    }
            }
			fin >> line;
		}
		fin.close();
	//}
    cout << "longest: " << longest << endl;
    cout << "n: " << n << endl;
	
    for(int i = 0; i < n - 1; i++) {
        bool swp = false;
        for(int j = 0; j < n - i -1; j++) {
            if (strcmp(data[j], data[j+1]) > 0) {

                //cout << "swap" << endl;
                char tmp[60];
                strcpy(tmp, data[j]);
                strcpy(data[j], data[j+1]);
                strcpy(data[j+1], tmp);
                swp = true;

            }
        }
        if (!swp) {
            break;
        }
    }

    int start = 0;
    int end = n-1;
   
    while (start <= end) {
        
        int mid = (start+end)/2;
        cout << "binary compare....\n";
        int cmpare = strcmp(data[mid], word);
        if (cmpare == 0) {
            cout << " ====FOUND====With binary Search" << endl;
            break;
        }

        if (cmpare > 0) {
            end = mid -1;
        }
        if (cmpare < 0) {
            start = mid + 1;
        }
    } 



    
    
    
    
    
    
    if (!isFound)
		cout << "Not found, or misspelled.\n";
	else
		cout << "---FOUND---\n";

	cout << endl;
	return 0;
}


















