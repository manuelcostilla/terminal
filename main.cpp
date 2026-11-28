#include <filesystem>
#include <cstdlib>
#include <iostream>
#include <string>

// moving cd to a separate function to stop making main bigger
 static void cd(const std::string&input) {
  std::error_code ec{};
   // this checks whether the user only provides cd as input, triggering an error message asking for identifying the directory
   // and returning to evade it to go down and execute the others if's
   if (input == "cd") {
     std::cout << "Error: please specify directory." << "\n";
     return;
   }
   // this provides the cd ~ function that takes you to the home of you OS, in this case using std::getenv on
   // std::filesystem current_path.
   if (input == "cd ~") {
     std::filesystem::current_path(std::getenv("HOME"));
     std::system("pwd");
     return;
   }
   // this handles the movement between directories
   if (input.starts_with("cd ")) {
     std::filesystem::current_path(input.substr(3), ec);
   }
   // error code handler in case the user don't provide a directory that exist
   if (ec) {
     std::cout << "Error: " << ec.message() << "\n";
   } else {
     // prints current working directory after checking for error
     std::system("pwd");
   };

};

int main() {
  {
    std::string input{};
    // I initialize this variable as an empty variable here
    /* then I use it here to make the loop, saying that while i is different from "exit" the loop will continue */
    /* Then I use the getline function to get the whole line the user puts on the terminal instead of only one like I would have with
        only the std cin, and update the i variable with that value and I do it inside the while parameters to prevent ctrl + D*/
    while (std::getline(std::cin,input) && input != "exit")  {
      // changes the conditional to check if the input is "cd" or "cd " to make the if's in the function work as intended also removed test help if block
      if (input == "cd" || input.starts_with("cd ")) {
        cd(input);
      }
      else {
        std::system(input.c_str());
      }
    }
  }
return 0;
}