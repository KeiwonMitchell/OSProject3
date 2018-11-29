#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){

    ofstream myfile;
    myfile.open ("FileRead.txt");
    myfile <<"This line has 5 words.\n This is the 2nd line.\n This line has file in it.\n";
    myfile.close();

    int filefilescount = 0;
    int filewordcount = 0;
    int count=1;
    string line;

    ifstream file("FileRead.txt");
    while(getline(file,line)){
        int linewordcount = 0;
        int startwithcap = 0;
        string word;
        stringstream lineStream(line);

        while (lineStream >> word){
            if(isupper(word[0])){++startwithcap;}
            if(word=="file"||word == "files"){++filefilescount;}
            ++linewordcount;}

        filewordcount=filewordcount + linewordcount;

        cout<<"Line "<<count<<" Has "<<linewordcount<<" words"<<endl;
        cout<<"Line "<<count<<" Has "<<startwithcap<<" words that start with capitals"<<endl;
        count++;
    }


    cout<<"File word count is : "<<filewordcount<<endl;
    cout << "Numbers of lines in the file : " << count << endl;
    cout << "Numbers of file/files in the file : " << filefilescount << endl;

    return 0;
}
