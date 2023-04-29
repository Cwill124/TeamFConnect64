#include <ScrollableAlertWindow.h>

namespace view {

ScrollableAlertWindow::ScrollableAlertWindow(const char *message, const char *title) :
		Fl_Window(200, 200, title) {
	begin();
	this->message = new Fl_Text_Display(5, 5, 180, 150);

	this->buffer = new Fl_Text_Buffer();
	this->closeAlertButton = new Fl_Button(65, 160, 70, 30, "Close");
	this->closeAlertButton->callback(cb_close, this);

	this->message->buffer(this->buffer);
	this->message->buffer()->text(message);

	end();
}

void ScrollableAlertWindow::cb_close(Fl_Widget *widget, void *data) {
	ScrollableAlertWindow *window = (ScrollableAlertWindow*) data;
	window->closeWindow();
}
void ScrollableAlertWindow::closeWindow() {
	this->hide();
}
ScrollableAlertWindow::~ScrollableAlertWindow() {
	this->message = nullptr;
	delete this->message;
	this->buffer = nullptr;
	delete this->buffer;
	this->closeAlertButton = nullptr;
	delete this->closeAlertButton;
}

}
