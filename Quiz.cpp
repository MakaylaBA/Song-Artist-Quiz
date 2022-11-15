#include "Quiz.h"
#include <fstream>
using namespace std;

void Quiz::readQuizFromFile(string filename) {
    //Clear Questions
    questions.clear();

    // Open the file
    ifstream inFile("../" + filename);

    // Read in the title and number of questions
    int numQuestions = 0;
    string newline;
    if (inFile) {
        getline(inFile, title);
        inFile >> numQuestions;
        getline(inFile, newline);
    }

    // Read in the questions
    int currQuestion = 0;
    Question q;
    string message = "";
    int number = 0;
    bool correct = false;
    while (inFile && currQuestion < numQuestions) {
        // Question Prompt
        getline(inFile, message);
        q.setPrompt(message);

        // Number of points
        inFile >> number;
        q.setPoints(number);

        // Clear Answers
        q.clearAnswers();

        // Number of answers
        inFile >> number;
        getline(inFile, newline);

        // Answers
        for (int i = 0; i < number; ++i) {
            // Read text
            getline(inFile, message);
            // Read correct
            inFile >> correct;
            getline(inFile, newline);
            // Add answer to question
            q.addAnswer(message, correct);
        }

        // Add the Question to vector field
        questions.push_back(q);

        // Increment question number
        ++currQuestion;
    }
    inFile.close();
}

Quiz::Quiz() : title(""), totalPointsCorrect(0), totalPointsPossible(0){
    questions.clear();
}

/* Getters */
string Quiz::getTitle() const{
    return title;
}
int Quiz::getTotalPointsCorrect() const{
    return totalPointsCorrect;
}
int Quiz::getTotalPointsPossible() const{
    return totalPointsPossible;
}
int Quiz::getNumberOfQuestions() const{
    return questions.size();
}

Question Quiz::getQuestion(int index) const{
    if (index<questions.size() && index >= 0) {
        return questions[index];
    }
    return Question();
}
Question Quiz::getQuestion(string prompt) const{
    for(int i = 0; i<questions.size(); i++){
        if (prompt == questions[i].getPrompt()){
            return questions[i];
        }
    }
    return Question();
}

/* Setter */
void Quiz::setTitle(string title){
    this->title = title;
}
void Quiz::addQuestion(Question newQuestion){
    questions.push_back(newQuestion);
}

/* Remove Question either by index or prompt */
bool Quiz::removeQuestion(int index){
    if (index < 0 || index >= questions.size()) {
        return false;
    }
    questions.erase(questions.begin() + index);
    return true;
}

bool Quiz::removeQuestion(string prompt){
    bool removed = false;
    for (int i = 0; i < questions.size(); ++i) {
        if (questions[i].getPrompt() == prompt) {
            questions.erase(questions.begin() + i);
            --i;
            removed = true;
        }
    }
    return removed;
}



void Quiz::takeQuiz(string filename, ostream& outs, istream& ins) {
    // Read the quiz from the file
    readQuizFromFile(filename);

    // Reset fields
    totalPointsPossible = 0;
    totalPointsCorrect = 0;

    // Print title
    outs << title << endl << endl;

    string input;
    int index;
    // Print each question and get answer from user
    for (Question& q : questions) {
        totalPointsPossible += q.getPoints();

        // Print the question
        outs << q << endl;

        outs << "Your answer: ";
        getline(ins, input);
        // Input validation
        while (input.size() != 1 || tolower(input[0]) < 'a' || tolower(input[0]) >= ('a' + q.getNumAnswers())) {
            outs << "Invalid input. Try again: " << endl;
            getline(ins, input);
        }

        // Get the index of the answer based on the input from the user
        index = tolower(input[0]) - 'a';
        if (q.isCorrect(index)) {
            totalPointsCorrect += q.getPoints();
            outs << "Correct!" << endl << endl;
        } else {
            outs << "Incorrect" << endl << endl;
        }
    }

    outs << "You scored " << totalPointsCorrect;
    outs << " out of " << totalPointsPossible << endl;
}