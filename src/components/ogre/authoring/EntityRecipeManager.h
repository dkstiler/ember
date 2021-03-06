//
// C++ Interface: EntityRecipeManager
//
// Description:
//
//
// Author: Alexey Torkhov <atorkhov@gmail.com>, (C) 2008
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
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.//
//
#ifndef EMBEROGREENTITYRECIPEMANAGER_H
#define EMBEROGREENTITYRECIPEMANAGER_H

#include "components/ogre/EmberOgrePrerequisites.h"

#include <OgreResourceManager.h>
#include "framework/Singleton.h"
#include "XMLEntityRecipeSerializer.h"

namespace Ember
{
namespace OgreView
{
namespace Authoring
{
/**
 * Resource manager for entity recipes.
 */
class EntityRecipeManager: public Ogre::ResourceManager, public Singleton<EntityRecipeManager>
{
public:
	/**
	 * Constructor
	 */
	EntityRecipeManager();

	/**
	 * Destructor
	 */
	~EntityRecipeManager() override;

	/// Create a new EntityRecipe
	/// @see ResourceManager::createResource
	EntityRecipePtr create (const Ogre::String& name, const Ogre::String& group,
			bool isManual = false, Ogre::ManualResourceLoader* loader = nullptr,
			const Ogre::NameValuePairList* createParams = nullptr);

	/**
	 * Parse a script file.
	 */
	void parseScript(Ogre::DataStreamPtr &stream, const Ogre::String &groupName) override;

protected:
	/**
	 Serializer for xml.
	 */
	XMLEntityRecipeSerializer mXmlSerializer;

	/**
	 * Create a new resource instance compatible with this manager.
	 */
	Ogre::Resource* createImpl(const Ogre::String& name, Ogre::ResourceHandle handle, const Ogre::String& group, bool isManual, Ogre::ManualResourceLoader* loader, const Ogre::NameValuePairList* createParams) override;
};

}
}
}
#endif
