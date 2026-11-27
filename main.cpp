#include <filesystem>
#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
  std::string input{}; // I initialize this variable as an empty variable here

  /* then I use it here to make the loop, saying that while i is different from "exit" the loop will continue */
  /* Then I use the getline function to get the whole line the user puts on the terminal instead of only one like I would have with
      only the std cin, and update the i variable with that value and I do it inside the while parameters to prevent ctrl + D*/
  while (std::getline(std::cin,input) && input != "exit")  {

    // then I use an if conditional to check the value of i and compare it against the world "help" if the word is help
    // then I print help is here and that's all for now

    // next additions should be OS commands and personalized commands.

    if (input == "help") {
      std::cout << "help is here";
    }
    else if (input.starts_with("cd ")) { //adding else if block to add cd functionality
      std::error_code ec; // using std::error_code to catch the exception in cd when it tries to access a folder that doesn't exist
      std::filesystem::current_path(input.substr(3), ec); // using the filesystem std to get the current path on the system to then pass
      // the target path with the input, using substr to get the third position from where it start the path line
      if (ec) {
        std::cout << "Error: " << ec.message();
      } else {
      std::system("pwd"); }; // using pwd to print the directory it goes to
    }
    else {
      std::system(input.c_str());
    }
  }
return 0;
}


