#include <cctype>
#include <fstream>
#include <json/json.h>
#include <json/writer.h>
#include <iostream>
#include <string>


void done_task(int task_index){
}


void add_task(std::string title){
}


int main(){
  std::ifstream db_file("db.json");
  Json::Value db;
  if(db_file){
    db_file >> db;
    db_file.close();
  }
  std::string response;
  std::cout << "Digite o índice da task para concluir ou o nome da task para adicionar: ";
  std::cin >> response;
  if (isdigit(response[0]) && response.length() == 1) {
    done_task((int)response[0]);
  } else {
    add_task(response);
  }
  return 0;
}
