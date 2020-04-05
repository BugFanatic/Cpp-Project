
#include <iostream>
#include <string>
#include <cmath>
#include <filesystem>

namespace fs = std::filesystem;



int main()
{

    std::string year, month, day, vendor_Name, POS_Name,user_name;

    std::cout <<"\n#######################################"<<std::endl;
    std::cout <<"Identify yourself(User Name): ";
    std::cin >> user_name;
    std::cout <<std::endl;

    std::cout <<"\n#######################################"<<std::endl;
    std::cout <<"Enter The POS(Machine) Number: ";
    std::cin >> POS_Name;
    std::cout <<std::endl;

    std::cout << "Enter\nyear month day:\n";
    std::cin >>year>>month>>day;
    std::string current_date = year+month+day;

    std::cout <<"\n#######################################\n";
    std::cout <<"Enter The Vendor Name: ";
    std::cin >> vendor_Name;
    std::cout <<std::endl;


    std::string POS = "MM" + POS_Name + current_date;
    std::string threePP_name = "3pp" + current_date + ".csv";
    std::string MMKSSales_name = "MMKSSales" + current_date;
    std::string MMKMADJ_name = "MMKMADJComm" + current_date;
    std::string MMKM_name = "MMKM"+ vendor_Name + current_date;
    std::string MMKV_name = "MMKV" + vendor_Name + current_date;

    std::string filenames[] = {POS, threePP_name,MMKSSales_name, MMKMADJ_name, MMKM_name, MMKV_name};
    int len = size(filenames);

    //Create directories for recon
    fs::create_directory("C:\\Users\\"+user_name+"\\Desktop\\RECON_RREPORT\\");
    fs::create_directory("C:\\Users\\"+user_name+"\\Desktop\\RECON_RREPORT\\POS_FILES\\");
    fs::create_directory("C:\\Users\\"+user_name+"\\Desktop\\RECON_RREPORT\\SAP_FILES\\");
    fs::create_directory("C:\\Users\\"+user_name+"\\Desktop\\RECON_RREPORT\\FINANCE_FILES\\");

    int counter = 0;
    while(counter <= len)
    {


        do
        {
        //Display Options
            for(int i = counter; i < len; i++)
                std::cout <<"\n"<< (i + 1) << ". " << filenames[i] ;

            std::cout << "\nMake a selection: ";
            int choice;
            std::cin >> choice;
            choice--;
            //PATHS
            //For POS file
            std::string dir_POS_QA_COPY = "\\\\sc"+ POS_Name + "e001\\c$\\pcmaster\\BAK\\mm"+filenames[choice];
            std::string dir_POS_QA_PASTE = "C:\\Users\\"+user_name+"\\Desktop\\RECON_RREPORT\\POS_FILES\\" +filenames[choice];
            //For 3pp file
            std::string dir_3pp_QA_COPY = "\\\\mmqa\\mmqa\\mm\\Extracts\\Finance\\" + filenames[choice];
            std::string dir_3pp_QA_PASTE = "C:\\Users\\"+user_name+"\\Desktop\\RECON_RREPORT\\FINANCE_FILES\\"+filenames[choice];
            //For SAP files
            std::string dir_SAP_QA_COPY = "\\\\mmqa\\mmqa\\mm\\Extracts\\SAP\\Backup\\" + filenames[choice];
            std::string dir_SAP_QA_PASTE = "C:\\Users\\"+user_name+"\\Desktop\\RECON_RREPORT\\SAP_FILES\\"+filenames[choice];

            // CHECK the file size
            fs::path in_POS = fs::current_path() / dir_POS_QA_PASTE;
            fs::path in_SAP = fs::current_path() / dir_SAP_QA_PASTE;
            fs::path in_3pp = fs::current_path() / dir_3pp_QA_PASTE;

            switch(choice)
            {
            case 0:
                if(fs::exists(dir_POS_QA_PASTE) && fs::file_size(in_POS) >= 0)
                {
                    std::cout <<"\n"<< POS <<": "<<std::setprecision(5)<<fs::file_size(in_POS)/1000 <<"Kb Already Exists\n";
                }
                else if(fs::exists(dir_POS_QA_COPY))
                {
                    fs::copy(dir_POS_QA_COPY, dir_POS_QA_PASTE);
                    std::cout <<"\n"<< POS <<": "<<std::setprecision(5)<<fs::file_size(in_POS)/1000 <<"Kb Copied Successsfully\n";
                }
                else
                {
                    std::cout <<"\n"<< POS << " Does Not Exist\n";
                }
                break;
            case 1:
                if(fs::exists(dir_3pp_QA_PASTE) && fs::file_size(in_3pp) >= 0)
                {
                    std::cout <<"\n"<< threePP_name <<": "<<std::setprecision(5)<<fs::file_size(in_3pp)/1000 <<"Kb Already Exists\n";
                }
                else if(fs::exists(dir_3pp_QA_COPY))
                {
                    fs::copy(dir_3pp_QA_COPY, dir_3pp_QA_PASTE);
                    std::cout <<"\n"<< threePP_name <<": "<<std::setprecision(5)<<fs::file_size(in_3pp)/1000 <<"Kb Copied Successsfully\n";
                }
                else
                {
                    std::cout <<"\n"<< threePP_name << " Does Not Exist\n";
                }
                break;
            case 2:
                if(fs::exists(dir_SAP_QA_PASTE) && fs::file_size(in_SAP) >= 0)
                {
                    std::cout <<"\n"<< MMKSSales_name <<": "<<std::setprecision(5)<<fs::file_size(in_SAP)/1000 <<"Kb Already Exists\n";
                }
                else if(fs::exists(dir_SAP_QA_COPY))
                {
                    fs::copy(dir_SAP_QA_COPY, dir_SAP_QA_PASTE);
                    std::cout <<"\n"<< MMKSSales_name <<": "<<std::setprecision(5)<<fs::file_size(in_SAP)/1000 <<"Kb Copied Successsfully\n";
                }
                else
                {
                    std::cout <<"\n"<< MMKSSales_name << " Does Not Exist\n";
                }
                break;
            case 3:
                if(fs::exists(dir_SAP_QA_PASTE) && fs::file_size(in_SAP) >= 0)
                {
                    std::cout <<"\n"<< MMKMADJ_name <<": "<<std::setprecision(5)<<fs::file_size(in_SAP)/1000 <<"Kb Already Exists\n";
                }
                else if(fs::exists(dir_SAP_QA_COPY))
                {
                    fs::copy(dir_SAP_QA_COPY, dir_SAP_QA_PASTE);
                    std::cout <<"\n"<< MMKMADJ_name <<": "<<std::setprecision(5)<<fs::file_size(in_SAP)/1000 <<"Kb Copied Successsfully\n";
                }
                else
                {
                    std::cout <<"\n"<< MMKMADJ_name << " Does Not Exist\n";
                }
                break;
            case 4:
                if(fs::exists(dir_SAP_QA_PASTE) && fs::file_size(in_SAP) >= 0)
                {
                    std::cout <<"\n"<< MMKM_name <<": "<<std::setprecision(5)<<fs::file_size(in_SAP)/1000 <<"Kb Already Exists\n";
                }
                else if(fs::exists(dir_SAP_QA_COPY))
                {
                    fs::copy(dir_SAP_QA_COPY, dir_SAP_QA_PASTE);
                    std::cout <<"\n"<< MMKM_name <<": "<<std::setprecision(5)<<fs::file_size(in_SAP)/1000 <<"Kb Copied Successsfully\n";
                }
                else
                {
                    std::cout <<"\n"<< MMKM_name << " Does Not Exist\n";
                }
                break;
            case 5:
                if(fs::exists(dir_SAP_QA_PASTE) && fs::file_size(in_SAP) >= 0)
                {
                    std::cout <<"\n"<< MMKV_name <<": "<<std::setprecision(5)<<fs::file_size(in_SAP)/1000 <<"Kb Already Exists\n";
                }
                else if(fs::exists(dir_SAP_QA_COPY))
                {
                    fs::copy(dir_SAP_QA_COPY, dir_SAP_QA_PASTE);
                    std::cout <<"\n"<< MMKV_name <<": "<<std::setprecision(5)<<fs::file_size(in_SAP)/1000 <<"Kb Copied Successsfully\n";
                }
                else
                {
                    std::cout <<"\n"<< MMKV_name << " Does Not Exist\n";
                }
                break;
            default:
                    std::cout << "\nYour selection was out of bounds.\n\n";
            }

        }
        while(counter <=len);

    }
}

