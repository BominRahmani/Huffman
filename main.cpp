#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

void Compress(vector <char> ls){

}

int main() {

    //feed in text file into a vector
    vector <char> ls;
    ifstream inpF("C:/Users/Bomin/CLionProjects/HuffmanEncode/Ishmael");
    if(!inpF){
        cout << "error, empty or corrupted file" << endl;
        return -1;
    }

    string contents((std::istreambuf_iterator<char>(inpF)),
                         std::istreambuf_iterator<char>()); //capture entire file into string


    //apply huffman algorithm to it
    //Compress(ls);
    //output compressed version into new text
    return 0;
}
