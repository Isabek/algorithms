#include <cstdio>
#include <string>
#include <vector>

std::vector<int> build_prefix_array(std::string needle)
{
	int needle_size = needle.size();
	std::vector<int> prefix(needle_size, 0);

    int start = 0;
    int end = 1;

	while(end < needle_size && start < needle_size){
		if(needle[start] == needle[end]){
			prefix[end] = start + 1;
			start ++;
			end ++;
		}else{
			if(start > 0){
				start = prefix[start - 1];
			}
			else end ++;
		}
	}

	return prefix;
}

bool kmp_search(std::string haystack, std::string needle)
{
	std::vector<int> prefix_array = build_prefix_array(needle);

	int i = 0;
	int j = 0;

	int haystack_length = haystack.length();
	int needle_length = needle.length();

	while(i < haystack_length && j < needle_length){
		if(haystack[i] == needle[j]){
			i ++;
			j ++;
		}else{
			if(j > 0){
				j = prefix_array[j - 1];
			}else{
				i ++;
			}
		}
	}

	return j == needle_length ? true : false;
}

int main()
{
	if(kmp_search("loremipsum", "ips")){
		printf("%s\n", "Yes");
	}else{
		printf("%s\n", "No");
	}

	return 0;
}