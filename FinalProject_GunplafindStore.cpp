#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <limits> // for numeric limits (was used to check if the input in valid)
using namespace std;

//Reusable Headings of Each Page
void TopPageTemplate() {   
	cout << "\t\t\t\t\t\t\t\t  ------------------------------------------\n";
	cout << "\t\t\t\t\t\t\t\t        G U N P L A F I N D  S T O R E \n"; 
	cout << "\t\t\t\t\t\t\t\t            The Gundam Place Store\n";
	cout << "\t\t\t\t\t\t\t\t  ------------------------------------------\n\n";
}
void MasterPageTemplate() {
	cout << "\t\t\t\t\t\t\t\t       ================================\n";
	cout << "\t\t\t\t\t\t\t\t            M A S T E R  G R A D E \n";
	cout << "\t\t\t\t\t\t\t\t       ================================\n\n";
}
void PerfectPageTemplate() {
			cout << "\t\t\t\t\t\t\t\t\t================================\n";
			cout << "\t\t\t\t\t\t\t\t\t    P E R F E C T  G R A D E \n";
			cout << "\t\t\t\t\t\t\t\t\t================================\n\n";
	
}
void RealPageTemplate() {
			cout << "\t\t\t\t\t\t\t\t\t================================\n";
			cout << "\t\t\t\t\t\t\t\t\t       R E A L  G R A D E \n";
			cout << "\t\t\t\t\t\t\t\t\t================================\n\n";
}
void HighPageTemplate() {
			cout << "\t\t\t\t\t\t\t\t\t================================\n";
			cout << "\t\t\t\t\t\t\t\t\t       H I G H  G R A D E \n";
			cout << "\t\t\t\t\t\t\t\t\t================================\n\n";
}
void REPageTemplate() {
			cout << "\t\t\t\t\t\t\t\t\t================================\n";
			cout << "\t\t\t\t\t\t\t\t\t     R E / 1 0 0  G R A D E \n";
			cout << "\t\t\t\t\t\t\t\t\t================================\n\n";
}
void BillingTemplate() {
	cout << "\t\t\t\t\t\t\t\t       ================================\n";
	cout << "\t\t\t\t\t\t\t\t         B I L L I N G  S E C T I O N \n";
	cout << "\t\t\t\t\t\t\t\t       ================================\n\n";
}

void RetrieveHis() {
	cout << "\t\t\t\t\t\t\t\t    ======================================\n";
	cout << "\t\t\t\t\t\t\t\t              R E T R I E V I N G \n";
	cout << "\t\t\t\t\t\t\t\t     T R A N S A C T I O N  H I S T O R Y \n";
	cout << "\t\t\t\t\t\t\t\t                 S E C T I O N \n";
	cout << "\t\t\t\t\t\t\t\t    ======================================\n\n";
}

void realTime() {
	// current date/time based on current system
   time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

   cout << "Date and Time: " << dt << endl;
}

