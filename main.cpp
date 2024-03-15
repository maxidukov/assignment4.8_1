#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

void print_dirgraph(const std::vector<std::vector<bool>>& graph);

int main() {
  std::ifstream infile("input.txt");
  if(!infile.is_open()){
      std::cout << "Error opening file!\n";
      return 1;
    }
  int size{};
  infile >> size;
  std::vector<std::vector<bool>> graph(size);
  int i{};
  std::string str;
  while(std::getline(infile,str)){
    if(str.empty()) continue;
    std::istringstream ss(str);
    bool v{};
    while(ss>>v){
       graph[i].push_back(v);
    }
    i++;
  }
  std::cout<<"Текстовый вид орграфа:\n";
  print_dirgraph(graph);
}

void print_dirgraph(const std::vector<std::vector<bool>>& graph){
  bool is_empty = true;
  for(int i{};i<graph.size();i++){
    std::cout<<i+1<<": ";
    for(int j{};j<graph.size();j++){
      if(graph[i][j]){
         std::cout<<j+1<<" ";
         is_empty = false;
}
    }
    if(is_empty) std::cout<<"нет";
    std::cout<<std::endl;
    is_empty = true;
  }
}
