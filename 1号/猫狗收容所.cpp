class CatDogAsylum {
public:
    vector<int> asylum(vector<vector<int> > ope) {
        // write code here
        vector<int> pet;
        vector<int> ret;
        int sz = ope.size();
        for(int i = 0; i<sz; i++)
        {
            if(ope[i][0]==1)
                pet.push_back(ope[i][1]);
            else
            {
                if(!pet.empty())
                {
                    if(ope[i][1] == 0)
                    {
                        ret.push_back(pet[0]);
                        pet.erase(pet.begin());
                        
                    }
                    else if(ope[i][1] == 1)
                    {
                        //出狗
                        for(int j = 0; j<pet.size(); j++)
                        {
                            if(pet[j]>0)
                            {
                                ret.push_back(pet[j]);
                                pet.erase(pet.begin()+j);
                                break;
                            }
                        }
                    }
                    else
                    {
                        //出猫
                        for(int j = 0; j<pet.size(); j++)
                        {
                            if(pet[j]<0)
                            {
                                ret.push_back(pet[j]);
                                pet.erase(pet.begin()+j);
                                break;
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};