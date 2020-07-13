/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Borrow.h
 * Author: Pierre Abraham Mulamba
 *
 * Created on 29 June 2020, 22 h 20
 */

#ifndef BORROW_H
#define BORROW_H
#include <string>
#include "Subscriber.h"
#include "Book.h"

class Borrow {
public:
    // Constructors
    Borrow(Subscriber* sub = nullptr, Book* book = nullptr, const std::string& returnDate = "");
    
    // Copy and Move constructor
    Borrow(const Borrow& orig); // Copy constructor
    Borrow(Borrow&& orig)noexcept; // Move constructor
    
    // Copy and Move assignment operators
    Borrow& operator=(const Borrow& orig); // Copy assignment
    Borrow& operator=(Borrow&& orig)noexcept; // Move assignment
    
    virtual ~Borrow() = default; // Destructor
    
    // Getter methods
    Subscriber* getSubscriber()const;
    Book* getBook()const;
    const std::string& getReturnDate()const;
    
    // Setter methods
    void setSubscriber(Subscriber* subscriber);
    void setBook(Book* book);
    void setReturnDate(const std::string& returnDate);
    
    
    // Printing method
    void print()const;
    
private:
    Subscriber* subscriber_;
    Book* book_;
    std::string returnDate_;    
};
    
#endif /* BORROW_H */

