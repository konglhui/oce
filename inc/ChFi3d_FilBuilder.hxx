// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ChFi3d_FilBuilder_HeaderFile
#define _ChFi3d_FilBuilder_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <BlendFunc_SectionShape.hxx>
#include <ChFi3d_Builder.hxx>
#include <ChFi3d_FilletShape.hxx>
#include <Standard_Real.hxx>
#include <Handle_Law_Function.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_ChFiDS_SecHArray1.hxx>
#include <Handle_ChFiDS_SurfData.hxx>
#include <Handle_ChFiDS_HElSpine.hxx>
#include <Handle_ChFiDS_Spine.hxx>
#include <Handle_BRepAdaptor_HSurface.hxx>
#include <Handle_Adaptor3d_TopolTool.hxx>
#include <math_Vector.hxx>
#include <Handle_BRepAdaptor_HCurve2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopAbs_State.hxx>
#include <Handle_BRepBlend_Line.hxx>
#include <Handle_ChFiDS_Stripe.hxx>
class TopoDS_Shape;
class TopoDS_Edge;
class Law_Function;
class TopoDS_Vertex;
class gp_XY;
class ChFiDS_SecHArray1;
class ChFiDS_SurfData;
class ChFiDS_HElSpine;
class ChFiDS_Spine;
class BRepAdaptor_HSurface;
class Adaptor3d_TopolTool;
class BRepAdaptor_HCurve2d;
class ChFiDS_SequenceOfSurfData;
class BRepBlend_Line;
class ChFiDS_Stripe;
class ChFiDS_ListOfStripe;


//! Tool  of  construction of  fillets 3d on  edges (on a solid).
class ChFi3d_FilBuilder  : public ChFi3d_Builder
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT ChFi3d_FilBuilder(const TopoDS_Shape& S, const ChFi3d_FilletShape FShape = ChFi3d_Rational, const Standard_Real Ta = 1.0e-2);
  
  //! Sets the type of fillet surface.
  Standard_EXPORT   void SetFilletShape (const ChFi3d_FilletShape FShape) ;
  
  //! Returns the type of fillet surface.
  Standard_EXPORT   ChFi3d_FilletShape GetFilletShape()  const;
  
  //! initialisation of  a contour with the first edge
  //! (the following are found  by propagation).
  //! Attention, you  need  to start  with  SetRadius.
  Standard_EXPORT   void Add (const TopoDS_Edge& E) ;
  
  //! initialisation of the constant vector the corresponding  1st  edge.
  Standard_EXPORT   void Add (const Standard_Real Radius, const TopoDS_Edge& E) ;
  
  //! Set the radius of the contour of index IC.
  Standard_EXPORT   void SetRadius (const Handle(Law_Function)& C, const Standard_Integer IC, const Standard_Integer IinC) ;
  
  //! Returns true the contour is flaged as edge constant.
  Standard_EXPORT   Standard_Boolean IsConstant (const Standard_Integer IC) ;
  
  //! Returns the vector if the contour is flagged as edge
  //! constant.
  Standard_EXPORT   Standard_Real Radius (const Standard_Integer IC) ;
  
  //! Reset all vectors of contour IC.
  Standard_EXPORT   void ResetContour (const Standard_Integer IC) ;
  
  //! Set a constant on edge E of  the contour of
  //! index IC. Since  then  E is flagged as constant.
  Standard_EXPORT   void SetRadius (const Standard_Real Radius, const Standard_Integer IC, const TopoDS_Edge& E) ;
  
  //! Extracts the flag constant and the vector of edge E.
  Standard_EXPORT   void UnSet (const Standard_Integer IC, const TopoDS_Edge& E) ;
  
  //! Set a vector on vertex  V of  the contour of index IC.
  Standard_EXPORT   void SetRadius (const Standard_Real Radius, const Standard_Integer IC, const TopoDS_Vertex& V) ;
  
  //! Extracts the vector of  the vertex V.
  Standard_EXPORT   void UnSet (const Standard_Integer IC, const TopoDS_Vertex& V) ;
  
  //! Set  a vertex on the point of parametre U in the edge IinC
  //! of  the contour of index IC
  Standard_EXPORT   void SetRadius (const gp_XY& UandR, const Standard_Integer IC, const Standard_Integer IinC) ;
  
  //! Returns true E is flagged as edge constant.
  Standard_EXPORT   Standard_Boolean IsConstant (const Standard_Integer IC, const TopoDS_Edge& E) ;
  
  //! Returns the vector if E is flagged as edge constant.
  Standard_EXPORT   Standard_Real Radius (const Standard_Integer IC, const TopoDS_Edge& E) ;
  
  //! Returns in First and Last  les extremities of  the
  //! part of variable  vector framing E, returns
  //! False  if  E is flagged as edge constant.
  Standard_EXPORT   Standard_Boolean GetBounds (const Standard_Integer IC, const TopoDS_Edge& E, Standard_Real& First, Standard_Real& Last) ;
  
  //! Returns the rule of  elementary  evolution of  the
  //! part to  variable vector framing E, returns a
  //! rule zero if E is flagged as edge constant.
  Standard_EXPORT   Handle(Law_Function) GetLaw (const Standard_Integer IC, const TopoDS_Edge& E) ;
  
  //! Sets the rule of elementary evolution of  the
  //! part to variable  vector framing E.
  Standard_EXPORT   void SetLaw (const Standard_Integer IC, const TopoDS_Edge& E, const Handle(Law_Function)& L) ;
  
  Standard_EXPORT   void Simulate (const Standard_Integer IC) ;
  
  Standard_EXPORT   Standard_Integer NbSurf (const Standard_Integer IC)  const;
  
  Standard_EXPORT   Handle(ChFiDS_SecHArray1) Sect (const Standard_Integer IC, const Standard_Integer IS)  const;




