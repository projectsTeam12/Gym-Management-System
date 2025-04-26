#ifndef SYSTEMANALYTICS_H
#define SYSTEMANALYTICS_H

#pragma once
class SystemAnalytics
{
private:
    static int NumberOfMembers;
    static float TotalRevenuesubscriptions;
    static float TotalRevenueBookClasses;
    static float TotalRevenueBookCourts;
    static float TotalRevenue;
public:
    SystemAnalytics(int NumberOfMembers, float TotalRevenuesubscriptions,
                    float TotalRevenueBookClasses, float TotalRevenueBookCourts, float TotalRevenue);

    void setNumberOfMembers(int NumberOfMembers);
    void setTotalRevenuesubscriptions(float TotalRevenuesubscriptions);
    void setTotalRevenueBookClasses(float TotalRevenueBookClasses);
    void setTotalRevenueBookCourts(float TotalRevenueBookCourts);
    void setTotalRevenue(float TotalRevenue);

    int getNumberOfMembers();
    float getTotalRevenuesubscriptions();
    float getTotalRevenueBookClasses();
    float getTotalRevenueBookCourts();
    float getTotalRevenue();
};
#endif // SYSTEMANALYTICS_H
