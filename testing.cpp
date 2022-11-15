#include "Question.h"
#include "Quiz.h"
#include "Song.h"
#include "Artist.h"
#include "MusicLabel.h"
#include <iostream>
using namespace std;

bool testQuestion();
bool testQuiz();
bool testSong();
bool testArtist();
bool testLabel();

int main() {
    if (testQuestion()) {
        cout << "Passed all Question test cases" << endl << endl;
    }
    if (testQuiz()) {
        cout << "Passed all Quiz test cases" << endl << endl;
    }
    if (testSong()) {
        cout << "Passed all Song test cases" << endl << endl;
    }
    if (testArtist()) {
        cout << "Passed all Artist test cases" << endl << endl;
    }
    if (testLabel()) {
        cout << "Passed all Label test cases" << endl << endl;
    }
    return 0;
}

bool testQuestion() {
    bool passed = true;
    //constructors
    Question q1 = Question();
    if (q1.getPrompt() != "" || q1.getPoints() != 0 || q1.getNumAnswers() != 0) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }
    //getter and setters
    q1.setPrompt("Test");
    if(q1.getPrompt() != "Test"){
        passed = false;
        cout << "FAILED prompt test case 1" << endl;
    }
    q1.setPrompt("Test test");
    if(q1.getPrompt() != "Test test"){
        passed = false;
        cout << "FAILED prompt test case 2" << endl;
    }
    q1.setPoints(12);
    if(q1.getPoints() != 12) {
        passed = false;
        cout << "FAILED point test case 2" << endl;
    }
    q1.setPoints(0);
    if(q1.getPoints() != 0){
        passed = false;
        cout << "FAILED point test case 2" << endl;
    }

    //add answer, get number of answers, get answer
    answer a1 = answer();
    q1.addAnswer(a1);
    if (q1.getNumAnswers() != 1){
        passed = false;
        cout << "FAILED add answer test case " << endl;

    }
    q1.addAnswer("answer", true);
    q1.addAnswer("test", false);
    if (q1. getNumAnswers() != 3){
        passed = false;
        cout << "FAILED add answer test case " << endl;
    }
    //is correct
    if (!q1.isCorrect(1)){
        passed = false;
        cout << "FAILED is correct index test case " << endl;
    }
    if (q1.isCorrect("test")){
        passed = false;
        cout << "FAILED is correct string test case " << endl;
    }
    //cout <<
    cout << q1 << endl;
    //expected output
    /*Test test
      a.
      b. answer
      c. test */

    //remove and clear answers
    q1.removeAnswer(0);
    if(q1.getNumAnswers() != 2){
        passed = false;
        cout << "FAILED remove answer index test case " << endl;
    }
    q1.removeAnswer("test");
    if(q1.getNumAnswers() != 1){
        passed = false;
        cout << "FAILED remove answer prompt test case " << endl;
    }
    if (q1.removeAnswer(-2)){
        passed = false;
        cout << "FAILED remove answer out of index case " << endl;
    }
    if (q1.removeAnswer("word")) {
        passed = false;
        cout << "FAILED remove answer no prompt case " << endl;
    }
    q1.clearAnswers();
    if (q1.getNumAnswers() != 0){
        passed = false;
        cout << "FAILED clear answer test case " << endl;
    }
    return passed;
}

bool testQuiz() {
    bool passed = true;
    //constructor
    Quiz qz1 = Quiz();
    if (qz1.getTitle() != "" || qz1.getTotalPointsCorrect() != 0||
        qz1.getTotalPointsPossible() != 0|| qz1.getNumberOfQuestions() != 0){
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }
    //getter and setters
    if(qz1.getTotalPointsPossible()!= 0){
        passed = false;
        cout << "FAILED get points possible" << endl;
    }
    if(qz1.getTotalPointsCorrect()!= 0){
        passed = false;
        cout << "FAILED get points correct" << endl;
    }
    qz1.setTitle("Test");
    if(qz1.getTitle() != "Test"){
        passed = false;
        cout << "FAILED Title test case 1" << endl;
    }
    qz1.setTitle("Test test");
    if(qz1.getTitle() != "Test test"){
        passed = false;
        cout << "FAILED Title test case 2" << endl;
    }
    //add question, get number of question, get question
    Question question1 = Question();
    qz1.addQuestion(question1);
    if (qz1.getNumberOfQuestions() != 1){
        passed = false;
        cout << "FAILED add question test case " << endl;
    }
    Question question2 = Question();
    question2.setPrompt("test");
    qz1.addQuestion(question2);
    if (qz1.getNumberOfQuestions() != 2){
        passed = false;
        cout << "FAILED add question test case " << endl;
    }
    if (qz1.getQuestion(5).getPrompt() !=  ""){
        passed = false;
        cout << "FAILED get question out of index test case " << endl;
    }
    if (qz1.getQuestion(0).getPrompt() !=  question1.getPrompt()){
        passed = false;
        cout << "FAILED get question index test case " << endl;
    }
    if (qz1.getQuestion("wrong").getPrompt() !=  ""){
        passed = false;
        cout << "FAILED get question no prompt test case " << endl;
    }
    if (qz1.getQuestion("test").getPrompt() !=  question2.getPrompt()){
        passed = false;
        cout << "FAILED get question prompt test case " << endl;
    }
    //remove question
    qz1.removeQuestion(0);
    if(qz1.getNumberOfQuestions() != 1){
        passed = false;
        cout << "FAILED remove question index test case " << endl;
    }
    qz1.removeQuestion("test");
    if(qz1.getNumberOfQuestions() != 0){
        passed = false;
        cout << "FAILED remove question prompt test case " << endl;
    }
    if(qz1.removeQuestion(-3)){
        passed = false;
        cout << "FAILED remove question out of index test case " << endl;
    }
    if(qz1.removeQuestion("word")){
        passed = false;
        cout << "FAILED remove question no prompt test case " << endl;
    }
    return passed;
}

