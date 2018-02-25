//Project name: The Password Checker
//Author: Matthew Henschke
//Date: 3/04/2017

//Header files
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool Common(string[], string);
bool Length(string, int);
bool Alpha(string, int);
bool Capital(string, int);
bool Number(string, int);
bool Special(string, int);
bool NoSpaces(string, int);

int main(){
    
    //declaration of variables
    ifstream inFile;
    int i = 0;
    string password;
    string cpasswords[4000];
    int len;
    len= password.length();
    
    
    
    
    //opening file
    inFile.open("commonPasswords.txt");
    
    //if statement to make sure file opened
    if (!inFile){
        cout << "Your file could not be opened" << endl;
        return 1;
    }
    //while loop to read input file
    while (!inFile.eof()){
        getline(inFile, cpasswords[i]);
        i++;
    }
	//greeting the user ans asking for him/her to enter their password
    cout << "Welcome to the Password Checker." << endl;
    cout << "Please enter a password" << endl;
    getline(cin, password);
	
    
    //giant nested while loop
    while (true){
    //while loop to check part 1 to see if password is a common password
		while (true){
		len = password.length();
        Common(cpasswords, password);
        if (Common(cpasswords, password) == true){
            cout << "Your password is a common password" << endl;
            cout << "Please enter another password" << endl;
			getline(cin, password);
            continue;
        }
        else break;
    }
    
    //calling password checking functions
		//part 2 of project
    Length(password, len);
    Alpha(password, len );
    Capital(password, len );
    Number(password, len);
    Special(password, len);
    NoSpaces(password, len);
        //if statements to see if password is valid or not
	if (Length(password, len)== true && Alpha(password, len)== true &&
            Capital(password, len)== true &&
            Number(password, len)== true && Special(password, len)
            == true && NoSpaces(password, len)== true){
			cout << "Your password has all of the password requirements." << endl;
            cout << "Password is a valid password.\n";
            cout << "Thank you for visiting the Password Checker and Please Come Again :)\n";
            break;
        }
        
        else {
			if (Length(password, len) == false)
				cout << "Password is not at least 8 characters long." << endl;
			if (Alpha(password, len) == false)
				cout << "Password does not contain at least one letter." << endl;
			if (Capital(password, len) == false)
				cout << "Password does not contain at least one capital letter." << endl;
			if (Number(password, len) == false)
				cout << "Password does not contain at least one numeric character." << endl;	
			if (Special(password, len) == false)
				cout << "Password does not have at least one special character." << endl;
			if (NoSpaces(password, len) == false)
				cout << "You cannot have a space im your password." << endl;
			cout << "Password is not a valid password.\n";
            cout << "Please enter another password.\n";
			getline(cin, password);
            continue;
        }
        
            }
            //closing file and end of main
            inFile.close();
            return 0;
            
            }
              //methods that will check to see if password is valid
            
            bool Common(string cp[], string p){
                
                //declaration of variables
                int k;
                bool com = false;
			
                
                for (k = 0; k < 4000; k++){
                    if (cp[k] == p){
                        com = true;
                        break;
                    }
                    else continue;
                }
            
                if (com == true)
                    return true;
                else return false;
            }
			bool Length(string pass, int length)
				{
                if( length>= 8)
                    return true;
				else{
					return false;
					
			.

				}
            }
            bool Alpha (string pass, int length){
                int i;
                bool check= false;
                for (i=0; i< length; i++){
                    if(isalpha(pass[i])){
                        check=true;
                        break;
                    }
                    else continue;
            }
                if(check==true)
                    return true;
                else return false;
            }
            
            bool Capital (string pass, int length){
                
                int i;
                bool check1= false;
                for (i=0; i< length; i++){
                    
                    if (isupper(pass[i])){
                        check1= true;
                        break;}
                    else continue;
                }
                if (check1==true)
                    return true;
                else return false;
                
            }
            
            bool Number(string pass, int length){
                
                int i;
                bool check2=false;
                for (i=0; i< length; i++){
                    if (isdigit(pass[i])){
                        check2=true;
                    break;
                    }
                    else continue;
                }
                if (check2== true)
                    return true;
                else return false;
            }
            bool Special (string pass, int length){
                
                int i;
                bool check3= false;
                for (i=0; i< length; i++){
                    if (pass[i] == '!' || pass[i] == '#' || pass[i] == '%' || pass[i] == '&'){
                        check3= true;
                        break;
                    }
                    else continue;
                }
                if (check3== true)
                    return true;
                else return false;
            }
            bool NoSpaces(string pass, int length){
                
                int i;
                bool check4=true;
                for (i=0; i< length; i++){
                    if (pass[i]== ' '){
                        
                        check4=false;
                        break;
                    }
                    else
                        continue;
            }
                if (check4== false)
                    return false;
                else return true;
            }
        
            
            

            
            
            