protected:

  
  Standard_EXPORT   void SimulKPart (const Handle(ChFiDS_SurfData)& SD)  const;
  
  Standard_EXPORT   Standard_Boolean SimulSurf (Handle(ChFiDS_SurfData)& Data, const Handle(ChFiDS_HElSpine)& Guide, const Handle(ChFiDS_Spine)& Spine, const Standard_Integer Choix, const Handle(BRepAdaptor_HSurface)& S1, const Handle(Adaptor3d_TopolTool)& I1, const Handle(BRepAdaptor_HSurface)& S2, const Handle(Adaptor3d_TopolTool)& I2, const Standard_Real TolGuide, Standard_Real& First, Standard_Real& Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecOnS1, const Standard_Boolean RecOnS2, const math_Vector& Soldep, Standard_Integer& Intf, Standard_Integer& Intl) ;
  
  Standard_EXPORT virtual   void SimulSurf (Handle(ChFiDS_SurfData)& Data, const Handle(ChFiDS_HElSpine)& Guide, const Handle(ChFiDS_Spine)& Spine, const Standard_Integer Choix, const Handle(BRepAdaptor_HSurface)& S1, const Handle(Adaptor3d_TopolTool)& I1, const Handle(BRepAdaptor_HCurve2d)& PC1, const Handle(BRepAdaptor_HSurface)& Sref1, const Handle(BRepAdaptor_HCurve2d)& PCref1, Standard_Boolean& Decroch1, const Handle(BRepAdaptor_HSurface)& S2, const Handle(Adaptor3d_TopolTool)& I2, const TopAbs_Orientation Or2, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real& First, Standard_Real& Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP, const Standard_Boolean RecS, const Standard_Boolean RecRst, const math_Vector& Soldep) ;
  
  Standard_EXPORT virtual   void SimulSurf (Handle(ChFiDS_SurfData)& Data, const Handle(ChFiDS_HElSpine)& Guide, const Handle(ChFiDS_Spine)& Spine, const Standard_Integer Choix, const Handle(BRepAdaptor_HSurface)& S1, const Handle(Adaptor3d_TopolTool)& I1, const TopAbs_Orientation Or1, const Handle(BRepAdaptor_HSurface)& S2, const Handle(Adaptor3d_TopolTool)& I2, const Handle(BRepAdaptor_HCurve2d)& PC2, const Handle(BRepAdaptor_HSurface)& Sref2, const Handle(BRepAdaptor_HCurve2d)& PCref2, Standard_Boolean& Decroch2, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real& First, Standard_Real& Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP, const Standard_Boolean RecS, const Standard_Boolean RecRst, const math_Vector& Soldep) ;
  
  Standard_EXPORT virtual   void SimulSurf (Handle(ChFiDS_SurfData)& Data, const Handle(ChFiDS_HElSpine)& Guide, const Handle(ChFiDS_Spine)& Spine, const Standard_Integer Choix, const Handle(BRepAdaptor_HSurface)& S1, const Handle(Adaptor3d_TopolTool)& I1, const Handle(BRepAdaptor_HCurve2d)& PC1, const Handle(BRepAdaptor_HSurface)& Sref1, const Handle(BRepAdaptor_HCurve2d)& PCref1, Standard_Boolean& Decroch1, const TopAbs_Orientation Or1, const Handle(BRepAdaptor_HSurface)& S2, const Handle(Adaptor3d_TopolTool)& I2, const Handle(BRepAdaptor_HCurve2d)& PC2, const Handle(BRepAdaptor_HSurface)& Sref2, const Handle(BRepAdaptor_HCurve2d)& PCref2, Standard_Boolean& Decroch2, const TopAbs_Orientation Or2, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real& First, Standard_Real& Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP1, const Standard_Boolean RecRst1, const Standard_Boolean RecP2, const Standard_Boolean RecRst2, const math_Vector& Soldep) ;
  
  Standard_EXPORT   Standard_Boolean PerformFirstSection (const Handle(ChFiDS_Spine)& S, const Handle(ChFiDS_HElSpine)& HGuide, const Standard_Integer Choix, Handle(BRepAdaptor_HSurface)& S1, Handle(BRepAdaptor_HSurface)& S2, const Handle(Adaptor3d_TopolTool)& I1, const Handle(Adaptor3d_TopolTool)& I2, const Standard_Real Par, math_Vector& SolDep, TopAbs_State& Pos1, TopAbs_State& Pos2)  const;
  
  //! Method calculates the elements of construction of  the
  //! fillet (constant or evolutive).
  Standard_EXPORT   Standard_Boolean PerformSurf (ChFiDS_SequenceOfSurfData& SeqData, const Handle(ChFiDS_HElSpine)& Guide, const Handle(ChFiDS_Spine)& Spine, const Standard_Integer Choix, const Handle(BRepAdaptor_HSurface)& S1, const Handle(Adaptor3d_TopolTool)& I1, const Handle(BRepAdaptor_HSurface)& S2, const Handle(Adaptor3d_TopolTool)& I2, const Standard_Real MaxStep, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real& First, Standard_Real& Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecOnS1, const Standard_Boolean RecOnS2, const math_Vector& Soldep, Standard_Integer& Intf, Standard_Integer& Intl) ;
  
  Standard_EXPORT virtual   void PerformSurf (ChFiDS_SequenceOfSurfData& SeqData, const Handle(ChFiDS_HElSpine)& Guide, const Handle(ChFiDS_Spine)& Spine, const Standard_Integer Choix, const Handle(BRepAdaptor_HSurface)& S1, const Handle(Adaptor3d_TopolTool)& I1, const Handle(BRepAdaptor_HCurve2d)& PC1, const Handle(BRepAdaptor_HSurface)& Sref1, const Handle(BRepAdaptor_HCurve2d)& PCref1, Standard_Boolean& Decroch1, const Handle(BRepAdaptor_HSurface)& S2, const Handle(Adaptor3d_TopolTool)& I2, const TopAbs_Orientation Or2, const Standard_Real MaxStep, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real& First, Standard_Real& Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP, const Standard_Boolean RecS, const Standard_Boolean RecRst, const math_Vector& Soldep) ;
  
  Standard_EXPORT virtual   void PerformSurf (ChFiDS_SequenceOfSurfData& SeqData, const Handle(ChFiDS_HElSpine)& Guide, const Handle(ChFiDS_Spine)& Spine, const Standard_Integer Choix, const Handle(BRepAdaptor_HSurface)& S1, const Handle(Adaptor3d_TopolTool)& I1, const TopAbs_Orientation Or1, const Handle(BRepAdaptor_HSurface)& S2, const Handle(Adaptor3d_TopolTool)& I2, const Handle(BRepAdaptor_HCurve2d)& PC2, const Handle(BRepAdaptor_HSurface)& Sref2, const Handle(BRepAdaptor_HCurve2d)& PCref2, Standard_Boolean& Decroch2, const Standard_Real MaxStep, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real& First, Standard_Real& Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP, const Standard_Boolean RecS, const Standard_Boolean RecRst, const math_Vector& Soldep) ;
  
  Standard_EXPORT virtual   void PerformSurf (ChFiDS_SequenceOfSurfData& Data, const Handle(ChFiDS_HElSpine)& Guide, const Handle(ChFiDS_Spine)& Spine, const Standard_Integer Choix, const Handle(BRepAdaptor_HSurface)& S1, const Handle(Adaptor3d_TopolTool)& I1, const Handle(BRepAdaptor_HCurve2d)& PC1, const Handle(BRepAdaptor_HSurface)& Sref1, const Handle(BRepAdaptor_HCurve2d)& PCref1, Standard_Boolean& Decroch1, const TopAbs_Orientation Or1, const Handle(BRepAdaptor_HSurface)& S2, const Handle(Adaptor3d_TopolTool)& I2, const Handle(BRepAdaptor_HCurve2d)& PC2, const Handle(BRepAdaptor_HSurface)& Sref2, const Handle(BRepAdaptor_HCurve2d)& PCref2, Standard_Boolean& Decroch2, const TopAbs_Orientation Or2, const Standard_Real MaxStep, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real& First, Standard_Real& Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP1, const Standard_Boolean RecRst1, const Standard_Boolean RecP2, const Standard_Boolean RecRst2, const math_Vector& Soldep) ;
  
  //! Method to split an singular SurfData  in  several  non
  //! singular  SurfData..
  Standard_EXPORT   void SplitSurf (ChFiDS_SequenceOfSurfData& SeqData, const Handle(BRepBlend_Line)& line) ;
  
  Standard_EXPORT   void PerformTwoCorner (const Standard_Integer Index) ;
  
  Standard_EXPORT   void PerformThreeCorner (const Standard_Integer Index) ;
  
  Standard_EXPORT   void ExtentOneCorner (const TopoDS_Vertex& V, const Handle(ChFiDS_Stripe)& S) ;
  
  Standard_EXPORT   void ExtentTwoCorner (const TopoDS_Vertex& V, const ChFiDS_ListOfStripe& LS) ;
  
  Standard_EXPORT   void ExtentThreeCorner (const TopoDS_Vertex& V, const ChFiDS_ListOfStripe& LS) ;
  
  Standard_EXPORT   void SetRegul() ;




private:



  BlendFunc_SectionShape myShape;


};







#endif // _ChFi3d_FilBuilder_HeaderFile
