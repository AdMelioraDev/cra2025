//#ifdef _DEBUG
#if 0

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Engine.h"
#include "Car.h"
#include "BreakSystem.h"
#include "Steering.h"

#define CLEAR_SCREEN "\033[H\033[2J"

int stack[10];

void selectCarType(int answer);
void selectEngine(int answer);
void selectbrakeSystem(int answer);
void selectSteeringSystem(int answer);
void runProducedCar();
void testProducedCar();
void delay(int ms);
bool checkInvalidAnswer(int step, int answer);
bool IsUserSelectedGoBack(int answer);
int goBackPrevousStep(int step);

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    brakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

void delay(int ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}

int main()
{
    char buf[100];
    int step = CarType_Q;

    CarFactory carFactory{};
    EngineFactory engineFactory{};
    BreakSystemFactory breakFactory{};
    SteeringFactory steeringFactory{};
    ICar* mycar = nullptr;

    while (1)
    {

        if (step == CarType_Q)
        {
            printf(CLEAR_SCREEN);

            printf("        ______________\n");
            printf("       /|            | \n");
            printf("  ____/_|_____________|____\n");
            printf(" |                      O  |\n");
            printf(" '-(@)----------------(@)--'\n");
            printf("===============================\n");
            printf("� ���� Ÿ���� �����ұ��?\n");
            printf("1. Sedan\n");
            printf("2. SUV\n");
            printf("3. Truck\n");
        }
        else if (step == Engine_Q)
        {
            printf(CLEAR_SCREEN);
            printf("� ������ ž���ұ��?\n");
            printf("0. �ڷΰ���\n");
            printf("1. GM\n");
            printf("2. TOYOTA\n");
            printf("3. WIA\n");
            printf("4. ���峭 ����\n");
        }
        else if (step == brakeSystem_Q)
        {
            printf(CLEAR_SCREEN);
            printf("� ������ġ�� �����ұ��?\n");
            printf("0. �ڷΰ���\n");
            printf("1. MANDO\n");
            printf("2. CONTINENTAL\n");
            printf("3. BOSCH\n");
        }
        else if (step == SteeringSystem_Q)
        {
            printf(CLEAR_SCREEN);
            printf("� ������ġ�� �����ұ��?\n");
            printf("0. �ڷΰ���\n");
            printf("1. BOSCH\n");
            printf("2. MOBIS\n");
        }
        else if (step == Run_Test)
        {
            printf(CLEAR_SCREEN);
            printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
            printf("� ������ �ұ��?\n");
            printf("0. ó�� ȭ������ ���ư���\n");
            printf("1. RUN\n");
            printf("2. Test\n");
        }
        printf("===============================\n");

        printf("INPUT > ");
        fgets(buf, sizeof(buf), stdin);

        // ���� ���๮�� ����
        char* context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (!strcmp(buf, "exit"))
        {
            printf("���̹���\n");
            break;
        }

        // ���ڷ� �� ������� Ȯ��
        char* checkNumber;
        int answer = strtol(buf, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ

        // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
        if (*checkNumber != '\0')
        {
            printf("ERROR :: ���ڸ� �Է� ����\n");
            delay(800);
            continue;
        }

        if (checkInvalidAnswer(step, answer))
        {
            delay(800);
            continue;
        }

        // ������ ���ư��⸦ �������� ���
        if (IsUserSelectedGoBack(answer))
        {
            step = goBackPrevousStep(step);
            delay(800);
            continue;
        }

        if (step == CarType_Q)
        {
            //selectCarType(answer);

            mycar = carFactory.getCar(static_cast<CarType>(answer));
            delay(800);
            step = Engine_Q;
        }
        else if (step == Engine_Q)
        {
            //selectEngine(answer);
            mycar->addEngine(engineFactory.getEngine(static_cast<Engine>(answer)));
            delay(800);
            step = brakeSystem_Q;
        }
        else if (step == brakeSystem_Q)
        {
            //selectbrakeSystem(answer);
            mycar->addBreakSystem(breakFactory.getBreakSystem(static_cast<brakeSystem>(answer)));
            delay(800);
            step = SteeringSystem_Q;
        }
        else if (step == SteeringSystem_Q)
        {
            //selectSteeringSystem(answer);
            mycar->addSteering(steeringFactory.getSteering(static_cast<SteeringSystem>(answer)));
            delay(800);
            step = Run_Test;
        }
        else if (step == Run_Test && answer == 1)
        {
            runProducedCar();
            delay(2000);
        }
        else if (step == Run_Test && answer == 2)
        {
            printf("Test...\n");
            delay(1500);
            testProducedCar();
            delay(2000);
        }
    }
}

bool IsUserSelectedGoBack(int answer)
{
    return (answer == 0);
}

int goBackPrevousStep(int step)
{
    return (step == CarType_Q || step == Run_Test) ? CarType_Q : (step - 1);
}

bool checkInvalidAnswer(int step, int answer)
{
    if (step == CarType_Q && !(answer >= 1 && answer <= 3))
    {
        printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
        return true;
    }

    if (step == Engine_Q && !(answer >= 0 && answer <= 4))
    {
        printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
        return true;
    }

    if (step == brakeSystem_Q && !(answer >= 0 && answer <= 3))
    {
        printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
        return true;
    }

    if (step == SteeringSystem_Q && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
        return true;
    }

    if (step == Run_Test && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
        return true;
    }

    return false;
}

void selectCarType(int answer)
{
    stack[CarType_Q] = answer;

    switch (answer)
    {
    case SEDAN:
        printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
        break;
    case SUV:
        printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
        break;
    case TRUCK:
        printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
        break;
    default:
        break;
    }

    return;
}

void selectEngine(int answer)
{
    stack[Engine_Q] = answer;

    switch (answer)
    {
    case GM:
        printf("GM ������ �����ϼ̽��ϴ�.\n");
        break;
    case TOYOTA:
        printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
        break;
    case WIA:
        printf("WIA ������ �����ϼ̽��ϴ�.\n");
        break;
    default:
        break;
    }

    return;
}

void selectbrakeSystem(int answer)
{
    stack[brakeSystem_Q] = answer;
    if (answer == MANDO)
        printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
    else if (answer == CONTINENTAL)
        printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
    else if (answer == BOSCH_B)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
}

void selectSteeringSystem(int answer)
{
    stack[SteeringSystem_Q] = answer;
    if (answer == BOSCH_S)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
    else if (answer == MOBIS)
        printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
}

int isValidCheck()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        return false;
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
    {
        return false;
    }
    else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        return false;
    }
    else
    {
        return true;
    }
    return true;
}

void runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
    }
    else
    {
        if (stack[Engine_Q] == 4)
        {
            printf("������ ���峪�ֽ��ϴ�.\n");
            printf("�ڵ����� �������� �ʽ��ϴ�.\n");
        }
        else
        {
            if (stack[CarType_Q] == SEDAN)
                printf("Car Type : Sedan\n");
            else if (stack[CarType_Q] == SUV)
                printf("Car Type : SUV\n");
            else if (stack[CarType_Q] == TRUCK)
                printf("Car Type : Truck\n");

            if (stack[Engine_Q] == GM)
                printf("Engine : GM\n");
            else if (stack[Engine_Q] == TOYOTA)
                printf("Engine : TOYOTA\n");
            else if (stack[Engine_Q] == WIA)
                printf("Engine : WIA\n");

            if (stack[brakeSystem_Q] == MANDO)
                printf("Brake System : Mando");
            else if (stack[brakeSystem_Q] == CONTINENTAL)
                printf("Brake System : Continental\n");
            else if (stack[brakeSystem_Q] == BOSCH_B)
                printf("Brake System : Bosch\n");

            if (stack[SteeringSystem_Q] == BOSCH_S)
                printf("SteeringSystem : Bosch\n");
            else if (stack[SteeringSystem_Q] == MOBIS)
                printf("SteeringSystem : Mobis\n");

            printf("�ڵ����� ���۵˴ϴ�.\n");
        }
    }
}

void testProducedCar()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
    }
    else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
    }
    else
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    }
}

#endif