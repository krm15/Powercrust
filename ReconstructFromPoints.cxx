#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include "vtkPolyDataReader.h"
#include "vtkPolyDataWriter.h"
#include "vtkUnstructuredGrid.h"
#include <vtkPowerCrustSurfaceReconstruction.h>


int main(int argc, char *argv[])
{
    if ( argc < 2 )
    {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0] << " iPointsFile oSurface" << std::endl;
    return EXIT_FAILURE;
    }

  unsigned int m_NumberOfPoints;
  std::fstream infile;
  infile.open ( argv[1], std::ios::in );

  infile >> m_NumberOfPoints;

  float p[3];
  vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
  for( unsigned int i = 0; i <  m_NumberOfPoints; i++ )
  {
    infile >> p[0];
    infile >> p[1];
    infile >> p[2];
    points->InsertPoint(i,p);
    std::cout << p[0] << ' ' << p[1] << ' ' << p[2] << std::endl;
  }

  vtkSmartPointer<vtkUnstructuredGrid> dataSet = vtkSmartPointer<vtkUnstructuredGrid>::New();
  dataSet->SetPoints( points );

  vtkSmartPointer<vtkPowerCrustSurfaceReconstruction> reconstruct =
    vtkSmartPointer<vtkPowerCrustSurfaceReconstruction>::New();
  reconstruct->SetInput( dataSet );
  reconstruct->Update();

  vtkSmartPointer<vtkPolyDataWriter> writer = vtkSmartPointer<vtkPolyDataWriter>::New();
  writer->SetInput( reconstruct->GetMedialSurface() );
  writer->SetFileName( argv[2] );
  writer->Write();

  return EXIT_SUCCESS;
}
