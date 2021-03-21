#include "Tree1_traverse.h"
#include "Tree2_iterative.h"
#include "Tree3_level.h"

#include "Tree4_PathSum.h"

#include "Tree5_Diameter.h"

#include "Tree6_LCA.h"

#include "Tree7_Construct_Pre_In.h"

int main()
{
	cout << "__Traverse" << endl;
	Tree1_traverse();
	cout << endl;

	cout << "__Iterative" << endl;
	Tree2_iterative();
	cout << endl;

	cout << "__level" << endl;
	Tree3_level();
	cout << endl;

	cout << "__Path Sum" << endl;
	Tree4_pathsum();
	cout << endl;

	cout << "__Diameter" << endl;
	Tree5_Diameter();
	cout << endl;

	cout << "__LCA" << endl;
	Tree6_LCA();
	cout << endl;

	cout << "__Construct" << endl;
	Tree7_Construct();
	cout << endl;
}