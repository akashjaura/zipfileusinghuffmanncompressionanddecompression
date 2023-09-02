// #include<iostream>
// #include<bits/stdc++.h>
// #include<fstream>
// #include<chrono>

// using namespace std;
// std::ifstream::pos_type filesize(const char* filename) {
//     std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
//     return in.tellg();
// }
// struct Node{
//     char data;
//     unsigned freq;
//     string code;
//     Node*left,*right;
//     Node(){
//         left=right=NULL;
//     }

// };
// class huffmann{
//     private:
//     vector<Node*>arr;
//     fstream inFile,outFile;
//     string inFileName,outFileName;
//     Node*root;
    
//     class compare{
//         public:
//         bool operator()(Node*l,Node*r){
//             return l->freq>r->freq;
//         }
//     };
//     priority_queue<Node*,vector<Node*>,compare>minheap;
//     void createArr(){
//         for(int i=0;i<128;i++){
//             // arr.push_back(new Node());
//             arr[i]->data=i;
//             arr[i]->freq=0;
//         }
//     }
//     void transverse(Node*r,string str){
//         if(r->left==NULL&&r->right==NULL){
//             r->code =str;
//             return ;
//         }
//         transverse(r->left,str+'0');
//         transverse(r->right,str+'1');

//     }
//     int binToDec(string inStr) {
//     int res = 0;
//     for (auto c : inStr) {
//         res = res * 2 + c - '0';
//     }
//     return res;
// }
//     void createMinHeap(){
//     char id;// used to read the first char of file 
//     inFile.open(inFileName,ios::in);
//     inFile.get(id);
//     while(!inFile.eof()){//eof end of file
//         arr[id]->freq++;
//         inFile.get(id);
//     }
//     inFile.close();
//     for(int i=0;i<128;i++){
//         if(arr[i]->freq>0){
//             minheap.push(arr[i]);
//         }
//     }
//     }
//     void createTree(){
//         Node*left,*right;
//         priority_queue<Node*,vector<Node*>,compare>tempPq(minheap);
//         while(tempPq.size()!=-1){
//             left=tempPq.top();
//             tempPq.pop();
//             right=tempPq.top();
//             tempPq.pop();
//             root= new Node();
//             root->freq=left->freq+right->freq;
//             root->left=left;
//             root->right=right;
//             tempPq.push(root);
//         }
        
        
//     }
//     void createCodes(){
//         transverse(root,"");
//     }
//     void saveEncodedFile(){
//         inFile.open(inFileName,ios::in);
//         outFile.open(outFileName,ios::out|ios::binary);
//         string in="";
//         string s="";
//         char id;
//         in+=(char)minheap.size();
//         priority_queue<Node*,vector<Node*>,compare>tempPq(minheap);
//         while(!tempPq.empty()){
//             Node*curr=tempPq.top();
//             in+=curr->data;
//             s.assign(127-curr->code.length(),'0');
//             s+='1';
//             s+=curr->code;
//             in+=(char)binToDec(s.substr(0,8));
//             for(int i=0;i<15;i++){
//                 s=s.substr(8);
//                 in+=(char)binToDec(s.substr(0,8));
//             }
//             tempPq.pop();
//         }
//         s.clear();
//         inFile.get(id);
//         while (!inFile.eof()) {
//         s += arr[id]->code;
//         //Saving decimal values of every 8-bit binary code
//         while (s.length() > 8) {
//             in += (char)binToDec(s.substr(0, 8));
//             s = s.substr(8);
//         }
//         inFile.get(id);
//         }
//         //Finally if bits remaining are less than 8, append 0's
//         int count = 8 - s.length();
//         if (s.length() < 8) {
//             s.append(count, '0');
//         }
//         in += (char)binToDec(s);
//         //append count of appended 0's
//         in += (char)count;

//         //write the in string to the output file
//         outFile.write(in.c_str(), in.size());
//         inFile.close();
//         outFile.close();

//     }
//     public:
    
//     huffmann(string inFileName,string outFileName){
//         this->inFileName=inFileName;
//         this->outFileName=outFileName;
//         createArr();
//     }
//     void compress(){

//         createMinHeap();
//         createTree();
//         createCodes();
//         saveEncodedFile();

//     }
    
// };
// std::ifstream::pos_type filesize(const char*filename);
// int main(){
//     string mode;
//     string inpath;
//     string outpath;
//     cout<<"enter the working mode(compress or decompress):";
//     cin>>mode;
//     if(mode=="compress"){
//        cout<<"enter the file's path that you want to compress:";
//        cin>>inpath;
//        ifstream inFile(inpath);
//        if(!inFile){
//         cerr<<"Error :input file"<< inpath <<"not exist";
//         return 1;
//        }
//        cout<<"Enter the full path and name of the compressed file: ";
//        cin>>outpath;
//        clock_t tstart=clock();
//        huffmann f(inpath,outpath);
//        f.compress();
//        const char*inchararr=inpath.c_str();
//        const char *outchararr=outpath.c_str();
//        inFile.close();
//        if(filesize(outchararr)!=-1){
//             cout << "Compression completed successfully." << endl;
//             cout << "Time taken: " << (1.0 * (clock() - tstart) / CLOCKS_PER_SEC) << " seconds" << endl;
//             cout << "Input File Size: " << filesize(inchararr) << " bytes" << endl;
//             cout << "Compressed File Size: " << filesize(outchararr) << " bytes" << endl;
//             cout << "Compression Ratio: " << (1.0 * filesize(outchararr) / filesize(inchararr)) << endl;
//        }
//        else{
//         cerr<<"Error:occured";
//        }
//     }
//     else if(mode=="decompress"){

