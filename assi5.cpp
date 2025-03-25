#include<bits/stdc++.h>
using namespace std;
struct node
{
char data;
int freq;
node *left, *right;
node(char data, int freq)
{
left = right = NULL;
this->data = data;
this->freq = freq;
}
};
 
struct compare
{
bool operator()(node* l, node* r)
{
return (l->freq > r->freq);
}
};
 
void printCodes(struct node* root, string str)
{
if (!root)
return;
if (root->data != '$')
cout << root->data << ": " << str << "\n";
printCodes(root->left, str + "0");
printCodes(root->right, str + "1");
}
 
void HuffmanCodes(char data[], int freq[], int size)
{
struct node *left, *right, *top;
priority_queue<node*, vector<node*>, compare> minHeap;
for (int i = 0; i < size; ++i)
minHeap.push(new node(data[i], freq[i]));
while (minHeap.size() != 1) {
left = minHeap.top();
minHeap.pop();
right = minHeap.top();
minHeap.pop();
top = new node('$', left->freq + right->freq);
top->left = left;
top->right = right;
minHeap.push(top);
}
printCodes(minHeap.top(), "");
}
 
 
 
int main()
{char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
int freq[] = { 10, 5, 14, 14, 7, 9 };
cout<<"The Character and its Frequency:- "<<endl;
int size = sizeof(arr) / sizeof(arr[0]);
for(int i=0;i<sizeof(arr);i++)
{
cout<<"\t"<<arr[i]<<"\t"<<freq[i]<<endl;
}
cout<<"The Huffman Codes:- "<<endl;
HuffmanCodes(arr, freq, size);
return 0;
}