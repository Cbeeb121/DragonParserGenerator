#include <iostream> 
#include <fstream>
#include <list>
#include <map>
#include <string>
using namespace std; 

void buildMap(string file);
void addToMap(string key, string rhs);
void map_to_source(ostream &out); 
map<string, list<string> > grammar_map;

int main(int argc, char **argv){
  if (argc < 2){
    cout << "Yooo hooo! I expected an input grammar file (ex. `input.grammar`)\n";
  } else {
    buildMap(argv[1]);
  }
  ofstream outStream("parser.cpp");
  
  string line = "";
  // deal with footer
  ifstream headFile("parser_head.cpp.data");
  while(getline(headFile, line)){
    outStream << line << "\n";
  }
  headFile.close();
  
  map_to_source(outStream);

  ifstream footerFile("parser_footer.cpp.data");
  while(getline(footerFile, line)){
    outStream << line << "\n"; 
  }
  footerFile.close();
  // deal with header
  outStream.close(); 
}

void buildMap(string file){
  ifstream grammarFile(file);
  string line;
  string key = "";
  int delim = 0;

  while (getline(grammarFile, line)){
    if (line.find("::=") != string::npos) {
      delim = line.find("::=");
      key = line.substr(0, delim-1);
      line.erase(0, delim + 3);
      string rhs = line;
      addToMap(key, rhs);
    } else if (line.find("|")) {
      delim = line.find("|");
      line.erase(0, delim + 1);
      string rhs = line;
      addToMap(key, rhs);
    } else {
      cout << "\nproblem child here.\n";
    }
  }
}

void addToMap(string key, string rhs){
  if(rhs == "") { rhs = "~"; }
  if (rhs[0] == ' '){
    rhs = rhs.substr(1, rhs.length());
  }
  grammar_map[key].push_back(rhs);
}

void map_to_source(ostream &out) {
  out << "\tmap<string, list<string> > amap;\n";
  for(auto it = grammar_map.begin(); it != grammar_map.end(); ++it){
    string key = it->first;
    for(auto item : it->second){
      out << "\tamap[\"" + key + "\"].push_back(\"" + item + "\");\n";
    }
  }
}