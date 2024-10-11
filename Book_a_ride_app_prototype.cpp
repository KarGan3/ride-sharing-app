#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

class BookRide{
    private:
      string username;
      string password;
      string id;
      string pass;
      int otp;
    public:
      
      void signup(){
          
          int choice;
          cout<<"1.Are you a user."<<endl;
          cout<<"2.Are you a driver."<<endl;
          cout<<"Enter choice";
          cin>>choice;
          switch (choice)
          {
          case 1:
            User_login();
            break;
          case 2:
            Driver_login();
          default:
            break;
          }
      }
      void Driver_login(){
        cout<<"Enter username"<<endl;
        cin>>username;
        cout<<"Enter password"<<endl;
        cin>>password;

        save();

        cout<<"Signup Successful"<<endl;
      }
      void User_login(){
        cout<<"Enter username"<<endl;
        cin>>username;
        cout<<"Enter password"<<endl;
        cin>>password;

        save();

        cout<<"Signup Successful"<<endl;

        rider_otp();
      }
      void rider_otp(){

        srand(static_cast<unsigned>(time(0)));        
        otp = rand() % 9000 + 1000;
        cout<<otp<<endl;
        cout<<"Enter the above otp at the starting of the ride"<<endl;

      }
      void save(){
        string filename  = username + ".txt";

        ofstream myfile(filename);
        
        if(myfile.is_open()){
          myfile<<username<<endl;
          myfile<<password<<endl;
          myfile.close();
        }
        else{
          cout<<"Error in saving file"<<endl;
        }
      }
};
int main(){
  int choice;
    BookRide p1;
    cout<<"Welcome to app"<<endl;
    cout<<"signup to Book a ride"<<endl;
    p1.signup();
return 0;
}
