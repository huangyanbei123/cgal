// AUTHOR: Daniel Russel drussel@graphics.stanford.edu

// See http://graphics.stanford.edu/~drussel/pdb for documentation.
// 
// Feel free to contact me (Daniel, drussel@graphics.stanford.edu) 
// if you have any suggestions or patches. Thanks.

#ifndef EXTRACT_BALLS_FROM_PDB_H
#define EXTRACT_BALLS_FROM_PDB_H

#include <CGAL/PDB/PDB.h>
#include <CGAL/PDB/iterator.h>
#include <fstream>

template <class Range, class OIt>
void copy(Range r, OIt out) {
  std::copy(r.begin(), r.end(), out);
}

template <class Traits, class OutputIterator>
void extract_balls_from_pdb(const char *filename, 
			    Traits const &t,
			    OutputIterator weighted_points) 
{
  std::ifstream in(filename);

  if (!in) {
    std::cerr << "Error opening input file " << filename << std::endl;
  }

  CGAL::PDB::PDB pdb(in);
  CGAL::PDB::Model m=pdb.models().begin()->model();
  CGAL::PDB::Chain c=m.chains().begin()->chain();
  // get all weighted_points
    
  copy
    (CGAL::PDB::make_weighted_point_range(CGAL::PDB::make_atom_range
                                          (m.atoms()), t),
     weighted_points);
}
			    

#endif // EXTRACT_BALLS_FROM_PDB_H
