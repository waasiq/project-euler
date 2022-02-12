#! Euler Problem 19
#! Author: Waasiq Masood
#! Date: 12 - Feb - 2022

days = ['Monday' , 'Tuesday' , 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']

class Month:
    monthFirstDay = ''
    lastDay = ''

    @staticmethod
    def returnRespDays(param, increment):
        for index, day in enumerate(days):
            if (param == 'Saturday' and increment == 2): return 'Monday'
            elif (param == 'Sunday' and increment == 2): return 'Tuesday'
            elif (param == 'Sunday' and increment == 1): return 'Monday'
            elif (param == 'Monday' and increment == -1): return 'Sunday'
            if (day == param): return days[index+increment]           

class Year:
    isLeap = False
    months = [Month() for i in range(12)]
    firstSundayNumber = 0
    yearFirstDay = ''
    yearLastDay = ''

    @classmethod
    def intializeMonths(self, yearFirstDay, yearNumber):   
        isLeap = False 
        if (yearNumber % 4 == 0 or yearNumber % 400 == 0): isLeap = True

        for i in range(0, 12):
            if (i == 0): 
                self.months[i].monthFirstDay = yearFirstDay
                self.months[i].lastDay = Month.returnRespDays(yearFirstDay, 2) 
            else:    
                self.months[i].monthFirstDay = Month.returnRespDays(self.months[i-1].lastDay, 1)
            
            if (self.months[i].monthFirstDay == 'Sunday'): self.firstSundayNumber += 1

            if (i == 2 or i == 4 or i == 6 or i == 7 or i == 9 or i == 11):
                self.months[i].lastDay = Month.returnRespDays(self.months[i].monthFirstDay,2)
            elif (i == 1):
                if (isLeap == False):
                    self.months[i].lastDay = Month.returnRespDays(self.months[i].monthFirstDay, -1)
                elif(isLeap):
                    self.months[i].lastDay = self.months[i].monthFirstDay
            elif (i == 3 or i == 5 or i == 8 or i == 10):
                self.months[i].lastDay = Month.returnRespDays(self.months[i].monthFirstDay, 1)
        
        self.yearLastDay = self.months[11].lastDay


def main():
    years = [Year() for i in range(101)]
    
    yearNumber = 1901
    firstSundays = 0
    
    for i in range(0, 100):
        if (i == 0):
            years[i].yearFirstDay = 'Tuesday'
            years[i].intializeMonths(years[0].yearFirstDay , yearNumber)
        else:
            years[i].yearFirstDay = Month.returnRespDays(years[i-1].yearLastDay,1)
            years[i].intializeMonths(years[i].yearFirstDay , yearNumber)
        
        firstSundays += years[i].firstSundayNumber
        yearNumber += 1
        
    print(Year.firstSundayNumber)
    
if __name__ == '__main__':
    main() 