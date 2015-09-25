/*
 * Xournal++
 *
 * Abstract Sidebar Page
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "model/DocumentChangeType.h"
#include "model/DocumentListener.h"

#include <XournalType.h>

#include <gtk/gtk.h>

#include <string>
using std::string;

class Control;

class AbstractSidebarPage : public DocumentListener
{
public:
	AbstractSidebarPage(Control* control);
	virtual ~AbstractSidebarPage();

public:
	// DocumentListener interface
	virtual void documentChanged(DocumentChangeType type);
	virtual void pageSizeChanged(int page);
	virtual void pageChanged(int page);
	virtual void pageInserted(int page);
	virtual void pageDeleted(int page);
	virtual void pageSelected(int page);

public:

	/**
	 * The name of this sidebar page
	 */
	virtual string getName() = 0;

	/**
	 * The name of this sidebar page
	 */
	virtual string getIconName() = 0;

	/**
	 * If this sidebar page has data for the current document, e.g. if there are bookmarks or not
	 */
	virtual bool hasData() = 0;

	/**
	 * Gets the Widget to display
	 */
	virtual GtkWidget* getWidget() = 0;

	/**
	 * Temporary disable Sidebar (e.g. while saving)
	 */
	virtual void setTmpDisabled(bool disabled);

	/**
	 * Page selected
	 */
	virtual bool selectPageNr(int page, int pdfPage);

	/**
	 * Returns the Application controller
	 */
	Control* getControl();

private:
	XOJ_TYPE_ATTRIB;

protected:
	/**
	 * The Control of the Application
	 */
	Control* control;

public:
	/**
	 * The Sidebar button
	 */
	GtkToolItem* tabButton;

};
