#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class linear_model
{
    private:
    vector<double> feature;
    vector<double> label;
    double w, b;
    int size = 0;

    public:
    double cost(double w, double b)
    {
        double squared_error = 0;
        for(int i=0; i<size; i++) squared_error += (w*feature[i]+b - label[i])*(w*feature[i]+b - label[i]);
        return squared_error/(double)(2*size);
    }

    linear_model(vector<double> feature, vector<double> label)
    {
        if(feature.size()==label.size())
        {
            this->feature = feature;
            this->label = label;
            size = feature.size();
        }
    }

    bool initialise_data(vector<double> feature, vector<double> label)
    {
        if(feature.size()==label.size())
        {
            this->feature = feature;
            this->label = label;
            size = feature.size();
            return true;
        }
        return false;
    }

    void show_data()
    {
        for(int i=0; i<size; i++)
        {
            cout<<feature[i]<<" "<<label[i]<<endl;
        }
    }

    double get_coeff() {return this->w;}
    double get_const() {return this->b;}
};


int main()
{
    vector<double> f = {1.0, 2.0, 3.0};
    vector<double> b = {1.0, 2.0, 3.0};

    linear_model model(f, b);
    model.show_data();

    cout<<model.cost(1, 0);

    return 0;
}