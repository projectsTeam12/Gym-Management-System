#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H

#pragma once
#include "Model/Subscription/enSubscriptionPeriod.h"
#include "Model/Subscription/enSubscriptionType.h"
#include "Model/Subscription/enStatus.h"
#include "Model/Stuff/stDate.h"

class Subscription
{
private:
    enSubscriptionPeriod Period;
    enSubscriptionType Type;
    enStatus Status;
    float Price;
    stDate StartDate;
public:
    Subscription();

    // constructor for Load Data from File
    Subscription(enSubscriptionPeriod Period, enSubscriptionType Type,
                 enStatus Status, float Price, stDate StartDate);

    // constructor for Create new subscription for member

    Subscription(enSubscriptionPeriod Period, enSubscriptionType Type);

    // Setter
    void setPeriod(enSubscriptionPeriod SubscriptionPeriod);
    void setType(enSubscriptionType SubscriptionType);
    void setStatus(enStatus Status);
    void setPrice(float Price);
    void setStartDate(stDate StartDate);

    //Getter
    enSubscriptionPeriod getPeriod() const ;
    enSubscriptionType  getType() const;
    enStatus getStatus() const;
    float getPrice() const ;
    stDate getStartDate() const;

    void Renew(enSubscriptionPeriod period, enSubscriptionType Type);
    void Cancel();
    void Reactivate();
};


#endif // SUBSCRIPTION_H
