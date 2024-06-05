#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class WrongLabelsFormatException {
private:
    char *text;
public:
    WrongLabelsFormatException(const char *text) {
        this->text = new char[strlen(text) + 1];
        strcpy(this->text, text);
    }

    void showMessage() {
        cout << text;
    }
};

class Evaluator {
protected:
    char *pValue;
    char *tValue;
public:
    Evaluator(const char *trueCategory, const char *predictCategory) {
        if (strlen(trueCategory) != strlen(predictCategory)) {
            throw WrongLabelsFormatException("Labels must have the same lenght");
        }
        for (int i = 0; i < strlen(trueCategory); ++i) {
            if (!(trueCategory[i] == '-' || trueCategory[i] == '+' || predictCategory[i] == '-' ||
                  predictCategory[i] == '+')) {
                throw WrongLabelsFormatException("Labels must be + or -");
            }
        }
        this->tValue = new char[strlen(trueCategory) + 1];
        this->pValue = new char[strlen(predictCategory) + 1];
        strcpy(this->tValue, trueCategory);
        strcpy(this->pValue, predictCategory);
    }

    virtual double evaluate() = 0;

    virtual void print() = 0;

    bool operator>=(Evaluator &e) {
        return this->evaluate() >= e.evaluate();
    }
};

class AccuracyEvaluator : public Evaluator {
public:
    AccuracyEvaluator(const char *tValue, const char *pValue)
            : Evaluator(pValue, tValue) {}

    double evaluate() override {
        int br = 0;
        for (int i = 0; i < strlen(tValue); ++i) {
            if (tValue[i] == pValue[i]) {
                ++br;
            }
        }
        return (float) br / strlen(tValue);
    }

    void print() override {
        cout << "Number of data points: " << strlen(tValue) << " Prediction Accuracy: " << evaluate() << endl;
    }
};

class SensitivityEvaluator : public Evaluator {
public:
    SensitivityEvaluator(const char *tValue, const char *pValue)
            : Evaluator(pValue, tValue) {}

    double evaluate() override {
        int br = 0, brPos = 0;
        for (int i = 0; i < strlen(tValue); ++i) {
            if (tValue[i] == '+') {
                ++brPos;
                if (tValue[i] == pValue[i]) {
                    ++br;
                }
            }
        }
        return (float) br / brPos;
    }

    void print() override {
        cout << "Number of data points: " << strlen(tValue) << " Prediction Sensitivity: " << evaluate() << endl;
    }
};

Evaluator *highestScore(Evaluator **evaluators, int n) {
    Evaluator *max = evaluators[0];
    for (int i = 0; i < n; ++i) {
        if (*evaluators[i] >= *max) {
            max = evaluators[i];
        }
    }
    return max;
}


int main() {
    int testCase;
    char trueLabels[100];
    char predictedLabels[100];
    cin >> testCase;
    if (testCase == 1) {
        cout << "TESTING CREATION OF ACCURACY EVALUATOR. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;
        try{
            Evaluator *evaluator = new AccuracyEvaluator(trueLabels, predictedLabels);
            cout << evaluator->evaluate() << endl;
            evaluator->print();
        }
        catch (WrongLabelsFormatException e)
        {
            e.showMessage();
        }

    } else if (testCase == 2) {
        cout << "TESTING CREATION OF ACCURACY EVALUATOR. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;
        try
        {
            Evaluator *evaluator = new SensitivityEvaluator(trueLabels, predictedLabels);
            cout << evaluator->evaluate() << endl;
            evaluator->print();
        }
        catch (WrongLabelsFormatException e)
        {
            e.showMessage();
        }

    } else if (testCase == 3) {
        cout << "TESTING CREATION OF BOTH EVALUATORS. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;
        try {
            Evaluator *accuracy = new AccuracyEvaluator(trueLabels, predictedLabels);
            Evaluator *sensitivity = new SensitivityEvaluator(trueLabels, predictedLabels);
            accuracy->print();
            sensitivity->print();
        }
        catch (WrongLabelsFormatException e)
        {
            e.showMessage();
        }
    } else if (testCase == 4) {
        cout << "TESTING OPERATOR >=" << endl;
        cin >> trueLabels >> predictedLabels;
        Evaluator *accuracy = new AccuracyEvaluator(trueLabels, predictedLabels);
        Evaluator *sensitivity = new SensitivityEvaluator(trueLabels, predictedLabels);
        cin >> trueLabels >> predictedLabels;
        Evaluator *accuracy1 = new AccuracyEvaluator(trueLabels, predictedLabels);
        Evaluator *sensitivity1 = new SensitivityEvaluator(trueLabels, predictedLabels);

        accuracy->print();
        cout << (((*accuracy) >= (*sensitivity)) ? ">=" : "<") << endl;
        sensitivity->print();
        cout << endl;

        sensitivity->print();
        cout << (((*sensitivity) >= (*accuracy)) ? ">=" : "<") << endl;
        accuracy->print();
        cout << endl;

        accuracy->print();
        cout << (((*accuracy) >= (*accuracy1)) ? ">=" : "<") << endl;
        accuracy1->print();
        cout << endl;

        sensitivity->print();
        cout << (((*sensitivity) >= (*sensitivity1)) ? ">=" : "<") << endl;
        sensitivity1->print();
        cout << endl;
    } else {
        cout << "INTEGRATION TEST AND TESTING GLOBAL FUNCTION. EXCEPTION CAN HAPPEN HERE!" << endl;
        int n;
        cin >> n;
        Evaluator **evaluators = new Evaluator *[n];
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            cin >> trueLabels >> predictedLabels;
            try {
                if (type == 1) { //accuracy
                    evaluators[i] = new AccuracyEvaluator(trueLabels, predictedLabels);
                } else { //sensitivity
                    evaluators[i] = new SensitivityEvaluator(trueLabels, predictedLabels);
                }
            }
            catch (WrongLabelsFormatException e)
            {
                e.showMessage();
                --n;
                --i;
            }
        }

        cout << "PRINT ALL EVALUATORS FIRST!" << endl;
        for (int i = 0; i < n; i++) {
            evaluators[i]->print();
        }

        cout << "RESULT FROM HIGHEST SCORE METHOD" << endl;
        highestScore(evaluators, n)->print();
    }

}