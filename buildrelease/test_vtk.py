import vtk

reader = vtk.vtkStructuredPointsReader()
# reader.SetFileName("ukp1_paraview.vtk")
reader.SetFileName("/home/hugo/calcul_haute_performance/cpp_oriente_objet/TD/TD2/project_simulation/buildrelease/ukp1_paraview.vtk")
# reader.SetFileName("/home/hugo/calcul_haute_performance/cpp_oriente_objet/TD/TD2/project_simulation/buildrelease/test.vtk")
reader.Update()
try:
    reader.Update()
    print("File is valid.")
except Exception as e:
    print(f"File is invalid: {e}")
