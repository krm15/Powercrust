This is a VTK implementation of the powercrust algorithm:
Amenta, Choi and Kolluri, The power crust, 6th ACM Symposium on Solid Modeling, 2001, pages 249-260
Amenta, Choi and Kolluri, The power crust, unions of balls, and the medial axis transform, Computational Geometry: Theory and Applications, 2001, 19:(2-3), pages 127-153. 

Sample code in C with a GPL license was made available as a tar ball by the authors at:
http://www.cs.ucdavis.edu/~amenta/powercrust.html

It was subsequently improved and ported to VTK by Tim Hutton at:
http://www.sq3.org.uk/powercrust/

The VTK code had compilation bugs with gcc 4.6.3 with Ubuntu 12.04 LTS. I cleared the bugs and ported to VTK 6.0. Note that VTK 6.0 has backwards incompatible API changes. The VTK 6.0 compatible code is on master branch and VTK 5.0 compatible code is located on a separate branch.

To use the code, I have provided a sample CMakeLists.txt file for using CMake. I have also provided a simple main file ReconstructFromPoints.txt that accepts a text file of unorganized points in the following format:

NumberOfPoints
X Y Z
.....

Using the code, one can make changes in the r parameter and also write out the reconstructed surface and the medial surface. The original C code is more powerful and can simplify the medial surface and reconstruct a smoother surface.

If you improve the code, please contribute back to this repository.

Kishore Mosaliganti

Research Fellow in Megason Lab,
Department of Systems Biology,
Harvard Medical School,
200 Longwood Avenue, WAB 536,
Boston, MA 02115

