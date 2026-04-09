#include <iostream>
using namespace std;

class Numbers {
private:
    int se;  // مجموع الأعداد الزوجية
    int sd;  // مجموع الأعداد الفردية

public:
    // البان الافتراضي
    Numbers() : se(0), sd(0) {
        cout << "تم استدعاء البان الافتراضي" << endl;
    }

    // البان العادي مع مصفوفة وسيطة
    Numbers(int arr[]) {
        se = 0; // مجموع الزوجي
        sd = 0; // مجموع الفردي

        for (int i = 0; i < 10; i++) {
            if (arr[i] % 2 == 0) {
                se += arr[i];
            }
            else {
                sd += arr[i];
            }
        }
        cout << "تم استدعاء البان العادي" << endl;
    }

    // تابع الطباعة
    void print() {
        cout << "مجموع الأعداد الزوجية: " << se << endl;
        cout << "مجموع الأعداد الفردية: " << sd << endl;
    }

    // تابع المدمر
    ~Numbers() {
        cout << "تم استدعاء تابع المدمر للكائن" << endl;
    }
};

int main() {
    int x[20];

    // إدخال 20 عدد صحيح
    cout << "أدخل 20 عدد صحيح:" << endl;
    for (int i = 0; i < 20; i++) {
        cout << "العدد " << i + 1 << ": ";
        cin >> x[i];
    }

    // إنشاء كائن من الصف Numbers مع تمرير أول 10 أعداد
    Numbers ob1(x);

    // إنشاء كائن آخر مع تمرير الأعداد من 11 إلى 20
    Numbers ob2(x + 10);

    // طباعة النتائج
    cout << "\nالنتائج للأعداد من 1 إلى 10:" << endl;
    ob1.print();

    cout << "\nالنتائج للأعداد من 11 إلى 20:" << endl;
    ob2.print();

    return 0;
}