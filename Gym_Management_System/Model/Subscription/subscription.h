#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H

#pragma once
#include <iostream>
#include "Model/Subscription/enSubscriptionPeriod.h"
#include "Model/Subscription/enSubscriptionType.h"
#include "Model/Subscription/enStatus.h"
#include "Model/Stuff/Date.h"
using namespace std;
class Subscription
{
private:
    enSubscriptionPeriod Period;
    enSubscriptionType Type;
    enStatus Status;
    float Price;
    Date StartDate;
public:
    Subscription(enSubscriptionPeriod Period, enSubscriptionType Type,
                 enStatus Status, float Price, Date StartDate);
    void setPeriod(enSubscriptionPeriod SubscriptionPeriod);
    void setType(enSubscriptionType SubscriptionType);
    void setStatus(enStatus Status);
    void setPrice(float Price);
    void setStartDate(Date StartDate);

    enSubscriptionPeriod getPeriod();
    enSubscriptionType  getType();
    enStatus getStatus();
    float getPrice();
    Date getStartDate();

    void Renew(enSubscriptionPeriod period, bool IsVIP);
    void Cancel();
    void Reactivate();
};


#endif // SUBSCRIPTION_H
