#include "Student.hpp"

#include <iostream>
#include <utility>

Student creeazaStudent() {
    const int note[] = {7, 9, 10};
    Student temporar("Mihai", note, 3);
    return temporar;
}

int main() {
    const int noteAna[] = {9, 10, 8};
    Student ana("Ana", noteAna, 3);
    std::cout << "Media Anei: " << ana.calculeazaMedia() << "\n\n";

    std::cout << "--- Copy constructor: resurse independente ---\n";
    Student copieAna = ana;
    std::cout << "Media copiei: " << copieAna.calculeazaMedia() << '\n';
    std::cout << "Numarul de note al obiectului original: "
              << ana.getNumarNote() << "\n\n";

    std::cout << "--- Move constructor: transferul resursei ---\n";
    Student temporar = creeazaStudent();
    Student mihai(std::move(temporar));
    std::cout << "Media obiectului mutat: " << mihai.calculeazaMedia() << '\n';
    return 0;
}
