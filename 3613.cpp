#include <iostream>

#include <string>

using namespace std;



int main(void)

{

	string s;

	cin >> s;



	bool c = false, java = false, err = false;

	string result;

	for (int i = 0; i < s.length(); i++)

	{

		if ('A' <= s[i] && s[i] <= 'Z')

		{

			if (!i || c)

			{

				err = true;

				break;

			}

			result += '_';

			result += s[i] - 'A' + 'a';

			java = true;

		}

		else if (s[i] == '_')

		{

			if (!i || java || i == s.length() - 1 || s[i + 1] == '_' || ('A' <= s[i + 1] && s[i + 1] <= 'Z'))

			{

				err = true;

				break;

			}

			result += s[i + 1] - 'a' + 'A';

			i++;

			c = true;

		}

		else

			result += s[i];

	}



	if (err)

		cout << "Error!\n";

	else

		cout << result << "\n";

	return 0;

}
