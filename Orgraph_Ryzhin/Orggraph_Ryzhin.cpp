#include <iostream>
#include <fstream>
#include <random>

using namespace std;

const int INF = (int)1e9;

//сортування бульбашкою
void  sorted(int n, float a[100][3]){
    float temp;
    int b;
    for (int i = 0;i<n-1 ; i++){
        for( int j = 0; j<n-i-1;j++){
            if (a[j][2]>a[j+1][2]){
                temp = a[j][2];
                a[j][2]= a[j+1][2];
                a[j+1][2]=temp;
                for(int k = 0;k<2;k++){
                    b=a[j][k];
                    a[j][k]=a[j+1][k];
                    a[j+1][k]=b;
                }
            }
        }
    }
}
int more_than_zero(int n, float a[100][100], int j){
    int res = 0;
    for (int i=0;i<n;i++)
        if (a[j][i]>0) res++;
    }
class Orgraph// Клас для роботи з orgграфом
{
    int Count; // count of tops
    float Mass[100][100];// anrray
    float List[10000][3];// list
    int M;
    public:
    Orgraph(int n, float mass[100][100]){//  constructor graph with matrix
        M=0;
        Count = n;
        for (int i = 0; i < Count; i++)
            for (int j = 0; j < Count; j++)
            {
                Mass[i][j]=mass[i][j];
                if ((mass[i][j]!=0)&&(i!=j)){
                    List[M][0] = i+1;
                    List[M][1] = j+1;
                    List[M][2] = mass[i][j];
                    M++;
                }
            }
    }

    Orgraph( int n,int m,int mass [100][100],float c[10000]){// constructor list of edge
        M = m;
        Count = n ;
        for (int i = 0; i < M; i++)
        {
            Mass[mass[i][0]-1][mass[i][1]-1]=c[i];
            List[i][1] = mass[i][1];
            List[i][0] = mass[i][0];
            List[i][2] = c[i];
        }
    }

    Orgraph()//випадкове створення графу
    {
        Count = rand()%10 +1;
        for (int i=0;i<Count;i++)
            for (int j=0;j<Count;j++)
        {
            if (i==j) Mass[i][j] = 0;
            if (i!=j) Mass[i][j] = (rand ()%1000)/100.0;
        }
    }
    void show_graph_matr(){// виведення графу у вигляді матриці в консоль
        cout<<"Виведення графу у вигляді матриці"<<endl;
        for (int i = 0; i< Count; i++)
        {
            for (int j=0;j< Count ; j++)
                cout<< Mass[i][j]<<" ";
        cout<<endl;
        }
    }
    void show_to_file(){// виведення графу у вигляді матриці в файл
        ofstream fout ("show_graph.txt");
        for (int i = 0; i< Count; i++)
        {
            for (int j=0;j< Count ; j++)
                fout<< Mass[i][j]<<" ";
        fout<<endl;
        }
    }
    void show_graph_list(){// виведення графу у вигляді списку в консоль
      cout<<"Виведення графу у вигляді списку"<<endl;
      for (int i = 0;i< M; i++){
            cout<<List[i][0]<<" — "<<List[i][1]<<" "<<List[i][2]<<endl;
      }

    }

    /*алгоритм виділення остовного підграфа-дерева (дерево, що містить всі вершини
    графа та є підграфом даного графу, при цьому має найменшу вагу серед можливих).*/

    void Kassel(){
        cout << "Algotithm Krasskal: "<<endl;
        float cost=0;
        sorted(M,List);
        int res[100][2];
        int k = 0;
        int tree_id [100000];
        for(int i = 1; i<Count+1; i++)
            tree_id[i]=i;
        for (int i = 0; i<M;i++){
            int a = (int) List[i][0],b=(int) List[i][1];
            float l = List[i][2];
            if (tree_id[a]!=tree_id[b]){
            cost +=l;
            res[k][0]=a;
            res[k][1]=b;
            k++;
            int old_id =tree_id[b],new_id=tree_id[a];
            for(int j = 1;j<Count+1;j++){
                if (tree_id[j] ==old_id)
                    tree_id[j] =new_id;
            }
            }
        }
    cout<<"min cost = "<<cost<<endl<<"Way:"<<endl;
    for (int i = 0;i<k;i++)
        cout<<res[i][0]<<" "<<res[i][1]<<endl;
    }
    void test1_1 (){
    ofstream fout ("test1_out.txt");
    fout<<"As list: "<<endl;
    for (int i = 0;i< M; i++){
            fout<<List[i][0]<<" "<<List[i][1]<<" "<<List[i][2]<<endl;
      }
    fout<<endl;

    fout << "Algotithm Krasskal: "<<endl;
        float cost=0;
        sorted(M,List);
        int res[100][2];
        int k = 0;
        int tree_id [100000];
        for(int i = 1; i<Count+1; i++)
            tree_id[i]=i;
        for (int i = 0; i<M;i++){
            int a = (int) List[i][0],b=(int) List[i][1];
            float l = List[i][2];
            if (tree_id[a]!=tree_id[b]){
            cost +=l;
            res[k][0]=a;
            res[k][1]=b;
            k++;
            int old_id =tree_id[b],new_id=tree_id[a];
            for(int j = 1;j<Count+1;j++){
                if (tree_id[j] ==old_id)
                    tree_id[j] =new_id;
            }
            }
        }
    fout<<"min cost = "<<cost<<endl<<"Way:"<<endl;
    for (int i = 0;i<k;i++)
        fout<<res[i][0]<<" "<<res[i][1]<<endl;
    }
};


