#pragma once
#include "Person.h"
#include <iostream>

class SocialNetwork
{
public:
    SocialNetwork() {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                matrix[i][j] = 0;
        vertexCount = 0;
    }

    void addPerson(std::string PersonName) {
        Person per(PersonName, PersonsCount);
        vertexes[PersonsCount] = PersonsCount;
        PersonArray[PersonsCount] = per;
        PersonsCount++;
    }

    int findperIDbyName(std::string name) {
        for (int i = 0; i < SIZE; i++) {
            if (PersonArray[i].getName() == name) {
                return i;
            }
       }
        return 0;
    }

    void addFriendship(std::string Person1, std::string Person2) {
        matrix[findperIDbyName(Person1)][findperIDbyName(Person2)] = 1;
        matrix[findperIDbyName(Person2)][findperIDbyName(Person1)] = 1;
    }

    void delPerson(std::string Person) {

        for (int i = 0; i < SIZE; i++)
        {
            matrix[i][findperIDbyName(Person)] = 0;
            matrix[findperIDbyName(Person)][i] = 0;
        }
        // удаляем вершину из списка вершин
        int foundIndex = -1;
        for (int i = 0; i < vertexCount; i++)
        {
            if (vertexes[i] == findperIDbyName(Person))
                foundIndex = i;
        }
        vertexCount--;
        for (int i = foundIndex; i < vertexCount; i++)
        {
            vertexes[i] = vertexes[i + 1];
        }
        PersonsCount--;
    }

    void delEdge(int Person1ID, int Person2ID)
    {
        matrix[Person1ID][Person2ID] = 0;
        matrix[Person2ID][Person1ID] = 0;
    }
 
    void showThreeHandshakes() {
        for (int j = 0; j < PersonsCount; j++) {
            bool visited[SIZE]; // список посещенных вершин
            for (int i = 0; i < PersonsCount; i++) {
                visited[i] = false;
            }
            std::cout << std::endl << PersonArray[j].getName() << " friends: ";
            int iterration = 0;
            depthInner(j, visited, iterration);
        }
    }
    void depthInner(int current, bool visited[], int iterration) {
        visited[current] = true; // помечаем как посещенную
        iterration++;
        for (int i = 0; i < SIZE; i++)
        {
            if (iterration == 4) {
                std::cout << PersonArray[current].getName() << ", ";
               iterration = 0;
               break;
            }
            if (matrix[current][i] != 0 && visited[i] == false)
            {
               // iterration++;
                depthInner(i, visited, iterration); // если существует ребро и вершина не посещалась, то пройдем по нему в смежную вершину
            }
        }
        }

    /*Для проверки, существует ли вершина, нужно проверить, есть ли ее номер в массиве vertexes.*/
    bool vertexExists(int vnumber)
    {
        for (int i = 0; i < PersonsCount; i++)
            if (vertexes[i] == vnumber)
                return true;
        return false;
    }

    int PersonsCount = 0;
    Person PersonArray[SIZE];

private:
    int matrix[SIZE][SIZE]; // матрица смежности
    int vertexes[SIZE]; // хранилище вершин
    int vertexCount; // количество добавленных вершин
};
