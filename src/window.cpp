// Copyright 2018 Patrick Flynn
//
// Redistribution and use in source and binary forms, with or without modification, 
// are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, 
//	this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this 
//	list of conditions and the following disclaimer in the documentation and/or 
//	other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may 
//	be used to endorse or promote products derived from this software 
//	without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#include "window.hh"

AppWindow::AppWindow(Glib::RefPtr<Gtk::Application> appP) {
	app = appP;
	
	this->set_title("LogViewer");
	this->set_default_size(800,600);
    this->set_icon_name("logview");

    mainLayout = new Gtk::VBox(false,0);
    this->add(*mainLayout);

    splitter = new Gtk::HPaned;
    mainLayout->pack_start(*splitter,true,true,0);

    scroller1 = new Gtk::ScrolledWindow;
    scroller2 = new Gtk::ScrolledWindow;
    scroller1->set_policy(Gtk::POLICY_NEVER,Gtk::POLICY_AUTOMATIC);
    scroller2->set_policy(Gtk::POLICY_NEVER,Gtk::POLICY_AUTOMATIC);

    text = new TextView;
    scroller2->add(*text);
    splitter->add2(*scroller2);

    tree = new TreeView(text);
    scroller1->add(*tree);
    splitter->add1(*scroller1);

    header = new HeaderBar(appP);
	this->set_titlebar(*header);
}

AppWindow::~AppWindow() {
    delete mainLayout;
    delete splitter;
    delete scroller1;
    delete scroller2;
    delete text;
    delete tree;
    delete header;
}
