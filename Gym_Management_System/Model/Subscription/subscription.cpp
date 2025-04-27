#include "subscription.h"

Subscription::Subscription() {
}

// constructor for Load Data from File

Subscription::Subscription(enSubscriptionPeriod Period, enSubscriptionType Type,
                           enStatus Status, float Price, stDate StartDate){

    this->Period=Period;
    this->Type=Type;
    this->Status =Status;
    this->Price =Price ;
    this->StartDate=StartDate;
}

// constructor for Create new subscription for member

Subscription::Subscription(enSubscriptionPeriod Period, enSubscriptionType Type){

    this->Period=Period;
    this->Type=Type;
    this->Status =enStatus::Active;
    this->Price =Price ;
    this->StartDate.SetToCurrentDate();
}

// Getter
enSubscriptionPeriod Subscription:: getPeriod() const {
    return this->Period;
}

enSubscriptionType Subscription::getType() const {
    return this->Type;
}

enStatus Subscription::getStatus() const {
    return this->Status;
}

float Subscription::getPrice() const {
    return this->Price;
}

stDate Subscription::getStartDate() const {

    return this->StartDate;
}

// Setter
void Subscription::setPeriod(enSubscriptionPeriod SubscriptionPeriod) {
    this->Period = SubscriptionPeriod;
}

void Subscription::setType(enSubscriptionType SubscriptionType) {
    this->Type = SubscriptionType;
}

void Subscription::setStatus(enStatus Status) {
    this->Status = Status;
}

void Subscription::setPrice(float Price) {

    this->Price = Price;
}

void Subscription::setStartDate(stDate StartDate) {

    this->StartDate = StartDate;
}

void Subscription::Renew(enSubscriptionPeriod period, enSubscriptionType Type) {

}

void Subscription::Cancel(){
    this->Status=enStatus::Cancel;
}

void Subscription::Reactivate(){
    this->Status=enStatus::Active;

}
