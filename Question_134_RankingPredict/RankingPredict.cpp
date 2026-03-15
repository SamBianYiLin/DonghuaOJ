//  AI生成
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
struct Predict
{
    vector<int> seq;
    int correct;
};
vector<Predict> predicts;
vector<int> perm;   //  当前DFS生成的序列
bool used[10];  //  标记10个运动员是否访问过，防止重复访问
vector<vector<int>> ans;    //  符合要求的结果序列
bool check()
{
    int pos[10];    //  建立运动员与排名位置之间的映射关系
    for (int i = 0; i < n; i++)
        pos[perm[i]] = i;
    for (auto& p : predicts)
    {
        bool ok = true;
        for (int i = 1; i < p.seq.size(); i++)
        {
            //  pos[x]为运动员在当前DFS生成序列中的排名顺序
            //  p.seq[w]是在输入内容给出的序列中的顺序
            //  即：在预测序列在DFS生成序列的相对顺序要保持不变
            if (pos[p.seq[i - 1]] > pos[p.seq[i]])
            {
                ok = false;
                break;
            }
        }
        if (p.correct == 1 && !ok) return false;
        if (p.correct == 0 && ok) return false;
    }
    return true;
}
void dfs(int depth)
{
    if (depth == n)
    {
        if (check())
            ans.push_back(perm);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i]) continue;
        used[i] = true;
        perm.push_back(i);
        dfs(depth + 1);
        perm.pop_back();
        used[i] = false;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int c;
        scanf("%d", &c);
        Predict p;
        for (int j = 0; j < c; j++)
        {
            int t;
            scanf("%d", &t);
            p.seq.push_back(t);
        }
        scanf("%d", &p.correct);
        predicts.push_back(p);
    }
    dfs(0);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto& v : ans)
    {
        for (int x : v)
            printf("%d ", x);
        printf("\n");
    }
    return 0;
}