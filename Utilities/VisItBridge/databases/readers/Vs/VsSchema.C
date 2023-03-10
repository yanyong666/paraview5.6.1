#include <vtk_hdf5.h>
/**
 * @file  VsSchema.cpp
 *
 * @class VsSchema
 *
 * @brief Describes how instant datasets and meshes are found in the
 * file compliant with the schema.
 *
 * Copyright &copy; 2008 by Tech-X Corporation
 */

#include <VsSchema.h>

std::string VsSchema::mdAtt ="vsMD";

std::string VsSchema::typeAtt ="vsType";
std::string VsSchema::kindAtt = "vsKind";
std::string VsSchema::meshAtt = "vsMesh";
std::string VsSchema::maskAtt = "vsMask";
std::string VsSchema::nodeOffsetAtt = "vsNodeOffset";

std::string VsSchema::centeringAtt ="vsCentering";
std::string VsSchema::indexOrderAtt = "vsIndexOrder";
std::string VsSchema::numSpatialDimsAtt = "vsNumSpatialDims";
std::string VsSchema::numSpatialDimsAtt_deprecated = "numSpatialDims";
std::string VsSchema::spatialIndicesAtt = "vsSpatialIndices";
std::string VsSchema::labelsAtt = "vsLabels";
std::string VsSchema::axisLabelsAtt = "vsAxisLabels";
std::string VsSchema::VsSubCellLocationsAtt = "vsSubCellLocations";

std::string VsSchema::varKey = "variable";
std::string VsSchema::varWithMeshKey = "variableWithMesh";
std::string VsSchema::meshKey = "mesh";
std::string VsSchema::vsVarsKey = "vsVars";
std::string VsSchema::zonalCenteringKey = "zonal"; 
std::string VsSchema::nodalCenteringKey = "nodal"; // Default

// New to VsSchema 4.0
std::string VsSchema::edgeCenteringKey = "edge";
std::string VsSchema::faceCenteringKey = "face";

// Index ordering...
std::string VsSchema::compMajorCKey = "compMajorC"; //currently not supported
std::string VsSchema::compMinorCKey = "compMinorC"; //default ordering
std::string VsSchema::compMajorFKey = "compMajorF"; //currently not supported
std::string VsSchema::compMinorFKey = "compMinorF"; //supported

// Transforms
std::string VsSchema::transformKey = "vsTransform";
std::string VsSchema::transformedMeshKey = "vsTransformedMesh";
std::string VsSchema::zrphiTransformKey = "cylindricalZRPhi";
std::string VsSchema::zrphiTransformKey_deprecated = "Cylindrical";

// Meshes
std::string VsSchema::structuredMeshKey = "structured";

std::string VsSchema::Rectilinear::key = "rectilinear";
std::string VsSchema::Rectilinear::axis0Key = "vsAxis0";
std::string VsSchema::Rectilinear::axis0DefaultName = "axis0";
std::string VsSchema::Rectilinear::axis1Key = "vsAxis1";
std::string VsSchema::Rectilinear::axis1DefaultName = "axis1";
std::string VsSchema::Rectilinear::axis2Key = "vsAxis2";
std::string VsSchema::Rectilinear::axis2DefaultName = "axis2";

std::string VsSchema::Uniform::key = "uniform";
std::string VsSchema::Uniform::key_deprecated = "uniformCartesian";
std::string VsSchema::Uniform::lowerBounds = "vsLowerBounds";
std::string VsSchema::Uniform::lowerBounds_deprecated = "lowerBounds";
std::string VsSchema::Uniform::startCell = "vsStartCell";
std::string VsSchema::Uniform::startCell_deprecated = "startCell";
std::string VsSchema::Uniform::numCells = "vsNumCells";
std::string VsSchema::Uniform::numCells_deprecated = "numPhysCells";
std::string VsSchema::Uniform::upperBounds = "vsUpperBounds";
std::string VsSchema::Uniform::upperBounds_deprecated = "upperBounds";

std::string VsSchema::Unstructured::key = "unstructured";

std::string VsSchema::Unstructured::defaultPolygonsName = "polygons";
std::string VsSchema::Unstructured::defaultPolyhedraName = "polyhedra";

std::string VsSchema::Unstructured::defaultPointsName = "points";
std::string VsSchema::Unstructured::defaultLinesName = "lines";
std::string VsSchema::Unstructured::defaultTrianglesName = "triangles";
std::string VsSchema::Unstructured::defaultQuadrilateralsName = "quadrilaterals";

std::string VsSchema::Unstructured::defaultTetrahedralsName = "tetrahedrals";
std::string VsSchema::Unstructured::defaultPyramidsName = "pyramids";
std::string VsSchema::Unstructured::defaultPrismsName = "prisms";
std::string VsSchema::Unstructured::defaultHexahedralsName = "hexahedrals";

std::string VsSchema::Unstructured::vsPolygons = "vsPolygons";
std::string VsSchema::Unstructured::vsPolyhedra = "vsPolyhedra";

std::string VsSchema::Unstructured::vsPoints = "vsPoints";
std::string VsSchema::Unstructured::vsLines = "vsLines";
std::string VsSchema::Unstructured::vsTriangles = "vsTriangles";
std::string VsSchema::Unstructured::vsQuadrilaterals = "vsQuadrilaterals";

std::string VsSchema::Unstructured::vsTetrahedrals = "vsTetrahedrals";
std::string VsSchema::Unstructured::vsPyramids = "vsPyramids";
std::string VsSchema::Unstructured::vsPrisms = "vsPrisms";
std::string VsSchema::Unstructured::vsHexahedrals = "vsHexahedrals";

std::string VsSchema::Unstructured::vsPoints0 = "vsPoints0";
std::string VsSchema::Unstructured::vsPoints1 = "vsPoints1";
std::string VsSchema::Unstructured::vsPoints2 = "vsPoints2";

//Time
std::string VsSchema::timeKey = "time";
std::string VsSchema::timeAtt = "vsTime";
std::string VsSchema::cycleAtt = "vsStep";
std::string VsSchema::timeGroupAtt = "vsTimeGroup";

//Run info
std::string VsSchema::runInfoKey = "runInfo";
std::string VsSchema::softwareAtt = "vsSoftware";
