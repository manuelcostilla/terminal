#include <iostream>
#include <string>

int main()
{
  std::string i{}; // I initialize this variable as an empty variable here

  /* then I use it here to make the loop, saying that while i is different from "exit" the loop will continue */
  while (i != "exit")  {

    /* Then I use the getline function to get the whole line the user puts on the terminal instead of only one like I would have with
      only the std cin, and update the i variable with that value*/
    std::getline(std::cin,i);

    // then I use a if conditional to check the value of i and compare it against the world "help" if the word is help
    // then I print help is here and that's all for now

    // next additions should be OS commands and personalized commands.
    if (i == "help") {
      std::cout << "help is here";
    }
  }
return 0;
}


