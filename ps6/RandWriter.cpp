// RandWriter.cpp
// Copyright [2022] <Luiz Fernando>
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <ps6>
 *Instructor's name: <Dr. James Daly>
 *Date: <4/11/2022>
 *Sources Of Help: <professor and classmates through discord>
************************************************************/
#include"RandWriter.h"

RandWriter::RandWriter(std::string text, int k) {
    m_text = text;
    m_text_circular = text + text[0]+text[1];
    m_order = k;
    substring();
}

int RandWriter::orderK() const {
    return m_order;
}

int RandWriter::freq(std::string kgram) const {
    if (static_cast<int>(kgram.length()) != m_order)
        throw std::runtime_error("kgram is not of length k - freq(string)");

    int occurrence = 0;
    std::string::size_type pos = 0;

    while ((pos = m_text.find(kgram, pos)) != std::string::npos) {
            ++occurrence;
            pos += kgram.length();
    }
    return occurrence;
}

int RandWriter::freq(std::string kgram, char c) const {
    if (static_cast<int>(kgram.length()) != m_order)
        throw std::runtime_error(
                   "kgram is not of length k -> freq(string, char)");

    if (m_order == 0) {
        int occurrence = 0;
        std::string::size_type pos = 0;
        std::string myString(1, c);

        while ((pos = m_text.find(myString, pos)) != std::string::npos) {
                ++occurrence;
                pos += myString.length();
        }
        return occurrence;
    }

    int occurrence = 0;
    for (size_t i = 0; i < m_text.length(); i++) {
        if (m_text_circular.substr(i, kgram.length()) == kgram) {
            if (m_text_circular[i+kgram.length()] == c)
                occurrence++;
        }
    }
    return occurrence;
}

void RandWriter::substring() {
    std::string temp;
    int iTemp;
    for (int len = m_order; len <= m_order; len++) {
        for (int i = 0; i <= static_cast<int>(
             m_text_circular.length()) - len; i++) {
            int j = i + len - 1;
            for (int k = i; k <= j; k++) {
                temp = temp + m_text_circular[k];
            }
            for (int i = 0; i < 127; i++) {
                iTemp = freq(temp, static_cast<char>(i));
                if (iTemp > 0)
                    myMap[temp][static_cast<char>(i)] = iTemp;
            }
            temp.clear();
        }
    }
}

char RandWriter::kRand(std::string kgram) {
    if (static_cast<int>(kgram.length()) != m_order)
        throw std::runtime_error(
                   "kgram is not of length k -> freq(string, char)");
    std::default_random_engine randomGenerator;
    randomGenerator.seed(
      std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> random(0, 100);
    double num = random(randomGenerator);

    int total = 0;
    double probCount = 0;
    size_t i = 0;
    std::vector<char> variables;
    std::vector<double> probabilities;

    auto it = myMap.find(kgram);
    if (it == myMap.end())
        throw std::runtime_error("no such k-gram");

    for (auto const &ent1 : myMap) {
        if (ent1.first == kgram) {
            for (auto const &ent2 : ent1.second) {
                variables.push_back(ent2.first);
                probabilities.push_back(ent2.second);
                total = total + ent2.second;
            }
        }
    }

    size_t totalSize = accumulate(probabilities.begin(), probabilities.end(), 0,
      [](size_t sum, const double& str){ return sum + 1; });

    if (variables.size() == totalSize) {
        for (i = 0; i < totalSize; i++) {
          probabilities[i] = probabilities[i]/static_cast<double>(total) * 100;
        }
    }

    if (variables.size() == totalSize) {
        for (i = 0; i < variables.size(); i++) {
            probCount = probCount + probabilities[i];
            if (num <= probCount)
                break;
        }
    }
    return variables[i];
}

std::string RandWriter::generate(std::string kgram, int L) {
    if (static_cast<int>(kgram.length()) != m_order)
        throw std::runtime_error(
                   "kgram is not of length k -> generate(string, int)");
    std::string buildString = kgram;
    std::string nextKgram = buildString.substr(
       buildString.length()-kgram.length(), kgram.length());

    while (buildString.length() < static_cast<size_t>(L)) {
        buildString = buildString + kRand(nextKgram);
        nextKgram = buildString.substr(
          buildString.length()-kgram.length(), kgram.length());
    }

    return buildString;
}

std::ostream& operator<<(std::ostream& os, const RandWriter& obj) {
    std::string alphabet;
    for (int i = 0; i < 128; i++) {
        if (obj.m_text.find(static_cast<char>(i)) != std::string::npos) {
            alphabet = alphabet + static_cast<char>(i);
        }
    }
    std::cout<< "alphabet: " << alphabet << std::endl;
    for (auto const &ent1 : obj.myMap) {
        std::cout << ent1.first << " ";
        for (auto const &ent2 : ent1.second) {
            std::cout << ent2.first << ent2.second << " ";
        }
        std::cout << std::endl;
    }

    return os;
}
