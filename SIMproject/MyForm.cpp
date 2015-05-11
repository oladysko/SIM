#include "MyForm.h"
#include "Parser.h"
#include "DicomDataAdapter.h"
#include "VideoHandler.h"

using namespace System; 
using namespace System::Windows::Forms; 
using namespace System::Drawing;

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

		/*test generacji video*/
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
		/*koniec testu generacji video*/

		//variables
		unsigned int frameNumber;
		String^ debugInfo;
		String^ fileName;
		int bitmapHeight = 0, bitmapWidth = 0;
		std::string stdFileName;

		try
		{
			//get frame number
			frameNumber = Convert::ToUInt32(this->frame_textBox->Text);
			debugInfo = "selected frame = " + Convert::ToString(frameNumber) + "\n";

			//get file
			OpenFileDialog^ dlg = gcnew OpenFileDialog();
			dlg->ShowDialog();
			fileName = dlg->FileName;
			ParserH::MarshalString(fileName, stdFileName);
			ParserH::fileNametoPath(stdFileName);
			String^ tmpString = gcnew String(stdFileName.c_str());
			debugInfo = debugInfo + "selected file = \n" + tmpString + "\n";
		}
		catch (Exception^ errorHandle){
			this->Info_label->Text = errorHandle->Message;
			return;
		}

		DicomDataAdapter dicomData = DicomDataAdapter::DicomDataAdapter(stdFileName);

		//get height and width
		ParserH::getImageSize(bitmapHeight, bitmapWidth, frameNumber, &dicomData);
		debugInfo = "bitmapHeight = " + bitmapHeight + "\nbitmapWidth = " + bitmapWidth;//Format16bppGrayScale
		//create bitmap
		this->dicomImage = gcnew Bitmap(bitmapHeight, bitmapWidth, Imaging::PixelFormat::Format24bppRgb); 
		ParserH::getBitmap(bitmapHeight, bitmapWidth, frameNumber, &dicomData, this->dicomImage);

		//display picture
		pictureBox1->Image = this->dicomImage;
		this->Info_label->Text = debugInfo;
	}

	System::Void MyForm::saveCurrent_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveFileDialog ^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "JPeg Image|*.jpg|Bitmap Image|*.bmp|Gif Image|*.gif";
		saveFileDialog->Title = "Save an Image File";
		saveFileDialog->ShowDialog();

		//if filename is not empty string
		if (saveFileDialog->FileName != ""){
			this->Info_label->Text = "filename for saving: " + saveFileDialog->FileName;
			this->dicomImage->Save(saveFileDialog->FileName, Imaging::ImageFormat::Jpeg);
		}
	}
}

