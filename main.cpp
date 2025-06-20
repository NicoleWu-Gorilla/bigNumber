#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

static const int maxcharArrSize = 101;
static const int maxIntArrSize = 12;
static const int digitSize = 9;
static const int maxResult = 1000000000;

void convertChar2Int(char input[], int output[]) 
{
    int len = strlen(input);
    int count = maxIntArrSize - 1;
    int startIndex = len - digitSize - 1;
    char format[4];
    int convertNum = digitSize;

    memset(output, 0, sizeof(int) * maxIntArrSize);
    for (int i = len; i > 0; i -= digitSize) {
        const int start = i - digitSize > 0 ? i - digitSize : 0;
        convertNum = i - start;
        sprintf(format, "%%%dd", convertNum);
        sscanf(input + start, format, &output[count]);
        count -= 1;
    }
}

void SumUp(int sum[], int addend[])
{
    int carry = 0;
    for (int i = maxIntArrSize - 1; i > 0; i--) {
        sum[i - 1] += ((sum[i] + addend[i]) / maxResult);
        sum[i] = (sum[i] + addend[i]) % maxResult;

    } 
}

void printResult(int result[])
{
    int loc = 0;
	while (result[loc] == 0 && loc < maxIntArrSize - 1) {
		++loc;
	}

    // print the first non-zero padding number
	printf("%d", result[loc++]);
	while (loc < maxIntArrSize){
		printf("%09lld", result[loc]);
		++loc;
	}
}

int main()
{
    char line[maxcharArrSize];
    int sum[maxIntArrSize] = {0};
    int addend[maxIntArrSize] = {0};

    memset(sum, 0, sizeof(sum));
    while(scanf("%s", line) == 1 && strcmp(line, "0") != 0) {
        convertChar2Int(line, addend);
        SumUp(sum, addend);
    }
    printResult(sum);

    return 0;
}