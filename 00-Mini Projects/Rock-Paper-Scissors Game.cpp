#include <iostream>
#include<ctime>

using namespace std;

enum enGameoptions { Stone = 1, Paper = 2, Scissor = 3 };
enum enWinOrNot { Win = 1, Tied = 2, Lose = 3 };
struct stGameInfo {
    int GameRounds = 0;
    enGameoptions PlayerChoice;
    enGameoptions ComputerChoice;
    int PlayerWinTime = 0;
    int ComputerWinTime = 0;
    int DrawTimes = 0;
};





int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

short ReadHowManyRound() {
    short HowManyRound=0;
    do {
        cout << "\n How many rounds 1 to 10 :\n ";
        cin >> HowManyRound;
    } while (10 < HowManyRound || HowManyRound < 1);
    return HowManyRound;
}

enGameoptions TakeOptions(short Choice) {
    return (enGameoptions)Choice;
}

enGameoptions PlayerChoice(stGameInfo &Info) {
    short Choice;
    cout << "\n Your Choice { [1]Stone / [2]Paper / [3]Scissor} : ";
    cin >> Choice;
    Info.PlayerChoice = TakeOptions(Choice);
    return Info.PlayerChoice;
}

enGameoptions ComputerChoice(stGameInfo &Info) {

    Info.ComputerChoice = TakeOptions(RandomNumber(1, 3));
    return Info.ComputerChoice;
}

enWinOrNot PlayerWinOrNot(enGameoptions ComputerChoice, enGameoptions PlayerChoice) {
 
    if (PlayerChoice== Stone && ComputerChoice== Paper) {
        return Lose;
    }
    
    else if (PlayerChoice== Stone && ComputerChoice== Scissor) {
        return Win;
    }
    
    else if (PlayerChoice== Scissor && ComputerChoice== Paper) {
        return Win;
    }

    else if (PlayerChoice== Scissor && ComputerChoice== Stone) {
        return Lose;
    }
    
    else if (PlayerChoice== Paper && ComputerChoice== Stone) {
        return Win;
    }

    else if (PlayerChoice== Paper && ComputerChoice== Scissor) {
        return Lose;
    }
    else {
        return Tied;
    }

}

string Choice(enGameoptions Choice) {
    switch (Choice) {
    case Stone:
        return "Stone";
    case Paper:
        return "Paper";
    case Scissor:
        return "Scissor";
    default:
        return "Eror";
     }
}

string WhoIsWinner(enWinOrNot PlayerWinOrNot, stGameInfo& Info) {
    
    switch (PlayerWinOrNot) {
    case Win:
        system("color 2F");
        Info.PlayerWinTime++;
        return "[Player]";
    case Tied:
        system("color 6F");
        Info.DrawTimes++;
        return"[No Winner]";
    case Lose:
        system("color 4F");
        Info.ComputerWinTime++;
        return "[Computer]";
    }
}

void RoundResult(short RoundNumber, enWinOrNot PlayerWinOrNot,stGameInfo& Info) {
    Info.GameRounds++;
    cout << "\n ______________Round["<< RoundNumber<<"]__________________\n ";
    cout << "\n Player Choice : " << Choice(Info.PlayerChoice);
    cout << "\n computer Choice : " << Choice(Info.ComputerChoice);
    cout << "\n Round Winner :" << WhoIsWinner(PlayerWinOrNot,Info);
    cout << "\n -------------------------------------------------------------------\n";
}

void PrintGameOver(){
    cout << "\n\n\t\t____________________________________________________________\n";
    cout << "\n\t\t\t     * * * [G a m e    O v e r] * * *\n";
    cout << "\n\t\t____________________________________________________________\n\n";
}

string FinalWinner(stGameInfo Info) {
    int result = Info.PlayerWinTime - Info.ComputerWinTime;
    if (result > 0) {
        system("color 2F");
        return "Player";
    }
    else if (result < 0) {
        system("color 4F");
        return "Computer";
    }
    else {
        system("color 6F");
        return "No Winner";
    }
}

void FinalResult(stGameInfo Info) {
    PrintGameOver();
    cout << "\n\n\t___________________________[Game Results]________________________________\n";
    cout << "\tGame Rounds\t\t:"<<Info.GameRounds;
    cout << "\n\tPlayer Win Times\t:"<<Info.PlayerWinTime;
    cout << "\n\tComputer Win Times\t:"<<Info.ComputerWinTime;
    cout << "\n\tDraw Times\t\t:" << Info.DrawTimes;
    cout << "\n\tFinal Winner\t\t:"<< FinalWinner(Info);
    cout << "\n\t---------------------------------------------------------------------------\n";
}

void ResetGame(stGameInfo& GameInfo) {
    GameInfo.GameRounds = 0;
    GameInfo.PlayerWinTime = 0;
    GameInfo.ComputerWinTime = 0;
    GameInfo.DrawTimes = 0;
}

bool PlayAgain() {
    char Answer;
    cout << "\n\n\tDo you want to play again? (Y/N): ";
    cin >> Answer;
    return (Answer == 'Y' || Answer == 'y');
}

void ClearScreen() {
    system("color 07");
    system("cls");
}


void StartGame() {
    stGameInfo GameInfo;
    do {
        ResetGame(GameInfo);
        ClearScreen();
        short NumOfRounds = ReadHowManyRound();
        for (int i = 0; i < NumOfRounds; i++) {

            PlayerChoice(GameInfo);
            ComputerChoice(GameInfo);

            enWinOrNot PlayerResult = PlayerWinOrNot(GameInfo.ComputerChoice, GameInfo.PlayerChoice);

            RoundResult(i+1, PlayerResult, GameInfo);

            
        }
        FinalResult(GameInfo);

    } while (PlayAgain());


}

int main()
{

    srand((unsigned)time(NULL));
    StartGame();
   

  
}