int ForChoice ();
int ForQuantity();
string ForAsking();
int ForItemCateg();
void TotalPriceChecker (int CartNumCont);		//fucntion used for the billing section

	int choicet; // used in function ForCateg and used for the Main Menu
	int CartNum = 0;           // variables for arrays to store the choice of customer
	string CartItems[50];		//array to store the name of the toy
	float CartItemspriceSolo[50]; 	//array to store the price of the toy 
	float CartItemsprice[50];       //arrays to store the price of the toy multiplied by the quantity
	int CartItemQuan[50];			//array to store the quantity of the toy
	
	int cashtender;			// variables for payments purposes
	float totalPrice = 0;	//variable for the total price of all the purchases
	
	string choice; // used in checking if the user still want to use the program
	
	int quantityTemp, quantity; // used in ForQuantity function
	
	int ItemChoice, ItemChoiceTemp1, ItemChoiceHold;	// variables used in ForChoice Function
	string choiceAsking;	//used in ForAsking Function
	string choiceAsk;
		
	int receiptHold = 1;	//used for storing the receipts chronologically (numbering)
	string receiptHolder;	// string holder for the receiptHold
	int receiptCounter = 1; // used for numbering of the receipts
	
	int receiptNumber;
	
	string CodeDiscount;
	string CodeDiscountValid;
	int counterPromo;
	float UpdatedPrice;
	float PromoValue;
	
	string PromoCodes[10] = {"BUILDGUNPLA", "GUNPLA2023", "MODELKIT123", "MECHAWAR10", "GUNPLAPRO20", "BUILDWITHUS", "GUNDAMFAN1" ,"MODELKITSAV", "MECHAMANIA" };
	float PromoDiscount[10] = {0.10, 0.15, 0.20, 0.25, 0.30, 0.35, 0.40, 0.45, 0.50};
	
 main() {

	
	//Start of Perfect Grade Sub-Categories
	string PG_MobileSuit[5] = {"PG 1/60 MS-OOF Zaku II(Green)", "PG 1/60 MS-OOS Zaku II(Red)", "PG 1/60 RX-78 Gundam (PG)", "PG Unleashed RX-78-2 Gundam", "PG 1/60 Raiser Gundam"};
	string PG_MobileSuitCode[5] = {"PG11", "PG12","PG13", "PG14","PG15"};
	float PG_MobileSuitprice[5] = {7164.45, 7354.67, 13567.49, 14630.36, 16478.35};
	
	string PG_DustMemory[5] = {"PG 1/60 RX-78 Gundam GP01/Fb", "PG Strike Rouge + Skygrasper", "PG Strike Freedom Gundam", "PG RX-78/C.A. Casval's Gundam", "PG Perfect Gundam III"};
	string PG_DustMemoryCode[5] = {"PG21", "PG22","PG23", "PG24","PG25"};
	float PG_DustMemoryprice[5] = {10995.67, 11456.78,  12345.45, 13096.56, 14567.78};
	
	string PG_Gundamo[5] = {"PG Gundam Exia Led Unit", "PG GN-OOI Gundam Exia Model Kit", "PG 00 Gundam Seven Sword/G", "PG 1/60 00 Raiser", "PG 00 Gundam Seven Sword/g Inspection P-Bandai"};
	string PG_GundamoCode[5] = {"PG31", "PG32","PG33", "PG34","PG35"};
	float PG_Gundamoprice[5] = {9093.44, 12400.34, 12675.92, 16478.86, 21770.45};
	
	string PG_GundamSeed[5] = {"PG EVA-O1 Astray Test", "PG MSZ-006 Z Astray Gundam","PG Wing Gundam Zero Custom" ,"PG MBF-P02 GUNDAM ASTRAY RED FRAME", "PG 1/60 Gundam Astray Red Frame Kai"};
	string PG_GundamSeedCode[5] = {"PG41", "PG42","PG43", "PG44","PG45"};
	float PG_GundamSeedprice[5] = {10354.56, 11456.78, 12090.76, 12400.34, 14492.51};
	
	string PG_GundamUni[5] = {"PG RX-O Unicorn Gundam LED Unit", "PG Unicorn Gundam Armor Type", "PG Unicorn Heavy Gundam", "PG RX-O UNICORN Gundam", "PG Unicorn Gundam 02 Banshee Norn", };
	string PG_GundamUniCode[5] = {"PG51", "PG52","PG53", "PG54","PG55"};
	float PG_GundamUniprice[5] ={7825.72, 11456.56, 12678.34,  13061.72, 14329.37};
	
	//Start of Master Grade Sub-Categories 
	string MG_MSV[5] = {"MG Shin Musha Gundam", "MG Musha Gundam Mk-2", "MG MSN-OOS Sinanju Stein Ver.KA", "MG FAZZ Ver.Ka" , "MG Ex-s Gundam/S Gundam" };
	string MG_MSVCode[5] = {"MG11", "MG12","MG13", "MG14","MG15"};
	float MG_MSVprice[5] = {3471.69, 3634.84, 4684.23, 6611.05, 7825.79};
	
	string MG_ZetaGundam[5] = {"MG RMS-106 Hi-Zack", "MG RX-178 Gundam Mk-II Titans Ver. 2.0", "MG AMX-004 Qubeley" , "MG MSZ-006 Zeta Gundam Ver. 2.0" , "MG Hyaku-Shiki Version 2.0"};
	string MG_ZetaGundamCode[5] = {"MG21", "MG22","MG23", "MG24","MG25"};
	float MG_ZetaGundamprice[5] = {2259.17, 2534.74, 2755.21, 3416.58, 4684.23 };
	
	string MG_MobileSuitGundam [5] = {"MG RGB-79 Ball Ver. Ka", "MG YMS-15 Gyan", "MG MS-O6J Zaku II Ver.2.O", "MG RX-78-2 Gundam(Ver. 2.0)", "MG RX-75 GunTank" };
	string MG_MobileSuitGundamCode[5] = {"MG31", "MG32","MG33", "MG34","MG35"};
	float MG_MobileSuitGundamprice[5] = {1923.52, 2479.63, 2534.74, 2810.32, 3581.93};
	
	string MG_GundamSeed [5] = {"MG Force Impulse Gundam", "MG Strike Freedom Gundam", "MG INFINITE JUSTICE GUNDAM", "MG Eclipse Gundam", "MG Destiny Gundam Extrerne Blast Mode" };
	string MG_GundamSeedCode[5] = {"MG41", "MG42","MG43", "MG44","MG45"};
	float MG_GundamSeedprice [5] = {3085.89, 3306.35, 3471.69, 3637.04, 4684.23};
	
	string MG_Gundamo[5] = {"MG GNX-603T GN-X", "MG 00 Qan[T]", "MG 00 QAN[T] Full Saber", "MG 00 Raiser", "MG Gundam Virtue"};
	string MG_GundamoCode[5] = {"MG51", "MG52","MG53", "MG54","MG55"};
	float MG_Gundamoprice[5] = {2424.51, 3030.78, 3802.39, 4188.19, 5235.38};
	
	//Start of Real Grade Sub-Categories
	string RG_Neon[5] = {"RG Evangelion Unit-OO", "RG Evangelion Mark.06 Neon Genesis Evangelion", "RG EVANGELION UNIT-03" , "RG EVA-O IDX", "RG EVA Unit-OO DX Positron Cannon Set"};
	string RG_NeonCode[5] = {"RG11", "RG12","RG13", "RG14","RG15"};
	float RG_Neonprice[5] = {3030.78, 3467.34, 3756.23, 4093.45, 4230.45};
	
	string RG_MobileSuitGundam[5] = {"RG MS-OOS Char Zaku II", "RG #04 MS-06F Zaku II", "RG #01 RX-78-2 Gundam", "RG #34 Zeong", "RG SHOOT ZEONG SET"};
	string RG_MobileSuitGundamCode[5] = {"RG21", "RG22","RG23", "RG24","RG25"};
	float RG_MobileSuitGundamprice[5] = {1768.09, 1956.45, 2145.56, 3647.27, 5800.59 };
	
	string RG_GundamWing[5] = {"RG MS-06R-2 JOHNNY RIDDEN'S ZAW 11", "RG #28 Tallgeese EW", "RG #17 Wing Gundam Zero EW", "RG #20 Wing Gundam EW", "RG #35 Wing Gundam"};
	string RG_GundamWingGundamCode[5] = {"RG31", "RG32","RG33", "RG34","RG35"};
	float RG_GundamWingprice[5] = {1655.34, 1768.09, 1856.45, 1945.67, 2154.98};
	
	string RG_Char[5] = {"RG #31 Crossbone Gundam Xl", "RG #32 RX-93 Nu Gundam", "RG HI-NU GUNDAM", "RG #29 Sazabi Chars Counterattack", "RG RX-93 Nu Gundam Fin Funnel Effect Set"};
	string RG_CharCode[5] = {"RG41", "RG42","RG43", "RG44","RG45"};
	float RG_Charprice[5] = {1823.36, 3039.32, 3094.57, 3294.58, 3813.63};
	
	string RG_GundamUni[5] = {"RG #28 Tallgeese EW", "RG #17 Wing Gundam Zero EW", "RG #20 Wing Gundam EW", "RG #35 Wing Gundam", "RG #23 Wing GAT-X105B/FP"};
	string RG_GundamUniCode[5] = {"RG51", "RG52","RG53", "RG54","RG55"};
	float RG_GundamUniprice[5] = {1768.09, 1856.45, 1945.56, 2145.34, 2567.34};
	
	//Start of High Grade Sub-Categories
	
	string HG_War[5] = {"HG #225 Silver Bullet Suppressor", "HG #217 Sinanju Stein", "HG #216 UNICORN GUNDAM 03 PHENEX", "HG #227 Gundam 45 Scraper", " HG #218 Narrative Gundam (A-Packs)"};
	string HG_WarCode[5] = {"HG11", "HG12","HG13", "HG14","HG15"};
	float HG_Warprice[5] = {1823.36, 1933.91, 3370.92, 3481.46, 3592.55 };
	
	string HG_BuildDivers[5] = {"HG #21 Petit'gguy Chara'GGuy Ayame", "HG Gundam 00 Sky", "HG GM Ill Beam Master", "HG #17 Impulse Gundam Arc", "HG #18 Impulse Gundam Lancier"};
	string HG_BuildDiversCode[5] = {"HG21", "HG22","HG23", "HG24","HG25"};
	float HG_BuildDiversprice[5] = {552.15, 743.38, 939.59, 1050.13, 1326.48};
	
	string HG_BuildFighters[5] = {"HG #08 Leo NPD", "HG Sengoku Astray Gundam", "HG #16 Gundam Amazing Exia", "HG #06 Wing Gundam Fenice", "HG #13 Gundam Exia Dark Matter"};
	string HG_BuildFightersCode[5] = {"HG31", "HG32","HG33", "HG34","HG35"};
	float HG_BuildFightersprice[5] = {773.23, 861.78, 1068.92, 1215.94, 1492.29} ;
	
	string HG_GundamAge[5] = {"HG Gundam AGE-2 Dark Hound", "HG #20 Gundam Age Farsia", "HG #14 Gundam Age G-Bouncer", "HG Gundam AGE-I Glansa", "HG #27 Gundam AGE-1 Glansa"};
	string HG_GundamAgeCode[5] = {"HG41", "HG42","HG43", "HG44","HG45"};
	float HG_GundamAgeprice[5] = {964.46, 1075.53, 1185.54, 1406.62, 1517.16};
 	
 	string HG_GundamNarrative[5] = {"HG #222 Narrative Gundam (C Packs)", "HG #225 Silver Bullet Suppressor", "HG #217 Sinanju Stein (Narrative Version)", "HG #216 UNICORN GUNDAM 03 PHENEX", "HG #218 Narrative Gundam (A-Packs)"};
 	string HG_GundamNarrativeCode[5] = {"HG51", "HG52","HG53", "HG54","HG55"};
 	float HG_GundamNarrativeprice[5] = {1572.43, 1682.97, 1848.78, 2235.67, 2346.21};
 	
 	//Start RE/100 Sub-Categories
 	
	string RE_Iron[5] = {"RE Full Mechanics #041/100 Gundam Bael IBO", "RE 1/100 Gundam Barbatos Lupus Rex", "RE Full Mechanics 1/100 #02 Gundam", "RE Full Mechanics 1/100 #01 Gundam Killer Scraper" , "RE McGilliss Schwalbe Graze"};
	string RE_IronCode[5] = {"RE11", "RE12","RE13", "RE14","RE15"};
	float RE_Ironprice[5] = {2456.23, 2679.45, 2945.34, 3204.56, 36784.39};
	
	string RE_91[5] = {"RE 1/100 Gundam Names", "RE 1/100 #01 Gundam Exia", "RE Gundam 00 #031/100 GN-003 Gundam Kyrios", "RE 1/100 #02 Vigna-Gina (Mobile suit XM-07)", "RE 1/100 GUNDAM VIRTUE"};
	string RE_91Code[5] = {"RE21", "RE22","RE23", "RE24","RE25"};
	float RE_91price[5] = {1623.83, 1900.18, 2176.53, 2397.61, 2673.96};
	
	string RE_Shred[5] = {"RE 1/100 ZGMF-X42S Destiny Gundam", "RE 1/100 ZGMF-X20A Strike Freedom Gundam", "RE #08 Guncannon Detector", "RE 1/100 #15 ORB-OI Akatsuki Gundam", "RE 1/100 ZGMF-X56S/a Force Impulse Gundam"};
	string RE_ShredCode[5] = {"RE31", "RE32","RE33", "RE34","RE35"};
	float RE_Shredprice[5] = {1568.56, 1734.37, 1955.45, 2176.53, 2342.34}; 
	
	string RE_Gun[5] = {"RE 1/100 RE-02 Dragon Gundam", "RE 1/100 #02 Gundam Dynames", "RE 1/100 Gundam Exia", "RE Gundam 00 #031/100 GN-003 Gundam Kyrios", "RE 1/100 GUNDAM Piller"};
	string RE_GunCode[5] = {"RE41", "RE42","RE43", "RE44","RE45"};
	float RE_Gunprice[5] = {1098.21, 1208.75, 1429.83, 1595.64, 1989.72};
	
	string RE_Vidar[5] = {"RE Full Mechanics #041/10 Gundam Bael IBO", "RE FULL MECHANICS 1/10 Calamity Gundam", "RE 1/100 ZGMF-X20A Strike Freedom Gundam", "RE Gundam OO #031/100 GN-003 Gundam Kyrios", "RE Tank Detector"};
	string RE_VidarCode[5] = {"RE51", "RE52","RE53", "RE54","RE55"};
	float RE_Vidarprice[5] = {2100.26, 2210.84, 2487.15, 2597.69, 2708.23};
	
		
		TopPageTemplate();
	
			cout << "\t\t\t\t\t\t\t\t\t     [1]    Perfect Grade\n";
			cout << "\t\t\t\t\t\t\t\t\t     [2]    Master Grade\n";
			cout << "\t\t\t\t\t\t\t\t\t     [3]    Real Grade\n ";
			cout << "\t\t\t\t\t\t\t\t\t     [4]    High Grade\n ";
			cout << "\t\t\t\t\t\t\t\t\t     [5]    RE/100\n";
			cout << "\t\t\t\t\t\t\t\t\t     [6]    Retrieve Transaction History\n";
			cout << "\t\t\t\t\t\t\t\t\t     [7]    Exit\n\n ";
	
	while (true) {	//loop to check if the input of the user is valid
		
			cout << "\t\t\t\t\t     >> Choice Selection [1-7]: ";
			cin >> choicet;
			
        		if (cin.fail()) {
           			cin.clear(); // clear error flag
            		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore invalid input
            		cout << "\t\t\t\t\t\t   Invalid input. Please enter a number.\n" << endl;
        		}
        		else if ( (choicet < 1) || (choicet > 7) ) {	
					cout << "\t\t\t\t\t\t   Choice not available in the menu.\n\n";
				}
        		else {
            		break; // valid input received, exit loop
        		}
    }

	switch(choicet) {
		
		case 1:      //Perfect Grade
			PGMain: //for goto label
				system("cls");							// clears the previous output from the console
				
				TopPageTemplate();			//function for displaying Top Page Template
				PerfectPageTemplate();		//function for displaying Perfect Page Template
			
					cout << "\t\t\t[?]The ultimate Gundam experience! Perfect Grade kits are 1/60 in scale, as well as some of the most complex Gunpla around[?]\n\n";
						cout << "\t\t\t\t\t\t\t\t\t   [1]      Mobile Suit Gundam\n";
						cout << "\t\t\t\t\t\t\t\t\t   [2]      0083: Stardust Memory\n";
						cout << "\t\t\t\t\t\t\t\t\t   [3]      Gundam 00\n ";
						cout << "\t\t\t\t\t\t\t\t\t   [4]      Gundam SEED Astray\n ";
						cout << "\t\t\t\t\t\t\t\t\t   [5]      Gundam Unicorn\n\n ";
						cout << "\t\t\t\t\t\t\t\t\t   [6]      Return to Main Menu\n ";
						cout << "\t\t\t\t\t\t\t\t\t   [7]      Exit\n\n ";
			
		switch (ForItemCateg()) {
			
			case 1: //Mobile Suit Gundam
			
				system("cls");
				TopPageTemplate();
				PerfectPageTemplate;
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t      MOBILE SUIT GUNDAM \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
						for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << PG_MobileSuitprice[i] << "\t" <<PG_MobileSuit[i] <<"\n";
						};
							cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
							cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n\n\n;";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto PGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1; // if none of the conditions above were satisfied, continue to the price and quantity arrays
					
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = PG_MobileSuit[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = PG_MobileSuitprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = PG_MobileSuitprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
			break; //end of case 1
			
			case 2: //0083: Stardust Memory
			
				system("cls");
				TopPageTemplate();
				PerfectPageTemplate;
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t     0083: STARDUST MEMORY \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
						for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << PG_DustMemoryprice[i] << "\t" <<PG_DustMemory[i] <<"\n";
						};
							cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
							cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n\n\n;";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto PGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
					
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = PG_DustMemory[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = PG_DustMemoryprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = PG_DustMemoryprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
			break; //end of case 2
			
			case 3: //Gundam 00
			
				system("cls");
				TopPageTemplate();
				PerfectPageTemplate;
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t          GUNDAM 00 \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
						for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << PG_Gundamoprice[i] << "\t" <<PG_Gundamo[i] <<"\n";
						};
							cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
							cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n\n\n;";
						
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto PGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = PG_Gundamo[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = PG_Gundamoprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = PG_Gundamoprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
							
			break;	//end of case 3
			
			case 4: //Gundam SEED Astray
			
				system("cls");
				TopPageTemplate();
				PerfectPageTemplate;
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t      GUNDAM SEED ASTRAY \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
						for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << PG_GundamSeedprice[i] << "\t" <<PG_GundamSeed[i] <<"\n";
						};
							cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
							cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n\n\n;";
								
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto PGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = PG_GundamSeed[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = PG_GundamSeedprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = PG_GundamSeedprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
			break; // end of case 4
			
			case 5:	//Gundam Unicorn
			
				system("cls");
				TopPageTemplate();
				PerfectPageTemplate;
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t        GUNDAM UNICORN \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
						for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << PG_GundamUniprice[i] << "\t" <<PG_GundamUni[i] <<"\n";
						};
							cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
							cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n\n\n;";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto PGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = PG_GundamUni[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = PG_GundamUniprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = PG_GundamUniprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
			break; // end of case 5
			
			case 6: 
				system("cls");
				main();
			case 7:
				cout << "\n\n\t\t\t\t\t     Thank you for using the program!\n";
				exit(0);
		}
			
		break; // end of case 1 from the Main Menu
			
		case 2:      //Master Grade
			
			MGMain:
				
				system("cls");							// clears the previous output from the console
		 		TopPageTemplate();
		 		MasterPageTemplate();
			
					cout << "\t\t[?]Master Grade kits are just as finely detailed as the name implies and will easily be some of the best-looking Gunpla in your collection![?]\n\n";
						cout << "\t\t\t\t\t\t\t\t\t   [1]      MSV\n";
						cout << "\t\t\t\t\t\t\t\t\t   [2]      Zeta Gundam\n";
						cout << "\t\t\t\t\t\t\t\t\t   [3]      Mobile Suit Gundam\n ";
						cout << "\t\t\t\t\t\t\t\t\t   [4]      Gundam SEED Destiny\n ";
						cout << "\t\t\t\t\t\t\t\t\t   [5]      Gundam 00\n\n ";
						cout << "\t\t\t\t\t\t\t\t\t   [6]      Return to Main Menu\n ";
						cout << "\t\t\t\t\t\t\t\t\t   [7]      Exit\n\n ";
			
			switch (ForItemCateg()) {
				
				case 1: //MSV
				
					system("cls");
					TopPageTemplate();
			 		MasterPageTemplate();
				
							cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
							cout << "\t\t\t\t\t\t\t\t\t              MSV \n";
							cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
						
								for (int i = 0; i < 5; i++) {
									cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << MG_MSVprice[i] << "\t" <<MG_MSV[i] <<"\n";
								};
									cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
									cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n\n\n;";
						
							// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto MGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
						// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = MG_MSV[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = MG_MSVprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = MG_MSVprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
		
				break; // end of case 1
					
				case 2: // Zeta Gundam
				
					system("cls");
					TopPageTemplate();
			 		MasterPageTemplate();
				
							cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
							cout << "\t\t\t\t\t\t\t\t\t          ZETA GUNDAM \n";
							cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
							
								for (int i = 0; i < 5; i++) {
									cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << MG_ZetaGundamprice[i] << "\t" << MG_ZetaGundam[i] << "\n";
								};
									cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
									cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n\n\n;";
					
							// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto MGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
						// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = MG_ZetaGundam[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = MG_ZetaGundamprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = MG_ZetaGundamprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
				
				break; // end of case 2
					
				case 3: //Mobile Suit Gundam
				
					system("cls");
					TopPageTemplate();
			 		MasterPageTemplate();
					
						cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
						cout << "\t\t\t\t\t\t\t\t\t      MOBILE SUIT GUNDAM \n";
						cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
						
							for (int i = 0; i < 5; i++) {
								cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << MG_MobileSuitGundamprice[i] << "\t" << MG_MobileSuitGundam[i] << "\n";
							};
								cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
								cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n\n\n;";
					
						// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto MGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
						// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = MG_MobileSuitGundam[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = MG_MobileSuitGundamprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = MG_MobileSuitGundamprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
				
				break; // end of case 3
					
				case 4: //Gundam SEED Destiny
				
					system("cls");
					TopPageTemplate();
			 		MasterPageTemplate();
					
						cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
						cout << "\t\t\t\t\t\t\t\t\t     GUNDAM SEED DESTINY \n";
						cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
						
							for (int i = 0; i < 5; i++) {
								cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << MG_GundamSeedprice[i] << "\t" << MG_GundamSeed[i] << "\n";
							};
								cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
								cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n\n\n;";
						
						// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto MGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
						// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = MG_GundamSeed[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = MG_GundamSeedprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = MG_GundamSeedprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
				break; // end of case 4
					
				case 5: //Gundam 00
				
					system("cls");
					TopPageTemplate();
			 		MasterPageTemplate();
					
						cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
						cout << "\t\t\t\t\t\t\t\t\t           GUNDAM 00 \n";
						cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
						
							for (int i = 0; i < 5; i++) {
								cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << MG_Gundamoprice[i] << "\t" << MG_Gundamo[i] << "\n";
							};
								cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
								cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n\n\n;";
						
						// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto MGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
						// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = MG_Gundamo[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = MG_Gundamoprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = MG_Gundamoprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
						
						
						break;
			
				case 6: 
					system("cls");
					main();
				case 7:
					cout << "\n\n\t\t\t\t\t     Thank you for using the program!\n";
					exit(0);
			}
		 	
		break; // end of case 2 in the Main Menu
		 	
		case 3:      //Real Grade
		
			RGMain:
				system("cls");							// clears the previous output from the console
				
				TopPageTemplate();
		 		RealPageTemplate();
		
					cout << "\t\t[?]If you love the smaller scales of HG kits but also love a lot of detail, then Real Grade kits are just right for you![?]\n\n";
			
					cout << "\t\t\t\t\t\t\t\t\t   [1]      Neon Genesis Evangelion\n";
					cout << "\t\t\t\t\t\t\t\t\t   [2]      Gundam Wing\n";
					cout << "\t\t\t\t\t\t\t\t\t   [3]      Mobile Suit Gundam\n ";
					cout << "\t\t\t\t\t\t\t\t\t   [4]      Char's Counterattack'\n ";
					cout << "\t\t\t\t\t\t\t\t\t   [5]      Gundam Unicorn\n\n ";
					cout << "\t\t\t\t\t\t\t\t\t   [6]      Return to Main Menu\n ";
					cout << "\t\t\t\t\t\t\t\t\t   [7]      Exit\n\n ";
				
			switch (ForItemCateg()) {
				
				case 1: // Neon Genesis Evangelion
				system("cls");
				TopPageTemplate();
		 		RealPageTemplate();
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t   NEON GENESIS EVANGELION\n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
						cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << RG_Neonprice[i] << "\t" <<RG_Neon[i] <<"\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto RGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
					
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = RG_Neon[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = RG_Neonprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = RG_Neonprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
					
					break;
				case 2: // Gundam Wing
				system("cls");
				TopPageTemplate();
		 		RealPageTemplate();
				
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t         GUNDAM WING \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
						cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << RG_GundamWingprice[i] << "\t" << RG_GundamWing[i] << "\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto RGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = RG_GundamWing[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = RG_GundamWingprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = RG_GundamWingprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
			
					break;
					
				case 3: //Mobile Suit Gundam
				system("cls");
				TopPageTemplate();
		 		RealPageTemplate();
				
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t      MOBILE SUIT GUNDAM \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << RG_MobileSuitGundamprice[i] << "\t" << RG_MobileSuitGundam[i] << "\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto RGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = RG_MobileSuitGundam[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = RG_MobileSuitGundamprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = RG_MobileSuitGundamprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
					break;
					
				case 4: //Char's Counterattack
				system("cls");
				TopPageTemplate();
		 		RealPageTemplate();
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t    CHAR'S COUNTER ATTACK \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << RG_Charprice[i] << "\t" << RG_Char[i] << "\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto RGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = RG_Char[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = RG_Charprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = RG_Charprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
					
					break;
					
				case 5: //Gundam Unicorn
				system("cls");
				TopPageTemplate();
		 		RealPageTemplate();
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t        GUNDAM UNICORN \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << RG_GundamUniprice[i] << "\t" << RG_GundamUni[i] << "\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto RGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = RG_GundamUni[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = RG_GundamUniprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = RG_GundamUniprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
					break;
				
				case 6: 
					system("cls");
					main();
					
				case 7:
					
						cout << "\n\n\t\t\t\t\t     Thank you for using the program!\n";
						exit(0);
			}
		 	
		 	break;
			
			
		case 4:      //High Grade
			
			HGMain:
				system("cls");							// clears the previous output from the console
				
				TopPageTemplate();
				HighPageTemplate();
		
					cout << "\t\t[?]The most widely-produced scale by Bandai, with an abundance of mecha designs to choose from - you can't go wrong with a High Grade kit![?]\n\n";
			
					cout << "\t\t\t\t\t\t\t\t\t   [1]      0080: War in the Pocket\n";
					cout << "\t\t\t\t\t\t\t\t\t   [2]      Build Divers\n";
					cout << "\t\t\t\t\t\t\t\t\t   [3]      Build Fighters\n ";
					cout << "\t\t\t\t\t\t\t\t\t   [4]      Gundam AGE\n ";
					cout << "\t\t\t\t\t\t\t\t\t   [5]      Gundam Narrative\n\n ";
					cout << "\t\t\t\t\t\t\t\t\t   [6]      Return to Main Menu\n ";
					cout << "\t\t\t\t\t\t\t\t\t   [7]      Exit\n\n ";
				
			switch (ForItemCateg()) {
				
				case 1: // 0080: War in the Pocket
				system("cls");
				TopPageTemplate();
				HighPageTemplate();
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t    0080: WAR IN THE POCKET\n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
						cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << HG_Warprice[i] << "\t" <<HG_War[i] <<"\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto HGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = HG_War[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = HG_Warprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = HG_Warprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
					
					break;
					
				case 2: // Build Divers
				system("cls");
				TopPageTemplate();
				HighPageTemplate();
				
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t         BUILD DIVERS \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
						cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << HG_BuildDiversprice[i] << "\t" << HG_BuildDivers[i] << "\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto HGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = HG_BuildDivers[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = HG_BuildDiversprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = HG_BuildDiversprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
			
					break;
					
				case 3: // Build Fighters
				system("cls");
				TopPageTemplate();
				HighPageTemplate();
				
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t        BUILD FIGHTERS \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << HG_BuildFightersprice[i] << "\t" << HG_BuildFighters[i] << "\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto HGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = HG_BuildFighters[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = HG_BuildFightersprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = HG_BuildFightersprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
					
					break;
					
				case 4: // Gundam AGE
				system("cls");
				TopPageTemplate();
				HighPageTemplate();
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t          GUNDAM AGE \n";  
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << HG_GundamAgeprice[i] << "\t" << HG_GundamAge[i] << "\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto HGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = HG_GundamAge[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = HG_GundamAgeprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = HG_GundamAgeprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
					break;
				case 5: // Gundam Narrative
				system("cls");
				TopPageTemplate();
				HighPageTemplate();
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t       GUNDAM NARRATIVE \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << HG_GundamNarrativeprice[i] << "\t" << HG_GundamNarrative[i] << "\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto HGMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = HG_GundamNarrative[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = HG_GundamNarrativeprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = HG_GundamNarrativeprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
					break;
					
				case 6: 
					system("cls");
					main();
					
				case 7:
						
							cout << "\n\n\t\t\t\t\t     Thank you for using the program!\n";
							exit(0);
			}
		 	
		 	break;
			

		case 5:     //RE/100
		
			REMain:
				system("cls");							// clears the previous output from the console
				
				TopPageTemplate();
				REPageTemplate();
		
					cout << "\t\t\t\t[?]Designed to feature certain mobile suits in 1/100 scale but separate from the Master Grade (MG) line_[?]\n\n";
			
					cout << "\t\t\t\t\t\t\t\t\t   [1]      Iron-Blooded Orphans\n";
					cout << "\t\t\t\t\t\t\t\t\t   [2]      Gundam F91\n";
					cout << "\t\t\t\t\t\t\t\t\t   [3]      Gundam Seed Shreder\n ";
					cout << "\t\t\t\t\t\t\t\t\t   [4]      G Gundam'\n ";
					cout << "\t\t\t\t\t\t\t\t\t   [5]      Gundam Vidar\n\n ";
					cout << "\t\t\t\t\t\t\t\t\t   [6]      Return to Main Menu\n ";
					cout << "\t\t\t\t\t\t\t\t\t   [7]      Exit\n\n ";
				
			switch (ForItemCateg()) {
				
				case 1: // Iron-Blooded Orphans
				system("cls");
				TopPageTemplate();
				REPageTemplate();
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t     IRON-BLOODED ORPHANS\n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
						cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << RE_Ironprice[i] << "\t" <<RE_Iron[i] <<"\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto REMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = RE_Iron[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = RE_Ironprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = RE_Ironprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
					
					break;
				case 2: // Gundam F91
				system("cls");
				TopPageTemplate();
				REPageTemplate();
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t          GUNDAM F91 \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
						cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << RE_91price[i] << "\t" << RE_91[i] << "\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto REMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = RE_91[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = RE_91price[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = RE_91price[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
			
					break;
					
				case 3: // Gundam Seed Shreder
				system("cls");
				TopPageTemplate();
				REPageTemplate();
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t      GUNDAM SEED SHREDER \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << RE_Shredprice[i] << "\t" << RE_Shred[i] << "\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto REMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = RE_Shred[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = RE_Shredprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = RE_Shredprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
					
					break;
				case 4: // G Gundam
				system("cls");
				TopPageTemplate();
				REPageTemplate();
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t           G GUNDAM \n";  
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << RE_Gunprice[i] << "\t" << RE_Gun[i] << "\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto REMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = RE_Gun[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = RE_Gunprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = RE_Gunprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
					break;
				case 5: // Gundam Vidar
				system("cls");
				TopPageTemplate();
				REPageTemplate();
				
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n";
					cout << "\t\t\t\t\t\t\t\t\t         GUNDAM VIDAR \n";
					cout << "\t\t\t\t\t\t\t\t\t  **************************\n\n";
					
					for (int i = 0; i < 5; i++) {
							cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]    " << "Php " << RE_Vidarprice[i] << "\t" << RE_Vidar[i] << "\n";
					};
					cout << "\n\t\t\t\t\t\t\t\t[6] Return to Previous Menu\n";
					cout << "\t\t\t\t\t\t\t\t[7] Return to Main Menu\n;";
					
					cout << "\n\n";
					
					// for Item Choice
						ItemChoiceHold = ForChoice();
						if (ItemChoiceHold == 6) {	//if satisfied, return to previous menu
							goto REMain;
						}
						else if (ItemChoiceHold == 7) { //if satisfied, return to main menu (main)
							system("cls");
							main();
						}
							ItemChoice = ItemChoiceHold - 1;
						
					// for Quantity of the Item	
					quantity = ForQuantity();	
						
					CartItems[CartNum] = RE_Vidar[ItemChoice];	//storing the description of the toy in the array
					CartItemspriceSolo[CartNum] = RE_Vidarprice[ItemChoice];	//storing the individual price of the toy in the array
					CartItemsprice[CartNum] = RE_Vidarprice[ItemChoice] * quantity;	//storing the individual price of the toy multiplied by the quantity in the array
		
					// to store the Item Quantity in the array
					CartItemQuan[CartNum] = quantity;
					// for Asking the User if he wants to buy more toys
					ForAsking();	// should return the value for choiceAsking
					
					break;
				
				case 6: 
					system("cls");
					main();
				
				case 7:
						
							cout << "\n\n\t\t\t\t\t     Thank you for using the program!\n";
							exit(0);
			}
		 	
		 	break;
		
		case 6: //Retrieving Transaction History
			{
			ReceiptMain:
			
				while (true) {
					system("cls");
					TopPageTemplate();
					RetrieveHis();
					cout << "\n\t[NOTE: Please enter 0 if you want to return to the main menu.]\n";
       				cout << "\n\t>> Receipt Number: ";
					cin >> receiptNumber;

				        if (cin.fail()) {
				            cin.clear(); // clear error flag
				            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore invalid input
				            cout << "\t     Invalid input. Please enter a number.\n";
				            cout << "\n\t" << system("pause");
				        }
				        else if (receiptNumber == 0) {
				        	system("cls");
				        	main();
						}
				        else {
				        	receiptHolder = to_string(receiptNumber);
				            break; // valid input received, exit loop
				        }
    			}
    			
    			cout << "\t>> Processing your receipt....\n";	
 
				
    			fstream myFile;
					myFile.open("Receipt" + receiptHolder + ".txt", ios::in ); //read a text file
							if (myFile.is_open())	{
								cout << "\t>> Receipt Found. \n\n";

								string line;
									while (!myFile.eof()) {
	   							 	getline(myFile, line);
	    							cout << line << endl;
									}	
								myFile.close();
							}
							else if (!myFile.is_open()) {
								cout << "\t\t?Receipt cannot be found?." << endl;
								cout << "\n\t" << system("pause");
								goto ReceiptMain;
							}
			
			
			}
			
						do{	
							cout << "\n\n\t[NOTE: Please enter 0 if you want to retrieve more transaction history.]";
							cout << "\n\tDo you still want to use the program? [Y/N]: ";
							cin >> ws;
							getline(cin, choiceAsk);
								if (choiceAsk == "Y") {
									system("cls");
									main();
								}
								else if (choiceAsk == "N") {
									cout <<"\n\tThank you for using the program. ";
									exit(0);
								}
								else if (choiceAsk == "0") {
									goto ReceiptMain;
								}
								else {
									cout << "\tInvalid input. Please try again.\n";
								}
						}while (choiceAsk != "N" && choiceAsk != "Y" && choiceAsk != "0");
	
		case 7:
			cout << "\n\n\t\t\t\t\t     Thank you for using the program!\n";
			exit(0);
		
	}
	
	if (choiceAsking == "Y") {
		CartNum++;
		system("cls");
		main();
	}
	else if (choiceAsking == "N") {	
		system("cls");
		TotalPriceChecker(CartNum);
			
			receiptHolder = to_string(receiptHold);
			fstream myFile;
				myFile.open("Receipt" + receiptHolder + ".txt", ios::out ); //write into a text file
		
					if (myFile.is_open()) {
							myFile << "\t\tRECEIPT #00" << receiptHold << endl;	
							myFile << "\t\t==========================================\n";
							myFile << "\t\t      G U N P L A F I N D  S T O R E \n"; 
							myFile << "\t\t          The Gundam Place Store\n";
							myFile << "\t\t==========================================\n\n";
															
							myFile << "\t\t|Qty|\t|Price|\t\t|Total|\t\t|Description|\n";
							myFile << "\n";
								for (int x = 0 ; x <= CartNum; x++) {
										myFile << "\t\t  " <<	CartItemQuan[x] << "\tPhp " << CartItemspriceSolo[x] << "\tPhp " << CartItemsprice[x] << "\t" << CartItems[x] << endl;
									}
										myFile << "\n\t\t>> Total Price: PHP " << totalPrice << endl;
											if (counterPromo == 2) {
											myFile << "\t\t>> Promo Discount Code: N/A" << endl;
											}
											else if (counterPromo == 1) {
											myFile << "\t\t>> Promo Discount Code: " << CodeDiscountValid << endl;
											myFile << "\t\t>> Promo Discount Value: " << PromoValue << "%" << endl; 
											myFile << "\t\t>> Updated Total Price: PHP " << UpdatedPrice << endl << endl;
											}
										myFile << "\t\t>> Cash Tender: PHP " << cashtender << endl;
										myFile << "\t\t>> Change:      PHP " << cashtender - UpdatedPrice << endl << endl;
										myFile << "\t\t[THANK YOU FOR SHOPPING AT GUNPLAFIND STORE!] ";
												
							myFile.close();
					}

		do{
	
			cout << "\n\n\tDo you still want to use the program to make new purchases?[Y/N]: ";
			cin >> ws;
			getline(cin, choice);
	
				if (choice == "Y") {
						CartNum = 0;
						receiptHold += 1;
						totalPrice = 0;
						system("cls");
						main();		
				}
				else {
					cout << "\n\tThank you for using the program!";				
									}
	
	} while (choice != "Y" && choice != "N");
		
	}	
		
}



