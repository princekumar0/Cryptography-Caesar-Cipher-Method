

#include <iostream>

using namespace std;

int main()
{
 int option;
 cout<<"\t\t\t Welcome to the Program"<<endl;
 cout<<"Please Select the Option"<<endl;
 cout<<"Press 1 for Encryption"<<endl;
 cout<<"Press 2 for Decryption"<<endl;
 cin>>option;
 cin.ignore();
 if (option==1){
     //for Encryption
     string plainText;
     cout<<"plainText can only be Alphabetic"<<endl;
     cout<<"Please Enter the plainText:";
     getline(cin,plainText);
     int encryptionKey;
     cout<<"Please Enter the Encryption key(0-25):";
     cin>>encryptionKey;
     cin.ignore();
     string encryptedText=plainText;
     for(int i=0;i<plainText.size();i++){
         if(plainText[i]==32){
             continue; //because 32 is the ASCII value of space character...hence to avaoid any space we will skip that 
         }else {
             if(plainText[i]+encryptionKey>122){
                 //after 'z' move back to 'a' ...here 122 is the ASCII value of 'z'
                 int temp=(plainText[i]+encryptionKey)-122;
                 encryptedText[i]=96+temp;
             }else if(plainText[i]+encryptionKey>90 && plainText[i]<=96){
                 //after 'Z'move back to 'A'i.e Z's ASCII value is 90
                 int temp=(plainText[i]+encryptionKey)-90;
                 encryptedText[i]=64+temp;
             }else {
                 //case of characters between 'A'-'Z' && 'a'-'z'
                 encryptedText[i]+=encryptionKey;
             }
         }
     }cout<<"Here is your Encrypted Message:"<<encryptedText;
     
 }else if(option==2){
     //for Decryption
     string encryptedMsg;
     cout<<"encryptedText can only be alphabetic"<<endl;
     cout<<"Please Enter the Encrypted Message:";
     getline(cin,encryptedMsg);
     int decryptionKey;
     cout<<"Please Enter the Decryption key(0-25):"<<endl;
     cin>>decryptionKey;
     cin.ignore();
     string decryptedText=encryptedMsg;
     for(int i=0;i<encryptedMsg.size();i++){
         if (encryptedMsg[i]==32){
             continue; //because 32 is the ASCII value of space character...hence to avaoid any space we will skip that
         }else {
             if((encryptedMsg[i]-decryptionKey)<97 && (encryptedMsg[i]-decryptionKey)>90){
                 int temp=(encryptedMsg[i]-decryptionKey)+26;
                 decryptedText[i]=temp;
             }else if((encryptedMsg[i]-decryptionKey)<65){
                 int temp=(encryptedMsg[i]-decryptionKey)+26;
                 decryptedText[i]=temp;
             }else{
                 decryptedText[i]=encryptedMsg[i]-decryptionKey;
             }
         }
     }cout<<"Here is your Decrypted Message:"<<decryptedText;
     
 }else{
     //for every other input
     cout<<"TRY AGAIN!!!"<<endl;
 }

    return 0;
}
