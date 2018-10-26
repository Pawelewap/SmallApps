#include <iostream>
#include <string.h>
#include <vector>


int main()
{
  std::vector < std::vector<int> > baza = {{1,2,3},
                                           {4,5,6},
                                           {7,8,9}};
  /* is:
   * 1 2 3
   * 4 5 6
   * 7 8 9
   *
   * should be:
   * 7 4 1
   * 8 5 2
   * 9 6 3
*/

  static int transp[3][3];
  int temp = 2;
  for(int i = 0; i < 3; i++, temp--)
  {
	for(int j = 2; j >= 0; j--)
	{
		transp[j][i] = baza[temp][j];
	}
  }

  for(int i = 0; i < 3; i++)
  {
	for(int j = 0; j < 3; j++)
	{
		baza[i][j] = transp[i][j];
		std::cout << baza[i][j] << " ";
	}
	std::cout << std::endl;
  }
}
