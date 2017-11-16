#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "parser/bson-parser.hh"

namespace
{

  void help()
  {
    std::cout << "Usage: ./src/tauril-bson-parser file.bson\n";
  }

}

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    help();
    return 1;
  }

  try
  {
    // Load file and store content inside the buffer.
    std::ifstream file(argv[1]);
    if (!file.is_open())
      throw std::invalid_argument("Could not open input file.");

    std::vector<char> buffer;

    while (file.good())
      buffer.push_back(file.get());

    file.close();

    // Init the parser.
    Ast::Node<Ast::Document> doc;
    Parser::BsonParser parser(buffer, doc);

    doc->Dump();
  } catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 2;
  }

  return 0;
}
