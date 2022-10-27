#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class linear_model
{
    private:
    vector<double> feature;
    vector<double> label;
    bool trained = false;
    double w, b;
    int size = 0;

    double cost(double w, double b)
    {
        double squared_error = 0;
        for(int i=0; i<size; i++) squared_error += (w*feature[i]+b - label[i])*(w*feature[i]+b - label[i]);
        return squared_error/(double)(2*size);
    }

    double derivative_sum_w(double w, double b)
    {
        double error = 0;
        for(int i=0; i<size; i++) error += (w*feature[i]+b - label[i])*feature[i];
        return error/(double)(size);
    }

    double derivative_sum_b(double w, double b)
    {
        double error = 0;
        for(int i=0; i<size; i++) error += (w*feature[i]+b - label[i]);
        return error/(double)(size);
    }

    public:
    void gradient_descent(double learning_rate)
    {
        double w = 0, b = 0;
        double change = 1;
        double previous_cost = cost(w, b);
        while(change>=0.00001)
        {
            double _w = w - learning_rate*derivative_sum_w(w, b);
            double _b = b - learning_rate*derivative_sum_b(w, b);
            change = previous_cost - cost(_w, _b);
            previous_cost = cost(_w, _b);
            w = _w;
            b = _b;
            cout<<w<<" "<<b<<" "<<cost(w, b)<<endl;
        }
        this->w = w;
        this->b = b;
        trained = true;
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

    double predict(double feature)
    {
        if(trained) return (this->w)*feature + (this->b);
        return 0;
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
    model.gradient_descent(0.0001);

    cout<<model.predict(1.5);

    return 0;
}