//
// C++ Interface: CheckboxRepresentation
//
// Description: 
//
// Author: Martin Preisler <preisler.m@gmail.com>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.//
//
#ifndef EMBEROGRE_GUI_REPRESENTATIONS_CHECKBOXREPRESENTATION_H
#define EMBEROGRE_GUI_REPRESENTATIONS_CHECKBOXREPRESENTATION_H

#include "SingleAdapterRepresentationBase.h"
#include "LayoutHelper.h"
#include "../adapters/ComboboxAdapter.h"
#include <CEGUIWindowManager.h>
#include <elements/CEGUICheckbox.h>

namespace Ember {
namespace OgreView {

namespace Gui {

namespace Representations {

/**
 * @brief represents given value by a checkbox (the underlying value has to be bool!)
 */
template<typename ValueType>
class CheckboxRepresentation : public SingleAdapterRepresentationBase<ValueType>
{
public:
	/**
	 * @brief Ctor
	 * 
	 * @param value Value this representation should represent
	 */
	CheckboxRepresentation(ValueType& value):
		SingleAdapterRepresentationBase<ValueType>(value)
	{
		mLayout = LayoutHelper::loadLayout("CheckboxRepresentation.layout", mPrefix);
		
		this->setAdapter(new GenericPropertyAdapter<ValueType, bool>(value, CEGUI::WindowManager::getWindow(mPrefix + "Checkbox"), "Selected", CEGUI::Checkbox::EventCheckStateChanged);
	}
	
	/**
	 * @brief Dtor
	 */
	virtual ~CheckboxRepresentation()
	{
		CEGUI::WindowManager::getSingleton().destroyWindow(mLayout);
	}
	
	virtual CEGUI::Window* getGuiRoot()
	{
		return mLayout;
	}
	
protected:
	CEGUI::Window* mLayout;
	CEGUI::String mPrefix;
};

}

}

}

}

#endif