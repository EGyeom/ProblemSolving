//����
#include <iostream>
#include <vector>

int main()
{
	int n;
	std::vector<int> answer; // ��
	std::vector<int> st; // �ϳ��� Ǫ��
	std::vector<int> solution; // ���� Ǫ���ϱ�����
	int check = 0;
	int count = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int num;
		std::cin >> num;
		answer.push_back(num);
	}
	for (int i = 1; i <= answer.size(); i)
	{
		if (st.size() != 0)
		{
			if (st[st.end] == answer[count])
			{
				solution.push_back(i);
			}
			else
			{
				
			}
		}
		else
		{
			st.push_back(i);
		}
	}
}