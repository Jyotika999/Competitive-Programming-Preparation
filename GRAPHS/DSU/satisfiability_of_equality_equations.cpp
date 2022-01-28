class Solution {
public:
    
    // first of all combine all the equal ones,
    // then check if not equal wale pairs have same parent, i.e if they are in the same connected component 
    
    char parent[505];
    int r[505];
    
    char find_parent(char a)
    {
        if(a==parent[a])
        {
            return a;
        }
        return parent[a]=find_parent(parent[a]);
    }
    void unionn(char u, char v)
    {
        u = find_parent(u);
        v = find_parent(v);
        
        
        if(u!=v)
        {
            if(r[u]<r[v])
            {
                parent[u]=v;
            }   
            else if(r[u]>r[v])
            {
                parent[v]=u;
            }
            else
            {
                parent[u]=v;
                r[v]++;
            }
        
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        int n = equations.size();
        
        for(int i=0;i<26;i++)
        {
            parent[i+'a']=i+'a';
            r[i+'a']=0;
        }
        
        for(int i=0;i<n;i++)
        {
            char u = equations[i][0];
            char eq = equations[i][1];
            char v = equations[i][3];
            
            if(eq=='=')
            {
               
                  // should be in same components 
                unionn(u, v);
                cout<<parent[u]<<" "<<parent[v]<<"\n";
                
                // since they are equal
            }
           
        }
        
         for(int i=0;i<n;i++)
        {
            char u = equations[i][0];
            char eq = equations[i][1];
            char v = equations[i][3];
            
            if(eq=='!')
            {
               
                // check if already present in the same components 
                // tehn return false
                if(find_parent(u)==find_parent(v))
                    return false;
                
                // should be in different components
                // which will be already in dirreferent components
                // since we initialised it this way 
                
                
            }
           
        }
       
                
          return true;
    }
  
    
    // if a!=b , then we have to keep a and b in different connected components
    // if a=b , then we have to keep them in same components 
    
    
    
};