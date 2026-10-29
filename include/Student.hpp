#pragma once

#include <cstddef>
#include <string>

class Student {
private:
    std::string name;
    int* note;
    std::size_t numarNote;

public:
    Student(std::string name, const int* note, std::size_t numarNote);
    ~Student();

    Student(const Student& other);
    Student(Student&& other) noexcept;

    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;

    double calculeazaMedia() const;
    const std::string& getName() const;
    std::size_t getNumarNote() const;
};