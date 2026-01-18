#include <iostream>
#include <string>
#include <sstream>
#include <thread>   
#include <chrono>   
#include <windows.h>
#include <vector>

using namespace std;

// ===================== GRAPHICS HELPER MODULE ===================== //
class Graphics {
private:
    static int getCenteredX(const string& text) {

        return 40 - (text.length() / 2);
    }

    static void drawHeader(string title) {
        int x_pos = getCenteredX(title);
        
        setColor(BRIGHT_CYAN);
        
        gotoxy(x_pos - 10, 1);
        cout << "=======================================================";
        
        gotoxy(x_pos, 2);
        cout << title;
        
        gotoxy(x_pos - 10, 3);
        cout << "=======================================================";
        
        
        gotoxy(1, 5); 
        
        setColor(BRIGHT_WHITE);
    }
    
    static void drawStickman(int x, int y, int frame) {
       
        for(int i = 0; i < 4; i++) {
            gotoxy(x, y + i);
            cout << "      ";
        }

      
        if (frame % 4 == 0) {
           
            gotoxy(x, y+1); cout << " O";
            gotoxy(x, y+2); cout << "/|\\";
            gotoxy(x, y+3); cout << "/ \\";
        } else if (frame % 4 == 1) {
           
            gotoxy(x, y+1); cout << " O";
            gotoxy(x, y+2); cout << "/|\\";
            gotoxy(x, y+3); cout << "/_\\";
        } else if (frame % 4 == 2) {
          
            gotoxy(x, y+1); cout << " O";
            gotoxy(x, y+2); cout << "/|\\";
            gotoxy(x, y+3); cout << "/ \\";
        } else {
           
            gotoxy(x, y+1); cout << " O";
            gotoxy(x, y+2); cout << "/|\\";
            gotoxy(x, y+3); cout << "\\/ ";
        }
    }


public:
    // Color Codes
    static const int BLUE = 1;
    static const int GREEN = 2;
    static const int RED = 4;
    static const int PURPLE = 5;
    static const int YELLOW = 6;
    static const int WHITE = 7;
    static const int CYAN = 3;
    static const int BRIGHT_WHITE = 15;
    static const int BRIGHT_CYAN = 11;
    static const int BRIGHT_GREEN = 10;
    static const int BRIGHT_RED = 12;
    static const int BRIGHT_YELLOW = 14;

    static void setColor(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }

