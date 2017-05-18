#include <tree.h>
#include <catch.hpp>
#include <fstream>

SCENARIO ("init", "[init]")

{

  Tree<int> test;

  REQUIRE(test.root_() == nullptr);

  REQUIRE(test.get_count() == 0);

}

SCENARIO("insert", "[init]")

{

  Tree<int> test;

  test.insnode(5);

  REQUIRE(test.get_count() == 1);

  REQUIRE(test.find_node(5, test.root_())->key == 5);

}

SCENARIO("find_node", "[init]")

{

  Tree<int> test;

  test.insnode(4);

  REQUIRE(test.find_node(4, test.root_()) != nullptr);

  REQUIRE(test.find_node(4, test.root_())->key == 4);

}

SCENARIO("get root", "[init]")

{

  Tree<int> test;

  test.insnode(4);

  REQUIRE(test.root_() != 0);

}

SCENARIO("insert equal elements", "[insert]")

 {

   Tree<int> test;

   test.insnode(4);

   test.insnode(4);

   REQUIRE(test.get_count() == 1);

 }

SCENARIO ("read/write", "[init]")

{

  Tree<int> test1;
 test1.read("file1.txt");
      bool isCatched = false;
  try
    {
  
  test1.write("file1.txt");

    }// test1.write("~,  , *"); //
    
    catch(bool isCatched)
    {
      isCatched = true;
    }
   
  REQUIRE(isCatched == false); 

  Tree<int> test2;

  test2.read("file2.txt");

  REQUIRE(test2.find_node(4, test2.root_())!= nullptr);

  REQUIRE(test2.find_node(3, test2.root_())!= nullptr);

  REQUIRE(test1.get_count() == test2.get_count());

}

SCENARIO("deleteX")

{

  Tree<int> test;

  test.insnode(6);

  test.insnode(7);

  test.insnode(9);

  test.deleteVal(6);

  test.deleteVal(9);

  REQUIRE(test.find_node(9, test.root_())== nullptr);

  REQUIRE(test.find_node(7, test.root_())== test.root_());

  REQUIRE(test.root_() != nullptr);

  REQUIRE(test.get_count() == 1);

}
