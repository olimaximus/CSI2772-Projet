#include "Chain.h"

//Retourne le nombre de cartes dans une chaine
int Chain_Base::getSize() { return chain.size(); }

/**
 * @brief Fixer le type de chaine
 *
 * @param chainType
 */
void Chain_Base::setChainType(string chainType) { chainType = chainType; }

//Retourne le type de chaine
string Chain_Base::getChainType() { return chainType; }

/**
 * @brief Écrire une chaine dans un fichier
 *
 * @tparam T
 * @param file
 */
void Chain_Base::saveChain(ofstream &file) {
  file << endl << chainType << endl;
  
  for (int i = 0; i < chain.size(); i++) {
    chain.at(i)->saveCard(file);
    file << endl;
  }

  cout << "Chaine sauvegardee" << endl;
}

/**
 * @brief Opérateur d'insertion pour afficher une chaine
 *
 * @param output
 * @param c
 * @return ostream&
 */
ostream &operator<<(ostream &output, const Chain<Card *> &c) {
  output << c.chainType << "\t";

  // Afficher chaque carte dans une chaîne
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
  output << c.chainType << "\t" << setw(4);

  // Afficher chaque carte dans une chaîne de base
  for (int i = 0; i < c.chain.size(); i++) {
    c.chain.at(i)->print(output);
    output << " ";
  }

  return output;
}