    static void gotoxy(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    static void drawLine(int width, char symbol = '-') {
        for (int i = 0; i < width; i++) cout << symbol;
        cout << endl;
    }

    static void typeWrite(string text, int speed = 20) {
        for (char c : text) {
            cout << c;
            this_thread::sleep_for(chrono::milliseconds(speed));
        }
        cout << endl;
    }

    static void loadingBar(string taskName) {
        system("cls"); 
        gotoxy(30, 10);
        setColor(BRIGHT_CYAN);
        cout << taskName;
        gotoxy(30, 11);
        setColor(WHITE);
        cout << "[";
        for (int i = 0; i < 40; i++) {
            setColor(BRIGHT_GREEN);
            cout << "=";
            setColor(WHITE);
            this_thread::sleep_for(chrono::milliseconds(10)); 
        }
        cout << "]";
        this_thread::sleep_for(chrono::milliseconds(100)); 
        setColor(BRIGHT_WHITE);
        system("cls");
    }

    // Header Display 
    static void printHeader(string title) {
        system("cls");
        drawHeader(title);
    }
    
    static void printQuizHeader(string title) {
        system("cls");
        drawHeader(title);
    }


    static void splashScreen() {
        system("cls");
        
        int x_base = getCenteredX(" _____");
        
        setColor(BRIGHT_CYAN);
        gotoxy(x_base, 3);
        cout << "   _____                         \n";
        gotoxy(x_base, 4);
        cout << "  / ____|                        \n";
        gotoxy(x_base, 5);
        cout << " | |     __ _ _ __ ___  ___ _ __ \n";
        gotoxy(x_base, 6);
        cout << " | |    / _` | '__/ _ \\/ _ \\ '__|\n";
        gotoxy(x_base, 7);
        cout << " | |___| (_| | | |  __/  __/ |   \n";
        gotoxy(x_base, 8);
        cout << "  \\_____\\__,_|_|  \\___|\\___|_|   \n";
        
        gotoxy(x_base + 3, 10); 
        cout << "L  A  D  D  E  R"; 

        setColor(BRIGHT_GREEN);
        gotoxy(30, 12);
        typeWrite("Constructing your future path...", 40);
        
        this_thread::sleep_for(chrono::seconds(1));
        loadingBar("Initializing System");
    }
    
    static void climbingScreen() {
        system("cls");
        
        int x_center = getCenteredX(" | | | |"); 
        int ladder_width = 8;
        int stickman_start_y = 18;
        int animation_frames = 28;
        int delay = 100;

        setColor(BRIGHT_CYAN);
        for(int y = 5; y <= 19; y++) {
            gotoxy(x_center, y);
            cout << "|";
            gotoxy(x_center + ladder_width - 1, y);
            cout << "|";
        }
        for(int y = 5; y <= 18; y += 2) {
            gotoxy(x_center + 1, y);
            cout << "=====";
        }


        setColor(BRIGHT_YELLOW);
        gotoxy(x_center - 10, 3);
        cout << "ASCENDING TO SUCCESS";
        
        
        for (int frame = 0; frame < animation_frames; frame++) {
            setColor(BRIGHT_WHITE);
            
            int current_y = stickman_start_y - (frame / 2);
            
            drawStickman(x_center + 1, current_y, frame);
            
            if (frame >= 2 && frame % 2 == 0) {
            	
                int prev_rung_y = stickman_start_y - ((frame - 2) / 2) + 2; 
                if (prev_rung_y <= 18) {
                    setColor(BRIGHT_CYAN);
                    gotoxy(x_center + 1, prev_rung_y);
                    cout << "=====";
                }
            }

            int stepping_rung_y = current_y + 2;
            if (stepping_rung_y >= 5 && stepping_rung_y <= 18) {
                 setColor(BRIGHT_RED);
                 gotoxy(x_center + 1, stepping_rung_y);
                 cout << "=====";
            } else if (current_y <= 5) {
                setColor(BRIGHT_CYAN);
                gotoxy(x_center + 1, 5);
                cout << "=====";
            }

            
            setColor(BRIGHT_GREEN);
            gotoxy(x_center - 10, 22);
            cout << "Loading Career Ladder System...";
            this_thread::sleep_for(chrono::milliseconds(delay));
        }
        
        int star_y = 5;
        int star_x = x_center + 10;
        int star_colors[] = {BRIGHT_YELLOW, BRIGHT_WHITE, BRIGHT_CYAN};
        
        for(int flash = 0; flash < 6; flash++) {
            for(int i = 0; i < 3; i++) {
                setColor(star_colors[(flash + i) % 3]);
                gotoxy(star_x + i * 2, star_y - 1);
                cout << "*";
                this_thread::sleep_for(chrono::milliseconds(70));
            }
        }

        system("cls");
    }
    
    static void quizTransition() {
        system("cls"); 
    }
};

// ===================== MODULE 1 - Quiz ===================== //
class points{
    private:
        int engineering;
        int medical;
        int business;
        int it;
        int arts;
    public:
        points():engineering(0),medical(0),business(0),it(0),arts(0){}
        points(int e,int m,int b,int i,int a):engineering(e),medical(m),business(b),it(i),arts(a){}
        friend class score;
        points operator +(const points s){
            points temp;
            temp.engineering = engineering + s.engineering;
            temp.medical     = medical     + s.medical;
            temp.business    = business    + s.business;
            temp.it          = it          + s.it;
            temp.arts        = arts        + s.arts;
            return temp;
        }
        points& operator +=(points s1){
            engineering += s1.engineering;
            medical     += s1.medical;
            business    += s1.business;
            it          += s1.it;
            arts        += s1.arts;
            return *this;
        }
};

class question{
    protected:
        string text;
        string options[4];
        points p[4];
    public:
        virtual void ask(){
            Graphics::setColor(Graphics::BRIGHT_CYAN);
            cout << text << endl;
            Graphics::setColor(Graphics::WHITE);
            for(int i=0;i<4;i++){
                cout << "  " << (i + 1) << ") " << options[i] << endl;
            }
        }
        virtual points getpoints(int choice){
            if(choice>=1 && choice<=4){
                return p[choice-1];
            }
            return points();
        }
        virtual ~question() {};
};

class q1:public question{
    public:
        q1(){
            text = "1. What is your academic background?";
            options[0] = "Science";
            options[1] = "Commerce";
            options[2] = "Arts";
            options[3] = "Computer Science";
            p[0] = points(3, 3, 1, 2, 1);
            p[1] = points(1, 0, 4, 0, 1);
            p[2] = points(0, 0, 1, 0, 4);
            p[3] = points(3, 0, 1, 4, 0);
        }
};

class q2:public question{
    public:
        q2(){
            text = "2. Which subject do you like the most?";
            options[0] = "Math";
            options[1] = "Biology";
            options[2] = "Business Studies / Economics";
            options[3] = "Computer / Programming";
            p[0] = points(4, 1, 1, 2, 0);
            p[1] = points(0, 4, 0, 0, 0);
            p[2] = points(0, 0, 4, 0, 0);
            p[3] = points(2, 0, 1, 4, 0);
        }
};

class q3:public question{
    public:
        q3(){
            text = "3. What is your main goal?";
            options[0] = "Become an engineer";
            options[1] = "Become a doctor / medical professional";
            options[2] = "Start or run a business";
            options[3] = "Work in software / IT";
            p[0] = points(5, 0, 0, 1, 0);
            p[1] = points(0, 5, 0, 0, 0);
            p[2] = points(0, 0, 5, 0, 0);
            p[3] = points(1, 0, 1, 5, 0);
        }
};

class q4:public question{
    public:
        q4(){
            text = "4. Are you good in Math?";
            options[0] = "Yes, very good";
            options[1] = "Average";
            options[2] = "Not good";
            options[3] = "I dislike math";
            p[0] = points(4, 1, 1, 3, 0);
            p[1] = points(2, 2, 1, 1, 0);
            p[2] = points(0, 3, 2, 0, 1);
            p[3] = points(0, 1, 1, 0, 3);
        }
};

class q5:public question{
    public:
        q5(){
            text = "5. Which activity do you like the most?";
            options[0] = "Solving technical problems / experiments";
            options[1] = "Helping people / healthcare tasks";
            options[2] = "Leading teams / business planning";
            options[3] = "Creative designing / arts";
            p[0] = points(4, 0, 1, 3, 0);
            p[1] = points(0, 4, 1, 0, 0);
            p[2] = points(1, 0, 5, 0, 0);
            p[3] = points(0, 0, 1, 0, 4);
        }
};

class q6:public question{
    public:
        q6(){
            text = "6. When solving problems, you prefer?";
            options[0] = "Logical, formula-driven approach";
            options[1] = "Research and experiments";
            options[2] = "Market/customer-driven solutions";
            options[3] = "Creative, out-of-the-box solutions";
            p[0] = points(4, 1, 1, 3, 0);
            p[1] = points(2, 4, 0, 1, 0);
            p[2] = points(1, 0, 4, 0, 1);
            p[3] = points(0, 0, 1, 1, 4);
        }
};

class q7:public question{
    public:
        q7(){
            text = "7. Which best describes you?";
            options[0] = "Analytical / Detail oriented";
            options[1] = "Compassionate / Caregiver";
            options[2] = "Ambitious / Risk-taker";
            options[3] = "Imaginative / Expressive";
            p[0] = points(4, 1, 1, 2, 0);
            p[1] = points(0, 4, 1, 0, 1);
            p[2] = points(1, 0, 4, 1, 0);
            p[3] = points(0, 0, 1, 0, 4);
        }
};

class q8:public question{
    public:
        q8(){
            text = "8. Which outcome gives you most satisfaction?";
            options[0] = "Designing and building systems";
            options[1] = "Saving/helping someone's life";
            options[2] = "Growing a company or profit";
            options[3] = "Creating art or content";
            p[0] = points(4, 0, 1, 3, 0);
            p[1] = points(0, 5, 0, 0, 0);
            p[2] = points(0, 0, 5, 0, 0);
            p[3] = points(0, 0, 1, 0, 4);
        }
};

class q9:public question{
    public:
        q9(){
            text = "9. What is your biggest fear?";
            options[0] = "Failing technical tests / calculations";
            options[1] = "Seeing injuries or blood";
            options[2] = "Losing money / business failure";
            options[3] = "Criticism of my creativity";
            p[0] = points(1, 0, 0, 2, 0);
            p[1] = points(0, 4, 0, 0, 0);
            p[2] = points(0, 0, 4, 0, 0);
            p[3] = points(0, 0, 0, 0, 4);
        }
};

class q10:public question{
    public:
        q10(){
            text = "10. Which of the following you consider most boring?";
            options[0] = "Long technical calculations (heavy theory)";
            options[1] = "Detailed memorization of medical facts";
            options[2] = "Endless spreadsheets and planning";
            options[3] = "Repetitive manual drawing / craft";
            p[0] = points(1, 0, 0, 0, 3);
            p[1] = points(0, 1, 0, 0, 2);
            p[2] = points(0, 0, 1, 1, 0);
            p[3] = points(0, 0, 0, 0, 1);
        }
};

class score{
    private:
        points total;
    public:
        score():total(){}
        void add(const points &w){
            total += w;
        }
        string recomend(){
            int e = total.engineering;
            int m = total.medical;
            int b = total.business;
            int i = total.it;
            int a = total.arts;
            int maxi = 0;
            if(e>maxi){maxi=e;}
            if(m>maxi){maxi=m;}
            if(b>maxi){maxi=b;}
            if(i>maxi){maxi=i;}
            if(a>maxi){maxi=a;}
            string result = "";
            bool first=true;
            if(e == maxi) { if(!first) result += ", "; result += "Engineering"; first = false; }
            if(m == maxi) { if(!first) result += ", "; result += "Medical"; first = false; }
            if(b == maxi) { if(!first) result += ", "; result += "Business"; first = false; }
            if(i == maxi) { if(!first) result += ", "; result += "IT"; first = false; }
            if(a == maxi) { if(!first) result += ", "; result += "Arts"; first = false; }
            return result;
        }
        void showtotal() {
            Graphics::setColor(Graphics::BRIGHT_CYAN);
            cout << fixed;
            cout << "\nAnalysis Result Points:\n";
            cout << "Totals -> Engineering: " << total.engineering << endl;
            cout << "          Medical: " << total.medical << endl;
            cout << "          Business: " << total.business << endl;
            cout << "          IT: " << total.it << endl;
            cout << "          Arts: " << total.arts << endl;
            Graphics::setColor(Graphics::WHITE);
        }
};

// ===================== MODULE 2 - Field Recommendation ===================== //
class FieldRecommender {
    public:
        virtual void showRecommendation() const = 0;
        virtual ~FieldRecommender() {}
};
class EngineeringRecommender : public FieldRecommender {
    public:
        void showRecommendation() const override {
            Graphics::setColor(Graphics::BRIGHT_CYAN);
            cout << "[ Engineering ]\n" ;
            Graphics::setColor(Graphics::WHITE);
            cout << "You have strong analytical and problem-solving skills.\n";
            cout << "Recommended fields: Mechanical, Electrical, Civil, Software, Chemical Engineering.\n";
            cout << "Typical roles: Engineer, Project Designer, Analyst, Researcher.\n";
            cout << "Engineering fits those who love logic, design, and technology.\n";
        }
};
class Healthsciencesrecommender : public FieldRecommender {
    public:
        void showRecommendation() const override {
            Graphics::setColor(Graphics::BRIGHT_GREEN);
            cout << "[ Medical / Health Sciences ]\n";
            Graphics::setColor(Graphics::WHITE);
            cout << "You show compassion and interest in helping people.\n";
            cout << "Recommended fields: Medicine, Pharmacy, Nursing, Biotechnology.\n";
            cout << "Typical roles: Doctor, Nurse, Pharmacist, Medical Researcher.\n";
            cout << "This field suits those who are patient, disciplined, and empathetic.\n";
        }
};
class BusinessRecommender : public FieldRecommender {
    public:
        void showRecommendation() const override {
            Graphics::setColor(Graphics::BRIGHT_CYAN);
            cout << "[ Business & Management ]\n";
            Graphics::setColor(Graphics::WHITE);
            cout << "You enjoy leadership, planning, and taking calculated risks.\n";
            cout << "Recommended fields: BBA, MBA, Marketing, Finance, Entrepreneurship.\n";
            cout << "Typical roles: Business Analyst, Manager, Entrepreneur, Consultant.\n";
            cout << "This path fits ambitious and strategic thinkers.\n";
        }
};
class ITRecommender : public FieldRecommender {
    public:
        void showRecommendation() const override {
            Graphics::setColor(Graphics::BRIGHT_CYAN);
            cout << "[ Information Technology ]\n";
            Graphics::setColor(Graphics::WHITE);
            cout << "You have logical thinking and interest in computers or coding.\n";
            cout << "Recommended fields: BSCS, Software Engineering, AI, Data Science, Cybersecurity.\n";
            cout << "Typical roles: Developer, IT Analyst, Data Engineer, Network Specialist.\n";
            cout << "IT is perfect for those who like innovation and modern tech.\n";
        }
};
class ArtsRecommender : public FieldRecommender {
    public:
        void showRecommendation() const override {
            Graphics::setColor(Graphics::PURPLE);
            cout << "[ Arts & Creative Fields ]\n";
            Graphics::setColor(Graphics::WHITE);
            cout << "You are imaginative and like expressing yourself visually or verbally.\n";
            cout << "Recommended fields: Fine Arts, Media Studies, Fashion Design, Literature.\n";
            cout << "Typical roles: Artist, Designer, Writer, Actor, Creative Director.\n";
            cout << "Arts is ideal for those who value originality and expression.\n";
        }
};

void showFieldDetails(string fields) {
    stringstream obj(fields);
    string field;
    while (getline(obj, field, ',')) {
        if(field == "Engineering") { EngineeringRecommender rec; rec.showRecommendation(); }
        else if(field == "Medical") { Healthsciencesrecommender rec; rec.showRecommendation(); }
        else if(field == "Business") { BusinessRecommender rec; rec.showRecommendation(); }
        else if(field == "IT") { ITRecommender rec; rec.showRecommendation(); }
        else if(field == "Arts") { ArtsRecommender rec; rec.showRecommendation(); }
    }
}

// ===================== MODULE 3 - Universities ===================== //
class University {
    private:
        string name;
        string location;
        string admissionCriteria;
        int fee;
    public:
        University(string n, string loc, string criteria, int f) {
            name = n;
            location = loc;
            admissionCriteria = criteria;
            fee = f;
        }
        void show() {
            Graphics::setColor(Graphics::BRIGHT_CYAN);
            cout << "University Name: " << name << endl;
            Graphics::setColor(Graphics::WHITE);
            cout << "Location: " << location << endl;
            cout << "Admission Criteria: " << admissionCriteria << endl;
            cout << "Fee Structure: " << fee << " PKR" << endl << endl;
        }
};

class Field {
    public:
        virtual void showUniversities() = 0;
};

class Engineering : public Field {
    public:
        void showUniversities() override {
            Graphics::setColor(Graphics::BRIGHT_CYAN);
            cout << "=========== ENGINEERING UNIVERSITIES ===========" << endl;
            Graphics::setColor(Graphics::WHITE);
            
            University u1("UET Lahore", "Lahore", "ECAT Required", 150000);
            University u2("NUST", "Islamabad", "NUST Entry Test", 180000);
            University u3("PIEAS", "Islamabad", "PIEAS Test", 160000);
            
            u1.show(); 
            u2.show();
            u3.show();
            
            Graphics::setColor(Graphics::BRIGHT_GREEN);
            cout << "Top-Ranked University for Engineering:" << endl;
            u1.show();
        }
};

class Medical : public Field {
    public:
        void showUniversities() override {
            Graphics::setColor(Graphics::BRIGHT_GREEN);
            cout << "=========== MEDICAL UNIVERSITIES ===========" << endl;
            Graphics::setColor(Graphics::WHITE);
            
            University u1("KEMU", "Lahore", "MDCAT Required", 200000);
            University u2("AKUH", "Karachi", "AKUH Test", 250000);
            University u3("DUHS", "Karachi", "DUHS Test", 180000);
            
            u1.show();
            u2.show();
            u3.show();
            
            Graphics::setColor(Graphics::BRIGHT_GREEN);
            cout << "Top-Ranked University for Medical:" << endl;
            u1.show();
        }
};

class ComputerScience : public Field {
    public:
        void showUniversities() override {
            Graphics::setColor(Graphics::BRIGHT_CYAN);
            cout << "=========== COMPUTER SCIENCE UNIVERSITIES ===========" << endl;
            Graphics::setColor(Graphics::WHITE);
            
            University u1("FAST NUCES", "Islamabad", "FAST Entry Test", 250000);
            University u2("NUST", "Islamabad", "NUST Entry Test", 220000);
            University u3("LUMS", "Lahore", "LUMS Entry Test", 300000);
            
            u1.show();
            u2.show();
            u3.show();
            
            Graphics::setColor(Graphics::BRIGHT_GREEN);
            cout << "Top-Ranked University for Computer Science:" << endl;
            u1.show();
        }
};

class Business : public Field {
    public:
        void showUniversities() override {
            Graphics::setColor(Graphics::BRIGHT_CYAN);
            cout << "=========== BUSINESS UNIVERSITIES ===========" << endl;
            Graphics::setColor(Graphics::WHITE);
            
            University u1("LUMS", "Lahore", "SAT / LCAT", 500000);
            University u2("IBA", "Karachi", "IBA Admission Test", 450000);
            University u3("IBA Sukkur", "Sukkur", "IBA Admission Test", 400000);
            
            u1.show();
            u2.show();
            u3.show();
            
            Graphics::setColor(Graphics::BRIGHT_GREEN);
            cout << "Top-Ranked University for Business:" << endl;
            u1.show();
        }
};

class Arts : public Field {
    public:
        void showUniversities() override {
            Graphics::setColor(Graphics::PURPLE);
            cout << "=========== ARTS UNIVERSITIES ===========" << endl;
            Graphics::setColor(Graphics::WHITE);
            
            University u1("NCA", "Lahore", "Drawing Test + Interview", 120000);
            University u2("Indus Valley School", "Karachi", "Portfolio + Interview", 100000);
            University u3("Beaconhouse College of Arts", "Lahore", "Portfolio Review", 90000);
            
            u1.show();
            u2.show();
            u3.show();
            
            Graphics::setColor(Graphics::BRIGHT_GREEN);
            cout << "Top-Ranked University for Arts:" << endl;
            u1.show();
        }
};

// ===================== MODULE 4 - Courses ===================== //
class Course {
    public:
        string name, platform, field, syllabus, instructor, learning_outcomes, level, url;
        int duration;
        double cost, rating;
};

void showCoursesByField(string field) {
    Course courses[10] = {
        {"Intro to Engineering Design", "Coursera", "Engineering", "Basics of engineering design", "Prof. Ahmed", "Understand engineering design process", "Beginner", "https://www.coursera.org/learn/intro-engineering-design", 40, 15000, 4.5},
        {"Electrical Circuits 101", "Udemy", "Engineering", "Circuit fundamentals", "Dr. Khan", "Learn to analyze circuits", "Beginner", "https://www.udemy.com/course/electrical-circuits-101/", 50, 12000, 4.7},
        {"Human Anatomy", "edX", "Medical", "Anatomy basics", "Dr. Fatima", "Learn human body structure", "Intermediate", "https://www.edx.org/course/human-anatomy", 60, 20000, 4.8},
        {"Medical Diagnostics", "Coursera", "Medical", "Diagnostics techniques", "Dr. Ali", "Learn medical diagnostic methods", "Intermediate", "https://www.coursera.org/learn/medical-diagnostics", 45, 18000, 4.6},
        {"Business Management", "Udemy", "Business", "Fundamentals of business", "Mr. Shah", "Learn business strategy and management", "Beginner", "https://www.udemy.com/course/business-management/", 35, 22000, 4.9},
        {"Financial Analysis", "Coursera", "Business", "Finance principles", "Ms. Sara", "Learn financial reporting", "Intermediate", "https://www.coursera.org/learn/financial-analysis", 40, 25000, 4.7},
        {"Programming Fundamentals", "Udemy", "IT", "Basics of programming", "Mr. Bilal", "Learn coding fundamentals", "Beginner", "https://www.udemy.com/course/programming-fundamentals/", 50, 18000, 4.8},
        {"Data Science", "Coursera", "IT", "Data science techniques", "Ms. Nadia", "Learn data analysis and ML", "Intermediate", "https://www.coursera.org/specializations/data-science", 60, 30000, 4.9},
        {"Drawing Fundamentals", "Skillshare", "Arts", "Basics of drawing", "Mr. Imran", "Learn drawing techniques", "Beginner", "https://www.skillshare.com/classes/Drawing-Fundamentals/123456", 30, 12000, 4.5},
        {"Visual Design", "Udemy", "Arts", "Design principles", "Ms. Hina", "Learn visual storytelling", "Intermediate", "https://www.udemy.com/course/visual-design/", 35, 15000, 4.6}
    };

    Graphics::setColor(Graphics::BRIGHT_CYAN);
    cout << "\n===== Courses for " << field << " =====\n";
    Graphics::setColor(Graphics::WHITE);
    
    for(int i=0;i<10;i++){
        if(courses[i].field == field){
            Graphics::setColor(Graphics::BRIGHT_CYAN);
            cout << " Course Name: " << courses[i].name << endl;
            Graphics::setColor(Graphics::WHITE);
            cout << " Platform: " << courses[i].platform << endl;
            cout << " Duration: " << courses[i].duration << " hours" << endl;
            cout << " Cost: " << courses[i].cost << " PKR" << endl;
            cout << " Rating: " << courses[i].rating << endl;
            cout << " Course Link: " << courses[i].url << endl;
            cout << " Ctrl + Click to follow the link " << endl << endl;
        }
    }
}

// ===================== MODULE 5 : Lifestyle & Daily Routine of Selected Field
// =============================================================

class LifeInterface {
    public:
        virtual void showLifestyle() = 0;
        virtual string getVideoLink() = 0;
        virtual ~LifeInterface() {}
};

class LifeDetails {
    private:
        string morning;
        string afternoon;
        string evening;
    public:
        LifeDetails(string m, string a, string e) {
            morning = m;
            afternoon = a;
            evening = e;
        }
        string getMorning() { return morning; }
        string getAfternoon() { return afternoon; }
        string getEvening() { return evening; }
};

class EngineeringLife : public LifeInterface {
    private:
        LifeDetails details;
        string videoLink;
    public:
        EngineeringLife() : details(
            "Starts the day with technical reading or checking emails.",
            "Spends most hours designing systems, coding or solving engineering problems.",
            "Ends day with small debugging tasks or reviewing project progress."
        ) {
            videoLink = "https://example.com/engineering-lifestyle";
        }
        void showLifestyle() override {
            Graphics::setColor(Graphics::BRIGHT_CYAN);
            cout << "\nEngineering Professional Lifestyle:\n";
            Graphics::setColor(Graphics::WHITE);
            cout << " Morning: " << details.getMorning() << endl;
            cout << " Afternoon: " << details.getAfternoon() << endl;
            cout << " Evening: " << details.getEvening() << endl;
            cout << " Watch video: ";
            Graphics::setColor(Graphics::BLUE);
            cout << videoLink << endl;
            Graphics::setColor(Graphics::WHITE);
        }
        string getVideoLink() override { return videoLink; }
};

class MedicalLife : public LifeInterface {
    private:
        LifeDetails details;
        string videoLink;
    public:
        MedicalLife() : details(
            "Early morning hospital rounds or checking patient reports.",
            "Handles surgeries, patient checkups, diagnosis and medical procedures.",
            "Evening mostly used for writing reports or preparing for next day cases."
        ) {
            videoLink = "https://example.com/medical-lifestyle";
        }
        void showLifestyle() override {
            Graphics::setColor(Graphics::BRIGHT_GREEN);
            cout << "\nMedical Professional Lifestyle:\n";
            Graphics::setColor(Graphics::WHITE);
            cout << " Morning: " << details.getMorning() << endl;
            cout << " Afternoon: " << details.getAfternoon() << endl;
            cout << " Evening: " << details.getEvening() << endl;
            cout << " Watch video: ";
            Graphics::setColor(Graphics::BLUE);
            cout << videoLink << endl;
            Graphics::setColor(Graphics::WHITE);
        }
        string getVideoLink() override { return videoLink; }
};

class BusinessLife : public LifeInterface {
    private:
        LifeDetails details;
        string videoLink;
    public:
        BusinessLife() : details(
            "Starts with analyzing market trends or reviewing emails.",
            "Conducts meetings, negotiates deals, and handles business planning.",
            "Evening spent building strategies, forecasting or networking."
        ) {
            videoLink = "https://example.com/business-lifestyle";
        }
        void showLifestyle() override {
            Graphics::setColor(Graphics::BRIGHT_CYAN);
            cout << "\nBusiness Professional Lifestyle:\n";
            Graphics::setColor(Graphics::WHITE);
            cout << " Morning: " << details.getMorning() << endl;
            cout << " Afternoon: " << details.getAfternoon() << endl;
            cout << " Evening: " << details.getEvening() << endl;
            cout << " Watch video: ";
            Graphics::setColor(Graphics::BLUE);
            cout << videoLink << endl;
            Graphics::setColor(Graphics::WHITE);
        }
        string getVideoLink() override { return videoLink; }
};

class ITLife : public LifeInterface {
    private:
        LifeDetails details;
        string videoLink;
    public:
        ITLife() : details(
            "Checks project tasks and updates from team.",
            "Codes software modules, debugs, attends online meetings.",
            "Learns new technologies or updates skills in the evening."
        ) {
            videoLink = "https://example.com/it-lifestyle";
        }
        void showLifestyle() override {
            Graphics::setColor(Graphics::BRIGHT_CYAN);
            cout << "\nIT / Computer Science Professional Lifestyle:\n";
            Graphics::setColor(Graphics::WHITE);
            cout << " Morning: " << details.getMorning() << endl;
            cout << " Afternoon: " << details.getAfternoon() << endl;
            cout << " Evening: " << details.getEvening() << endl;
            cout << " Watch video: ";
            Graphics::setColor(Graphics::BLUE);
            cout << videoLink << endl;
            Graphics::setColor(Graphics::WHITE);
        }
        string getVideoLink() override { return videoLink; }
};

class ArtsLife : public LifeInterface {
    private:
        LifeDetails details;
        string videoLink;
    public:
        ArtsLife() : details(
            "Starts morning with sketching or creative thinking.",
            "Spends afternoon creating artwork, filming content or designing.",
            "Evening used for exploring new ideas, editing or preparing next projects."
        ) {
            videoLink = "https://example.com/arts-lifestyle";
        }
        void showLifestyle() override {
            Graphics::setColor(Graphics::PURPLE);
            cout << "\nArts / Creative Field Lifestyle:\n";
            Graphics::setColor(Graphics::WHITE);
            cout << " Morning: " << details.getMorning() << endl;
            cout << " Afternoon: " << details.getAfternoon() << endl;
            cout << " Evening: " << details.getEvening() << endl;
            cout << " Watch video: ";
            Graphics::setColor(Graphics::BLUE);
            cout << videoLink << endl;
            Graphics::setColor(Graphics::WHITE);
        }
        string getVideoLink() override { return videoLink; }
};

// Aggregation helper to show lifestyle by field name
void showFieldLifestyleDirect(const string &fieldRaw) {
    string field = fieldRaw;
    if(field == "Engineering") {
        EngineeringLife life; life.showLifestyle();
    } else if(field == "Medical") {
        MedicalLife life; life.showLifestyle();
    } else if(field == "Business") {
        BusinessLife life; life.showLifestyle();
    } else if(field == "IT") {
        ITLife life; life.showLifestyle();
    } else if(field == "Arts") {
        ArtsLife life; life.showLifestyle();
    }
}
//================================================================================================
//Module 6: Admission requirements
//=========================================================================?======================


//AdmissionInterface(Abstract class)
class AdmissionInterface{
public:
virtual void showRequirements()=0;   //pure virtual function
virtual ~AdmissionInterface(){
}
};
class AdmissionRequirements{
string majorsubject;
string minmarks;
string test;
string otherRequirements;
public:
AdmissionRequirements(string sub, string m, string t, string o){
majorsubject=sub;
minmarks=m;
test=t;
otherRequirements=o;
}
string getSubject(){
return majorsubject;
}
string getmarks(){
return minmarks;
}
string getTest(){
return test;
}
string getotherRequirements(){
return otherRequirements;
}
};
//Inheritance+Polymorphism
//Engineering 
class EngineeringAdmission:public AdmissionInterface{
AdmissionRequirements details;
public:
EngineeringAdmission():details("Physics, Maths, Chemistry",
"Minimum 60% in Fsc",
"Entry test(ECAT, SAT)",
"Portfolio for design field")
{}
void showRequirements() override{
Graphics::setColor(Graphics::BRIGHT_CYAN);
cout<<"\nEngineering Admission Requirements: "<<endl;
Graphics::setColor(Graphics::WHITE);
cout<<"Required Subjects: "<<details.getSubject()<<endl;
cout<<"Minimum marks: "<<details.getmarks()<<endl;
cout<<"Required tests: "<<details.getTest()<<endl;
cout<<"Other requirements: "<<details.getotherRequirements()<<endl;
}
};
//Medical
class MedicalAdmission: public AdmissionInterface{
AdmissionRequirements details;
public:
MedicalAdmission():details("Physics, Chemistry, Biology",
"Minimum 70% in Fsc",
"Entry tests(Mdcat, SAT biology)",
"Health volunteer certificate optional")
{}
void showRequirements()override{
Graphics::setColor(Graphics::BRIGHT_GREEN);
cout<<"\nMedical Admission Requirements"<<endl;
Graphics::setColor(Graphics::WHITE);
cout<<"Required Subjects: "<<details.getSubject()<<endl;
cout<<"Minimum marks: "<<details.getmarks()<<endl;
cout<<"Required tests: "<<details.getTest()<<endl;
cout<<"Other requirements: "<<details.getotherRequirements()<<endl;
}
};
//Business
class BusinessAdmission:public AdmissionInterface{
AdmissionRequirements details;
public:
BusinessAdmission():details("Maths, Economics, English",
"Minimum 60% in Fsc",
"Entry test required in some universities",
"Portfolio optional")
{}
void showRequirements()override{
Graphics::setColor(Graphics::BRIGHT_CYAN);
cout<<"\nBuisness Admission requirements"<<endl;
Graphics::setColor(Graphics::WHITE);
cout<<"Required Subjects: "<<details.getSubject()<<endl;
cout<<"Minimum marks: "<<details.getmarks()<<endl;
cout<<"Required tests: "<<details.getTest()<<endl;
cout<<"Other Requirements: "<<details.getotherRequirements()<<endl;
}
};
//IT/CS Admission
class ITAdmission:public AdmissionInterface{
AdmissionRequirements details;
public:
ITAdmission():details("Maths, Computer, Physics",
"Minimum 65% in Fsc",
"Entry test/Programming",
"Portfolio optional")
{}
void showRequirements()override{
Graphics::setColor(Graphics::BRIGHT_CYAN);
cout<<"\nCS/IT Admission requirements"<<endl;
Graphics::setColor(Graphics::WHITE);
cout<<"Required subjects: "<<details.getSubject()<<endl;
cout<<"Minimum marks: "<<details.getmarks()<<endl;
cout<<"Required tests: "<<details.getTest()<<endl;
cout<<"Other requirements: "<<details.getotherRequirements()<<endl;
}
};
//Arts Admission
class ArtsAdmission: public AdmissionInterface{
AdmissionRequirements details;
public:
ArtsAdmission():details("Any combination of subjects",
"Minimum 55% in Fsc",
"Creative Entry test may be required",
"Interview or portfolio ooptional")
{}
void showRequirements()override{
Graphics::setColor(Graphics::PURPLE);
cout<<"\nArts Admission requirements"<<endl;
Graphics::setColor(Graphics::WHITE);
cout<<"Required Subject: "<<details.getSubject()<<endl;
cout<<"Minimum marks: "<<details.getmarks()<<endl;
cout<<"Other Requirements: "<<details.getotherRequirements()<<endl;
}
};
//Aggregation
class FieldAdmission{
AdmissionInterface* admissionptr;
public:
FieldAdmission(string field){
if(field=="Engineering"){
admissionptr=new EngineeringAdmission();
}
else if(field=="Medical"){
admissionptr=new MedicalAdmission();
}
else if(field=="Business"){
admissionptr=new BusinessAdmission();
}
else if(field=="IT"){
admissionptr=new ITAdmission();
}
else if(field=="Arts"){
admissionptr=new ArtsAdmission();
}
}
void show(){
Graphics::setColor(Graphics::BRIGHT_CYAN);
cout<<"\n=====Module 6:Admission Requirements====="<<endl;
Graphics::setColor(Graphics::WHITE);
admissionptr->showRequirements();
}
~FieldAdmission(){
delete admissionptr;
}
};
class scholarship{
	public:
		virtual void overview()=0;
		virtual void eligibility()=0;
		virtual void guidelines()=0;
		virtual void documents()=0;
		virtual void rules()=0;
		virtual void portal()=0;
		virtual ~scholarship() {}
};
class honahar:public scholarship{
	public: 
	void overview() override{
		Graphics::setColor(Graphics::BRIGHT_CYAN);
		cout << "\n****** Honahar Scholarship Program ******\n";
		Graphics::setColor(Graphics::WHITE);
        cout << "This scholarship supports talented students with strong academic performance.\n";
	}
	void eligibility ()override{
		 Graphics::setColor(Graphics::BRIGHT_CYAN);
		 cout << "\n******Eligibility criteria******\n";
		 Graphics::setColor(Graphics::WHITE);
        cout << "1- Minimum 85% marks in FSC/Intermediate\n";
        cout << "2- must be resident of punjab with domicile\n";
        cout << "3- family income must be less than 5 lakh\n";
	}
	void guidelines() override{
		Graphics::setColor(Graphics::BRIGHT_CYAN);
		cout << "\n******How to Apply******\n";
		Graphics::setColor(Graphics::WHITE);
        cout << "1. Create an account on Honahar Portal\n";
        cout << "2. Upload documents\n";
        cout << "3. Submit application and wait for verification\n";
	}
	void documents() override{
		Graphics::setColor(Graphics::BRIGHT_CYAN);
		cout << "\n******Documents Required******\n";
		Graphics::setColor(Graphics::WHITE);
        cout << "1- CNIC/B-Form\n";
        cout << "2- Matric & Intermediate result cards\n";
        cout << "3- Domicile\n";
        cout << "4- Passport size photos\n";
        
	}
	void rules() override{
		Graphics::setColor(Graphics::BRIGHT_CYAN);
		cout << "\n******How to Maintain Scholarship******\n";
		Graphics::setColor(Graphics::WHITE);
        cout << "1- Maintain minimum 3.0 GPA\n";
        cout << "2- No discipline issues\n";
        cout << "3- 75% attendance mandatory\n";
        cout << "4- maintain minimum 2.5 SGPA\n";
	}
	void portal(){
		Graphics::setColor(Graphics::GREEN);
		cout << "\n******Apply Here******\n";
		Graphics::setColor(Graphics::WHITE);
        cout << "Honahar Portal: https://honhaarscholarship.punjabhec.gov.pk/\n";
	}
};
class PEEF : public scholarship {
public:
    void overview() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n******PEEF Scholarship ******\n";
        cout << "Punjab Education Endowment Fund supports needy and talented students.\n";
    }

