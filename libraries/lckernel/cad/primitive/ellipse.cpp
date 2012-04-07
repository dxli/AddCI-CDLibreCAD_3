#include "ellipse.h"

using namespace lc;

Ellipse::Ellipse(const geo::Coordinate& center, const geo::Coordinate& majorP, double minorRadius, double startAngle, double endAngle)
    : geo::Ellipse(center, majorP, minorRadius, startAngle, endAngle) {

}

Ellipse::Ellipse(const geo::Coordinate& center, const geo::Coordinate& majorP, double minorRadius, double startAngle, double endAngle, const QList<MetaTypePtr>& metaTypes)
    : CADEntity(metaTypes),  geo::Ellipse(center, majorP, minorRadius, startAngle, endAngle) {
}
