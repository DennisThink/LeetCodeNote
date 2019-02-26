#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch2(string s, string p) {
        int sIndex = 0;
        int pIndex = 0;
        if(p == ".*")
        {
            return true;
        }
        while(pIndex < p.length() && sIndex < s.length())
        {
            //.匹配任意一个字符
            if(p[pIndex] == '.')
            {
                pIndex++;
                sIndex++;
            }
            
            //匹配上了
            if(p[pIndex]==s[sIndex])
            {
                if(pIndex+1 < p.length())
                {
                    if(p[pIndex+1]=='*')
                    {
                        sIndex++;
                    }
                    else
                    {
                        sIndex++;
                        pIndex++;
                    }
                }
                else
                {
                    sIndex++;
                    pIndex++;
                }
            }
            else 
            {
                if(pIndex+1 < p.length())
                {
                    if(p[pIndex+1]=='*')
                    {
                        pIndex+=2;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if(pIndex == p.length() && sIndex == s.length())
        {
            return true;   
        }
        else
        {
            if(pIndex == p.length()-2 && p[pIndex+1]=='*')
            {
                return true;
            }
            return false;
        }
    }

    struct Match_t
    {
        char m_ch;
        bool m_bCopy;//可以被拷贝
        bool m_bZero;//可以0匹配
        Match_t(char ch,bool bCopy=false,bool bZero=false)
        {
            m_ch = ch;
            m_bCopy = bCopy;
            m_bZero = bZero;
        }

        void Print()
        {
            std::cout<<m_ch<<" Copy:"<<m_bCopy<<"  Zero:"<<m_bZero<<std::endl;
        }
    };

    bool isMatch(string s,string p)
    {
        std::vector<Match_t> matchVec;
        int pIndex = 0;
        while(pIndex < p.length())
        {
            if(pIndex < p.length()-1 && p[pIndex+1]=='*')
            {
                matchVec.push_back(Match_t(p[pIndex],true,true));
                pIndex+=2;
            }
            else if(p[pIndex] == '*')
            {
                pIndex++;
            }
            else
            {
                if(!matchVec.empty())
                {
                    auto item = matchVec.rbegin();
                    if(item->m_ch == p[pIndex])
                    {
                        
                    }
                }
                matchVec.push_back(Match_t(p[pIndex]));
                pIndex++;
            }
        }

        for(auto item:matchVec)
        {
            item.Print();
        }

        int sIndex = 0;
        int matchIndex = 0;
        while(sIndex < s.length() && matchIndex < matchVec.size())
        {

            
            auto matchValue=matchVec[matchIndex];
            matchValue.Print();
            std::cout<<s[sIndex]<<__LINE__<<std::endl;
            //匹配上了
            if(matchValue.m_ch == s[sIndex])
            {
                sIndex++;
                //不能拷贝，matchIndex++
                if(!(matchValue.m_bCopy))
                {
                   std::cout<<__LINE__<<std::endl;
                   matchIndex++;
                }  
                else
                {
                    std::cout<<__LINE__<<std::endl;
                }      
            }
            else
            {
                //不是.
                if(matchValue.m_ch != '.')
                {
                    //可以忽略，跳过当前匹配
                    if(matchValue.m_bZero)
                    {
                        std::cout<<__LINE__<<std::endl;
                        matchIndex++;
                    }
                    //不可以忽略，匹配失败
                    else
                    {
                        std::cout<<__LINE__<<std::endl;
                        return false;
                    }
                }
                //是.
                else
                {
                    //.并且可以拷贝，比较.之后的字符
                    if(matchValue.m_bCopy)
                    {
                        if(sIndex < s.length()-1)
                        {
                            //当前位置和下一个位置匹配
                            if(s[sIndex] == s[sIndex+1])
                            {
                                sIndex++;
                            }
                            //当前位置和下一个位置不匹配
                            else
                            {
                                sIndex++;
                                matchIndex++;
                            }
                        }
                        else
                        {
                            /* code */
                            sIndex++;
                        }
                        
                        if(matchIndex == matchVec.size()-1)
                        {
                            std::cout<<__LINE__<<std::endl;
                            return true;
                        }
                        else
                        {
                            std::cout<<__LINE__<<std::endl;
                            sIndex++;
                        }
                    }
                    else
                    {
                        //. 匹配任意字符
                        std::cout<<__LINE__<<std::endl;
                        matchIndex++;
                        sIndex++;
                    }
                }
            }
        }
        if(sIndex != s.length())
        {
            std::cout<<__LINE__<<std::endl;
            return false;
        }
        else 
        {
            if(matchIndex == matchVec.size())
            {
                std::cout<<__LINE__<<std::endl;
                return true;
            }
            else
            {
                while(matchIndex < matchVec.size())
                {
                    if(matchVec[matchIndex].m_bZero)
                    {
                        matchIndex++;
                    }
                    else
                    {
                        std::cout<<__LINE__<<std::endl;
                        return false;
                    }
                }
            }
        }
        std::cout<<__LINE__<<std::endl;
        return true;
    }
};


int main(int argc,char * argv[])
{
    Solution solu;
    /*if(solu.isMatch("aa","a"))
    {
        std::cout<<"bad"<<std::endl;
    }
    else
    {
        std::cout<<"good"<<std::endl;
    }

    if(solu.isMatch("aa","a*"))
    {
        std::cout<<"good"<<std::endl;
    }
    else
    {
        std::cout<<"bad"<<std::endl;
    }

    if(solu.isMatch("ab",".*"))
    {
        std::cout<<"good"<<std::endl;
    }
    else
    {
        std::cout<<"bad"<<std::endl;
    }
    
    if(solu.isMatch("aab","c*a*b"))
    {
        std::cout<<"good"<<std::endl;
    }
    else
    {
        std::cout<<"bad"<<std::endl;
    }*/

    if(solu.isMatch("mississippi","mis*is*p*."))
    {
       std::cout<<"good"<<std::endl;
    }
    else
    {
        std::cout<<"bad"<<std::endl;
    }
    return 0;
}