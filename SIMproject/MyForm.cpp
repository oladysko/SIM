#include "MyForm.h"
#include "Parser.h"
#include "DicomDataAdapter.h"

//included by Marek Kos
#include "VideoHandler.h"
#include "ColorPalete.h"
#include <Vcclr.h>

using namespace System; 
using namespace System::Windows::Forms; 
using namespace System::Drawing;

VideoHandler *vh;
ColorPalete* cp;
bool dir = true;//z czasem

[STAThread] 
void Main(array<String^>^ args) 
{ 
	srand(time(NULL));
	Application::EnableVisualStyles(); 
	Application::SetCompatibleTextRenderingDefault(false); 
	SIMproject::MyForm form;
	Application::Run(%form); 
} 

namespace SIMproject{
	System::Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e) {


		unsigned int frameNumber;
		String^ debugInfo;
		String^ fileName;
		array<System::String^>^ fileNames;
		int bitmapHeight = 0, bitmapWidth = 0;
		std::string stdFileName;

		try
		{
			//get frame number
			frameNumber = Convert::ToUInt32(this->frame_textBox->Text);
			debugInfo = "selected frame = " + Convert::ToString(frameNumber) + "\n";

			//get file
			OpenFileDialog^ dlg = gcnew OpenFileDialog();
			dlg->Multiselect = true; //Uwaga mnogie zaznaczanie! - Marek Kos
			dlg->ShowDialog();
			fileNames = dlg->FileNames;
			//fileName = dlg->FileName;
			if (fileNames->GetLength(0) != 0)
			{
				ParserH::MarshalString(fileNames[0], stdFileName);
				ParserH::fileNametoPath(stdFileName);
				String^ tmpString = gcnew String(stdFileName.c_str());
				debugInfo = debugInfo + "selected file = \n" + tmpString + "\n";
			}
		}
		catch (Exception^ errorHandle){
			this->Info_label->Text = errorHandle->Message;
			return;
		}
		
		cp = new ColorPalete(GREYSCALE);
		//Zabawa. Nie przejmowac sie
		int** tab;
		tab = new int*[5];
		for (int i = 0; i < 5; i++)
		{
			tab[i] = new int[3];
			for (int j = 0; j < 3; j++)
			{
				tab[i][j] = rand()%256; //Randomowe kolorki!!! You didn't see that coming, did you?
			}
		}
		cp->makeCustom(tab, 5, 256);
		//Koniec zabawy
		vh = new VideoHandler(10,1,cp);
		
		//vh->setOddLine(true);
		for (int i = 0; i < fileNames->GetLength(0); i++)
		{
		//Przyklad skradziony z MSDN
		// Pin memory so GC can't move it while native function is called
		pin_ptr<const wchar_t> wch = PtrToStringChars(fileNames[i]);
		
		size_t convertedChars = 0;
		size_t  sizeInBytes = ((fileNames[i]->Length + 1) * 2);
		errno_t err = 0;
		char    *ch = (char *)malloc(sizeInBytes);

		err = wcstombs_s(&convertedChars,ch, sizeInBytes,wch, sizeInBytes);
		if (err != 0)
			//gui sie powinno rzucic tu ze podalismy nielegalne znaki w nazwie pliku
			return;

			DicomDataAdapter dicomData = DicomDataAdapter::DicomDataAdapter(ch, vh);
			dicomData.CreateBmp();
		}
		vh->getSize(bitmapWidth, bitmapHeight);
		this->dicomImage = gcnew Bitmap(bitmapHeight, bitmapWidth, Imaging::PixelFormat::Format24bppRgb);

		this->Info_label->Text = bitmapWidth + " " + bitmapHeight;
		int min, max;
		//vh->getCurrentMinMax(min,max); //pelna dynamika kazdej klatki. falszuje informacje miedzy obrazami
		vh->getGlobalMinMax(min, max);  //nie pelna dynamika klatek. Prawdziwe relacje miedzy barwami w roznych klatkach
		int* frame = vh->getThisFrame();

		ParserH::getBitmap(bitmapWidth, bitmapHeight, this->dicomImage,frame,min,max,cp);
		reverser->Checked = vh->getCurrentState();

		//display picture
		pictureBox1->Image = this->dicomImage;
		//this->Info_label->Text = ;
		
		//delete(vh);
	}

	System::Void MyForm::next_Click(System::Object^  sender, System::EventArgs^  e) {
		
		int bitmapHeight = 0, bitmapWidth = 0, min,max;
		int* frame;
		//vh->getCurrentMinMax(min,max); //pelna dynamika kazdej klatki. falszuje informacje miedzy obrazami
		vh->getGlobalMinMax(min, max);  //nie pelna dynamika klatek. Prawdziwe relacje miedzy barwami w roznych klatkach
		
		if (vh->moveToNextFrame())
		{
	
		}
			else {
				frame = vh->getThisFrame();

				vh->getSize(bitmapWidth, bitmapHeight);
				this->dicomImage = gcnew Bitmap(bitmapHeight, bitmapWidth, Imaging::PixelFormat::Format24bppRgb);
				ParserH::getBitmap(bitmapWidth, bitmapHeight, this->dicomImage, frame, min, max,cp);

				//display picture
				pictureBox1->Image = this->dicomImage;
				reverser->Checked = vh->getCurrentState();
			}
	}

	System::Void MyForm::back_Click_1(System::Object^  sender, System::EventArgs^  e) {
		int bitmapHeight = 0, bitmapWidth = 0, min, max;
		int* frame;
		//vh->getCurrentMinMax(min,max); //pelna dynamika kazdej klatki. falszuje informacje miedzy obrazami
		vh->getGlobalMinMax(min, max);  //nie pelna dynamika klatek. Prawdziwe relacje miedzy barwami w roznych klatkach

		if ((vh->moveToPrevFrame()))
		{

		}
		else
		{
			frame = vh->getThisFrame();
			vh->getSize(bitmapWidth, bitmapHeight);
			this->dicomImage = gcnew Bitmap(bitmapHeight, bitmapWidth, Imaging::PixelFormat::Format24bppRgb);
			ParserH::getBitmap(bitmapWidth, bitmapHeight, this->dicomImage, frame, min, max,cp);
			reverser->Checked = vh->getCurrentState();

			//display picture
			pictureBox1->Image = this->dicomImage;
		}
	}
	
	
	System::Void MyForm::video_maker_Click(System::Object^  sender, System::EventArgs^  e)
	{
		vh->video_encode("test2.mp4", AV_CODEC_ID_MPEG4);
	}
	
	System::Void MyForm::reverser_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		vh->setCurrentState(reverser->Checked);
	}

}

