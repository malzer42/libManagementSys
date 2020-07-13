/**
 * File: main.cpp
 * Author(s): Pierre Abraham Mulamba
 * Created (modified): 20200629, 21:28 (20200711), 22:52
 * Description: Definition of the class Subscriber
 * Usage: To be included as header file in the Subscriber.cpp
 */


#include <iostream>
#include <chrono>
#include <memory>

#include "Subscriber.h"
#include "Book.h"
#include "Borrow.h"
#include "Library.h"
#include "Title.h"

/*
 * Supreme Commander
 */
int main(int argc, char** argvs) {
    try{
        const std::string version = "20180625 LTS";
        const std::string program = argvs[0];
        std::string program1(program, 89, program.size());
        Title title(program1, version);
        
        std::cout << "\n\t\tLIBRARY MANAGEMENT INVENTORY SYSTEM.\n"
                << "\t\t-----INTEGRATION TEST PROGRAM.-------\n";
        
        clock_t begin = clock();
        
        // Creation of instances of Subscriber        
        Subscriber sub1("1839456", "John", "Doe", 23, "12345");
        Subscriber sub2("1630236", "Nicolas", "Gagnon", 8, "67891");
        Subscriber sub3("1268348", "Martin", "Tremblay", 18, "10112");
        
        std::cout << "\n\t\tPRINTING SUBSCRIBER INSTANCES\n";
        sub1.print();
        sub2.print();
        sub3.print();
        
        // Creation of Books instances
        std::unique_ptr<Book> book7 = std::make_unique<Book>("HB514", "Big D++", 2010, 9, 4); // ("GA403", "Big C++", 2009, 8, 3);
        std::unique_ptr<Book> book1 = std::make_unique<Book>("GA403", "Big C++", 2009, 8, 3); // ("GA403", "Big C++", 2009, 8, 3)
        std::unique_ptr<Book> book2 = std::make_unique<Book>("QA203", "Multiple variables Calculus part 1", 2011, 3, 2);
        std::unique_ptr<Book> book3 = std::make_unique<Book>("QA204", "Multiple variables Calculus part 2", 2011, 3, 2);
        std::unique_ptr<Book> book4 = std::make_unique<Book>("AC409", "Le chateau d'Ortrante", 1764, 16, 4);
        std::unique_ptr<Book> book5 = std::make_unique<Book>("BD302", "Harry Potter and the Azkaban prisoner", 1999, 3, 5);
        std::unique_ptr<Book> book6 = std::make_unique<Book> ("CE413", "Ibssz Qpuufs et le prisionier c'balbcbo", 2000, 4, 7);

        std::cout << "\n\t\tPRINTING BOOK INSTANCES\n";
       
        
        book1-> print();
        book2->print();
        book3->print();
        book4->print();
        book5->print();
        book6->print();
        book7->print();
        
        // Creation of Borrow instances
        Borrow borrow11(&sub1, &*book1, "202011");
        Borrow borrow12(&sub1, &*book2, "202012");
        Borrow borrow13(&sub1, &*book3, "202013");
        Borrow borrow14(&sub1, &*book4, "202014");
        Borrow borrow15(&sub1, &*book5, "202015");
        Borrow borrow16(&sub1, &*book6, "202016");
        Borrow borrow17(&sub1, &*book7, "202017");
        
        Borrow borrow21(&sub2, &*book1, "202021");
        Borrow borrow22(&sub2, &*book2, "202022");
        Borrow borrow23(&sub2, &*book3, "202023");
        Borrow borrow24(&sub2, &*book4, "202024");
        Borrow borrow25(&sub2, &*book5, "202025");
        Borrow borrow26(&sub2, &*book6, "202026");
        Borrow borrow27(&sub2, &*book7, "202027");
        
        Borrow borrow31(&sub3, &*book1, "202031");
        Borrow borrow32(&sub3, &*book2, "202032");
        Borrow borrow33(&sub3, &*book3, "202033");
        Borrow borrow34(&sub3, &*book4, "202034");
        Borrow borrow35(&sub3, &*book5, "202035");
        Borrow borrow36(&sub3, &*book6, "202036");
        Borrow borrow37(&sub3, &*book7, "202037");
        
        std::cout << "\n\t\tPRINTING THE BORROWING\n";
        borrow11.print();
        borrow12.print();
        borrow13.print();
        borrow14.print();
        borrow15.print();
        borrow16.print();
        borrow17.print();
        
        borrow21.print();
        borrow22.print();
        borrow23.print();
        borrow24.print();
        borrow25.print();
        borrow26.print();
        borrow27.print();
        
        borrow31.print();
        borrow32.print();
        borrow33.print();
        borrow34.print();
        borrow35.print();
        borrow36.print();
        borrow37.print();
        
        // Creation of a Library instance
        Library library;
        library.addSubscriber(sub1);
        library.addSubscriber(sub2);
        library.addSubscriber(sub3);
        
        library.addBook(book1);
        library.addBook(book2);
        library.addBook(book3);
        library.addBook(book4);
        library.addBook(book5);
        library.addBook(book6);
        library.addBook(book7);
        
        
        
//        library.addBorrow(borrow11);
//        library.addBorrow(borrow22);
//        library.addBorrow(borrow33);
//        library.addBorrow(borrow17);
        
        
        std::cout << "\n\t\tPRINTING THE CONTENT OF THE LIBRARY";
        library.print();
        
        std::cout << "\n/*******************************************************************/\n";
        std::cout << "/*                      BEGINNING OF TESTS                         */\n";
        std::cout << "/* Remaining modification are at the bottom of main function    .  */\n";
        std::cout << "/*******************************************************************/\n";

        
        std::cout << "\n\t\tSEARCHING BOOKS BY TITLE\n";
        std::cout << "Search for a title containing: Calcul\n";
        library.searchTitle("Calcul");
        
        std::cout << "\nSearch for a title containing: Small\n";
        library.searchTitle("Small");
        
        std::cout << "\nSearch for a title containing: Big\n";
        library.searchTitle("Big");       
        
        
        std::cout << "\n\t\tSEARCHING BOOKS BY QUOTE\n";
        // Search by quote
        std::cout << "\nSearch for a quote containing: AC409\n";
        library.searchQuote("AC409");
        std::cout << "\nSearch for a quote containing: BD302\n";
        library.searchQuote("BD302");
        std::cout << "\nSearch for a quote containing: QA204\n";
        library.searchQuote("QA204");
        std::cout << "\nSearch for a quote containing: QA203\n";
        library.searchQuote("QA203");
        std::cout << "\nSearch for a quote containing: AC209\n";
        library.searchQuote("AC209");
        
        std::cout <<"\n\t\tTESTING THE BORROWING\n\n";
        std::cout << "// Should fail because Nicolas is too young! AC409 <--> 1630236\n";
        if (library.borrowBookBySubscriber("1630236", "AC409", "160204")) 
        {
            std::cout << "AC409 borrowed by 1630236\n";
        }   
        else{
            std::cout << "!!!BORROWING OF AC409 by 1630236 failed because the Subscriber is too young!!!\n";
        }
        
        std::cout << "// Should work. BD302 borrowed by 1630236\n";
        if (library.borrowBookBySubscriber("1630236", "BD302", "160204"))
        {
            std::cout << "BD302 borrowed by 1630236\n";
        }   
        else{
            std::cout << "!!!BORROWING BD302 by 1630236 failed!!!\n";
        }
        
        // Should not work because the book is not available anymore
        if (library.borrowBookBySubscriber("1839456", "BD302", "160204"))
        {
            std::cout << "BD302 borrowed by 1839456\n";
        }
        else{
            std::cout << "!!!BORROWING BD302 by 1839456 failed because the book is not Available!!!\n";
        }

        // Should not work because the subscriber has the book
        if (library.borrowBookBySubscriber("1630236", "BD302", "160204"))
        {
            std::cout << "BD302 borrowed by 1630236\n";
        }
        else{
            std::cout << "!!!BORROWING BD302 by 1630236 failed because the Subscriber has the book!!!\n";
        }

        // Should work
        if (library.borrowBookBySubscriber("1630236", "QA204", "160204"))
        {
            std::cout << "QA204 borrowed by 1630236\n";
        } 
        else{
            std::cout << "!!!BORROWING QA204 by 1630236 failed!!!\n";
        }

        // Should not work because the subscriber has reached the limit of books to borrow
        if (library.borrowBookBySubscriber("1630236", "QA203", "160204"))
        {
            std::cout << "QA203 borrowed by 1630236\n";
        }
        else {
            std::cout << "!!!BORROWING QA203 by 1630236 failed because the limit is exceeded!!!\n";
        }

        // Info of a subscriber before returning a book
        std::cout << "\n\t\tINFO OF A SUBSCRIBER BEFORE RETURNING A BOOK.\n";
        library.infoSubscriber("1630236");

        std::cout << "\n\t\tTESTS ON BOOKS RETURN.\n";

        // should work
        if (library.returnBook("1630236", "QA204")) 
        {
            std::cout << "QA204 return by 1630236\n";
        } 
        else{
            std::cout << "!!!Returning of BD302 by 1630236 Failed!!!\n";
        }

        // Should not work because the subscriber never borrowed a book
        if (library.returnBook("1839456", "QA203")) 
        {
            std::cout << "QA203 return by 1839456\n";
        } 
        else{
            std::cout << "!!!Returning failed!!!\n";
        }

        // Info of a Subscriber after returning a book
        std::cout << "\n\t\tINFO OF A SUBSCRIBER AFTER RETURNING A BOOK.\n";
        library.infoSubscriber("1630236");

        
        library.print();
        
        
        std::cout << "\n/*******************************/\n";
        std::cout << "/*       END OF TESTS          */\n";
        std::cout << "/*******************************/";
        
        // Free dynamically allocated memory (the heap) if necessary
        std::cout << "\n\t\tEND OF TESTS\n";
        std::cout << "\t\tPROGRAM ENDED SUCCESSFULLY!\n\n";
        
        clock_t end = clock();
        clock_t elapsed_seconds = (end - begin) / CLOCKS_PER_SEC;
        std::cout << "\t\telapsed: " << elapsed_seconds << '\n';
        std::cout << "\t\tSmart pointers used. No memory to free\n";
        return 0;
    }
    catch(Subscriber::BadSubscriber& e){
        std::cerr << e.badSubscriberException << '\n';
    }
    catch(...){
        std::cerr << "Unknown Exception thrown\n";
    }
}

