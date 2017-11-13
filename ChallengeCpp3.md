# Challenge Cpp #3 - BSON parser

Your challenge will be to develop a BSON (Binary Json) parser in C++.

Bson is a binary version of JSON, frequenlty used in web apps. only partially reversed.


## Requirements

Your code will be fully developped in C++

Your main() function will load the contents of a "BSON" sample file to a ‘std::vector<char>‘ buffer.

Once loaded, this buffer will be given to the constructor of the "BSON" class in charge of parsing.

You are free to define an approriate class architecture for proper format parsing.

Your base class will provide appropriate accessors to the parsed values.

Your base class will provide a Dump() method printing in a "human readable" form loaded contents. Unknown fields will be dumped in hexadecimal format.


## Evaluation

You will be evaluated on the following criterions:

  - C++ code readability (using proper class names, method names)
  - Class architecture (defining pertinent sub-classes with appropriate methods)
  - Comments
  - Respect of those guidelines

## The BSON file format


[http://bsonspec.org/spec.html](http://bsonspec.org/spec.html)

