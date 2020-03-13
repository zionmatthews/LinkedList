Zion Matthews
:-
s198031
Assesment 4
LinkedList

## 1. Design

  **File**: UnorderedList.h
  
    Name: search
    Description: returns true if the node is found
    Type: bool
    
    Name: insertFirst
    Description: adds a node to the beginning of the list
    Type: function
    
    Name: insertLast
    Description: adds a node to the end of the list
    Type: function
    
    Name: deleteNode
    Description: deletes a node
    Type: function
    
    Name: clear
    Description: clears everything
    Type: function
    
   **File**: Node.h
   
     Name: info
     Description:used as info for the node
     Type: variable
     
     Name: next/prevoius
     Description: the node that is next / last
     Type: variable
     
     Name: Node/~Node
     Description: default deconstructor
     Type: constructor func
     
   **File**: List.h
   
     Name: mCout
     Description: keeps track of the list
     Type: int
     
     Name: m_last/m_first
     Description: the first and last of list
     Type: variable
     
     Name: initalizeList
     Description: Sets everything in list
     Type: function
     
     Name: isListempty
     Description: checks to see if the list is empty
     Type: bool
     
     Name: length
     Description: Keeps track of the length of the list
     Type: int
     
     Name front/back
     Description: first and last spot of the list
     Type: variable
     
     Name: search
     Description: Searches for a node
     Type: function
     
     Name: insertFirst
     Description: adds a node to the beginning o fthe list
     Type: function
     
     Name: insertLast
     Description: adds a node to the nd of the list
     Type: function
     
     Name: deleteNode
     Description: deletes a node
     Type: function
     
     Name: begin
     description: starts at the beginning of the list
     Type: variable
     
     Name: end
     Description: starts at the end o fthe list
     Type: variable
     
     name: List/~List
     Description: defualt deconstructors
     type: deconstructor func
     
   **File**: Iterator.h
   
     Name: currentNode
     Description: Variable for node
     Type: variable
     
     name: operator++
     Description: turns to the next node in the list
     Type: function
     
     Name: operator--
     Description: turns to the last node in the list
     Type: function
     
     Name: operator*
     Description: gives data
     Type: variable
     
     Name: Iterator/~Iterator
     description: default deconstructor
     Type: deconstructor func
     
     Name:Iterator ptr
     Description: creates a pointer to the current node
     Type: function
     
     Name: operator==
     description: checks for a equal node
     tyep: bool func
     
     name: operator!=
     description: checks for a unequal node
     type: bool func

## License

MIT License - Copyright (c) 2018 Academy of Interactive Entertainment

For more information, see the [license][lic] file.

Third party works are attributed under [thirdparty.md][3p].

[lic]:license.md
[3p]:thirdparty.md
[raylib]:https://github.com/raysan5/raylib