class Graph{
    int Count; // кількість точок
    float Mass[100][100];// граф у вигляді масиву
    float List[100][3];// граф у вигляді списку
    int M;
    public:
    vector<int> comp;
    bool used[100];
    Graph( int n,int m,int mass [100][100],float c[10000]){// конструктор для введення графу
        M = m;
        Count = n ;
        for (int i = 0; i < M; i++)
        {
            Mass[mass[i][0]-1][mass[i][1]-1]=c[i];
            Mass[mass[i][1]-1][mass[i][0]-1]=c[i];
            List[i][1] = mass[i][1];
            List[i][0] = mass[i][0];
            List[i][2] = c[i];
        }
    }
    void show_graph_matr()// виведення графу у вигляді матриці в консоль
    {
        for (int i = 0; i< Count; i++)
        {
            for (int j=0;j< Count ; j++)
                cout<< Mass[i][j]<<" ";
        cout<<endl;
        }
    }

    void dfs (int v){//пошук у глубину
        used[v]=true;
        comp.push_back(v);
        for (int i=0;i<Count;i++){
            int to=Mass[v][i];
            if((!used[i])&&(to!=0))
                dfs(i);
        }
    }
    /*Визначення кількості зв’язних компонент цього графу*/
    void find_comps(){
    int g = 1;
    for (int i=0;i<Count;i++)
        used[i]=false;
    for (int i=0;i<Count;i++)
        if (!used[i]){
            comp.clear();
            dfs(i);
            cout<<"Component:";
            for(int j=0;j<comp.size();j++)
                cout<<" "<<comp[j]+1;
            cout<<endl;
            g++;
        }
    cout<<"Count of component = "<<g-1<<endl;
    }

void floyd(vector<vector<float> > &g, vector<int> &comp){
  int i, j, k;
  for(k = 0; k < comp.size(); k++)
    for(i = 0; i < Count; i++)
      for(j = 0; j < Count; j++)
        if (g[i][comp[k]] + g[comp[k]][j] < g[i][j])
          g[i][j] = g[i][comp[k]] + g[comp[k]][j];
}



pair<int, vector<vector<float> > > getDiamtr(vector<int> &comp){//найти діаметр (тобто найдовший шлях без циклу).
    vector<vector<float> > cpMass(100, vector<float> (100));
    for(int i = 0; i < Count; i++)
        for(int j = 0; j < Count; j++){
            if (Mass[i][j] == 0) cpMass[i][j] = INF;
            else cpMass[i][j] = 1;
        }

    floyd(cpMass, comp);
    int diam = 0;
    for(int i = 0; i < Count; i++){
      int maxi = 0;
      for(int j = 0; j < Count; j++)
        if (cpMass[i][j] > maxi && cpMass[i][j] != INF) maxi = cpMass[i][j];
      diam = max(maxi, diam);
    }
    return make_pair(diam, cpMass);
}

int getMaxDistForm(int v, vector<vector<float> > &g){//Знайти найбільш віддалену від даної вершини вершину (тобто найбільшу серед мінімальних суму ваг при умові зв’язності графу).
    int maxDist = 0;
    for(int j = 0; j < Count; j++)
        if (g[v][j] > maxDist && g[v][j] != INF) maxDist = g[v][j];
    return maxDist;
}

void find_comps2(){
    pair<int, vector<vector<float> > >  a;
    int maxi1 =0;
    int j=1;
    for (int i=0;i<Count;i++)
        used[i]=false;
    for (int i=0;i<Count;i++)
        if (!used[i]){
            comp.clear();
            dfs(i);
            a = getDiamtr(comp);
            cout<<" Diametr comp "<<j<<" ="<<a.first<<endl;
            j++;
            for (int k =0;k<comp.size();k++)
                maxi1= max(maxi1,getMaxDistForm(comp[k],a.second));
        }
    cout<<"Maxi distance = "<<maxi1;
    }
void test2_2(){
    ofstream fout ("test2_out.txt");
    int g = 1;
    for (int i=0;i<Count;i++)
        used[i]=false;
    for (int i=0;i<Count;i++)
        if (!used[i]){
            comp.clear();
            dfs(i);
            fout<<"Component:";
            for(int j=0;j<comp.size();j++)
                fout<<" "<<comp[j]+1;
            fout<<endl;
            g++;
        }
    fout<<"Count of component = "<<g-1<<endl;

    pair<int, vector<vector<float> > >  a;
    int maxi1 =0;
    int j=1;
    for (int i=0;i<Count;i++)
        used[i]=false;
    for (int i=0;i<Count;i++)
        if (!used[i]){
            comp.clear();
            dfs(i);
            a = getDiamtr(comp);
            fout<<" Diametr comp "<<j<<" ="<<a.first<<endl;
            j++;
            for (int k =0;k<comp.size();k++)
                maxi1= max(maxi1,getMaxDistForm(comp[k],a.second));
        }
    fout<<"Maxi distance = "<<maxi1;
    fout.close();
    }
};
Orgraph enter_as_matrix_org(){
    int n,m;
    float a[100][100];
    cout<<"Enter number of tops: ";
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    return Orgraph(n,a);
    }