//     }
//     else {
//         cout<<"invalid input"<<endl;
//     }
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <chrono>
#include <cstring> // For strlen
#include <bitset>  // For bit manipulation

using namespace std;

struct Node {
    char data;
    unsigned freq;
    string code;
    Node* left;
    Node* right;

    Node() : data(0), freq(0), left(nullptr), right(nullptr) {}
};

class Huffman {
private:
    vector<Node*> arr;
    ifstream inFile;
    ofstream outFile;
    string inFileName;
    string outFileName;
    Node* root;

    class Compare {
    public:
        bool operator()(Node* left, Node* right) {
            return left->freq > right->freq;
        }
    };

    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    void createArr() {
        arr.resize(128);
        for (int i = 0; i < 128; i++) {
            arr[i] = new Node();
            // arr[i]->data = static_cast<char>(i);c
             arr[i]->data = i;
            arr[i]->freq = 0;
        }
    }

    void traverse(Node* r, string str) {
        if (r->left == nullptr && r->right == nullptr) {
            r->code = str;
            return;
        }
        traverse(r->left, str + '0');
        traverse(r->right, str + '1');
    }

    void createMinHeap() {
        char id;
        inFile.open(inFileName, ios::in | ios::binary);
        inFile.get(id);
        while (!inFile.eof()) {
            arr[id]->freq++;
            inFile.get(id);
        }
        inFile.close();
        for (int i = 0; i < 128; i++) {
            if (arr[i]->freq > 0) {
                minHeap.push(arr[i]);
            }
        }
    }

    void createTree() {
        Node* left;
        Node* right;
        priority_queue<Node*, vector<Node*>, Compare> tempPq(minHeap);
        while (tempPq.size() > 1) {
            left = tempPq.top();
            tempPq.pop();
            right = tempPq.top();
            tempPq.pop();
            root = new Node();
            root->freq = left->freq + right->freq;
            root->left = left;
            root->right = right;
            tempPq.push(root);
        }
    }

    void saveEncodedFile() {
        inFile.open(inFileName, ios::in | ios::binary);
        outFile.open(outFileName, ios::out | ios::binary);

        string in = "";
        string s = "";
        char id;

        in += static_cast<char>(minHeap.size());
        priority_queue<Node*, vector<Node*>, Compare> tempPq(minHeap);
        while (!tempPq.empty()) {
            Node* curr = tempPq.top();
            in += curr->data;
            s.assign(127 - curr->code.length(), '0');
            s += '1';
            s += curr->code;
            in += static_cast<char>(binToDec(s.substr(0, 8)));
            for (int i = 0; i < 15; i++) {
                s = s.substr(8);
                in += static_cast<char>(binToDec(s.substr(0, 8)));
            }
            tempPq.pop();
        }

        s.clear();
        inFile.get(id);
        while (!inFile.eof()) {
            s += arr[id]->code;
            while (s.length() >= 8) {
                in += static_cast<char>(binToDec(s.substr(0, 8)));
                s = s.substr(8);
            }
            inFile.get(id);
        }

        int count = 8 - s.length();
        if (s.length() < 8) {
            s.append(count, '0');
        }
        in += static_cast<char>(binToDec(s));
        in += static_cast<char>(count);

        outFile.write(in.c_str(), in.size());
        inFile.close();
        outFile.close();
    }

    int binToDec(string inStr) {
        int res = 0;
        for (auto c : inStr) {
            res = res * 2 + c - '0';
        }
        return res;
    }

public:
    Huffman(const string& inFileName, const string& outFileName)
        : inFileName(inFileName), outFileName(outFileName), root(nullptr) {
        createArr();
    }

    ~Huffman() {
        for (Node* node : arr) {
            delete node;
        }
    }

    void compress() {
        createMinHeap();
        createTree();
        traverse(root, "");
        saveEncodedFile();
    }
};

std::ifstream::pos_type filesize(const char* filename) {
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

int main() {
    string mode;
    string inpath;
    string outpath;

    cout << "Enter the working mode (compress or decompress): ";
    cin >> mode;

    if (mode == "compress") {
        cout << "Enter the file's path that you want to compress: ";
        cin >> inpath;
        ifstream inFile(inpath, ios::binary);
        if (!inFile) {
            cerr << "Error: Input file " << inpath << " does not exist." << endl;
            return 1;
        }

        cout << "Enter the full path and name of the compressed file: ";
        cin >> outpath;
        clock_t tstart = clock();
        Huffman huffman(inpath, outpath);
        huffman.compress();
        const char* inchararr = inpath.c_str();
        const char* outchararr = outpath.c_str();
        inFile.close();

        if (filesize(outchararr) != -1) {
            cout << "Compression completed successfully." << endl;
            cout << "Time taken: " << (1.0 * (clock() - tstart) / CLOCKS_PER_SEC) << " seconds" << endl;
            cout << "Input File Size: " << filesize(inchararr) << " bytes" << endl;
            cout << "Compressed File Size: " << filesize(outchararr) << " bytes" << endl;
            cout << "Compression Ratio: " << (1.0 * filesize(outchararr) / filesize(inchararr)) << endl;
        } else {
            cerr << "Error occurred." << endl;
        }
    } else if (mode == "decompress") {
        // Implement decompression logic here
    } else {
        cout << "Invalid input" << endl;
    }

    return 0;
}