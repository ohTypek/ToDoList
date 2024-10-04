#include <iostream>
#include <fstream>

void showNotes() {

  std::string note;
  std::cout << "\nYour notes:\n" << std::endl;

  std::ifstream read("notes.txt");
  if (!read) {
    std::cerr << "Error opening the file." << std::endl;
  }
  for (int i = 1; std::getline(read, note); i++) {
    std::cout << note << std::endl;
  }
}

void addNewNote() {

  std::string note;

  std::cout << "Add content: ";
  std::cin.ignore();
  std::getline(std::cin, note);

  std::ofstream outputFile("notes.txt", std::ios::app);
  if(!outputFile) {
    std::cerr << "Error opening the file.\n";
  }
  if(!note.empty()) {
    outputFile << note << std::endl;
  }

  outputFile.close();

  showNotes();

  char answer;
  std::cout << "\nDo you want to add more notes? (y/n): ";
  std::cin >> answer;

  if (tolower(answer) == 'y')
  {
    addNewNote();
  }
}

void removeAllNotes() {
  std::ofstream file("notes.txt");
  file << "";
  file.close();
}

int main() {

  int answer;
  int note_count = 0;

  std::cout << "TO DO LIST" << std::endl; 

  showNotes();

  std::cout << "\n1: Add new\n2: Remove All\n3: End\nYour choice: ";
  std::cin >> answer;

  if (answer == 1) {
    addNewNote();
  } else if (answer == 2) {
    removeAllNotes();
  }

  return 0;
}