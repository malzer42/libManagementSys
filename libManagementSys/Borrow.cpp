/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Borrow.cpp
 * Author: Pierre Abraham Mulamba
 * 
 * Created on 29 June 2020, 22 h 20
 */

#include "Borrow.h"

/**
 * Constructor with parameters
 * @param subscriber
 * @param book
 * @param returnDate
 */
Borrow::Borrow(Subscriber* subscriber, Book* book, const std::string& returnDate) : subscriber_(subscriber), book_(book),
        returnDate_(returnDate){
    
}

// Getter methods

/**
 * Get the subscriber_ attribute
 * @return subscriber_ 
 */
Subscriber* Borrow::getSubscriber()const{
    return subscriber_;
}

/**
 * Get the book_ attribute
 * @return book_
 */
Book* Borrow::getBook() const{
    return book_;
}

/**
 * Get the returnDate_ attribute
 * @return returnDate_
 */
const std::string& Borrow::getReturnDate() const{
    return returnDate_;
}

// Setter methods

/**
 * Set subscriber_ attribute
 * @param subscriber
 */
void Borrow::setSubscriber(Subscriber* subscriber){
    subscriber_ = subscriber;
}

/**
 * Set book_ attribute
 * @param book
 */
void Borrow::setBook(Book* book){
    book_ = book;
}

/**
 * Set the returnDate_ attribute
 * @param returnDate
 */
void Borrow::setReturnDate(const std::string& returnDate){
    returnDate_ = returnDate;
}

// Copy and Move constructors
/**
 * Copy constructor
 * @param orig
 */
Borrow::Borrow(const Borrow& orig) : subscriber_(orig.getSubscriber()), book_(orig.getBook()), 
        returnDate_(orig.getReturnDate()){}

/**
 * Move constructor
 * @param orig
 */
Borrow::Borrow(Borrow&& orig)noexcept : subscriber_(nullptr), book_(nullptr), returnDate_(""){
    subscriber_ = orig.getSubscriber();
    book_ = orig.getBook();
    returnDate_ = orig.getReturnDate();
    
    orig.setSubscriber(nullptr);
    orig.setBook(nullptr);
    orig.setReturnDate("");
}

// Copy and Move assignments

/**
 * Copy assignment operator
 * @param orig
 * @return *this
 */
Borrow& Borrow::operator=(const Borrow& orig){
    if(this != &orig){
        subscriber_ = orig.getSubscriber();
        book_ = orig.getBook();
        returnDate_ = orig.getReturnDate();
    }
    return *this;
}

/**
 * Move assignment
 * @param orig
 * @return *this
 */
Borrow& Borrow::operator=(Borrow&& orig)noexcept{
     if(this != &orig){
         subscriber_ = nullptr;
         book_ = nullptr;
         returnDate_ = "";
         
         subscriber_ = orig.getSubscriber();
         book_ = orig.getBook();
         returnDate_ = orig.getReturnDate();
         
         orig.setSubscriber(nullptr);
         orig.setBook(nullptr);
         orig.setReturnDate("");
     }
     return *this;
}

/**
 * Printing method
 */
void Borrow::print()const{
    std::cout << " #" << getSubscriber()->getIdNumber() 
            << ". " << getBook()->getQuote() 
            << ". " << getReturnDate() << ".\n";
    
}

