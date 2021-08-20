/* # is a preprocessor directive and a preporcessor starts with a #
and next to it is the HeaderFile*/
//seeding rand() because it might not randomize for every device
#include <iostream> //input & output
#include <ctime> //computer time

//new function that will return no value and it will handle our game
//void is a function type that returns no value or data

void PrintIntrodcution(int Difficulty)
{
    std::cout << "\n\nIn a future faraway, a citadel of level " << Difficulty;
    std::cout<< ", where there is the corrupt and good, where there is malicious softwares to hack into human brains, "<< std::endl;
    std::cout<<"\n";
    std::cout<< "you are a white hat, who cares about saving humanity, and clean this citadel of corrupt hackers, and start a new path! "<< std::endl;
    std::cout<<"\n";
    std::cout<<"enter the combination of code To Continue.."<<std::endl;
    std::cout<<"========================================"<<std::endl;
}

//bool function must return a true or false value whenever there is a condition check

bool PlayGame(int Difficulty)
{
      /*std is short for standard and its a nameSpace avoiding naming the code the same name
    the :: is the scope operator to check for code inside the nameSpace
     such as cout<< ""; cout is defined in nameSapce*/

    // << is called the insertion operator
    // >> is called the extractor operator 

     /*endl to end the line and start a new line
     endl is also defined in std namespace
     */
    
    PrintIntrodcution(Difficulty);
   
    const int FirstCode =rand() % Difficulty + Difficulty;
    const int SecondCode = rand() % Difficulty + Difficulty;
    const int ThirdCode = rand() % Difficulty + Difficulty;
    int CodeSum = FirstCode+SecondCode+ThirdCode;
    int CodeProduct = FirstCode*SecondCode*ThirdCode;
  
    std::cout<<"+ There are 3 numbers in the code"<< std:: endl;
    //print sum and product to the terminal
    std::cout<<"+ The codes add up to:"<<CodeSum<<std::endl;
    std::cout<<"+ The codes multiply to give:"<<CodeProduct<<std::endl;


    //store player guesses
    int GuessA, GuessB, GuessC;
    std::cin>> GuessA >> GuessB>> GuessC;
    
    int SumGuess = GuessA+GuessB+GuessC;
    int ProductGuess= GuessA*GuessB*GuessC;

    //std::cout<<"You Entered These Three numbers:\n" <<"First:" << GuessA << std::endl <<"Second:"<< GuessB << std::endl <<"Third:" <<GuessC <<std::endl;
    std::cout<<"\nThe Sum of your guesses:"<<SumGuess<<std::endl;
    std::cout<<"The product of your guesses:"<<ProductGuess<<std::endl;


    //check if players is correct
     if (CodeSum == SumGuess && CodeProduct == ProductGuess)
    {
        std::cout<<"\nYou win!"<<std::endl;
                std::cout<<"\nOnto the Next Level!"<<std::endl;

        return true;
    }
    else{
        std::cout<<"\nThe Hackers Caught You, You Lost EveryThing..."<<std::endl;
                        std::cout<<"\nTry Again"<<std::endl;

        return false;
    }

}



int main()
{
/*note that a variable thats declared in a specific function is local in this function
 and its scope cant be anywhere else before it since its not global, so u can define it as a function paramter*/
    srand(time(NULL)); //create new random sequence based on the time of day
    int LevelDifficulty = 1;
    int const MaximumLevel=5;
    while (LevelDifficulty <= MaximumLevel) //loop the game until all level completes
    {
        // //modulous operator that get the remainder of a division
        // //so when u act with a modulous operator on the randomizer function you will get a pattern of number.
        // std::cout<<rand() % 3<< "\n";
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

               std::cout<<"You Got the Right Combination, Now RUN!!!"<<std::endl;
    return 0;
 
} 




