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
    Subscription(enSubscriptionPeriod Period, enSubscriptionType Type,
                 enStatus Status, float Price, stDate StartDate);
    Subscription(const Subscription& other)
        : Period(other.Period), Type(other.Type), Status(other.Status),
        Price(other.Price), StartDate(other.StartDate) {}
    void setPeriod(enSubscriptionPeriod SubscriptionPeriod);
    void setType(enSubscriptionType SubscriptionType);
    void setStatus(enStatus Status);
    void setPrice(float Price);
    void setStartDate(stDate StartDate);

    enSubscriptionPeriod getPeriod();
    enSubscriptionType  getType();
    enStatus getStatus();
    float getPrice();
    stDate getStartDate();

    void Renew(enSubscriptionPeriod period, bool IsVIP);
    void Cancel();
    void Reactivate();
};


#endif // SUBSCRIPTION_H
