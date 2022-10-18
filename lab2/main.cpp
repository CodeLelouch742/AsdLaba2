#include "Utils.h"

Snail* snails;
float temp;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    if(snailsInput() == 1)
    {
        return 0;
    }

    lookingSnailsConfusion();

    for (int i = 0; i < snailAmount; i++)
    {
        for (int j = 0; j < snailAmount; j++)
        {
            if (i != j)
            {
                temp = pathLenght(snails[i].x, snails[i].y, snails[j].x, snails[j].y);
                if(snails[i].confusion && snails[j].confusion)
                    temp = 141422;
                if(!snails[i].confusion && !snails[j].confusion){
                    temp = temp/2;
                }
                if (temp < shortestTime)
                    shortestTime = temp;
            }
        }
    }

    int snailsNumber = snailsConfusionOutput();
    shortestTimeOutput(snailsNumber);
    delete [] snails;
    system("pause");
    return 0;
}

void lookingSnailsConfusion(){
    int numberpath = 0;
    for (int i = 0; i < snailAmount; i++)
    {
        for (int j = 0; j < snailAmount; j++)
        {
            if(i != j)
            {
                temp = pathLenght(snails[i].x, snails[i].y, snails[j].x, snails[j].y);
                snails[i].paths[numberpath] = temp;
                numberpath++;
            }
        }
        snails[i].lookingConfusion();
        numberpath=0;
    }
}

int snailsConfusionOutput(){
    int snailsNumber = 0;
    for (int i = 0; i < snailAmount; i++)
    {
        if (snails[i].confusion)
        {
            cout << "Улитка " << i+1 << " в замешательстве\n";
            snailsNumber++;
        }
    }
    return snailsNumber;
}

void shortestTimeOutput(int snailsNumber){
    if (snailsNumber != snailAmount)
        cout << "Ближайшие улитки достигнут друг друга через " << shortestTime << " сек." << endl << endl;
}

int snailsInput(){
    int check;
    cout << "Введите колличество улиток: ";
    cin >> snailAmount;
    if (snailAmount == 1) {
        cout << "Улитка в замешательстве, так как она одна" << endl;
        system("pause");
        return 1;
    }
    snails = new Snail[snailAmount];
    cout << "Введите стартовую позицию для каждой улитки(X,Y), где X и Y должны быть в диапозоне от 0 до 100000" << endl;
    for (int i = 0; i < snailAmount; i++)
    {
        check = 1;
        while(check){
            cout <<"Улитка "<< i+1 << ": " << endl << "X: ";
            cin >> snails[i].x;
            cout << "Y: ";
            cin >> snails[i].y;
            cout << endl;
            if(((snails[i].x > 0) && (snails[i].x < 100000)) && ((snails[i].y > 0) && (snails[i].y < 100000)))
            {
                check=0;
            }
            else{
                cout << "Введены неверные координаты. Попробуйте снова.\n";
            }
        }
    }
    return 0;
}

float pathLenght(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}






