class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int teamSkill = skill.front() + skill.back();
        long long totalChemistry = 0;
        for(int i = 0, j = skill.size() - 1; i < j; i++, j--)
        {
            if(teamSkill != (skill[i] + skill[j]))
                return -1;
            totalChemistry = totalChemistry + 1LL * skill[i] * skill[j];
        }
        return totalChemistry;
    }
};