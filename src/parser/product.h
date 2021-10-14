#ifndef PRODUCT_H
#define PRODUCT_H

#include <vector>
#include "dl_creationinterface.h"

#define CircleData 0

struct component
{
    int type;
    const void *entities;
    component(int t, const void *e):type(t), entities(e){}
};

class product
: public DL_CreationInterface
{
public:
    product() {}
    ~product() {}

    void addLayer(const DL_LayerData& data){}

    /**
     * Called for every block. Note: all entities added after this
     * command go into this block until endBlock() is called.
    *
     * @see endBlock()
     */
    void addBlock(const DL_BlockData& data){}

    /** Called to end the current block */
    void endBlock(){}

    /** Called for every point */
    void addPoint(const DL_PointData& data){}

    /** Called for every line */
    void addLine(const DL_LineData& data){}

    /** Called for every arc */
    void addArc(const DL_ArcData& data){}

    /** Called for every circle */
    void addCircle(const DL_CircleData& data);

    /** Called for every ellipse */
    void addEllipse(const DL_EllipseData& data){}

    /** Called for every polyline start */
    void addPolyline(const DL_PolylineData& data){}

    /** Called for every polyline vertex */
    void addVertex(const DL_VertexData& data){}
	
	/** Called for every spline */
    void addSpline(const DL_SplineData& data){}
	
	/** Called for every spline control point */
    void addControlPoint(const DL_ControlPointData& data){}
	
	/** Called for every spline knot value */
    void addKnot(const DL_KnotData& data){}

    /** Called for every insert. */
    void addInsert(const DL_InsertData& data){}
    
    /** Called for every trace start */
    void addTrace(const DL_TraceData& data){}
    
    /** Called for every 3dface start */
    void add3dFace(const DL_3dFaceData& data){}

    /** Called for every solid start */
    void addSolid(const DL_SolidData& data){}


    /** Called for every Multi Text entity. */
    void addMText(const DL_MTextData& data){}

    /**
     * Called for additional text chunks for MTEXT entities.
     * The chunks come at 250 character in size each. Note that 
     * those chunks come <b>before</b> the actual MTEXT entity.
     */
    void addMTextChunk(const char* text){}

    /** Called for every Text entity. */
    void addText(const DL_TextData& data){}

    /**
     * Called for every aligned dimension entity. 
     */
    void addDimAlign(const DL_DimensionData& data,
                             const DL_DimAlignedData& edata){}
    /**
     * Called for every linear or rotated dimension entity. 
     */
    void addDimLinear(const DL_DimensionData& data,
                              const DL_DimLinearData& edata){}

	/**
     * Called for every radial dimension entity. 
     */
    void addDimRadial(const DL_DimensionData& data,
                              const DL_DimRadialData& edata){}

	/**
     * Called for every diametric dimension entity. 
     */
    void addDimDiametric(const DL_DimensionData& data,
                              const DL_DimDiametricData& edata){}

	/**
     * Called for every angular dimension (2 lines version) entity. 
     */
    void addDimAngular(const DL_DimensionData& data,
                              const DL_DimAngularData& edata){}

	/**
     * Called for every angular dimension (3 points version) entity. 
     */
    void addDimAngular3P(const DL_DimensionData& data,
                              const DL_DimAngular3PData& edata){}
	
    /**
     * Called for every ordinate dimension entity. 
     */
    void addDimOrdinate(const DL_DimensionData& data,
                             const DL_DimOrdinateData& edata){}
    
    /** 
	 * Called for every leader start. 
	 */
    void addLeader(const DL_LeaderData& data){}
	
	/** 
	 * Called for every leader vertex 
	 */
    void addLeaderVertex(const DL_LeaderVertexData& data){}
	
	/** 
	 * Called for every hatch entity. 
	 */
    void addHatch(const DL_HatchData& data){}
	
	/** 
	 * Called for every image entity. 
	 */
    void addImage(const DL_ImageData& data){}

	/**
	 * Called for every image definition.
	 */
	void linkImage(const DL_ImageDefData& data){}

	/** 
	 * Called for every hatch loop. 
	 */
    void addHatchLoop(const DL_HatchLoopData& data){}

	/** 
	 * Called for every hatch edge entity. 
	 */
    void addHatchEdge(const DL_HatchEdgeData& data){}
	
	/** 
	 * Called after an entity has been completed.  
	 */
    void endEntity(){}
    
    /**
     * Called for every comment in the DXF file (code 999).
     */
    void addComment(const char* comment){}

    /**
     * Called for every vector variable in the DXF file (e.g. "$EXTMIN").
     */
    void setVariableVector(const char* key, 
	               double v1, double v2, double v3, int code){}
	
    /**
     * Called for every string variable in the DXF file (e.g. "$ACADVER").
     */
    void setVariableString(const char* key, const char* value, int code){}
	
    /**
     * Called for every int variable in the DXF file (e.g. "$ACADMAINTVER").
     */
    void setVariableInt(const char* key, int value, int code){}
	
    /**
     * Called for every double variable in the DXF file (e.g. "$DIMEXO").
     */
    void setVariableDouble(const char* key, double value, int code){}
	
     /**
      * Called when a SEQEND occurs (when a POLYLINE or ATTRIB is done)
      */
     void endSequence(){}

     void print();

private:
     std::vector<component> components;
};

#endif