void TotalPriceChecker (int CartNumCont) {
	
	
	TopPageTemplate();
	BillingTemplate();
	
	cout << "\t\tLegend: " << endl;
	cout << "\t\t\t[PG] Perfect Grade\n";
	cout << "\t\t\t[MG] Master Grade\n";
	cout << "\t\t\t[RG] Real Grade\n";
	cout << "\t\t\t[HG] High Grade\n";
	cout << "\t\t\t[RE] RE/100\n\n\n\n";
	
	cout << "\t**********\t*******\t\t   *******\t       *************\n";
	cout << "\t|Quantity|\t|Price|\t\t   |Total|\t       |Description|\n\n";
	for (int x = 0 ; x <= CartNumCont; x++) {
		
		cout << "\t    " <<	CartItemQuan[x] << "\t\t Php " << CartItemspriceSolo[x] << "\t    Php " << CartItemsprice[x] << "\t\t" << CartItems[x] << endl;
		totalPrice += CartItemsprice[x];
	}
	
	
	cout << "\n\n\t>> Total Price is: PHP " << totalPrice << endl << endl;
	
	cout << "\n\tEnter \"NONE\" if you don't have Promo Code\n";
	
	do {
    cout << "\n\t>> Promo Code: ";
    getline(cin, CodeDiscount);
    
	if (CodeDiscount == "NONE") {
    		UpdatedPrice = totalPrice;
    		counterPromo += 2;
	}
    
    else {
    	
	    for (int x = 0; x < 10; x++) {
	    	
	    	if (CodeDiscount == PromoCodes[x] ) {
	    		cout << "\tPromo Code found.\n";
	    		PromoValue = PromoDiscount[x] * 100;
	    		UpdatedPrice = totalPrice - (totalPrice * PromoDiscount[x]);
	    		cout << "\n\tPromo Code Value: " << PromoDiscount[x] * 100 << "%";
	    		cout << "\n\n\t  >> Updated Total Price: PHP " << UpdatedPrice << endl;
	    		counterPromo += 1;
	    		CodeDiscountValid = CodeDiscount;
	    		break;
			}
			else {
				counterPromo = 0;
			}
			
			}
	}
	
	if (counterPromo == 0 ) {
		cout << "\t     Invalid Promo Code.\n";
	}
	
	} while (counterPromo == 0);
	
	while(true){
        cout << "\n\t>> Cash Tender: PHP ";
        cin >> cashtender;

        if (cin.fail()) {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore invalid input
            cout << "\t     Invalid input. Please enter a number.\n\n";
        }
        else if (cashtender < UpdatedPrice) {	
			cout << "\t     Cash is too low. Please try again.\n\n";
		}
        else {
            break; // valid input received, exit loop
        }
    }
    
	
    		cout << "\t>> Received: PHP " << cashtender << endl;
	    		if (CodeDiscount == "NONE") {
	    			cout << "\t>> Promo Discount: N/A "<< endl;
				}
				else {
	    		cout << "\t>> Promo Discount: " << PromoValue << "%" << endl; 
				}
			cout << "\t>> Your change is: PHP " << cashtender - UpdatedPrice << endl;
			cout << "\tThank you for shopping at GUNPLAFind Store.\n\n\n";
			cout << "\n\t* Here is your receipt. *";
			cout << "\n\n\t\tRECEIPT #00" << receiptHold << endl;				
			cout << "\t\t==========================================\n";
			cout << "\t\t      G U N P L A F I N D  S T O R E \n"; 
			cout << "\t\t          The Gundam Place Store\n";
			cout << "\t\t==========================================\n\n";
							
			cout << "\t\t|Qty|\t|Price|\t\t|Total|\t\t|Description|\n";
			cout << "\n";
					for (int x = 0 ; x <= CartNumCont; x++) {
							cout << "\t\t  " <<	CartItemQuan[x] << "\tPhp " << CartItemspriceSolo[x] << "\tPhp " << CartItemsprice[x] << "\t" << CartItems[x] << endl;
						}
			cout << "\n\t\t>> Total Price: PHP " << totalPrice << endl;
			if (counterPromo == 2) {			
				cout << "\t\t>> Promo Discount Code: N/A" << endl;
			}
			else if (counterPromo == 1) {
				cout << "\t\t>> Promo Discount Code: " << CodeDiscountValid << endl;
				cout << "\t\t>> Promo Discount Value: " << PromoValue << "%" << endl; 
				cout << "\t\t>> Updated Total Price: PHP " << UpdatedPrice << endl << endl;
			}
			cout << "\t\t>> Cash Tender: PHP " << cashtender << endl;
			cout << "\t\t>> Change:      PHP " << cashtender - UpdatedPrice << endl << endl;
			cout << "\t\t[THANK YOU FOR SHOPPING AT GUNPLAFIND STORE!] ";	
			cout << "\n\n\t=====================================================================================";
			cout << "\n\tG-----U-----N-----P-----L-----A-----F-----I-----N-----D-----S-----T-----O-----R-----E";
			cout << "\n\t=====================================================================================";

}

