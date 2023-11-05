
#include <iostream>
#include "decorator.h"

int main()
{
 //   auto text = new Text();
 //   auto text_block = new ItalicText(new BoldText(text));
//    text_block->render("Hello world");

 //   auto text_block = new Paragraph(new Text());
//    text_block->render("Hello world");

    auto text_block = new Reversed(new Text());
    text_block->render("Hello world");

 //  auto text_block = new Link(new BoldText(new Text()));
 //  text_block->render("netology.ru", "Hello world");

}