    void eligibility() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n******Eligibility******\n";
        Graphics::setColor(Graphics::WHITE);
        cout << "1- Punjab domicile\n";
        cout << "2- 60% marks in last exam\n";
        cout << "3- Income below 50,000\n";
    }

    void guidelines() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n******Steps to Apply******\n";
        cout << "1. Download PEEF form\n";
        cout << "2. Fill and submit in your college/university\n";
        cout << "3. Wait for approval\n";
    }

    void documents() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n******Documents******\n";
        cout << "1- Father’s income certificate\n";
        cout << "2- B-Form/CNIC\n";
        cout << "3- Result cards\n";
    }

    void rules() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n******Maintain PEEF******\n";
        cout << "1- Minimum GPA 2.5\n";
        cout << "2- No supplementary exams\n";
    }

    void portal() override {
        Graphics::setColor(Graphics::GREEN);
        cout << "\n******Portal******\n";
        cout << "PEEF Official Site: peef.org.pk \n";
    }
};
class NeedBase : public scholarship{
public:
    void overview() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n****** Need-Based Scholarship ******\n";
        cout << "Financial support for deserving students with low income.\n";
    }

    void eligibility() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n****** Eligibility******\n";
        cout << "1- Family income < 45,000\n";
        cout << "2- University verification required\n";
        cout << "3- Atleast 50% marks in intermediate/matric\n";
    }

    void guidelines() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n****** How to Apply ******\n";
        cout << "1. Visit your university financial aid office\n";
        cout << "2. Submit financial aid form\n";
    }

    void documents() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n****** Documents******\n";
        cout << "1- Guardian income proof\n";
        cout << "2- Utility bills\n";
        cout << "3- CNIC\n";
    }

    void rules() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n****** Maintain Scholarship ******\n";
        cout << "1- Maintain GPA 2.0+\n";
        cout << "2- No fake documents\n";
        cout << "3- no supplementary exams\n ";
    }

    void portal() override {
        Graphics::setColor(Graphics::GREEN);
        cout << "\n****** Portal ******\n";
        cout << "Your university's official website\n";
    }
};
class Ehsaas : public scholarship {
public:
    void overview() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n****** Ehsaas Undergraduate Scholarship ******\n";
        cout << "Largest need-based scholarship in Pakistan.\n";
    }

    void eligibility() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n****** Eligibility Criteria ******\n";
        cout << "1- Family income < 45,000\n";
        cout << "2- Admitted on merit\n";
        cout << "3- Not availing any other scholarship\n";
    }

    void guidelines() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n****** How to Apply ******\n";
        cout << "1. Visit Ehsaas Application Portal\n";
        cout << "2. Fill online form\n";
        cout << "3. Submit documents\n";
    }

    void documents() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n****** Documents ******\n";
        cout << "1- Income certificate\n";
        cout << "2- House rent agreement (if applicable)\n";
        cout << "3- Bank statements\n";
    }

    void rules() override {
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "\n****** Maintain Ehsaas Scholarship ******\n";
        cout << "1- 2.0+ GPA\n";
        cout << "2- 75% attendance\n";
    }

    void portal() override {
        Graphics::setColor(Graphics::GREEN);
        cout << "\n****** Portal ******\n";
        cout << "Ehsaas Portal: ehsaas.hec.gov.pk \n";
    }
};
class scholar:public scholarship{
	public:
		void displayAll() {
	        honahar h;
	        PEEF p;
	        NeedBase n;
	        Ehsaas e;
	        scholarship* arr[4] = { &h, &p, &n, &e };
	        for (int i = 0; i < 4; i++) {
	            arr[i]->overview();
	            arr[i]->eligibility();
	            arr[i]->documents();
	            arr[i]->guidelines();
	            arr[i]->rules();
	            arr[i]->portal();
	            Graphics::setColor(Graphics::PURPLE);
	            cout << "----------------------------------\n";
	            Graphics::setColor(Graphics::WHITE);
	        }
    }
		void overview() override {}
		void guidelines() override {}
		void eligibility() override {}
		void documents() override {}
		void rules() override {}
		void portal() override {}
		
};
class mainMenu{
	public:
	void displayMenu() {
    Graphics::printHeader("CAREER LADDER MENU");
    
    // Graphical Menu Box
    Graphics::setColor(Graphics::WHITE);
    cout << "\n";
    cout << "\t\t  1. Show Recommended Fields\n";
    cout << "\t\t  2. Show Recommended Universities\n";
    cout << "\t\t  3. Show Recommended Courses\n";
    cout << "\t\t  4. Show Field Lifestyle\n";
    cout << "\t\t  5. Show Scholarships\n";
    cout << "\t\t  6. Exit\n";
    cout << "\n";
    Graphics::setColor(Graphics::BRIGHT_GREEN);
    cout << "\t\tChoose an option: ";
    Graphics::setColor(Graphics::WHITE);
}

};


