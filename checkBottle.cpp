// 5. Calculate report
// Insert counter for defect
#include<iostream>
#include<cstring>
using namespace std;

void showRemark(bool wChck, bool hChck, bool tChck);

int main(){

    char nextTest;
    char sampleID[10];
    float weight, height, thickness;
    char weightCondition[8],heightCondition[8], thickCondition[8], remark[32];
    int wDefect=0, hDefect=0, tDefect=0;

    do
    {
        bool wChck=true, hChck=true, tChck=true;
        cout << "Do you have another bottle to test [Y-Yes|N-No] ? ";
        cin >> nextTest;

        // Break when "N"
        if(nextTest=='N')
        break;

        cout << "Insert Sample ID : ";
        cin >> ws;
        cin.getline(sampleID,10);

        cout << "Insert Weight (g) : ";
        cin >> weight;
        if (weight<189.5||weight>190.5)
        {
            // Generate report for weight
            cout << "=======================================" << endl;
            cout << "Sample ID : " << sampleID << endl;
            cout << "Weight : Not OK" << endl;
            cout << "Remark : Send to rework immediately" << endl;
            cout << "=======================================" << endl;
            wChck=false;
            wDefect++;
            continue;
        }
        else
        {
            strcpy(weightCondition,"OK");
        }
        

        cout << "Insert Height (cm) : ";
        cin >> height;
        cout << "Insert Wall Thickness (mm) : ";
        cin >> thickness;

        if (height<23||height>24)
        {
            strcpy(heightCondition,"Not OK");
            hChck=false;
            hDefect++;
        }
        else
        {
            strcpy(heightCondition,"OK");
        }
         if (thickness<1.8||thickness>2.0)
        {
            strcpy(thickCondition,"Not OK");
            tChck=false;
            tDefect++;
        }
        else
        {
            strcpy(thickCondition,"OK");
        }       
             // Generate report
            cout << "=======================================" << endl;
            cout << "Sample ID : " << sampleID << endl;
            cout << "Weight : " << weightCondition << endl;
            cout << "Height : " << heightCondition << endl;
            cout << "Wall : " << thickCondition << endl;
            showRemark(wChck, hChck, tChck);
            cout << "\n=======================================" << endl;       

    } while (nextTest=='Y'); // Repeat again when 'Y' is inserted

    // Summary report
    cout << "TOTAL WEIGHT DEFECT: " << wDefect << endl;
    cout << "TOTAL HEIGHT DEFECT: " << hDefect << endl;
    cout << "TOTAL WALL DEFECT: " << tDefect << endl;
    float reworkCost = wDefect*0.03+hDefect*0.05+tDefect*0.15;
    cout << "TOTAL REWORK COST : USD " << reworkCost << endl;
    return 0;
}

// Function: Show remark
void showRemark(bool wChck, bool hChck, bool tChck){
    
    if (wChck==true && hChck==true && tChck==true)
    {
        cout << "Remark : Ready to ship.";
    }
    else
    {
        cout << "Remark : Send to Rework";
    }
    
    
}
