ActionBar = {}

function ActionBar:addSlot()
	local yPosition = 0
	local xPosition = 0
	if self.layout == "Horiz" then
		yPosition = math.floor(self.slotcounter / self.maxSlots)
		xPosition = self.slotcounter - math.floor(self.slotcounter/self.maxSlots)*self.maxSlots 
	else
		yPosition = self.slotcounter - math.floor(self.slotcounter/self.maxSlots)*self.maxSlots 
		xPosition = math.floor(self.slotcounter / self.maxSlots)
	end	
	
	self.slotcounter = self.slotcounter + 1
	
	local slot = self.entityIconManager:createSlot(self.iconSize)
	slot:getWindow():setPosition(CEGUI.UVector2(CEGUI.UDim(0, self.iconSize * xPosition), CEGUI.UDim(0, self.iconSize * yPosition)))
	slot:getWindow():setAlpha(1.0)
	slot:getWindow():setProperty("FrameEnabled", "true")
	slot:getWindow():setProperty("BackgroundEnabled", "true")
	self.iconContainer:addChildWindow(slot:getWindow())
	local slotWrapper = {slot = slot}
	table.insert(self.slots, slotWrapper)
	
	slotWrapper.entityIconDropped = function(entityIcon)
		local oldSlot = entityIcon:getSlot()
		slotWrapper.slot:addEntityIcon(entityIcon)
		if oldSlot ~= nil then
			oldSlot:notifyIconDraggedOff(entityIcon)
		end
	end
	
	slotWrapper.entityIconDropped_connector = EmberOgre.LuaConnector:new_local(slot.EventIconDropped):connect(slotWrapper.entityIconDropped)
	
	return slotWrapper
end

function ActionBar:buildCEGUIWidget(widgetName)
	self.widget = guiManager:createWidget()
	if widgetName == nil then
		widgetName = "ActionBar/"
	end
	self.widget:loadMainSheet("ActionBar.layout", widgetName)
	self.iconContainer = self.widget:getWindow("IconContainer")
	
	local slotSize = (self.maxSlots*self.iconSize)+(self.maxSlots*2)
	self.dragBar = self.widget:getWindow("TitleBar")
	
	if self.layout == "Horiz" then
		self.widget:getMainWindow():setSize(CEGUI.UVector2(CEGUI.UDim(0.0,slotSize),CEGUI.UDim(0.0,self.iconSize))) 
	else
		self.widget:getMainWindow():setSize(CEGUI.UVector2(CEGUI.UDim(0.0,self.iconSize),CEGUI.UDim(0.0,slotSize+20)))
		--Drag bar needs to be resized to the top for vertical action bars.
		self.dragBar:setSize(CEGUI.UVector2(CEGUI.UDim(1.0,0.0),CEGUI.UDim(0.0,12.0)))
		--Need to shift the icon container down so that our drag bar doesn't overlap.
		self.iconContainer:setPosition(CEGUI.UVector2(CEGUI.UDim(0.0,0.0),CEGUI.UDim(0.0,12.0)))
	end
	self.widget:show()
	
	--Make 10 slots in the ActionBar.
	for i = 1,self.maxSlots do
		self:addSlot()
	end
	
end

function ActionBar:gotInput(args)
	debugObject(args)
end

function ActionBar.new(rotation)
	local actionbar = {   iconSize = 50,
				maxSlots = 5,
				iconcounter = 0,
				slotcounter = 0,
				inputHelper = nil,
				iconContainer = nil,
				icons = {},
				connectors={},
				widget = nil,
				layout = rotation, --Vertical or horizontal action bar
				slots = {}};
				
	setmetatable(actionbar,{__index=ActionBar})
	return actionbar
end

function ActionBar:init(widgetName)
	--TODO: When we implement the shutdown method, we need to delete this
	self.input1 = EmberOgre.Gui.ActionBarInput:new("1")
	
	self.entityIconManager = guiManager:getEntityIconManager()
	
	connect(self.connectors, self.input1.EventGotHotkeyInput, self.gotInput, self)
	
	self:buildCEGUIWidget(widgetName)
end

function ActionBar:shutdown()
	disconnectAll(self.connectors)
	guiManager:destroyWidget(self.widget)

end