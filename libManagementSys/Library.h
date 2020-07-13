/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Library.h
 * Author: pamulamba
 *
 * Created on 29 juin 2020, 22 h 21
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdexcept>
#include <exception>
#include <memory> // std::shared_ptr, std::make_unique<Type>
#include <regex> // std::regex, std::regex_match, std::regex_search, std::regex_replace
#include "Subscriber.h"
#include "Book.h"
#include "Borrow.h"

class Library {
public:
    const unsigned int MAX_SUB = {100}; // Maximum number of Subscribers
    const unsigned int MAX_BOOK = {1000}; // Maximum number of Books
    const unsigned int MAX_BORROW = {200}; // Maximum number of Borrows

    Library(); // Ctor
    Library(const Library& orig);
    Library(Library&& orig) noexcept;
    Library& operator=(const Library &orig);
    Library& operator=(Library&& orig)noexcept;
    virtual ~Library(); // Dtor

    class BadLibrary : public std::exception {
  public:
    const std::string exceptionMsg = {"BadLibraryError: Unable to process item in the library\n"};
  };

    // Processing subscribers in the library
    void addSubscriber(Subscriber& subscriber);
    void removeSubscriber(const std::string& id);
    void sortSubscriber(unsigned int option);
    void swapSubscriber(Subscriber &sub1, Subscriber &sub2);

    // Processing books in the library
    void addBook(std::unique_ptr<Book>& book);
    void removeBook(const std::string& quote);
    void sortBook(unsigned int option);
    void swapBook(Book &book1, Book &book2);
    
    

    // Searching, borrowing, returning, displaying methods
    void searchTitle(const std::string &str);
    void searchQuote(const std::string &book_quote);
    bool borrowBookBySubscriber(const std::string &subscriber_id, const std::string &book_quote, const std::string& returnDate);
    bool returnBook(const std::string &subscriber_id, const std::string &book_quote);
    void infoSubscriber(const std::string &subscriber_id) const;
    void swapBorrow(Borrow &borrow1, Borrow &borrow2);
    void print()const;

private:
    Subscriber** subs_;
    unsigned short nSubs_;
    
    Book** books_;
    unsigned short nBooks_;
    
    Borrow** borrows_;
    unsigned short nBorrows_;
    
    /**
     * Adding and instance of Borrow to the list of Borrowers
     * @param borrow
     */
    void addBorrow(Borrow& borrow);
    
    /**
     * Removing an instance of Borrow to the list of Borrowers
     * @param borrow
     */
    void removeBorrow(Borrow* borrow);
    
    

};

#endif /* LIBRARY_H */
