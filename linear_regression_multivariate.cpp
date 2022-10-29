#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class linear_model
{
    private:
    vector<vector<double>> features;
    vector<double> label;

    bool trained = false;

    vector<double> w;
    double b;

    int size = 0;
    int tot_features = 0;

    
    // double derivative_sum_w(double w, double b)
    // {
        
    // }

    // double derivative_sum_b(double w, double b)
    // {
        
    // }

    public:

    double cost(vector<double> w, double b)
    {
        double tot_squared_error = 0;
        for(int entry = 0; entry<size; entry++)
        {
            double dot_product = 0;
            for(int feature = 0; feature<tot_features; feature++)
            {
                dot_product += w[feature]*this->features[feature][entry];
            }
            double error = dot_product - this->label[entry] - b;
            tot_squared_error += error*error;
            cout<<error*error<<endl;
        }
        return tot_squared_error/(double)(2*size);
    }


    // void gradient_descent(double learning_rate)
    // {
        
    // }

    linear_model(vector<vector<double>> features, vector<double> label)
    {
        this->features = features;
        this->label = label;
        this->size = label.size();
        this->tot_features = features.size();
    }

    // double predict(double feature)
    // {
        
    // }

    bool initialise_data(vector<vector<double>> features, vector<double> label)
    {
        this->features = features;
        this->label = label;
        this->size = label.size();
        this->tot_features = features.size();
    }

    void show_data()
    {
        for(int entry=0; entry<size; entry++)
        {
            for(int feature=0; feature<tot_features; feature++)
            {
                cout<<features[feature][entry]<<" ";
            }
            cout<<"--> "<<label[entry]<<endl;
        }
    }

    vector<double> get_coeff() {return this->w;}
    double get_const() {return this->b;}
};


int main()
{
    vector<vector<double>> features = {
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3}
    };
    vector<double> label = {2, 3, 1};

    linear_model model(features, label);
    model.show_data();
    // model.gradient_descent(0.0001);

    cout<<model.cost({1, 1, 1}, 0);

    return 0;
}