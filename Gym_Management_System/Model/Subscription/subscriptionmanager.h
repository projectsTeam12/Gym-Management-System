#ifndef SUBSCRIPTIONMANAGER_H
#define SUBSCRIPTIONMANAGER_H

#pragma once
#include <iostream>
#include "Model/Subscription/enSubscriptionPeriod.h"
#include "Model/Subscription/enSubscriptionType.h"
#include <unordered_map>
using namespace std;
class SubscriptionManager
{
private:
    static double EarlyRenewalDiscount;
    static unordered_map<enSubscriptionType, unordered_map<enSubscriptionPeriod, double>>Prices;
public:
    static void SetPrice(enSubscriptionType, enSubscriptionPeriod, double);
    static void SetEarlyRenewal(double EarlyRenewalDiscount);
    static double GetEarlyRenewalDiscount();
    static double GetPrice(enSubscriptionType, enSubscriptionPeriod);
};



#endif // SUBSCRIPTIONMANAGER_H
