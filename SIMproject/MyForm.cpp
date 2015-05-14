#include "MyForm.h"
#include "Parser.h"
#include "DicomDataAdapter.h"

//included by Marek Kos
#include "VideoHandler.h"
#include <Vcclr.h>

using namespace System; 
using namespace System::Windows::Forms; 
using namespace System::Drawing;

VideoHandler *vh;
bool dir = true;//z czasem

[STAThread] 
void Main(array<String^>^ args) 
{ 
	Application::EnableVisualStyles(); 
	Application::SetCompatibleTextRenderingDefault(false); 
	SIMproject::MyForm form;
	Application::Run(%form); 
} 

namespace SIMproject{
	System::Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e) {

		/*
		//TEST generacji video
		VideoHandler *vh = new VideoHandler(352, 352, 25); //generalnie na razie w konstruktorze przekazuje sie parametry video
		int *tab; //wskaznik na frame'a
		for (int t = 0; t < 50; t++) //50 razy 1/25 = 2s
		{
			tab = new int[352 * 352]; //tworze nowego frame'a
			for (int i = 0; i < 352 * 352; i++)
			{
				tab[i] = (352 - 1 - i % 352) + i / 352 +t * 5; //wypelniam czyms
			}
			vh->addNewFrame(tab); //dodaj nowego frame'a
		}
		vh->video_encode("test.mp4", AV_CODEC_ID_MPEG4);
		delete(vh);
		//koniec testu generacji video
		*/

		//variables
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
		
		vh = new VideoHandler(25,1);
		
		//vh->setOddLine(true);
		for (int i = 0; i < fileNames->GetLength(0); i++)
		{
		//Przyklad zkradziony z MSDN
		// Pin memory so GC can't move it while native function is called
		pin_ptr<const wchar_t> wch = PtrToStringChars(fileNames[i]);
		// Conversion to char* :
		// Can just convert wchar_t* to char* using one of the 
		// conversion functions such as: 
		// WideCharToMultiByte()
		// wcstombs_s()
		// ... etc
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
		int* frame = vh->getAndMoveFrame();

		ParserH::getBitmap(bitmapWidth, bitmapHeight, this->dicomImage,frame,min,max);

		//display picture
		pictureBox1->Image = this->dicomImage;
		//this->Info_label->Text = ;
		
		vh->video_encode("test2.mp4", AV_CODEC_ID_MPEG4);
		int a, b,c;
		c=a + b;
		//delete(vh);
	}

	System::Void MyForm::saveCurrent_Click(System::Object^  sender, System::EventArgs^  e) {
		/*
		SaveFileDialog ^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "JPeg Image|*.jpg|Bitmap Image|*.bmp|Gif Image|*.gif";
		saveFileDialog->Title = "Save an Image File";
		saveFileDialog->ShowDialog();

		//if filename is not empty string
		if (saveFileDialog->FileName != ""){
			this->Info_label->Text = "filename for saving: " + saveFileDialog->FileName;
			this->dicomImage->Save(saveFileDialog->FileName, Imaging::ImageFormat::Jpeg);
		}*/
		int bitmapHeight = 0, bitmapWidth = 0, min,max;
		int* frame;
		//vh->getCurrentMinMax(min,max); //pelna dynamika kazdej klatki. falszuje informacje miedzy obrazami
		vh->getGlobalMinMax(min, max);  //nie pelna dynamika klatek. Prawdziwe relacje miedzy barwami w roznych klatkach
		if (dir)
		{
			frame = vh->getAndMoveFrame();
		}
		else{
			frame = vh->getAndBackFrame();
		}
		if (frame == NULL)
		{
			frame = vh->getThisFrame();
			dir = !dir;
		}
		vh->getSize(bitmapWidth, bitmapHeight);
		this->dicomImage = gcnew Bitmap(bitmapHeight, bitmapWidth, Imaging::PixelFormat::Format24bppRgb);
		ParserH::getBitmap(bitmapWidth, bitmapHeight, this->dicomImage, frame,min,max);

		//display picture
		pictureBox1->Image = this->dicomImage;
	}
}

