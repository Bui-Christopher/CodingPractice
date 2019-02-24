#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char** argv) 
{
    std::string name, userName;
    int age = 0;
    char choice;

    std::cout << "Please enter your name.\n";
    std:: cin >> name;
    
    std::cout << "Please enter your age.\n";
    std:: cin >> age;
    
    std::cout << "Please enter your username.\n";
    std:: cin >> userName;
    
    std::cout << "Would you like to save this data? Enter Y or N.\n";
    std:: cin >> choice;
    
    if (choice == 'Y')
        
    {
        std::ofstream myfile ("ChallengeOne.txt");
        
        if (!myfile)
        {
            std::cerr << "ChallengeOne.txt could not be opened. \n";
            exit(1);
        }  
        
        myfile << name << "\r\n";
        myfile << age << "\r\n";
        myfile << userName << "\r\n";
    }
    
    else
    
    std::cout << "Your name is: " << name << ". Your age is: " << age
              << ". Your username is: " << userName << "." << std:: endl;
    return 0;
}

