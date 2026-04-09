
#include <iostream>  
#include <cstdlib>   
#include <ctime>     
using namespace std;

enum enQuestionLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, MixLevel = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOP = 5 };

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

short ReadHowManyQuestions() {
    short HowManyQuestions;
    cout << "\n How Many Questions do you want to answer :";
    cin >> HowManyQuestions;
    return HowManyQuestions;
}


enQuestionLevel ReadQuestionLevel() {
    short QuestionLevel;
    do {
        cout << "\n Enter Question Level [1]Easy, [2]Med, [3]Hard, [4]Mix :";
        cin >> QuestionLevel;
    } while (QuestionLevel > 4 || QuestionLevel < 1);
    return (enQuestionLevel)QuestionLevel;
}
string QuestionLevelText(enQuestionLevel QuestionLevel) {
    string LevelNamesArray[4] = { "Easy","Med","Hard" ,"Mix" };
    return LevelNamesArray[QuestionLevel - 1];
}

enOperationType ReadOperationType() {
    short OperationType;
    do {
        cout << "\n Enter Operation Type [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix :";
        cin >> OperationType;
    } while (OperationType < 1 || OperationType > 5);
    return (enOperationType)OperationType;
}
string OperationTypeName(enOperationType OperationType) {
    string OperationNamesArray[5] = { "Add","Sub","Mul","Div","Mix" };
    return OperationNamesArray[OperationType - 1];
}
string OperationTypeSymbol(enOperationType OperationType) {
    string OperationChar[4] = { "+","-","*","/" };
    return OperationChar[OperationType - 1];
}

int SimpleCalculator(int Num1, int Num2, enOperationType OperationType) {
    
    switch (OperationType) {
    case Add:
        return Num1 + Num2;
        
    case Sub:
        return Num1 - Num2;
        
    case Mul:
        return Num1 * Num2;
     
    case Div:
        return(Num2 != 0) ? Num1 / Num2 : 0;
      
    }
    return 0;
}

struct stQuestion {
    int Number1 = 0;
    int Number2 = 0;
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;
    int CorrectAnswer = 0;
    int UserAnswer = 0;
    bool IsCorrect = 0;
};

struct stQuizz {
    short HowManyQuestions = 0;
    stQuestion Question[100];
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;
	int NumberOfCorrectAnswer = 0;
	int NumberOfWrongAnswer = 0;
	bool isPassed = 0;

};

void SetScreenColor(bool Right){
    if (Right) {
        system("color 2F");
    }
    else {
        system("color 4F");
        cout << "\a";
    }
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel,enOperationType OpType) {
    stQuestion Question;
    if (QuestionLevel == MixLevel) {
        QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
    }
    if (OpType == MixOP) {
        OpType = (enOperationType)RandomNumber(1, 4);
    }
    Question.OperationType = OpType;
    Question.QuestionLevel = QuestionLevel;
    switch (QuestionLevel) {
    case EasyLevel:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, OpType);
        return Question;
    case MedLevel:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, OpType);
        return Question;
    case HardLevel:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, OpType);
        return Question;
    }
    return Question;
}

stQuizz GeneretQuestions(stQuizz& Quizz) {

    for (int QuestionNymber = 0; QuestionNymber < Quizz.HowManyQuestions; QuestionNymber++) {
        Quizz.Question[QuestionNymber] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OperationType);

    }
    return Quizz;
}

void PrintQuestion(stQuizz& Quizz,int QuestionNumber){
    
        cout << "\n Question [" <<QuestionNumber+1 << "/" << Quizz.HowManyQuestions << "]\n";
        cout << "   " << Quizz.Question[QuestionNumber].Number1 << endl;
        cout << "   " << Quizz.Question[QuestionNumber].Number2;
        cout << " " << OperationTypeSymbol(Quizz.Question[QuestionNumber].OperationType) << endl;
        cout << "  ----------\n   ";

    
    }

void CorectQuestionAnswer(stQuizz& Quizz, int QuestionNumber){
    if (Quizz.Question[QuestionNumber].CorrectAnswer == Quizz.Question[QuestionNumber].UserAnswer) {
        Quizz.Question[QuestionNumber].IsCorrect = true;
        cout << "\n Right Answer :-)\n";
        Quizz.NumberOfCorrectAnswer++;
    }
    else {
        cout << "\n Wrong Answer :-(\a" << endl;
        cout << " The Right Answer is : " << Quizz.Question[QuestionNumber].CorrectAnswer << endl;
        Quizz.Question[QuestionNumber].IsCorrect = false;
        Quizz.NumberOfWrongAnswer++;
    }
    SetScreenColor(Quizz.Question[QuestionNumber].IsCorrect);
}

int ReadAnswer() {
    int Answer;
    cin >> Answer;
    return Answer;
}

void AskAndCorrectQuestions(stQuizz& Quizz){

    for (int QuestionNumber = 0; QuestionNumber<Quizz.HowManyQuestions; QuestionNumber++) {
        PrintQuestion(Quizz, QuestionNumber);
        Quizz.Question[QuestionNumber].UserAnswer=ReadAnswer();
        CorectQuestionAnswer(Quizz, QuestionNumber);
    }
    Quizz.isPassed=(Quizz.NumberOfCorrectAnswer >= Quizz.NumberOfWrongAnswer);

}

string GetFinalResultsText(bool Pass)
{
    if (Pass)
        return "PASS :-)";
    else
        return "Fail :-(";
}
void PrintQuizzReulte(stQuizz& Quizz){
    cout << "\n ______________________________\n";
    cout << "\n   Final Result is " << GetFinalResultsText(Quizz.isPassed);
    SetScreenColor(Quizz.isPassed);
    cout << "\n ______________________________\n";
    cout << "\n Number of Question     : " << Quizz.HowManyQuestions;
    cout << "\n Questions Level        : " << QuestionLevelText(Quizz.QuestionLevel);
    cout << "\n Operation Type         : " << OperationTypeName(Quizz.OperationType);
    cout << "\n Number of Right Answer : " << Quizz.NumberOfCorrectAnswer;
    cout << "\n Number of Wrong Answer : " << Quizz.NumberOfWrongAnswer;
    cout << "\n ______________________________\n";
}

void StartQuizz() {
    stQuizz Quizz;
    Quizz.HowManyQuestions = ReadHowManyQuestions();
    Quizz.QuestionLevel = ReadQuestionLevel();
    Quizz.OperationType = ReadOperationType();

    GeneretQuestions(Quizz);
    AskAndCorrectQuestions(Quizz);
    PrintQuizzReulte(Quizz);
}

void ResetGame() {
    system("cls");
    system("color 0F");
}

void StartGame() {
    char PlayAgain = 'y';
    do {
        ResetGame();
        StartQuizz();

        cout << "\n Do you need to play again [Y/N] :";
        cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');
}


int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}

