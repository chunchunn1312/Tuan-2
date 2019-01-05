#include <iostream>
#include <fstream>

using namespace std;

class Question
{
    public:
        virtual void readFromFile(ifstream &fileInput) =0;
        virtual void printQuestion() =0;
        virtual bool getAnswer() =0;
};

class MultipleQuestion: public Question
{
    private:
        string question, choice[4];
        char correctAnswer;

    public:
        void readFromFile(ifstream &fileInput)
        {
            getline(fileInput, question);
            for (int i = 0; i < 4; i ++)
                getline(fileInput, choice[i]);
            fileInput >> correctAnswer;
        }

        void printQuestion()
        {
            cout << question << '\n';
            for (int i = 0; i < 4; i ++)
            {
            	
                char label = 'A' + i;
                cout << label << ": " << choice[i] << '\n';
            }
        }

        bool getAnswer()
        {
        	cout<<"Nhap dap an cua ban: ";
            char answer; cin >> answer;
            if (answer == correctAnswer)
            {
                cout << "Cau tra loi dung!\n";
                return true;
            }
            else
            {
                cout << "Cau tra loi sai! Cau tra loi dung la " << correctAnswer << '\n';
                return false;
            }
        }
};

class TrueFalse: public Question
{
    private:
        string question;
        char correctAnswer;

    public:
        void readFromFile(ifstream &fileInput)
        {
            getline(fileInput, question);
            fileInput >> correctAnswer;
        }

        void printQuestion()
        {
            cout << question << " (T/F)\n";
        }

        bool getAnswer()
        {
        	cout<<"Nhap dap an cua ban: ";
            char answer; cin >> answer;
            if (answer == correctAnswer)
            {
                cout << "Cau tra loi dung!\n";
                return true;
            }
            else
            {
                cout << "Cau tra loi sai! Cau tra loi dung la " << correctAnswer << '\n';
                return false;
            }
        }
};

class NumberQuestion: public Question
{
    private:
        string question;
        double correctAnswer;

    public:
        void readFromFile(ifstream &fileInput)
        {
            getline(fileInput, question);
            fileInput >> correctAnswer;
        }

        void printQuestion()
        {
            cout << question << endl;
        }

        bool getAnswer()
        {
        	cout<<"Nhap dap an cua ban: ";
            double answer; cin >> answer;
            if (answer == correctAnswer)
            {
                cout << "Cau tra loi dung!\n";
                return true;
            }
            else
            {
                cout << "Cau tra loi sai! Cau tra loi dung la " << correctAnswer << '\n';
                return false;
            }
        }
};

char fileName[100];
int n, correctAnswer = 0; /* correctAnswer là s? lu?ng câu tr? l?i dúng */
Question *allQuestion[1000];

int main()
{
    cout << "Hay nhap file cau hoi: ";
    cin >> fileName;

    ifstream fileInput; fileInput.open(fileName);
    fileInput >> n;
    for (int i = 1; i <= n; i ++)
    {
        char questionType;
        fileInput >> questionType;
        
        string temp; getline(fileInput, temp); 
        if (questionType == 'M')
            allQuestion[i] = new MultipleQuestion;
        if (questionType == 'T')
            allQuestion[i] = new TrueFalse;
        if (questionType == 'N')
            allQuestion[i] = new NumberQuestion;
        allQuestion[i]->readFromFile(fileInput);
    }

    for (int i = 1; i <= n; i ++)
    {
        allQuestion[i]->printQuestion();
        if (allQuestion[i]->getAnswer())
            correctAnswer ++;
    }

    cout << "So luong cau tra loi dung: " << correctAnswer;
    return 0;
}
