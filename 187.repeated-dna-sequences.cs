/*
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (33.71%)
 * Total Accepted:    101.1K
 * Total Submissions: 299.8K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 * 
 * Example:
 * 
 * 
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 
 * Output: ["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 * 
 */
public class Solution
{
    public IList<string> FindRepeatedDnaSequences(string s)
    {
        int key = 0;
        var result = new List<string>();
        Dictionary<int, bool> map = new Dictionary<int, bool>();
        
        if (s.Length < 10) return result;

        for (var i = 0; i < 9; ++i)
        {
            key = key << 3 | s[i] & 7;
        }

        for (var i = 9; i < s.Length; ++i)
        {
            key = key << 3 & 1073741823 | s[i] & 7;
            if (map.ContainsKey(key))
            {
                if (map[key]) 
                {
                    result.Add(s.Substring(i - 9, 10));
                    map[key] = false;
                }
            }
            else
            {
                map[key] = true;
            }
        }

        return result;
    }
}