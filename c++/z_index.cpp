#include <cstdio>
#include <vector>
#include <string>

std::vector<int> calculate_z_array(std::string str)
{
	int length = str.length();
	std::vector<int> z(length, 0);

	int left = 0;
	int right = 0;

	for(int i = 1; i < length; i ++){
		if(right < i){
			left = right = i;
			while(right < length && str[right - left] == str[right]) right ++;
			z[i] = right - left;
			right --;
		}
		else{
			int k = i - left;
			if(z[k] < right - i + 1) z[i] = z[k];
			else{
				left = i;
				while(right < length && str[right - left] == str[right]) right ++;
				z[i] = right - left;
				right --;
			}
		}
	}

	return z;
}

std::vector<int> match_pattern(std::string haystack, std::string needle)
{
	std::string s = needle + "$" + haystack;
	std::vector<int> z = calculate_z_array(s);
	int needle_length = needle.length();
 
    std::vector<int> result;
	for(int i = 0; i < s.length(); i ++){
		if(z[i] == needle_length){
			result.push_back(i - needle_length - 1);
		}
	}

	return result;
}

int main()
{

	std::vector<int> result = match_pattern("loremipsumloremips", "lorem");

	for(const int & index : result){
		printf("%d ", index);
	}

	return 0;
}