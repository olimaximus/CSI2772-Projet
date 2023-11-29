#include "Chain.h"
#include <iomanip>

/**
 * @brief retourne le nombre de cartes dans une chaine
 *
 * @return int
 */
int Chain_Base::getSize() { return chain.size(); }

/**
 * @brief Fixer le type de chaine
 *
 * @param chainType
 */
void Chain_Base::setChainType(string chainType) { chainType = chainType; }

/**
 * @brief Obtenir le type de chaine
 *
 * @return string
 */
string Chain_Base::getChainType() { return chainType; }

/**
 * @brief Écrire une chaine dans un fichier
 *
 * @tparam T
 * @param filename
 */
void Chain_Base::saveChain(ofstream &filename) {
  filename << endl << chainType << endl;
  for (int i = 0; i < chain.size(); i++) {
    chain.at(i)->saveCard(filename);
    filename << endl;
  }

  cout << "Saved Chain successfully" << endl;
}

/**
 * @brief Opérateur d'insertion pour afficher une chaine
 *
 * @param output
 * @param c
 * @return ostream&
 */
ostream &operator<<(ostream &output, const Chain<Card *> &c) {
  output << c.chainType << " ";
  for (int i = 0; i < c.chain.size(); i++) {
    c.chain.at(i)->print(output);
    output << " ";
  }

  return output;
};

/**
 * @brief Opérateur d'insertion pour afficher une chaine_base
 *
 * @param output
 * @param c
 * @return ostream&
 */
ostream &operator<<(ostream &output, const Chain_Base &c) {
  output << c.chainType << " " << setw(4);
  for (int i = 0; i < c.chain.size(); i++) {
    c.chain.at(i)->print(output);
    output << " ";
  }

  return output;
}