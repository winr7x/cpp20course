#include <cassert>

#include "scores.h"

double& Scores::operator[](size_t index) {
    assert(index < 20);
    return m_scores[index];
 }

double Scores::operator[](size_t index) const {
    assert(index < 20);
    return m_scores[index];
}