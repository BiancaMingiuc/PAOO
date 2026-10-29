#include "Student.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

Student::Student(std::string name, const int* note, std::size_t numarNote)
    : name(std::move(name)), note(new int[numarNote]), numarNote(numarNote) {
    std::copy(note, note + numarNote, this->note);
    std::cout << "[Constructor] Creat: " << this->name << '\n';
}

Student::~Student() {
    std::cout << "[Destructor] Eliberat: " << name << '\n';
    delete[] note;
}

Student::Student(const Student& other) 
    : name(other.name + " (copie)"), note(new int[other.numarNote]), numarNote(other.numarNote) {
    std::copy(other.note, other.note + numarNote, note);
    std::cout << "[Copy constructor] Copiere profunda: " << name << '\n';
}

Student::Student(Student&& other) noexcept 
    : name(std::move(other.name) + " (mutat)"),
      note(other.note),
      numarNote(other.numarNote) {
    other.note = nullptr; // Sursa cedează pointerul
    other.numarNote = 0;
    std::cout << "[Move constructor] Transfer fara copiere: " << name << '\n';
}

Student& Student::operator=(const Student& other) {
    if (this == &other) {
        return *this;
    }

    int* noteNoi = new int[other.numarNote];
    std::copy(other.note, other.note + other.numarNote, noteNoi);
    delete[] note;

    name = other.name;
    note = noteNoi;
    numarNote = other.numarNote;
    return *this;
}

Student& Student::operator=(Student&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    delete[] note;
    name = std::move(other.name);
    note = other.note;
    numarNote = other.numarNote;

    other.note = nullptr;
    other.numarNote = 0;
    return *this;
}

double Student::calculeazaMedia() const {
    if (numarNote == 0) {
        return 0.0;
    }

    int suma = 0;
    for (std::size_t index = 0; index < numarNote; ++index) {
        suma += note[index];
    }
    return static_cast<double>(suma) / numarNote;
}

const std::string& Student::getName() const {
    return name;
}

std::size_t Student::getNumarNote() const {
    return numarNote;
}
