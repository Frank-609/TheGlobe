#include <iostream>     
#include <cstdlib>    
#include <ctime>   
#include <string>
using namespace std;
int questionNumber = 1, correct = 0, wrong = 0, score = 0, teamsnum;
int duelcorrect[4] = { 0, 0, 0, 0 }, duelwrong[4] = { 0, 0, 0, 0 };
string choice, teams;
int b = 24;
string Correct[24][30] = {
{"AFGHANISTAN", "ALBANIA", "ALGERIA", "ANDORRA", "ANGOLA", "ANTIGUA AND BARBUDA", "ARGENTINA", "ARMENIA", "AUSTRALIA", "AUSTRIA", "AZERBAIJAN"},
{"BAHAMAS", "BAHRAIN", "BANGLADESH", "BARBADOS", "BELARUS", "BELGIUM", "BELIZE", "BENIN", "BHUTAN", "BOLIVIA", "BOSNIA AND HERZEGOVINA", "BOTSWANA", "BRAZIL", "BRUNEI", "BULGARIA", "BURKINA FASO", "BURUNDI"},
{"CÔTE D'IVOIRE","CAPE VERDE", "CAMBODIA", "CAMEROON", "CANADA", "CENTRAL-AFRICAN-REPUBLIC", "CHAD", "CHILE", "CHINA", "COLOMBIA", "COMOROS", "CONGO", "COSTA RICA", "CROATIA", "CUBA", "CYPRUS", "CZECHIA", "CZECH-REPUBLIC", "DEMOCRATIC REPUBLIC OF THE CONGO"},
{"DENMARK", "DJIBOUTI", "DOMINICA", "DOMINICAN REPUBLIC"},
{"EAST TIMOR", "ECUADOR", "EGYPT", "EL SALVADOR", "EQUATORIAL GUINEA", "ERITREA", "ESTONIA", "ESWATINI", "ETHIOPIA"},
{"FIJI", "FINLAND", "FRANCE"},
{"GABON", "GAMBIA", "GEORGIA", "GERMANY", "GHANA", "GREECE", "GRENADA", "GUATEMALA", "GUINEA", "GUINEA-BISSAU", "GUYANA"},
{"HAITI", "HONDURAS", "HUNGARY"},
{"ICELAND", "INDIA", "INDONESIA", "IRAN", "IRAQ", "IRELAND", "ISRAEL", "ITALY", "IVORY COAST"},
{"JAMAICA", "JAPAN", "JORDAN"},
{"KAZAKHSTAN", "KENYA", "KIRIBATI", "KUWAIT", "KYRGYZSTAN", "NORTH KOREA", "SOUTH KOREA"},
{"LAOS", "LATVIA", "LEBANON", "LESOTHO", "LIBERIA", "LIBYA", "LIECHTENSTEIN", "LITHUANIA", "LUXEMBOURG"},
{"MADAGASCAR", "MALAWI", "MALAYSIA", "MALDIVES", "MALI", "MALTA", "MARSHALL ISLANDS", "MAURITANIA", "MAURITIUS", "MEXICO", "MICRONESIA", "MOLDOVA", "MONACO", "MONGOLIA", "MONTENEGRO", "MOROCCO", "MOZAMBIQUE", "MYANMAR"},
{"NAMIBIA", "NAURU", "NEPAL", "NETHERLANDS", "NEW ZEALAND", "NICARAGUA", "NIGER", "NIGERIA", "NORTH KOREA", "NORTH MACEDONIA", "NORWAY"},
{"OMAN"},
{"PAKISTAN", "PALAU", "PALESTINE", "PANAMA", "PAPUA NEW GUINEA", "PARAGUAY", "PERU", "PHILIPPINES", "POLAND", "PORTUGAL"},
{"QATAR"},
{"ROMANIA", "RUSSIA", "RWANDA"},
{"SAINT KITTS AND NEVIS", "SAINT LUCIA", "SAINT VINCENT AND THE GRENADINES", "SAMOA", "SAN MARINO", "SAO TOME AND PRINCIPE", "SAUDI ARABIA", "SENEGAL", "SERBIA", "SEYCHELLES", "SIERRA LEONE", "SINGAPORE", "SLOVAKIA", "SLOVENIA", "SOLOMON ISLANDS", "SOMALIA", "SOUTH AFRICA", "SOUTH KOREA", "SOUTH SUDAN", "SPAIN", "SRI LANKA", "SUDAN", "SURINAME", "SWEDEN", "SWITZERLAND", "SYRIA"},
{"TAIWAN" ,"TAJIKISTAN", "TANZANIA", "THAILAND", "TIMOR-LESTE", "TOGO", "TONGA", "TRINIDAD AND TOBAGO", "TUNISIA", "TURKEY", "TURKMENISTAN", "TUVALU"},
{"UGANDA", "UKRAINE", "UNITED ARAB EMIRATES", "UNITED KINGDOM", "UNITED STATES OF AMERICA", "URUGUAY", "UZBEKISTAN"},
{"VANUATU", "VATICAN CITY", "VENEZUELA", "VIETNAM"},
{"YEMEN"},
{"ZAMBIA", "ZIMBABWE"},
};
char letter[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'Y', 'Z' };
char charchoice = 'Z';
bool ask[50] = { true, true, true, true, true, true, true, true, true, true,
true, true, true, true, true, true, true, true, true, true,
true, true, true, true, true, true, true, true, true, true,
true, true, true, true, true, true, true, true, true, true,
true, true, true, true, true, true, true, true, true, true };
void runGame();
void display();
void map();
void results();
void question(string, string, string, string, string, string, string, string);
void displayRandomQuestion();
void chooseTeams();
void duelDisplay();
void duelResults();
void duelQuestion(string, string, string, string, string, string, string, string);
void globalQuestion(string, string, string, string, string, string, string, string);
void guessTheCountry();
void about();
void howToUse();
void rules(string);
int main()
{
	cout << "\t  W E L C O M E   T O   T H E   G L O B E \n";
	map();
	system("read");
	srand(time(0));
	howToUse();
	runGame();
	return 0;
}
void runGame() {
	questionNumber = 1, correct = 0, wrong = 0, score = 0;
	for (int i = 0; i < 4; i++) {
		duelcorrect[i] = 0;
		duelwrong[i] = 0;
	}
	do {
		system("clear");
		cout << "A - QUIZ\nB - TEAMS\nC - GUESS THE COUNTRY\nD - ABOUT AND HOW TO USE\nE - QUIT\n\n";
		do {
			cin >> choice;
			if (choice != "a" && choice != "A" && choice != "b" && choice != "B" && choice != "c" && choice != "C" && choice != "d" && choice != "D" && choice != "e" && choice != "E")
				cout << "Invalid Input, Please Choose an Available Option: ";
		} while (choice != "a" && choice != "A" && choice != "b" && choice != "B" && choice != "c" && choice != "C" && choice != "d" && choice != "D" && choice != "e" && choice != "E");
		if (choice == "a" || choice == "A")
			charchoice = 'A';
		else if (choice == "b" || choice == "B")
			charchoice = 'B';
		else if (choice == "c" || choice == "C")
			charchoice = 'C';
		else if (choice == "d" || choice == "D")
			charchoice = 'D';
		else if (choice == "e" || choice == "E")
			charchoice = 'E';
		switch (charchoice) {
		case 'A':
			rules("To answer every question choose one of the 4 choices by typing A, B, C or D.\n"
				"Use \'*\' to go back to the main menu and display your final results.");
			display();
			break;
		case 'B':
			rules("Start by choosing the number of teams (2, 3 or 4).\n"
				"Every team will answer a question then the turn will pass to the next team.\n"
				"To answer every question choose between the 4 options by pressing A, B, C or D.\n"
				"Use \'*\' to go back to the main menu and display your final results.\n"
				"Note that you cannot go back to the main menu if the teams did not answer the same\n"
				"number of questions (you can go to the main menu only when it's the first team's turn.");
			chooseTeams();
			duelDisplay();
			break;
		case 'C':
			if (b != 0) {
				rules("Make sure to enter a country name correctly as it will be gramatically checked");
				guessTheCountry();
			}
			else {
				system("clear");
				cout << "All letters have passed.\nRerun the program to try again\n\n";
				system("read");
			}
			break;
		case 'D':
			about();
			break;
		case 'E':
			system("clear");
			cout << "Thank you for Playing <3\n\n";
			system("read");
			exit(0);
			break;
		}
	} while (charchoice != 'e' && charchoice != 'E');
}
void display() {
	system("clear");
	cout << "Question Number: " << questionNumber << "\t\tCorrect Answers: " << correct << "\t\tWrong Answers: " << wrong << "\t\t\'*\' To Go Back\n"
		<< "\t\t\t\t\t\t\t\t\t\t\t\tTo The Main Menu\n";
	displayRandomQuestion();
}
void map(){
		cout<<"******************************************************************"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣄⣠⣀⡀⣀⣠⣤⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⢠⣠⣼⣿⣿⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⢠⣤⣦⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⢦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣟⣾⣿⣽⣿⣿⣅⠈⠉⠻⣿⣿⣿⣿⣿⡿⠇⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⢀⡶⠒⢉⡀⢠⣤⣶⣶⣿⣷⣆⣀⡀⠀⢲⣖⠒⠀⠀⠀⠀⠀⠀⠀*"<<endl;
cout<<"*⠀⢀⣤⣾⣶⣦⣤⣤⣶⣿⣿⣿⣿⣿⣿⣽⡿⠻⣷⣀⠀⢻⣿⣿⣿⡿⠟⠀⠀⠀⠀⠀⠀⣤⣶⣶⣤⣀⣀⣬⣷⣦⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣤⣦⣼⣀⠀*"<<endl;
cout<<"*⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠓⣿⣿⠟⠁⠘⣿⡟⠁⠀⠘⠛⠁⠀⠀⢠⣾⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠏⠙⠁*"<<endl;
cout<<"*⠀⠀⠸⠟⠋⠀⠈⠙⣿⣿⣿⣿⣿⣿⣷⣦⡄⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⣼⣆⢘⣿⣯⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡉⠉⢱⡿⠀⠀⠀⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⡿⠦⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⡗⠀⠈⠀⠀⠀⠀⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣉⣿⡿⢿⢷⣾⣾⣿⣞⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⣠⠟⠀⠀⠀⠀⠀⠀⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⠿⠿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣾⣿⣿⣷⣦⣶⣦⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠈⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣤⡖⠛⠶⠤⡀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠙⣿⣿⠿⢻⣿⣿⡿⠋⢩⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠧⣤⣦⣤⣄⡀⠀⠀⠀⠀⠀⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠘⣧⠀⠈⣹⡻⠇⢀⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣤⣀⡀⠀⠀⠀⠀⠀⠀⠈⢽⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠹⣷⣴⣿⣷⢲⣦⣤⡀⢀⡀⠀⠀⠀⠀⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣷⢀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠂⠛⣆⣤⡜⣟⠋⠙⠂⠀⠀⠀⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⠉⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣾⣿⣿⣿⣿⣆⠀⠰⠄⠀⠉⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⠿⠿⣿⣿⣿⠇⠀⠀⢀⠀⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⡿⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⡇⠀⠀⢀⣼⠗⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠃⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠁⠀⠀⠀*"<<endl;
cout<<"*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀*"<<endl;
		cout<<"******************************************************************"<<endl;

}
void results() {
	system("clear");
	if (correct == 0 && questionNumber - 1 == 0)
		runGame();
	else {
		cout << "Questions Answered = " << questionNumber - 1 << endl;
		cout << "Correct Answers  = " << correct << endl;
		cout << "Wrong Answers = " << wrong << endl;
		cout << "Your Consistency: " << (correct * 100) / (questionNumber - 1) << "%\n\n";
		system("read");
		runGame();
	}
}
void question(string q, string a, string b, string c, string d, string correction, string correctAnswer, string CorrectAnswer) {
	cout << q << endl;
	cout << "A.\t" << a << endl;
	cout << "B.\t" << b << endl;
	cout << "C.\t" << c << endl;
	cout << "D.\t" << d << endl;
	string answer;
	do {
		cin >> answer;
		if (answer != "a" && answer != "A" &&
			answer != "b" && answer != "B" &&
			answer != "c" && answer != "C" &&
			answer != "d" && answer != "D" &&
			answer != "*")
			cout << "Invalid Input. Choose one of the given answers: ";
	} while (answer != "a" && answer != "A" &&
		answer != "b" && answer != "B" &&
		answer != "c" && answer != "C" &&
		answer != "d" && answer != "D" &&
		answer != "*");
	if (answer == "*") {
		results();
		runGame();
	}
	else {
		if (answer == correctAnswer || answer == CorrectAnswer) {
			cout << "Correct!" << endl;
			correct++;
		}
		else {
			cout << "Incorrect, the correct answer is " << CorrectAnswer << ". " << correction << endl;
			wrong++;
		}
		questionNumber++;
		if (questionNumber == 13) {
			system("read");
			results();
		}
		system("read");
		display();
	}
}
void displayRandomQuestion() {
	bool isQuestionRemaining = false;
	for (int i = 0; i < 50; i++) {
		if (ask[i] == true) {
			isQuestionRemaining = true;
			break;
		}
	}
	while (isQuestionRemaining == true) {
		int no = rand() % 50;
		if (ask[no] == true) {
			ask[no] = false;
			switch (no) {
			case 0: globalQuestion("Which of these countries shares borders with Brazil", "Paraguay", "Chile", "Lebanon", "None of the above", "Paraguay", "a", "A"); break;
			case 1: globalQuestion("What is the capital of Canada?", "Toronto", "Ottawa", "Vancouver", "Ontario", "Ottawa", "b", "B"); break;
			case 2: globalQuestion("What is the capital of Uganda?", "Yaoundé", "Kampala", "N'Djamena", "Maseru", "Kampala", "b", "B"); break;
			case 3: globalQuestion("What is the capital of Italy?", "Venice", "Florence", "Rome", "Naples", "Rome", "c", "C"); break;
			case 4: globalQuestion("On which continent is the Sahara Desert located?", "Asia", "South America", "Africa", "Europe", "Africa", "c", "C"); break;
			case 5: globalQuestion("How tall is Mount Everest?", "6,849", "7,849", "8,849", "9,849", "8,849", "c", "C"); break;
			case 6: globalQuestion("Which of these countries is larger in population? (as of May 2023)", "India", "China", "U.S.A.", "Russia", "India", "a", "A"); break;
			case 7: globalQuestion("Which of these is NOT an American State?", "New Delhi", "New Jersey", "New Hampshire", "New York", "New Delhi", "a", "A"); break;
			case 8: globalQuestion("Which two countries is NOT in Africa?", "Guyana and Papua New Guinea", "Equatorial Guinea and Guinea-Bissau", "Guinea and Gabon", "Guinea-Bissau and Gambia", "Guyana and Papua New Guinea", "a", "A"); break;
			case 9: globalQuestion("What is the capital of the United Arab Emirates?", "Dubai", "Abu Dhabi", "Sharjah", "Ajman", "Abu Dhabi", "b", "B"); break;
			case 10: globalQuestion("What is the smallest country in the world?", "Andorra", "Luxembourg", "Vatican City", "Belgium", "Vatican City", "c", "C"); break;
			case 11: globalQuestion("Two of the countries bordering Egypt are:", "Saudi Arabia and Iran", "Algeria and Cyprus", "India and Pakistan", "Algeria and Sudan", "Algeria and Sudan", "d", "D"); break;
			case 12: globalQuestion("Which of these countries does NOT share borders with Germany?", "France", "Austria", "Poland", "Lithuania", "Lithuania", "d", "D"); break;
			case 13: globalQuestion("Which of these countries does NOT share borders with Ukraine?", "Belarus", "Russia", "Latvia", "Romania", "Latvia", "c", "C"); break;
			case 14: globalQuestion("Which of these countries does NOT share borders with Lebanon", "Jordan", "Cyprus", "Damascus", "All of the above", "All of the above", "d", "D"); break;
			case 15: globalQuestion("What is the capital of Madagascar?", "Antananarivo", "Kyiv", "Bern", "Helsinki", "Antananarivo", "a", "A"); break;
			case 16: globalQuestion("What is the capital of Mexico?", "Mini Mexico", "New Mexico", "Mexico City", "San Francisco", "Mexico City", "c", "C"); break;
			case 17: globalQuestion("What is the capital of Sweden?", "Stockholm", "Khartoum", "Lusaka", "St. John's", "Stockholm", "a", "A"); break;
			case 18: globalQuestion("On which continent can we find \"Timor-Leste\"?", "Africa", "Australia", "Asia", "Europe", "Asia", "c", "C"); break;
			case 19: globalQuestion("Which sea is located WEST of Lebanon?", "Meditarian", "Miditarranian", "Meditarrinian", "Mediterranian", "Mediterranian", "d", "D"); break;
			case 20: globalQuestion("Which of these countries shares borders with Kazakhstan?", "Russia", "Ethiopia", "Yemen", "Serbia", "Russia", "a", "A"); break;
			case 21: globalQuestion("Which of these countries shares borders with Monaco?", "Spain and Italy", "Laos and Myanmar", "France", "Lithuania and Latvia", "France", "c", "C"); break;
			case 22: globalQuestion("Which of these countries shares borders with Chile?", "U.S.A.", "Colombia", "Argentina", "Mexico", "Argentina", "c", "C"); break;
			case 23: globalQuestion("Which of these countries does NOT share borders with U.S.A?", "Mexico", "Canada", "Brazil", "None of the above", "Brazil", "c", "C"); break;
			case 24: globalQuestion("Two of the countries that NEITHER shares borders with China:", "Lebanon and Nepal", "Qatar and Indonesia", "Vietnam and The Philippines", "North Korea and Papua New Guinea", "Qatar and Indonesia", "b", "B"); break;
			case 25: globalQuestion("What is the capital of Burkina Faso?", "Agadagou", "Gougadaga", "Gagoudaga", "Ougadougou", "Ougadougou", "d", "D"); break;
			case 26: globalQuestion("What is the capital of South Korea?", "Tbilisi", "Seoul", "N'Djamena", "Pyongyang", "Seoul", "b", "B"); break;
			case 27: globalQuestion("What is the capital of Romania?", "Tbilisi", "Seoul", "Copenhagen", "Bucharest", "Bucharest", "d", "D"); break;
			case 28: globalQuestion("What is the capital of Georgia?", "London", "Saint George's", "Bucharest", "Tbilisi", "Tbilisi", "d", "D"); break;
			case 29: globalQuestion("What is the capital of India?", "Old Delhi", "Delhi", "New Delhi", "Newest Delhi Ever", "New Delhi", "c", "C"); break;
			case 30: globalQuestion("What is the capital of Venezuela?", "Santiago", "Asuncion", "Montevideo", "Caracas", "Caracas", "d", "D"); break;
			case 31: globalQuestion("What is the capital of Albania?", "Paris", "Minsk", "Tirana", "Ougadougou", "Tirana", "c", "C"); break;
			case 32: globalQuestion("What is the capital of Belarus?", "Berlin", "Oslo", "Valetta", "Minsk", "Minsk", "d", "D"); break;
			case 33: globalQuestion("What is the capital of Armenia?", "Ashgabat", "Yerevan", "Budapest", "Ankara", "Yerevan", "b", "B"); break;
			case 34: globalQuestion("What is the capital of Mongolia?", "Ulaanbaatar", "Kyiv", "Valetta", "Sofia", "Ulaanbaatar", "a", "A"); break;
			case 35: globalQuestion("What is the capital of Estonia?", "Vaduz", "Kyiv", "Tallinn", "Yamoussoukro", "Tallinn", "c", "C"); break;
			case 36: globalQuestion("What is one capital of Sri Lanka?", "Sri Jayewardenepura Kotte", "Sri", "Jayewardenepura", "Kotte", "Jayewardenepura Kotte", "a", "A"); break;
			case 37: globalQuestion("What are the three capitals of South Africa?", "Sri, Jayewardenepura and Kotte", "Pretoria, Bloemfontein, and Cape Town", "Bandar, Seri and Begawan", "Jerusalem, Constantinople and Alexandria", "Pretoria, Bloemfontein, and Cape Town", "b", "B"); break;
			case 38: globalQuestion("What are the three capitals of Kiribati?", "Bairiki, Ambo, and Betio", "Sofia, Washington D.C and Warsaw", "Beirut, Ambo and Baalbek", "Jerusalem, Constantinople and Alexandria", "Bairiki, Ambo, and Betio", "a", "A"); break;
			case 39: globalQuestion("What is the capital of Bosnia and Herzegovina?", "Berlin", "Valetta", "Madrid", "Sarajevo", "Sarajevo", "d", "D"); break;
			case 40: globalQuestion("Which of these U.S states is landlocked (has no access to sea)?", "Hawai'i", "Florida", "Colorado", "California", "Colorado", "c", "C"); break;
			case 41: globalQuestion("Which of these U.S states is landlocked (has no access to sea)?", "Washington", "Hawai'i", "Texas", "Kansas", "Kansas", "d", "D"); break;
			case 42: globalQuestion("Which of these countries is landlocked (has no access to sea)?", "The Philippines", "Afghanistan", "Cyprus", "Russia", "Afghanistan", "b", "B"); break;
			case 43: globalQuestion("Which of these countries is the largest in area?", "Nepal", "Cambodia", "Singapore", "Indonesia", "Indonesia", "d", "D"); break;
			case 44: globalQuestion("Which of these U.S states is the largest in area?", "California", "Alaska", "New York", "Kentucky", "Alaska", "b", "B"); break;
			case 45: globalQuestion("Which of these countries is smallest in area?", "Italy", "Luxembourg", "Somalia", "The Philippines", "Luxembourg", "b", "B"); break;
			case 46: globalQuestion("Which of these countries is NOT landlocked (has access to sea)", "Nepal", "Sri Lanka", "Bolivia", "Chad", "Sri Lanka", "b", "B"); break;
			case 47: globalQuestion("Which of these countries is NOT landlocked (has access to sea)?", "Uzbekistan", "Kyrgyztan", "Pakistan", "Tajikistan", "Pakistan", "c", "C"); break;
			case 48: globalQuestion("Which of these elements (from the periodic table) is NOT named after a country?", "Ruthenium", "Praseodymium", "Germanium", "Polonium", "Praseodymium", "b", "B"); break;
			case 49: globalQuestion("Which country literaly means \"Equator\" ?", "Bhutan", "Yemen", "El Salvador", "Ecuador", "Ecuador", "d", "D"); break;
			}
		}
	}
}
void chooseTeams() {
	system("clear");
	cout << "Choose the number of teams:\t\t\t\t\t\t\t\t\t\'*\' To Go Back\n"
		<< "\t\t\t\t\t\t\t\t\t\t\t\tTo The Main Menu\n"
		<< "Press A for 2 Teams\n"
		<< "Press B for 3 Teams\n"
		<< "Press C for 4 Teams\n\n";
	do {
		cin >> teams;
		if (teams == "*")
			runGame();
		else if (teams == "a" || teams == "A")
			teamsnum = 2;
		else if (teams == "b" || teams == "B")
			teamsnum = 3;
		else if (teams == "c" || teams == "C")
			teamsnum = 4;
		else
			cout << "Invalid Input, Please Choose an Available Option: ";
	} while (teams != "a" && teams != "A"
		&& teams != "b" && teams != "B"
		&& teams != "c" && teams != "C");
}
void duelDisplay() {
	system("clear");
	cout << "Score:\t\t\t\t\t\t\t\t\t\t\t\t\'*\' To Go Back\n"
		<< "Team 1: " << duelcorrect[0] << "\t\t\t\t\t\t\t\t\t\t\tTo The Main Menu"
		<< "\nTeam 2: " << duelcorrect[1];
	if (teamsnum > 2)
		cout << "\nTeam 3: " << duelcorrect[2];
	if (teamsnum > 3)
		cout << "\nTeam 4: " << duelcorrect[3] << "\n\n";
	else
		cout << "\n\n";
	cout << "Team " << (questionNumber + (teamsnum - 1)) % teamsnum + 1 << "'s Turn:" << "\n\n";
	displayRandomQuestion();
	/*switch (teamsnum) {
	case 2: cout << "Score:\t\t\t\t\t\t\t\t\t\t\t\t\'*\' To Go Back\n"
		<< "Team 1: " << duelcorrect[0] << "\t\t\t\t\t\t\t\t\t\t\tTo The Main Menu"
		<< "\nTeam 2: " << duelcorrect[1];
		if (teamsnum > 2)
			cout << "\nTeam 3: " << duelcorrect[2];
		if (teamsnum > 3)
			cout << "\nTeam 4: " << duelcorrect[3] << "\n\n";
		else
			cout << "\n\n";
		cout << "Team " << questionNumber % teamsnum << "'s Turn:" << "\n\n";
		displayRandomQuestion();
		break;
	case 3: cout << "Score:\t\t\t\t\t\t\t\t\t\t\t\t\'*\' To Go Back\n"
		<< "Team 1: " << duelcorrect[0] << "\t\t\t\t\t\t\t\t\t\t\tTo The Main Menu"
		<< "\nTeam 2: " << duelcorrect[1] << "\nTeam 3: " << duelcorrect[2] << "\n\n";
		displayRandomQuestion();
		break;
	case 4: cout << "Score:\t\t\t\t\t\t\t\t\t\t\t\t\'*\' To Go Back\n"
		<< "Team 1: " << duelcorrect[0] << "\t\t\t\t\t\t\t\t\t\t\tTo The Main Menu"
		<< "\nTeam 2: " << duelcorrect[1] << "\nTeam 3: " << duelcorrect[2] << "\nTeam 4: " << duelcorrect[3] << "\n\n";
		displayRandomQuestion();
		break;
	}*/
}
void duelResults() {
	system("clear");
	if (questionNumber - 1 == 0)
		runGame();
	else {
		cout << "Questions Answered = " << (questionNumber - 1) / teamsnum << "\n\n";
		cout << "Team 1:\t\tCorrect Answers = " << duelcorrect[0] << "\tWrong Answers = " << duelwrong[0] << "\tConsistency: " << (duelcorrect[0] * 100) / ((questionNumber - 1) / teamsnum) << "%\n";
		cout << "Team 2:\t\tCorrect Answers = " << duelcorrect[1] << "\tWrong Answers = " << duelwrong[1] << "\tConsistency: " << (duelcorrect[1] * 100) / ((questionNumber - 1) / teamsnum) << "%\n";
		if (teamsnum > 2)
			cout << "Team 3:\t\tCorrect Answers = " << duelcorrect[2] << "\tWrong Answers = " << duelwrong[2] << "\tConsistency: " << (duelcorrect[2] * 100) / ((questionNumber - 1) / teamsnum) << "%\n";
		if (teamsnum > 3)
			cout << "Team 4:\t\tCorrect Answers = " << duelcorrect[3] << "\tWrong Answers = " << duelwrong[3] << "\tConsistency: " << (duelcorrect[3] * 100) / ((questionNumber - 1) / teamsnum) << "%\n\n";
		else cout << "\n";
		cout << "Congratulations to the team with the highest consistency!\n\n";
		system("read");
		runGame();
	}
}
void duelQuestion(string q, string a, string b, string c, string d, string correction, string correctAnswer, string CorrectAnswer) {
	cout << q << endl;
	cout << "A.\t" << a << endl;
	cout << "B.\t" << b << endl;
	cout << "C.\t" << c << endl;
	cout << "D.\t" << d << endl;
	string answer;
	do {
		cin >> answer;
		if (answer != "a" && answer != "A" &&
			answer != "b" && answer != "B" &&
			answer != "c" && answer != "C" &&
			answer != "d" && answer != "D" &&
			answer != "*")
			cout << "Invalid Input. Choose one of the given answers: ";
	} while (answer != "a" && answer != "A" &&
		answer != "b" && answer != "B" &&
		answer != "c" && answer != "C" &&
		answer != "d" && answer != "D" &&
		answer != "*");
	if (answer == "*" && (questionNumber + (teamsnum - 1)) % teamsnum == 0) {
		duelResults();
		runGame();
	}
	else {
		if (answer == "*" && (questionNumber + (teamsnum - 1)) % teamsnum != 0) {
			cout << "Let all teams finish their turn. Please answer this question: ";
			do {
				cin >> answer;
				if (answer != "a" && answer != "A" &&
					answer != "b" && answer != "B" &&
					answer != "c" && answer != "C" &&
					answer != "d" && answer != "D")
					cout << "Invalid Input. Choose one of the given answers: ";
			} while (answer != "a" && answer != "A" &&
				answer != "b" && answer != "B" &&
				answer != "c" && answer != "C" &&
				answer != "d" && answer != "D");
		}
		if (answer == correctAnswer || answer == CorrectAnswer) {
			cout << "Correct!" << endl;
			duelcorrect[(questionNumber + (teamsnum - 1)) % teamsnum]++;
		}
		else {
			cout << "Incorrect, the correct answer is " << CorrectAnswer << ". " << correction << endl;
			duelwrong[(questionNumber + (teamsnum - 1)) % teamsnum]++;
		}
		questionNumber++;
		if (questionNumber == 13) {
			system("read");
			duelResults();
		}
		system("read");
		duelDisplay();
	}
}
void globalQuestion(string q, string a, string b, string c, string d, string correction, string correctAnswer, string CorrectAnswer) {
	if (charchoice == 'A')
		question(q, a, b, c, d, correction, correctAnswer, CorrectAnswer);
	else if (charchoice == 'B')
		duelQuestion(q, a, b, c, d, correction, correctAnswer, CorrectAnswer);
}
void guessTheCountry() {
	string name = "null";
	for (int k = 1; k <= 24; k++) {
		system("clear");
		if (k == 9 || b == 0) {
			cout << "Questions Asked = " << questionNumber - 1 << "\n";
			cout << "Correct Answers = " << score << "\n";
			cout << "Wrong Answers = " << questionNumber - 1 - score << "\n";
			cout << "Your Consistency: " << (score * 100) / (questionNumber - 1) << "%\n\n";
			system("read");
			runGame();
		}
		cout << "Question Number: " << questionNumber << "\t\tCorrect Answers: " << score << "\t\tWrong Answers: " << questionNumber - score - 1
			<< "\t\t\'*\' To Go Back\n\t\t\t\t\t\t\t\t\t\t\t\tTo The Main Menu\n";
		int i = rand() % b;
		char chosenletter = letter[i];
		cout << "Name a country that starts with the letter " << chosenletter << "\n\n";
		if (k == 1)
			getline(cin, name);
		do {
			getline(cin, name);
		} while (name == "");
		cout << "\n";
		if (name == "*") {
			system("clear");
			if (questionNumber != 1) {
				cout << "Questions Asked = " << questionNumber - 1 << "\n";
				cout << "Correct Answers = " << score << "\n";
				cout << "Wrong Answers = " << questionNumber - 1 - score << "\n";
				cout << "Your Consistency: " << (score * 100) / (questionNumber - 1) << "%\n\n";
				system("read");
			}
			runGame();
		}
		else {
			questionNumber++;
			int caseShifter = 0;
			while (name[caseShifter] != '\0') {
				name[caseShifter] = toupper(name[caseShifter]);
				caseShifter++;
			}
			int scorebefore = score;
			for (int countryname = 0; countryname < 30; countryname++)
				if (name == Correct[i][countryname]) {
					cout << "Correct!" << endl;
					score++;
					break;
				}
			if (scorebefore == score)
			{
				cout << "Incorrect, possibilities are:\n";
				for (int counter = 0; counter < 30; counter++) {
					if (Correct[i][counter + 1] != "\0")
						cout << Correct[i][counter] << ", ";
					else { 
						cout << Correct[i][counter] << "." << endl; 
						break; 
					}
				}
			}
			for (int j = i; j < b; j++)
				letter[j] = letter[j + 1];
			for (int j = i; j < b; j++)
				for (int col = 0; col < 30; col++)
					Correct[j][col] = Correct[j + 1][col];
			b--;
			cout << "\n";
			system("read");
		}
	}

}
1