int ForQuantity() {
	
	while (true) {
		
       	cout << "\t\t\t\t>> Item Quantity: ";
		cin >> quantityTemp;

	        if (cin.fail()) {
	            cin.clear(); // clear error flag
	            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore invalid input
	            cout << "\t\t\t\t       Invalid input. Please enter a number.\n\n";;
	        }
	        else if (quantityTemp >= 1000) {	
				cout << "\t\t\t\t       Error. Maximum quantity is 999 only.\n\n";
			}
	        else {
	            break; // valid input received, exit loop
	        }
	}
	return quantityTemp;			
}

string ForAsking() {
	
		do {
			cout << "\t\t\t\t    Do you want to buy another item ([Y]/[N]): ";
			cin >> ws;
			getline(cin,choiceAsking);	
				
		} while (choiceAsking != "Y" && choiceAsking != "N");

			return choiceAsking;
}
int ForChoice () {
	
	while (true) {
       	cout << "\t\t\t\t>> Item Number: ";
		cin >> ItemChoiceTemp1;

        	if (cin.fail()) {
            	cin.clear(); // clear error flag
            	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore invalid input
            	cout << "\t\t\t\t       Invalid Input. Please enter a number.\n\n";
       	 	}
        	else if ( (ItemChoiceTemp1 < 1) || (ItemChoiceTemp1 > 7) ) {	
				cout << "\t\t\t\t       Choice not available in the menu.\n\n";
			}
        	else {
            	break; // valid input received, exit loop
        	}	
    }
	return ItemChoiceTemp1;	
}

int ForItemCateg() { // function for Item Categories

	while (true) {
       	cout << "\t\t\t\t\t>> Item Category Number: ";
		cin >> choicet;

        	if (cin.fail()) {
            	cin.clear(); // clear error flag
           		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore invalid input
            	cout << "\t\t\t\t\t\tInvalid input. Please enter a number.\n" << endl;
       		 }
        	else if ( (choicet < 1) || (choicet > 7) ) {	
				cout << "\t\t\t\t\t\tChoice not available in the menu.\n\n";
			}
        	else {
            	break; // valid input received, exit loop
       	 	}
    }
	return choicet;
}