// ===================== MAIN ===================== //
int main() {
    
    // Display the cute animated climbing screen before the main splash screen
    Graphics::climbingScreen(); 
    
    // Show Intro Splash
    Graphics::splashScreen();
    
    string recommendedFields = "";
    question* quiz[10];
    quiz[0] = new q1();
    quiz[1] = new q2();
    quiz[2] = new q3();
    quiz[3] = new q4();
    quiz[4] = new q5();
    quiz[5] = new q6();
    quiz[6] = new q7();
    quiz[7] = new q8();
    quiz[8] = new q9();
    quiz[9] = new q10();
    score c1;
    
    Graphics::printHeader("Career Fit Test (10 Questions)");
    
    Graphics::setColor(Graphics::BRIGHT_CYAN);
    cout<<"\nInstructions:\n";
    Graphics::setColor(Graphics::WHITE);
	cout<<" 1-Read each question carefully and select the option that matches your interest the most.\n";
	cout<<" 2-Answer honestly so the system can recommend the most accurate career field for you.\n";
	cout<<" 3-Choose only one option (1-4) for every question to move to the next step.\n\n";
    cout << "Press Enter to start the Quiz...";
    cin.get();
    
    // Quiz Execution Loop (Modified to show one MCQ at a time with header)
    for(int i=0;i<10;i++){
        Graphics::quizTransition(); // Acts as the black screen flash/clear
        Graphics::printQuizHeader("Career Fit Test (Question " + to_string(i+1) + " of 10)");
        
        Graphics::setColor(Graphics::BRIGHT_CYAN);
        cout << "----------------------------------------\n";
        quiz[i]->ask();
    	 bool valid = false;
		int qchoice;
		while(!valid) {
            Graphics::setColor(Graphics::BRIGHT_GREEN);
		    cout << "\n\nEnter choice (1-4): ";
            Graphics::setColor(Graphics::WHITE);
		    cin >> qchoice;
		
		    try {
		        if(cin.fail()) {       
		            cin.clear();       
		            cin.ignore(1000, '\n'); 
		            Graphics::setColor(Graphics::BRIGHT_RED);
		            throw "You entered a non-number!";
		        }
		        if(qchoice < 1 || qchoice > 4) { 
		            Graphics::setColor(Graphics::BRIGHT_RED);
		            throw 1; 
		        }
		
		        valid = true; 
		    }
		    catch(const char* msg) {
                Graphics::setColor(Graphics::BRIGHT_RED);
		        cout << msg << " Please enter a number between 1 and 4.\n";
                Graphics::setColor(Graphics::WHITE);
		    }
		    catch(int) {
                Graphics::setColor(Graphics::BRIGHT_RED);
		        cout << "Invalid number! Please enter a number between 1 and 4.\n";
                Graphics::setColor(Graphics::WHITE);
		    }
		    catch(...) {
                Graphics::setColor(Graphics::BRIGHT_RED);
		        cout << "Unknown error! Please try again.\n";
                Graphics::setColor(Graphics::WHITE);
		    }
            Graphics::setColor(Graphics::WHITE);
		}
		 c1.add(quiz[i]->getpoints(qchoice));
         cout<<"\n";
         
    }
    
    Graphics::loadingBar("Calculating Results");
    
    Graphics::printHeader("Career Fit Test Results");
    
    c1.showtotal();
    recommendedFields = c1.recomend();
    
    Graphics::setColor(Graphics::BRIGHT_CYAN);
    cout << "\nRecommended field(s): " << recommendedFields << "\n";
    Graphics::setColor(Graphics::BRIGHT_CYAN);
    cout << "----------------------------------------\n";
    showFieldDetails(recommendedFields);
    Graphics::setColor(Graphics::WHITE);
    cout << "\nPress Enter to view menu...";
    cin.get(); 

    
    int choice;
    do {
    	mainMenu m;
        m.displayMenu();
        
        bool wrong=false;
        int temp_choice; 
        while(!wrong) {
            cin >> temp_choice;
            cin.ignore(); 
            try {
                if(cin.fail()) {       
                    cin.clear();       
                	cin.ignore(1000, '\n'); 
                    Graphics::setColor(Graphics::BRIGHT_RED);
                	cout << "You entered a non-number! Please enter a number between 1 and 6.\n";
                }
                else if(temp_choice < 1 || temp_choice > 6) { 
                    Graphics::setColor(Graphics::BRIGHT_RED);
                	cout << "Invalid choice. Please enter a number between 1 and 6.\n"; 
                }
                else {
                    wrong = true; 
                    choice = temp_choice;
                }
                
            }
            catch(const char* msg) {
                cout << msg << " Please enter a number between 1 and 6.\n";
            }
            catch(int) {
                cout << "Invalid number! Please enter a number between 1 and 6.\n";
            }
            catch(...) {
                cout << "Unknown error! Please try again.\n";
            }
            Graphics::setColor(Graphics::WHITE);
        }

        switch(choice) {
            case 1: {
                Graphics::loadingBar("Loading Recommended Fields");
                Graphics::printHeader("Recommended Fields");
                
                Graphics::setColor(Graphics::BRIGHT_CYAN);
                cout << "Recommended field(s): " << recommendedFields << "\n";
                Graphics::setColor(Graphics::BRIGHT_CYAN);
                cout << "----------------------------------------\n";
                showFieldDetails(recommendedFields);
                Graphics::setColor(Graphics::WHITE);
                
                cout << "\nPress Enter to return to menu...";
                cin.get();
                break;
            }
            case 2: {
                // Universities
                if(recommendedFields.empty()) {
                    Graphics::setColor(Graphics::BRIGHT_RED);
                    cout << "\n[!] Please take the Career Quiz first!\n";
                    Graphics::setColor(Graphics::WHITE);
                    this_thread::sleep_for(chrono::seconds(2));
                    break;
                }
                Graphics::loadingBar("Fetching Universities");
                Graphics::printHeader("Recommended Universities");
                
                stringstream obj(recommendedFields);
                string field;
                while(getline(obj, field, ',')) {
                    if(field == "Engineering") { Engineering eng; eng.showUniversities(); }
                    else if(field == "Medical") { Medical med; med.showUniversities(); }
                    else if(field == "Business") { Business bus; bus.showUniversities(); }
                    else if(field == "IT") { ComputerScience cs; cs.showUniversities(); }
                    else if(field == "Arts") { Arts arts; arts.showUniversities(); }
                }
                
                cout << "\nPress Enter to return to menu...";
                cin.get();
                break;
            }
            case 3: {
                // Courses
                if(recommendedFields.empty()) {
                    Graphics::setColor(Graphics::BRIGHT_RED);
                    cout << "\n[!] Please take the Career Quiz first!\n";
                    Graphics::setColor(Graphics::WHITE);
                    this_thread::sleep_for(chrono::seconds(2));
                    break;
                }
                Graphics::loadingBar("Loading Courses");
                Graphics::printHeader("Recommended Courses");
                
                stringstream obj(recommendedFields);
                string field;
                while(getline(obj, field, ',')) {
                    showCoursesByField(field);
                }
                
                cout << "\nPress Enter to return to menu...";
                cin.get();
                break;
            }
            case 4: {
                // Lifestyle
                if(recommendedFields.empty()) {
                    Graphics::setColor(Graphics::BRIGHT_RED);
                    cout << "\n[!] Please take the Career Quiz first!\n";
                    Graphics::setColor(Graphics::WHITE);
                    this_thread::sleep_for(chrono::seconds(2));
                    break;
                }
                Graphics::loadingBar("Analyzing Lifestyle");
                Graphics::printHeader("Professional Lifestyle Preview");
                
                stringstream obj(recommendedFields);
                string field;
                while(getline(obj, field, ',')) {
                    showFieldLifestyleDirect(field);
                }
                
                cout << "\nPress Enter to return to menu...";
                cin.get();
                break;
            }
            case 5: {
                // Scholarships
                                if(recommendedFields.empty()) {
                    Graphics::setColor(Graphics::BRIGHT_RED);
                    cout << "\n[!] Please take the Career Quiz first!\n";
                    Graphics::setColor(Graphics::WHITE);
                    this_thread::sleep_for(chrono::seconds(2));
                    break;
                }
                Graphics::loadingBar("Loading Scholarships");
                Graphics::printHeader("Available Scholarships");
                scholar s;
                s.displayAll();
                
                cout << "\nPress Enter to return to menu...";
                cin.get();
                break;
            }
            case 6: {
                Graphics::setColor(Graphics::BRIGHT_GREEN);
                cout << "Exiting program. Goodbye!\n";
                Graphics::setColor(Graphics::WHITE);
                break;
            }
            default:
                Graphics::setColor(Graphics::BRIGHT_RED);
                cout << "Invalid choice. Try again.\n";
                Graphics::setColor(Graphics::WHITE);
                this_thread::sleep_for(chrono::seconds(1));
        }

    } while(choice != 6);

    // Clean up
    for(int i=0;i<10;i++) delete quiz[i];

    return 0;
}
