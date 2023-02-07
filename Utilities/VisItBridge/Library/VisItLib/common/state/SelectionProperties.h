/*****************************************************************************
*
* Copyright (c) 2000 - 2017, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef SELECTIONPROPERTIES_H
#define SELECTIONPROPERTIES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>


// ****************************************************************************
// Class: SelectionProperties
//
// Purpose:
//    Contains attributes for a selection
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API SelectionProperties : public AttributeSubject
{
public:
    enum SelectionType
    {
        BasicSelection,
        CumulativeQuerySelection
    };
    enum CombinationType
    {
        CombineAnd,
        CombineOr
    };
    enum HistogramType
    {
        HistogramTime,
        HistogramMatches,
        HistogramID,
        HistogramVariable
    };
    enum IDVariableType
    {
        UseZoneIDForID,
        UseGlobalZoneIDForID,
        UseLocationsForID,
        UseVariableForID
    };
    static const double MIN;
    static const double MAX;

    // These constructors are for objects of this class
    SelectionProperties();
    SelectionProperties(const SelectionProperties &obj);
protected:
    // These constructors are for objects derived from this class
    SelectionProperties(private_tmfs_t tmfs);
    SelectionProperties(const SelectionProperties &obj, private_tmfs_t tmfs);
public:
    virtual ~SelectionProperties();

    virtual SelectionProperties& operator = (const SelectionProperties &obj);
    virtual bool operator == (const SelectionProperties &obj) const;
    virtual bool operator != (const SelectionProperties &obj) const;
private:
    void Init();
    void Copy(const SelectionProperties &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectName();
    void SelectSource();
    void SelectHost();
    void SelectIdVariable();
    void SelectVariables();
    void SelectVariableMins();
    void SelectVariableMaxs();
    void SelectHistogramVariable();

    // Property setting methods
    void SetName(const std::string &name_);
    void SetSource(const std::string &source_);
    void SetHost(const std::string &host_);
    void SetSelectionType(SelectionType selectionType_);
    void SetIdVariableType(IDVariableType idVariableType_);
    void SetIdVariable(const std::string &idVariable_);
    void SetVariables(const stringVector &variables_);
    void SetVariableMins(const doubleVector &variableMins_);
    void SetVariableMaxs(const doubleVector &variableMaxs_);
    void SetMinTimeState(int minTimeState_);
    void SetMaxTimeState(int maxTimeState_);
    void SetTimeStateStride(int timeStateStride_);
    void SetCombineRule(CombinationType combineRule_);
    void SetHistogramType(HistogramType histogramType_);
    void SetHistogramNumBins(int histogramNumBins_);
    void SetHistogramAutoScaleNumBins(bool histogramAutoScaleNumBins_);
    void SetHistogramStartBin(int histogramStartBin_);
    void SetHistogramEndBin(int histogramEndBin_);
    void SetHistogramVariable(const std::string &histogramVariable_);

    // Property getting methods
    const std::string  &GetName() const;
          std::string  &GetName();
    const std::string  &GetSource() const;
          std::string  &GetSource();
    const std::string  &GetHost() const;
          std::string  &GetHost();
    SelectionType      GetSelectionType() const;
    IDVariableType     GetIdVariableType() const;
    const std::string  &GetIdVariable() const;
          std::string  &GetIdVariable();
    const stringVector &GetVariables() const;
          stringVector &GetVariables();
    const doubleVector &GetVariableMins() const;
          doubleVector &GetVariableMins();
    const doubleVector &GetVariableMaxs() const;
          doubleVector &GetVariableMaxs();
    int                GetMinTimeState() const;
    int                GetMaxTimeState() const;
    int                GetTimeStateStride() const;
    CombinationType    GetCombineRule() const;
    HistogramType      GetHistogramType() const;
    int                GetHistogramNumBins() const;
    bool               GetHistogramAutoScaleNumBins() const;
    int                GetHistogramStartBin() const;
    int                GetHistogramEndBin() const;
    const std::string  &GetHistogramVariable() const;
          std::string  &GetHistogramVariable();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string SelectionType_ToString(SelectionType);
    static bool SelectionType_FromString(const std::string &, SelectionType &);
protected:
    static std::string SelectionType_ToString(int);
public:
    static std::string CombinationType_ToString(CombinationType);
    static bool CombinationType_FromString(const std::string &, CombinationType &);
protected:
    static std::string CombinationType_ToString(int);
public:
    static std::string HistogramType_ToString(HistogramType);
    static bool HistogramType_FromString(const std::string &, HistogramType &);
protected:
    static std::string HistogramType_ToString(int);
public:
    static std::string IDVariableType_ToString(IDVariableType);
    static bool IDVariableType_FromString(const std::string &, IDVariableType &);
protected:
    static std::string IDVariableType_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    const std::string &GetOriginatingPlot() const;
    void SetOriginatingPlot(const std::string &);

    // IDs that can be used to identify fields in case statements
    enum {
        ID_name = 0,
        ID_source,
        ID_host,
        ID_selectionType,
        ID_idVariableType,
        ID_idVariable,
        ID_variables,
        ID_variableMins,
        ID_variableMaxs,
        ID_minTimeState,
        ID_maxTimeState,
        ID_timeStateStride,
        ID_combineRule,
        ID_histogramType,
        ID_histogramNumBins,
        ID_histogramAutoScaleNumBins,
        ID_histogramStartBin,
        ID_histogramEndBin,
        ID_histogramVariable,
        ID__LAST
    };

private:
    std::string  name;
    std::string  source;
    std::string  host;
    int          selectionType;
    int          idVariableType;
    std::string  idVariable;
    stringVector variables;
    doubleVector variableMins;
    doubleVector variableMaxs;
    int          minTimeState;
    int          maxTimeState;
    int          timeStateStride;
    int          combineRule;
    int          histogramType;
    int          histogramNumBins;
    bool         histogramAutoScaleNumBins;
    int          histogramStartBin;
    int          histogramEndBin;
    std::string  histogramVariable;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define SELECTIONPROPERTIES_TMFS "sssiiss*d*d*iiiiiibiis"

#endif
