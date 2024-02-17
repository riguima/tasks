#include <cctype>
#include <fstream>
#include <json/json.h>
#include <json/value.h>
#include <json/writer.h>
#include <iostream>
#include <string>

using namespace std;


void show_tasks(Json::Value &db){
  if (db["tasks"].empty()){
    cout << "Sem tarefas adicionadas\n\n";
  } else {
    int count = 0;
    for (auto task:db["tasks"]){
      cout << count << " - " << task.asString() << '\n';
      count++;
    }
    cout << '\n';
  }
}


void done_task(Json::Value &db, int task_index){
  int count = 0;
  Json::Value tasks = Json::arrayValue;
  for (auto task:db["tasks"]) {
    if (count != task_index) {
      tasks.append(task);
    }
    count++;
  }
  db["tasks"] = tasks;
}


int main(){
  ifstream db_file("db.json");
  Json::Value db;
  if(db_file){
    db_file >> db;
    db_file.close();
  } else {
    db["tasks"] = Json::arrayValue;
  }
  string response;
  ofstream result("db.json");
  while (true) {
    system("clear");
    show_tasks(db);
    cout << "Digite o índice da task para concluir ou o nome da task para adicionar, digite exit para sair: ";
    getline(cin, response);
    if (response == "exit") {
      break;
    } else if (isdigit(response[0]) && response.length() == 1) {
      done_task(db, stoi(response));
    } else {
      db["tasks"].append(response);
    }
  }
  result << db;
  result.close();
  return 0;
}
