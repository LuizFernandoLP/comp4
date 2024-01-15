// EDistance.cpp
// Copyright [2022] <Luiz Fernando>
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps5>
 *Instructor's name: <Dr. James Daly>
 *Date: <4/5/2022>
 *Sources Of Help: <professor, peers in discord, a bunch of youtube videos and documentations>
************************************************************/
#include "EDistance.h"

EDistance::EDistance(std::string sequence1,
                     std::string sequence2, int gapPenalty) {
    sequence_1 = sequence1;
    sequence_2 = sequence2;
    n = sequence_1.size();
    m = sequence_2.size();
    Pgap = gapPenalty;
    m_2dMatrix.resize(n+1, std::vector<int>(m+1, 0));
}

int EDistance::penalty(char a, char b) {
    if (a == b)
        return 0;
    else
        return 1;
}

int EDistance::printPenalty(std::string a, std::string b) {
    if (a == b && a != "-")
        return 0;
    else if (a != b && a != "-" && b != "-")
        return 1;
    else
        return 2;
}

int EDistance::min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    else if (b <=a && b <= c)
        return b;
    else
        return c;
}

int EDistance::optDistance() {
    for (size_t i = 0; i <= m; ++i)
        m_2dMatrix[0][i] = Pgap * i;
    for (size_t i = 0; i <= n; ++i)
        m_2dMatrix[i][0] = Pgap * i;

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            m_2dMatrix[i][j] = min(m_2dMatrix[i-1][j-1] +
                                   penalty((sequence_1[i-1]-'A'),
                                   sequence_2[j-1]-'A'),
                                   m_2dMatrix[i-1][j] + Pgap,
                                   m_2dMatrix[i][j-1] + Pgap);
        }
    }

    return m_2dMatrix[n][m];
}

std::string EDistance::alignment() {
    seq1Final = "";
    seq2Final = "";
    size_t j = m;
    size_t i = n;
    for (; i >= 1 && j >= 1; --i) {
        if (m_2dMatrix[i][j] == m_2dMatrix[i-1][j-1] +
            penalty((sequence_1[i-1]-'A'), sequence_2[j-1]-'A')) {
                seq1Final = sequence_1[i-1] + seq1Final;
                seq2Final = sequence_2[j-1] + seq2Final;
                --j;
        } else if (m_2dMatrix[i][j] == m_2dMatrix[i-1][j] + Pgap) {
            seq1Final = sequence_1[i-1] + seq1Final;
            seq2Final = '-' + seq2Final;
        } else {
            seq1Final = '-' + seq1Final;
            seq2Final = sequence_2[j-1] + seq2Final;
            --j;
        }
    }
    while (i >= 1 && j < 1) {
        seq1Final = sequence_1[i-1] + seq1Final;
        seq2Final = '-' + seq2Final;
        --i;
    }
    while (j >= 1 && i < 1) {
        seq1Final = '-' + seq1Final;
        seq2Final = sequence_2[j-1] + seq2Final;
        --j;
    }

    std::string finalString = "";
    for (i = 0; i < seq1Final.size(); i++) {
        std::string _a(1, seq1Final[i]);
        std::string _b(1, seq2Final[i]);
        finalString = finalString + seq1Final[i] + " " +
                      seq2Final[i] + " " +
                      std::to_string(printPenalty(_a, _b)) + "\n";
    }

    return finalString;
}
