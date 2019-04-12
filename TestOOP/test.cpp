#include "pch.h"

#include "../Unit-test/shape.cpp"
#include "../Unit-test/container.cpp"
#include "../Unit-test/tetrahedron.cpp"
#include "../Unit-test/ball.cpp"
#include "../Unit-test/box.cpp"

using namespace std;
using namespace simple_shapes;

// ќжидаетс€, что данные, считанные из файла, и добавленные программно совпадут.
TEST(ReadTests, IsReadCorrect)
{
	container *actual = new container, *expected = new container;
	ifstream CorrectCheckStream("../TestOOP/ReadTestFile.txt");
	actual->In(CorrectCheckStream);
	expected->Add(new tetrahedron(3, 300));
	expected->Add(new ball(2, 200));
	expected->Add(new box(2, 3, 4, 100));
	for (int i = 0; i < 3; i++)
	{
		EXPECT_EQ(actual->GetElement(i)->ToString(), expected->GetElement(i)->ToString());
	}
}

// ќжидаетс€, что данные, считанные из файла помен€ютс€ местами при сортировке, так как сортировка 
// идет по возрастанию периметра и станут совпадать с добавленными в правльном пор€дке программно.
TEST(SortTests, IsSortCorrect)
{
	container *actual = new container, *expected = new container;
	ifstream SortStream("../TestOOP/SortTestFile.txt");
	actual->In(SortStream);
	actual->Sort();
	expected->Add(new box(14, 40, 12, 100));
	expected->Add(new box(10, 14, 30, 100));
	expected->Add(new ball(3, 400));
	expected->Add(new ball(2, 100));
	expected->Add(new tetrahedron(4, 100));
	
	
	for (int i = 0; i < 2; i++)
	{
		EXPECT_EQ(actual->GetElement(i)->ToString(), expected->GetElement(i)->ToString());
	;
	}
}

// »дет сравнение вычисленных программой объемов с ожидаемыми.
TEST(VTests, IsVCorrect)
{
	tetrahedron Tetrahedron = tetrahedron(12, 200);
	EXPECT_EQ(Tetrahedron.V(), 201.6);
	ball Ball = ball(3, 200);
	EXPECT_EQ(Ball.V(), 113.04);
	box Box = box(2, 3, 4, 100);
	EXPECT_EQ(Box.V(), 24);
}
//функци€ сравнени€ файлов
bool CompareFiles(string path1, string path2)
{
	string temp;
	ifstream File1(path1);
	vector<string> File1Lines;
	while (File1)
	{
		getline(File1, temp);
		File1Lines.push_back(temp);
	}
	ifstream File2(path2);
	vector<string> File2Lines;
	while (File2)
	{
		getline(File2, temp);
		File2Lines.push_back(temp);
	}
	if (File1Lines.size() != File2Lines.size())
		return false;
	for (int i = 0; i < (int)File1Lines.size(); i++)
		if (File1Lines[i] != File2Lines[i])
			return false;
	return true;
}

TEST(WriteTests, IsWriteCorrect)
{
	
	container *Container = new container;
	Container->Add(new tetrahedron(3, 300));
	Container->Add(new ball(2, 200));
	Container->Add(new box(2, 3, 4, 100));
	ofstream WriteStream("../TestsOOP/ActualWriteFile.txt");
	Container->Out(WriteStream);
	EXPECT_TRUE(CompareFiles("../TestsOOP/ActualWriteFile.txt", "../TestsOOP/ExpectedWriteFile.txt"));
}

TEST(WriteTests, IsFilteredWriteCorrect)
{
	container *Container = new container;
	Container->Add(new tetrahedron(3, 300));
	Container->Add(new ball(2, 200));
	Container->Add(new box(2, 3, 4, 100));
	ofstream WriteStream("../TestsOOP/ActualOutputFile.txt");
	Container->OutBalls(WriteStream);
	EXPECT_TRUE(CompareFiles("../TestsOOP/ActualOutputFile.txt", "../TestsOOP/ExpectedOutputFile.txt"));
}