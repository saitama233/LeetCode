CXX = g++
CXXFLAGS += -std=c++11 -Wall -Wno-uninitialized -Wno-unused-function

RM = /bin/rm

OBJS += 001.TwoSum 002.AddTwoNumbers 003.LongestSubstringWithoutRepeatingCharacters 004.MedianOfTwoSortedArrays
OBJS += 005.LongestPalindromicSubstring 010.RegularExpressionMatching
OBJS += 011.ContainerWithMostWater 015.3Sum 017.LetterCombinationsofaPhoneNumber
OBJS += 019.RemoveNthNodeFromEndofList 020.ValidParentheses 021.MergeTwoSortedLists
OBJS += 022.GenerateParentheses 023.MergeKSortedLists 031.NextPermutation 
OBJS += 032.LongestValidParentheses 033.SearchinRotatedSortedArray
OBJS += 034.FindFirstandLastPositionofElementinSortedArray 035.SearchInsertPosition 039.CombinationSum
OBJS += 042.TrappingRainWater 046.Permutations 048.RotateImage
OBJS += 049.GroupAnagrams 055.JumpGame 056.MergeIntervals

# .PHONY: all clean
all: $(OBJS)

%: %.o
	$(CXX) $(CXXFLAGS) $^ -o $@ 

sources = $(OBJS:%=%.cc)
include ${sources:.cc=.d}

%.d: %.cc
	set -e; \
	$(RM) -f $@; \
	$(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	$(RM) -f $@.$$$$

clean:
	-$(RM) *.d *.o $(OBJS)
