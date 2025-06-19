#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

const int maxcharArrSize = 101;
const int maxIntArrSize = 12;
const int digitSize = 9;

void convertChar2Int(char input[], int output[]) 
{
    int len = strlen(input);
    int count = maxIntArrSize - 1;
    int startIndex = len - digitSize - 1;

    for (int i = startIndex; i >= 0; i-=digitSize) {
        sscanf(input + i, "%9d", &output[count]);
        count -= 1;
    }

    int remainder = len % digitSize - 1;
    if (remainder > 0) {
        char format[4];
        sprintf(format, "%%%dd", remainder);
        sscanf(input, format, &output[count]);
    }
}

void SumUp(int sum[], int addend[])
{
    int carry = 0;
    int maxResult = pow(10, digitSize);
    for (int i = maxIntArrSize - 1; i >= 0; i--) {
        sum[i] += addend[i] + carry;
        if ((sum[i]) >= maxResult) {
            sum[i] = sum[i] % maxResult;
            carry = 1;
        }
        else {
            carry = 0;
        }
    }
}

void printResult(int result[])
{
    bool isPadding = false;
    for (int i = 0; i < maxIntArrSize; i++) {
        if (result[i] == 0 && !isPadding) {
            continue;
        }
        else {
            isPadding ? printf("%09lld", result[i]) : printf("%d", result[i]);
            isPadding = true;
        }
    }
}

void sumUpBigNumber (char line[], int sum[], int addend[]) {
    while(fgets(line, maxcharArrSize, stdin)) {
        if (strcmp(line, "0\0") == 0) {
            break;
        }

        memset(addend, 0, sizeof(maxIntArrSize));
        convertChar2Int(line, addend);
        SumUp(sum, addend);
    }
    printResult(sum);
}

int main()
{
    char line[maxcharArrSize];
    int sum[maxIntArrSize] = {0};
    int addend[maxIntArrSize] = {0};

    sumUpBigNumber(line, sum, addend);

    return 0;
}