bool testSong(){
    bool passed = true;
    //constructors
    Song s1 = Song();
    if (s1.getTitle() != "" || s1.getArtist().getName() != "" ||
            s1.getGenre() != "" || s1.getYear() != 0){
        passed = false;
        cout << "FAILED default constructor test" << endl;
    }
    Song s2 = Song("Hello", Artist("alex", 24), "pop", 2022);
    if (s2.getTitle() != "Hello" || s2.getArtist().getName() != "alex" ||
            s2.getGenre() != "pop" || s2.getYear() != 2022){
        passed = false;
        cout << "FAILED constructor test" << endl;
    }
    //getters and setters
    s1.setTitle("tester");
    if (s1.getTitle() != "tester"){
        passed = false;
        cout << "FAILED set/get title test1" << endl;
    }
    s1.setTitle("test");
    if (s1.getTitle() != "test"){
        passed = false;
        cout << "FAILED set/get title test2" << endl;
    }
    s1.setArtist(Artist("bob", 34));
    if (s1.getArtist().getName() != "bob") {
        passed = false;
        cout << "FAILED set/get artist test1" << endl;
    }
    s1.setArtist(Artist("harry", 34));
    if (s1.getArtist().getName() != "harry") {
        passed = false;
        cout << "FAILED set/get artist test2" << endl;
    }
    s1.setGenre("pop");
    if (s1.getGenre() != "pop") {
        passed = false;
        cout << "FAILED set/get genre test1" << endl;
    }
    s1.setGenre("rock");
    if (s1.getGenre() != "rock"){
        passed = false;
        cout << "FAILED set/get genre test2" << endl;
    }
    s1.setYear(2022);
    if (s1.getYear() != 2022) {
        passed = false;
        cout << "FAILED set/get year test" << endl;
    }
    s1.setYear(-3453);
    if (s1.getYear() != 0) {
        passed = false;
        cout << "FAILED set/get year test less than 0" << endl;
    }
    //overloaded operator
    cout << s2 << endl << endl;
    return passed;
}

bool testArtist(){
    bool passed = true;
    Artist a1 = Artist();
    if (a1.getName() != "" || a1.getAge() != 0){
        passed = false;
        cout << "FAILED default constructor test" << endl;
    }
    Artist a2 = Artist("Holly", 34);
    if (a2.getName() != "Holly" || a2.getAge() != 34){
        passed = false;
        cout << "FAILED constructor test" << endl;
    }
    //getters and setters
    a1.setName("Joy");
    if (a1.getName() != "Joy"){
        passed = false;
        cout << "FAILED set/get name test1" << endl;
    }
    a1.setName("polly");
    if (a1.getName() != "polly"){
        passed = false;
        cout << "FAILED set/get name test2" << endl;
    }
    a1.setAge(23);
    if (a1.getAge() != 23) {
        passed = false;
        cout << "FAILED set/get age test" << endl;
    }
    a1.setAge(-34);
    if (a1.getAge() != 0) {
        passed = false;
        cout << "FAILED set/get age less than 0" << endl;
    }
    //overloaded operator
    cout << a2 << endl;
    return passed;
}

bool testLabel(){
    bool passed = true;
    MusicLabel l1 = MusicLabel();
    if (l1.getLabelName() != "" || l1.getArtists().size() != 0){
        passed = false;
        cout << "FAILED default constructor test" << endl;
    }
    MusicLabel l2 = MusicLabel("labels", vector<Artist> {Artist("Jack", 45)});
    if (l2.getLabelName() != "labels" || l2.getArtists().size() != 1){
        passed = false;
        cout << "FAILED constructor test" << endl;
    }
    //get/set label name
    l1.setLabelName("record");
    if(l1.getLabelName() != "record"){
        passed = false;
        cout << "FAILED get get/set label name1" << endl;
    }
    l1.setLabelName("record2");
    if(l1.getLabelName() != "record2"){
        passed = false;
        cout << "FAILED get get/set label name2" << endl;
    }
    //artist functions
    Artist a1 = Artist();
    l1.addArtist(a1);
    if (l1.getArtists().size() != 1){
        passed = false;
        cout << "FAILED add Artist test case " << endl;
    }
    Artist a2 = Artist("andy", 23);
    l1.addArtist(a2);
    if (l1.getArtists().size() != 2){
        passed = false;
        cout << "FAILED add Artist test case " << endl;
    }
    if (l1.getArtist(7).getName() !=  ""){
        passed = false;
        cout << "FAILED get artist out of index test case " << endl;
    }
if (l1.getArtist(1).getName() !=  a2.getName()){
        passed = false;
        cout << "FAILED get artist index test case " << endl;
    }
    if (l1.getArtist("hello").getName() !=  ""){
        passed = false;
        cout << "FAILED get artist no prompt test case " << endl;
    }
    if (l1.getArtist("andy").getName() !=  a2.getName()){
        passed = false;
        cout << "FAILED get artist prompt test case " << endl;
    }
    //remove question2
    l1.removeArtist(0);
    if(l1.getArtists().size() != 1){
        passed = false;
        cout << "FAILED remove answer index test case " << endl;
    }
    l1.removeArtist("andy");
    if(l1.getArtists().size() != 0){
        passed = false;
        cout << "FAILED remove artist prompt test case " << endl;
    }
    if(l1.removeArtist(-3)){
        passed = false;
        cout << "FAILED remove artist out of index test case " << endl;
    }
    if(l1.removeArtist("word")){
        passed = false;
        cout << "FAILED remove artist no prompt test case " << endl;
    }
    //overloaded operator
    cout << l2 << endl;
    return passed;
}