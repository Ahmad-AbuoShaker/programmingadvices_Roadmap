#pragma once

namespace MathLib {

	int MyABS(int Num) {
		return(Num >= 0) ? Num : -Num;
	}

    float GetFractionPart(float Num) {
        return Num - (int)Num;
    }

    int MyRound(float Num) {
        int IntPart = (int)Num;
        return  (abs(GetFractionPart(Num)) < 0.5) ? IntPart ://OR
            ((Num > 0) ?
                ++IntPart : --IntPart);
    }

    int MyFloor(float Num) {
        int IntPart = (int)Num;
        return ((Num >= 0) ? IntPart : --IntPart);
    }

    int MyCeil(float Num) {
        int IntPart = (int)Num;
        if (GetFractionPart(Num) == 0.0) {
            return IntPart;
        }
        else {
            return ((Num > 0) ? ++IntPart : IntPart);
        }
    }

    void swap(int& Num1, int& Num2) {
        int Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

}