Orgraph enter_as_list_org(){
    int n,m;
    float a[10000];
    int c[100][100];
    cout<<"Enter number of tops: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    for(int i=0;i<m;i++)
            cin>>c[i][0]>>c[0][1]>>a[i];
    return Orgraph(n,m,c,a);
}
Orgraph enter_from_file_org(){
    ifstream fin ("test1_in.txt");
    int n,m;
    float a[100][100];
    fin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fin>>a[i][j];
    fin.close();
    return Orgraph(n,a);

    }
Graph enter_as_list_g(){
    int n,m;
    float a[100];
    int c[100][100];
    cout<<"Enter number of tops: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    for(int i=0;i<m;i++)
            cin>>c[i][0]>>c[i][1]>>a[i];
    return Graph(n,m,c,a);
}
Graph enter_as_list_g_file(){
    ifstream fin ("test2_in.txt");
    int n,m;
    float a[100];
    int c[100][100];
    fin>>n;
    fin>>m;
    for(int i=0;i<m;i++)
            fin>>c[i][0]>>c[i][1]>>a[i];
    fin.close();
    return Graph(n,m,c,a);
}
void test1()
{
    Orgraph G = enter_from_file_org();
    G.test1_1();
    }
void test2(){
    Graph G = enter_as_list_g_file();
    G.test2_2();
    }
int main(){
    bool flag = true;
    while (flag){
    char c ;
    Orgraph G;
    cout<<"Enter regim:"<<endl;
    cout<<"1 - enter orgraph like a matrix"<<endl;
    cout<<"2 - enter orgraph like a list"<<endl;
    cout<<"4 - make a random orgraph"<<endl;
    cout<<"5 - enter graph like a list "<<endl;
    cout<<"6 - make test 1"<<endl;
    cout<<"7 - make test 2"<<endl;
    cout<<"0 - exit"<<endl;
    cin>>c;
    if (c == '0') flag = false;
    if (c == '1'){ Orgraph G = enter_as_matrix_org();
    G.show_graph_matr();
    G.show_graph_list();
    G.show_to_file();
    G.Kassel();
    }
    if (c == '2'){ Orgraph G = enter_as_list_org();
    G.show_graph_matr();
    G.show_graph_list();
    G.show_to_file();
    G.Kassel();
    }
    if (c == '4') {Orgraph G = enter_from_file_org();
    G.show_graph_matr();
    G.show_graph_list();
    G.show_to_file();
    G.Kassel();
    }
    if (c == '5'){
        Graph D = enter_as_list_g();
        D.show_graph_matr();
        D.find_comps();
        D.find_comps2();
        continue;
    }
    if (c== '6'){
        test1();
        }
    if (c =='7') test2();
    }
    return 0;
}
