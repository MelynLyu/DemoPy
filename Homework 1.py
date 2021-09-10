class Calculator:
    def __init__(self, depositAmount:float, fee:float, interestRate:float, years:int) -> None:
        self.depositAmount = depositAmount
        self.fee = fee / 100
        self.interestRate = interestRate / 100
        self.years = years
        self.withdrawFeePerYear = 74
    
    def GetPresentValue(self) -> float:
        return self.depositAmount

    def GetWithdrawlFee(self) -> int:
        return self.withdrawFeePerYear * self.years
    
    def GetFutureValueBeforeWithdraw(self) -> float:
        return self.depositAmount * pow(1+ self.interestRate, self.years) - self.depositAmount * self.fee
    
    def GetFutureValueAfterWithdraw(self) -> float:
        return self.GetFutureValueBeforeWithdraw() - self.GetWithdrawlFee()
    
    def GetGrowthAmount(self) -> float:
        return self.GetFutureValueAfterWithdraw() - self.depositAmount
    
    def GetGrowthPercentage(self) -> float:
        return self.GetGrowthAmount() / self.depositAmount

if __name__ == "__main__":
    depositAmount = float(input("Please input your one-time deposit amount in $: "))
    fee = float(input("Please input the one-time investment fee percentage in (%): "))
    interestRate = float(input("Please input the compounded interest rate in (%): "))
    years = int(input("Please input years you wanna hold: "))

    calculator = Calculator(depositAmount, fee, interestRate, years)

    print("-----Here are the results-----")
    print("The investment's present value is {:.2f} $".format(calculator.GetPresentValue()))
    print("The investment's future value before the withdrawal fee applied is {:.2f} $".format(calculator.GetFutureValueBeforeWithdraw()))
    print("The investment's withdrawal fee is {:.2f} $".format(calculator.GetWithdrawlFee()))
    print("The investment's future value after the withdrawal fee applied is {:.2f} $".format(calculator.GetFutureValueAfterWithdraw()))
    print("The growth amount between the one-time deposit and withdrawal is {:.2f} $".format(calculator.GetGrowthAmount()))
    print("The growth percentage between the one-time deposit and withdrawal is {0:.1%}".format(calculator.GetGrowthPercentage()))
